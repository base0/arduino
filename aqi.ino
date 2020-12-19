#include <MyHttpClient.h>
#include <ArduinoJson.h>

MyHttpClient myHttpClient;
DynamicJsonDocument doc(1024);

void setup() {
  Serial.begin(9600);
  
  myHttpClient.setup("ssid", "password");
  char* url = "http://api.airvisual.com/v2/city?city=Chatuchak&state=Bangkok&country=Thailand&key=";

  Serial.println(myHttpClient.get(url));
  Serial.println(myHttpClient.getResponse());

  deserializeJson(doc, myHttpClient.getResponse());
  int aqi = doc["data"]["current"]["pollution"]["aqius"];
  Serial.println(aqi);
}

void loop() {
  delay(10000);
}
