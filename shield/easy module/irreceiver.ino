// IRremote library by shirriff, z3t0
#include <IRremote.h> 

IRrecv receiver(6); 

void setup() {
  Serial.begin(9600); 
  receiver.enableIRIn(); 
  receiver.blink13(true); 
}

void loop() {
}
