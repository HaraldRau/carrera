#include <DigitLedDisplay.h>

// initialize with pin numbers for DIN, CS, CLK
DigitLedDisplay ld = DigitLedDisplay(7, 6, 5);

boolean ir_1 = 1;
unsigned long startzeit = millis();
unsigned long rennzeit = 0;

void setup() {
  Serial.begin(9600);
  ld.setBright(15); // range is 0-15
  ld.setDigitLimit(8);
}


void loop() {
  if (ir_1 ==1)
  {
    ir_1 = digitalRead(2);
    ld.printDigit(rennzeit,4); // schreibe die zahl beginned bei digit 4 von rechts gezaelt ab 01234567
    delay(100);
    rennzeit = abs((millis()-startzeit)/100);
    ld.printDigit(rennzeit,0);
  }
  else
  {
    Serial.println(rennzeit);
    delay(1000);
  }
  delay(10);
}