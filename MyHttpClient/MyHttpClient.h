// Credit : https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266HTTPClient/examples/BasicHttpClient
#ifndef MY_HTTP_CLIENT
#define MY_HTTP_CLIENT

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

class MyHttpClient {
public:
  void setup(const char*, const char*);
  int get(const char* url);
  int getHttpCode();
  String& getResponse();
private:
  int httpCode;
  String response;
};

#endif
