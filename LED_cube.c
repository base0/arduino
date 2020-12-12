/*
each layer has common anode + connect to PIN 9, 10, 11
each column has common cathod - connect to PIN 0-8
*/
const byte TOP = 9;
const byte MIDDLE = 10;
const byte BOTTOM = 11;

enum {ON, OFF, BLINK};

int led[3][9];
int lasttime;
int state = 0;

void setup() {
  randomSeed(analogRead(5));
  
  for (int i = 0; i < 12; i++)
    pinMode(i, OUTPUT);
    
  for (int level = 0; level < 3; level++) {
    for (int i = 0; i < 9; i++) {
      led[level][i] = OFF;
    }
  }
  
  for (int i = 0; i < 9; i++) {
    led[0][i] = ON;
  }
  
  lasttime = millis() / 1000;
}

void set(int level, int n) {
  int a[] = {HIGH, HIGH, HIGH};
  a[level] = LOW;
  digitalWrite(TOP, a[0]);
  digitalWrite(MIDDLE, a[1]);
  digitalWrite(BOTTOM, a[2]);
  digitalWrite(n, HIGH);
  
  digitalWrite(TOP, HIGH);
  digitalWrite(MIDDLE, HIGH);
  digitalWrite(BOTTOM, HIGH);
  digitalWrite(n, LOW);
}

void clr(int level, int n) {
  digitalWrite(n, LOW);
  digitalWrite(TOP, HIGH);
  digitalWrite(MIDDLE, HIGH);
  digitalWrite(BOTTOM, HIGH);
}

void display() {
  unsigned long t = millis();
  for (int level = 0; level < 3; level++) {
    for (int i = 0; i < 9; i++) {
      switch (led[level][i]) {
        case ON:
          set(level, i);
          break;
        case OFF:
          clr(level, i);
          break;
        case BLINK:
          if ((t / 100) % 2 == 0)      
            set(level, i);
          else
            clr(level, i);
          break;
        }
    }
  }
}

int select;
bool fall;

void update() {
  switch(state % 6) {
    case 2:
      // find a dot on top or a bottom and blink
       select = random(9);
       fall = led[0][select] == ON;
       if (fall) led[0][select] = BLINK;
       else      led[2][select] = BLINK;
       break;
    case 3:
       // move the choosen dot to the middle
       led[1][select] = BLINK;
       if (fall) led[0][select] = OFF;
       else      led[2][select] = OFF;
       break;
    case 4:
       led[1][select] = OFF;
       if (fall) led[2][select] = BLINK;
       else      led[0][select] = BLINK;
       break;
    case 5:
       if (fall) led[2][select] = ON;
       else      led[0][select] = ON;
       break;
  }
}

void loop() {
  int currenttime = millis() / 1000;
  if (currenttime == lasttime) {
    display();
  } else {
    lasttime = currenttime;
    state++;
    update();
  }
}
