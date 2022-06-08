#ifndef MClIENT_H
#define MCLIENT_H

class MClient {
  private:

    WebSocketsClient webSocket;
    const char *id;
    bool connected = false;

    static void webSocketEvent(WStype_t type, uint8_t* payload, size_t length) {

    MClient* instance = MClient::instance;
 
    switch(type) {
      case WStype_DISCONNECTED:
        Serial.printf("Disconnected!\n");
        instance->connected = false;
        break;

      case WStype_CONNECTED: {
        Serial.printf("Connected to url: %s\n", payload);

        instance->webSocket.sendTXT((String("{'type': 'identifier', 'id': '") + String(instance->id) + String("'}")).c_str());
        instance->connected = true;
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
    static MClient* instance;

    MClient(const char *url, uint16_t port, const char *id) {
      this->instance = this;

      this->id = id;

      this->webSocket.begin(url, port);
      this->webSocket.onEvent(webSocketEvent);
    }

    void loop(){
      this->webSocket.loop();
    }
};

MClient* MClient::instance = nullptr;

#endif
