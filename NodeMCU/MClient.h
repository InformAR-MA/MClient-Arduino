#ifndef MClIENT_H
#define MCLIENT_H


class MClient{
  private:
    WebSocketsClient webSocket;

   public:
    MClient(){
     webSocket.begin("192.168.137.1", 8080, "/");
    }

    void loop(){
      webSocket.loop();
    }
};


#endif
