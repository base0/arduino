#include <MyHttpClient.h>

MyHttpClient myHttpClient;

void setup() {
  Serial.begin(9600);
  
  myHttpClient.setup("ssid", "password");
  char* url = "http://api.airvisual.com/v2/city?city=Chatuchak&state=Bangkok&country=Thailand&key=";

  Serial.println(myHttpClient.get(url));
  Serial.println(myHttpClient.getResponse());
}

void loop() {
  delay(10000);
}
