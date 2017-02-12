int speakerPin = 3;
int pirPin = 7;
int ledPin = 13;
 
int minSecsDelay = 2500;
bool enableSound = false;
long lastSend = millis() - minSecsDelay;

void setup()
{
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  if (enableSound) alarm();
}

void alarm()
{
  tone(speakerPin, 1060);
  delay(300);
  tone(speakerPin, 860);
  delay(600);
  noTone(speakerPin);
}

void loop()
{
  long now = millis();
  if (digitalRead(pirPin) == HIGH)
  {
    if (now > (lastSend + minSecsDelay))
    {
      Serial.println(now);
      digitalWrite(ledPin, HIGH);
      if (enableSound){
        alarm();
      }
      else
        delay(500);
      lastSend = now;
    } 
  }
  digitalWrite(ledPin, LOW);
}
