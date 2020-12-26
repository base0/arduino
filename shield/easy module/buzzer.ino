void setup() {
}

const int buzzerPin = 5;
int freqs[] = {523, 587, 659, 698, 784, 880, 988};

void loop() {
  for (int i = 0; i < 7; i++) {
    tone(buzzerPin, freqs[i], 500);
    delay(1000);
  }

  delay(1000);
}
