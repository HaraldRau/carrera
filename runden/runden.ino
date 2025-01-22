#include <DigitLedDisplay.h>

// initialize with pin numbers for DIN, CS, CLK
DigitLedDisplay ld = DigitLedDisplay(7, 6, 5);

bool durchfahrt_1 = 0;
bool durchfahrt_2 = 0;
bool start = 0;
int runde = 0;
int runden_zeit_1[50];
int runden_zeit_2[50];
unsigned long startzeit = millis();
unsigned long rennzeit = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), spur_1, FALLING);
  ld.setBright(15); // range is 0-15
  ld.setDigitLimit(8);
  starten();//Rennen starten und Starzeit auf Runde 0 setzen
}


void loop()
{
  rennzeit = abs(millis()/100)-startzeit;
  if (durchfahrt_1 == 1 && runden_zeit_1[runde]+100<rennzeit)
  {
    runde++;
    runden_zeit_1[runde] = rennzeit;
    durchfahrt_1 = 0;
    delay(10);
    anzeige_1();
  }
  else
  {
    durchfahrt_1 = 0;
  }
	delay(10);
  //Kontrollausgabe auf dem Monitor kann später gelöscht werden
  if (runde>9)
  {
    for (int i=0; i< 10; i++)
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
  ld.clear();
  ld.printDigit(rennzeit,4);
  delay(1500);
  ld.clear();
  ld.printDigit(runde,4);
  Serial.println(rennzeit);
  //Serial.print("Runde: ");
  //Serial.print(runde);
  //Serial.print(" ");
}
void starten()
{
  ld.printDigit(8,0);
  delay(500);
  ld.printDigit(88,0);
  delay(500);
  ld.printDigit(888,0);
  delay(500);
  ld.printDigit(8888,0);
  delay(500);
  ld.printDigit(88888,0);
  delay(500);
  ld.printDigit(888888,0);
  delay(500);
  ld.printDigit(8888888,0);
  delay(500);
  ld.printDigit(88888888,0);
  delay(1000);
  ld.clear();
  startzeit = abs(millis()/100);
  runden_zeit_1[0]=0;
  Serial.println(startzeit);
  Serial.println("--START--");
  return;
}
void ziel(){}
void geschwindigkeit(){}
