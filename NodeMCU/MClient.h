#ifndef MClIENT_H
#define MCLIENT_H


class MClient {
  private:
    WebSocketsClient webSocket;
    const char *id;
    bool connected = false;

    void webSocketEvent(WStype_t type, uint8_t* payload, size_t length) {
 
    switch(type) {
      case WStype_DISCONNECTED:
        Serial.printf("Disconnected!\n");
        this->connected = false;
        break;

      case WStype_CONNECTED: {
        Serial.printf("Connected to url: %s\n", payload);

        this->webSocket.sendTXT((String("{'type': 'identifier', 'id': '") + String(id) + String("'}")).c_str());
        this->connected = true;
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
    MClient(const char *url, uint16_t port, const char *id) {
      this->id = id;

      webSocket.begin(url, port);
    }

    void loop(){
      webSocket.loop();
    }
};


#endif
