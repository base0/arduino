const int buttonPin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  static int count;
  if (digitalRead(buttonPin) == LOW) {
    Serial.println(count++);
  }
}
