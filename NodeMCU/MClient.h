#ifndef MClIENT_H
#define MCLIENT_H


class MClient {
  private:
    static MClient* client = nullptr;

    WebSocketsClient webSocket;
    const char *id;
    bool connected = false;

    static void webSocketEvent(WStype_t type, uint8_t* payload, size_t length) {
    MClient* client = MClient::client;
 
    switch(type) {
      case WStype_DISCONNECTED:
        Serial.printf("Disconnected!\n");
        client->connected = false;
        break;

      case WStype_CONNECTED: {
        Serial.printf("Connected to url: %s\n", payload);

        client->webSocket.sendTXT((String("{'type': 'identifier', 'id': '") + String(id) + String("'}")).c_str());
        client->connected = true;
        break;

      case WStype_TEXT:
        Serial.printf("Received: %s\n", payload);
        break;

      case WStype_BIN:
      case WStype_PING:
      case WStype_PONG:
      case WStype_ERROR:
      case WStype_FRAGMENT_TEXT_START:
      case WStype_FRAGMENT_BIN_START:
      case WStype_FRAGMENT:
      case WStype_FRAGMENT_FIN:
        break;
    }
  }
}

  public:
    MClient* create(const char *url, uint16_t port, const char *id) {
      if(this->client != nullptr) return this->client;

      this->client = new MClient;
      client->id = id;

      client->webSocket.begin(url, port);
      client->webSocket.onEvent(webSocketEvent);

      return this->client;
    }

    void loop(){
      webSocket.loop();
    }
};


#endif
