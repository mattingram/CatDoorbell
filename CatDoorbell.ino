int pirPin = 7;
int ledPin = 13;
 
int minSecsBetweenEmails = 0; // 1 min
 
long lastSend = -minSecsBetweenEmails * 1000l;
 
void setup()
{
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  long now = millis();
  if (digitalRead(pirPin) == HIGH)
  {
    if (now > (lastSend + minSecsBetweenEmails * 1000l))
    {
      Serial.println("MOVEMENT");
      blinkLED();
      lastSend = now;
    }
    else
    {
      Serial.println("Too soon");
      blinkLED();
    }
  }
  delay(500);
}

void blinkLED()
{
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
}
