bool durchfahrt_1 = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), spur_1, FALLING);
}


void loop()
{
	Serial.println(durchfahrt_1);
	delay(100);
}

void spur_1()
{
durchfahrt_1 = 1
return durchfahrt_1
}


