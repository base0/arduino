// https://github.com/markruys/arduino-DHT

#include "DHT.h"

DHT dht;

void setup() {
  Serial.begin(9600);
  dht.setup(4);
}
void loop() {
  Serial.println(dht.getTemperature());
  Serial.println(dht.getHumidity());
  Serial.println(dht.getStatusString());
  delay(dht.getMinimumSamplingPeriod()*2);
}
