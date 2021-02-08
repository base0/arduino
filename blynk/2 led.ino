// LED

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "";
char ssid[] = "";
char pass[] = "";

BlynkTimer timer;

void myTimerEvent() {
  static int output;

  Serial.println(output);
  Blynk.virtualWrite(V6, output);
  output += 63;
  if (output > 255) output = 0;
}

void setup() {
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass); //, "blynk.iot-cm.com", 8080);
  timer.setInterval(1000L, myTimerEvent);
}

void loop() {
  Blynk.run();
    timer.run();
}
