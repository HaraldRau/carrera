bool durchfahrt_1 = 0;
bool durchfahrt_2 = 0;
int runde = 0;
int runden_zeit[9];
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
  rennzeit = abs(millis()/10);
  if (durchfahrt_1 == 1)
  {
    Serial.print("Runde: ");
    Serial.print(runde);
    Serial.print(" ");
    Serial.println(rennzeit);
    delay(100);
    durchfahrt_1 = 0;
    runde++;
  }
	delay(10);
}

void spur_1()
{
durchfahrt_1 = 1;
return durchfahrt_1;
}
