#include <ESP8266WiFi.h>
#include "IFTTTWebhook.h"

const char* WIFI_SSID = ""; 
const char* WIFI_PASSWORD = ""; 

const char* IFTT_KEY = "";
const char* IFTT_EVENT = "";

void setup () {
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());

  IFTTTWebhook wh(IFTT_KEY,  IFTT_EVENT);
  Serial.println(wh.trigger());
}

void loop() {

}
