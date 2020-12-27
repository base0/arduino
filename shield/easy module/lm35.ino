const int tempPin = 2;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  float tempC = analogRead(tempPin); 
  tempC = (5 * tempC * 100) / 1024; 
  Serial.println(tempC);
  delay(1000);
}
