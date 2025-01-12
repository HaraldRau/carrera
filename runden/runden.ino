bool durchfahrt_1 = 0;
bool durchfahrt_2 = 0;
int runde = 0;
int runden_zeit[50];
unsigned long startzeit = millis();
unsigned long rennzeit = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), spur_1, FALLING);
  Serial.println(startzeit);
}


void loop()
{
  runden_zeit[0]=startzeit;
  rennzeit = abs(millis()/10);
  if (durchfahrt_1 == 1)
  {
    if (runden_zeit[runde]+150<rennzeit)
    {
      runde++;
      Serial.print("Runde: ");
      Serial.print(runde);
      Serial.print(" ");
      Serial.println(rennzeit);
      delay(10);
      durchfahrt_1 = 0;
      runden_zeit[runde] = rennzeit;
    }
  }
	delay(10);
  if (runde>9)
  {for (int i=0; i< 10; i++)
  {
    Serial.println(runden_zeit[i]);
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
