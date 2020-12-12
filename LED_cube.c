const byte TOP = 9;
const byte MIDDLE = 10;
const byte BOTTOM = 11;
enum {ON, OFF, BLINK};
int state[3][9];

void setup() {
  for (int i = 0; i < 12; i++)
    pinMode(i, OUTPUT);
  for (int level = TOP; level <= BOTTOM; level++) {
    for (int i = 0; i < 9; i++) {
      state[level][i] = BLINK;
    }
  }
}

const int D = 2;

void set(int n, int level, int val) {
  level -= TOP;
  int a[] = {HIGH, HIGH, HIGH};
  a[level] = LOW;
  digitalWrite(TOP, a[0]);
  digitalWrite(MIDDLE, a[1]);
  digitalWrite(BOTTOM, a[2]);
  digitalWrite(n, val);
  //delay(D);
  /*digitalWrite(TOP, HIGH);
  digitalWrite(MIDDLE, HIGH);
  digitalWrite(MIDDLE, HIGH);
  digitalWrite(n, LOW);*/
  //delay(D);
}



void display() {
  unsigned long t = millis();
  for (int level = TOP; level <= BOTTOM; level++) {
    for (int i = 0; i < 9; i++) {
      switch (state[level][i]) {
        case ON:
          set(i, level, HIGH);
          break;
        case OFF:
          set(i, level, LOW);
          break;
        case BLINK:
          if ((t / 500) % 2 == 0)      
            set(i, level, HIGH);
          else
            set(i, level, LOW);
        }
    }
  }
  
  for (int level = TOP; level <= BOTTOM; level++) {
    for (int i = 0; i < 9; i++) {
      set(i, level, LOW);
    }
  }
}



void loop() {
  display();
}
