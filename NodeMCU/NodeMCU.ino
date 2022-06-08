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

  pinMode(wifiLed, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(wifiLed, HIGH);
  digitalWrite(ledPin, HIGH);
  
  
  // Connect to Wi-Fi
  wifiConnect();

  client = new MClient;
}
 
void loop() {  
  client->loop();
}
