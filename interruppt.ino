int running = 0;
int counter = 0;

//String ausgabe = "";

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), blink, FALLING);

  Serial.println(name);
}


void loop()
{
//Serial.println(digitalRead(2));
delay(100);
}

void blink()
{
  if (running > 0) 
  {
    return 0;
  }
  else
  {
    running = 1;
    String ausgabe = "Counter: ";
    ausgabe.concat(counter);
    ausgabe.concat(name);
    Serial.println(ausgabe);
    counter++;
    delay(3000);
    name = "Harald";
    running = 0;
  }

}


