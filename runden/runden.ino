#include <DigitLedDisplay.h>

// initialize with pin numbers for DIN, CS, CLK
DigitLedDisplay ld = DigitLedDisplay(7, 6, 5);

bool durchfahrt_1 = 0;
bool durchfahrt_2 = 0;
// bool start = 0;
int runde_1 = 0;
int runde_2 = 0;
int runden_zeit_1[50];
int runden_zeit_2[50];
unsigned long startzeit = millis();
unsigned long rennzeit = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), spur_1, FALLING);
  attachInterrupt(digitalPinToInterrupt(2), spur_2, FALLING);
  ld.setBright(15); // range is 0-15
  ld.setDigitLimit(8);
  starten();//Rennen starten und Starzeit auf Runde 0 setzen
}


void loop()
{
  rennzeit = abs(millis()/10)-startzeit;
  if (durchfahrt_1 == 1 && runden_zeit_1[runde_1]+200<rennzeit)
  {
    runde_1++;
    runden_zeit_1[runde_1] = rennzeit;
    durchfahrt_1 = 0;
    // delay(10);
    anzeige();
  }
  else
  {
    durchfahrt_1 = 0;
  }

    if (durchfahrt_2 == 1 && runden_zeit_2[runde_2]+200<rennzeit)
  {
    runde_2++;
    runden_zeit_2[runde_2] = rennzeit;
    durchfahrt_2 = 0;
    // delay(10);
    anzeige();
  }
  else
  {
    durchfahrt_2 = 0;
  }

   if (runde_1 > 9)
  {
    for (int i=1; i< 20; i++)
    {
      Serial.print(runden_zeit_1[i] - runden_zeit_1[i-1]);
      Serial.print(" | ");
      Serial.println(runden_zeit_2[i] - runden_zeit_2[i-1]);
      delay(100);
      runde_1=0;
      runde_2=0;
    }
  }

	delay(10);
// Kontrollausgabe auf dem Monitor kann später gelöscht werden
// Später alles für die zweite Spur duplizieren
}

void spur_1()
{
durchfahrt_1 = 1;
return durchfahrt_1;
}

void spur_2()
{
durchfahrt_2 = 1;
return durchfahrt_2;
}

void anzeige()
{
  ld.clear();
  // ld.printDigit(rennzeit,4);
  // delay(1500);
  // ld.clear();
  ld.printDigit(runde_1,4);
  ld.printDigit(runde_2,0);
  // Serial.println(rennzeit);
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
  startzeit = abs(millis()/10);
  runden_zeit_1[0]=0;
  runden_zeit_2[0]=0;
  Serial.println(startzeit);
  Serial.println("--START--");
  return;
}
void ziel(){}
void geschwindigkeit(){}
