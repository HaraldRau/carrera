#include <DigitLedDisplay.h>

// initialize with pin numbers for DIN, CS, CLK
DigitLedDisplay ld = DigitLedDisplay(7, 6, 5);

bool durchfahrt_1 = 0;
bool durchfahrt_2 = 0;
int runde = 0;
int runden_zeit_1[50];
unsigned long startzeit = millis();
unsigned long rennzeit = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), spur_1, FALLING);
  ld.setBright(15); // range is 0-15
  ld.setDigitLimit(8);
}


void loop()
{
  runden_zeit_1[0]=startzeit;
  rennzeit = abs(millis()/100);
  if (durchfahrt_1 == 1 && runden_zeit_1[runde]+100<rennzeit)
  {
    runde++;
    delay(10);
    durchfahrt_1 = 0;
    anzeige_1();   
  }
  else
  {
    durchfahrt_1 = 0;
  }
	delay(10);
  if (runde>9)
  {for (int i=0; i< 10; i++)
  {
    Serial.println(runden_zeit_1[i]);
    delay(100);
    runde=0;
    }
  }
}

void spur_1()
{
durchfahrt_1 = 1;
return durchfahrt_1;
}

void anzeige_1()
{
  runden_zeit_1[runde] = rennzeit;
  ld.clear();ld.printDigit(runde,4);
  ld.printDigit(rennzeit,0);
  Serial.println(rennzeit);
  //Serial.print("Runde: ");
  //Serial.print(runde);
  //Serial.print(" ");
}
