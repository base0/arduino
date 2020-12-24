void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}
void loop() {
  if (digitalRead(2) == HIGH)
    digitalWrite(12, HIGH);
  else
    digitalWrite(12, LOW);
 
  if (digitalRead(3) == HIGH)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
}
