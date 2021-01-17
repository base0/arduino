#include <ESP8266WiFi.h>
#include "IFTTTWebhook.h"

const char* ssid = "vivoviii"; 
const char* password = "9988776655"; 

const char* KEY = "d7hynZdp8At9PIKp9Eme0U";
const char* EVENT = "";

void setup () {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());

  IFTTTWebhook wh(KEY,  EVENT);
  Serial.println(wh.trigger());
}

void loop() {

}
