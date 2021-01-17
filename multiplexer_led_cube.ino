const byte TOP = 9;
const byte MIDDLE = 10;
const byte BOTTOM = 11;
void setup() {
  for (int i = 0; i < 12; i++)
    pinMode(i, OUTPUT);
  
}


void loop() {
  digitalWrite(TOP, HIGH);
  digitalWrite(BOTTOM, HIGH);
  digitalWrite(MIDDLE, LOW);
  digitalWrite(5, HIGH);
  
  digitalWrite(TOP, HIGH);
  digitalWrite(BOTTOM, HIGH);
  digitalWrite(MIDDLE, HIGH);
  digitalWrite(5, LOW);
  
  digitalWrite(TOP, LOW);
  digitalWrite(BOTTOM, HIGH);
  digitalWrite(MIDDLE, HIGH);
  digitalWrite(1, HIGH);

  digitalWrite(TOP, HIGH);
  digitalWrite(BOTTOM, HIGH);
  digitalWrite(MIDDLE, HIGH);
  digitalWrite(1, LOW);

  
}
