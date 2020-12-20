// Credit : https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266HTTPClient/examples/BasicHttpClient

#include "myhttpclient.h"

ESP8266WiFiMulti WiFiMulti;

void MyHttpClient::setup(const char* ssid, const char* password) {
  for (uint8_t t = 4; t > 0; t--) {
    //Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, password);
}

int MyHttpClient::get(const char* url) {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    Serial.println(WiFi.localIP());
    WiFiClient client;

    HTTPClient http;

    //Serial.print("[HTTP] begin...\n");
    if (http.begin(client, url)) {  // HTTP

      //Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        //Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          response = http.getString();
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
      return httpCode;
    } else {
      Serial.printf("[HTTP] Unable to connect\n");
      return -1;
    }
  } else {
	Serial.println("cannot connect to WiFi");
    return -1;
  }
}

int MyHttpClient::getHttpCode() {
  return httpCode;
}

String& MyHttpClient::getResponse() {
  return response;
}
