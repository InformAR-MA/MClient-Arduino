#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <WebSocketsClient.h>

#define wifiLed D1
#define ledPin D2


#include "network.h" 
#include "MClient.h"



MClient* client;

void setup () {
  Serial.begin(115200);
  
  wifiConnect();

  client = new MClient("192.168.137.1", 8080);
}
 
void loop() {  
  client->loop();
}
