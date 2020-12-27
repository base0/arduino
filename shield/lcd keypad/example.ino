// modified from allnewstep.com https://bit.ly/3puZPg7
#include <LiquidCrystal.h>

const int pin_RS = 8;
const int pin_EN = 9;

LiquidCrystal lcd( pin_RS, pin_EN, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hello");
}
void loop() {
  lcd.setCursor(0, 1);
  
  int x = analogRead(0);
  if (x < 60) {
    lcd.print("Right ");
  } else if (x < 200) {
    lcd.print("Up    ");
  } else if (x < 400) {
    lcd.print("Down  ");
  } else if (x < 600) {
    lcd.print("Left  ");
  } else if (x < 800) {
    lcd.print("Select");
  }
}
