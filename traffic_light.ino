const byte R = 7;
const byte Y = 6;
const byte G = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
}

int color = 0;

void loop() {
  byte P0, P1, P2;
  switch (color) {
    case 0:
      P0 = R; P1 = G; P2 = Y; break;
    case 1:
      P0 = G; P1 = R; P2 = Y; break;
    case 2:
      P0 = Y; P1 = R; P2 = G; break;
  }
  color++;
  color %= 3; 
  digitalWrite(P0, HIGH);
  digitalWrite(P1, LOW);
  digitalWrite(P2, LOW);
  delay(1000);
}
