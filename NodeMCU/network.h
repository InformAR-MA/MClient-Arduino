const char* ssid     = "NodeMCU"; // wifi lan
const char* password = "NodeMCUTesting"; // wifi lan


void wifiConnect(){
  WiFi.begin(ssid, password); // connect to wifi ssid with password 
  while (WiFi.status() != WL_CONNECTED) {
      //digitalWrite(wifiLed, HIGH);
      delay(1000); // wait 1 sec
      Serial.print("Connecting..");
      }
      //digitalWrite(wifiLed, LOW);
  //if connected
  Serial.print("\r\nConnected: IP address: "); 
  Serial.println(WiFi.localIP());
  //digitalWrite(wifiLed, HIGH);
  //digitalWrite(ledPin, HIGH);

  
 }
