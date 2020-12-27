const int LED_RED   =  9;
const int LED_GREEN = 10;
const int LED_BLUE  = 11;

void setup() {
  Serial.begin(9600); 
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
}

void loop() {
  analogWrite(LED_RED, random(0, 255));
  analogWrite(LED_GREEN, random(0, 255));
  analogWrite(LED_BLUE, random(0, 255));
  delay(1000);
}
