// Uses a PIR sensor to detect movement, buzzes a buzzer

bool soundEnabled = true;
int maxTimeout = 3;
 
int ledPin = 13;                // choose the pin for the LED
int inputPin = 7;               // choose the input pin (for PIR sensor)
int pinSpeaker = 3;             // Set up a speaker on a PWM pin (digital 9, 10, or 11)

int loopCount = 0;
bool motionDetected = false;

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(pinSpeaker, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensor = digitalRead(inputPin);  // read sensor

  if (sensor == HIGH) {                // motion detected
    // if previously no motion was detected
    if (motionDetected == false) {
      Serial.println("Motion detected!");
      digitalWrite(ledPin, HIGH);        // turn LED ON
      meow(2);
      loopCount = 0;
      motionDetected = true;
    }
  }
  else if (sensor == LOW)      // no motionx
  {
    // if previous state was motion detected
    if (motionDetected == true)
    {
      Serial.println("Motion ended!");
      digitalWrite(ledPin, LOW); // turn LED OFF
      noTone(pinSpeaker);        // turn speaker off
      loopCount = 0;
      motionDetected = false;
    }
  }
  
  if (loopCount >= maxTimeout)
  {
    Serial.println("Timeout expired.");
    digitalWrite(ledPin, LOW); // turn LED OFF
    noTone(pinSpeaker);        // turn speaker off
    loopCount = 0;
    motionDetected = false;
  }
  
  loopCount++;
  //Serial.println(loopCount);
  Serial.println(sensor);
  delay(1000);                // delay 1 second
}


void meow(int times)
{
  for(int i=0; i < times; i++)
  {
    Serial.println("Meow");
    if (soundEnabled)
      tone(pinSpeaker, 1060);
    delay(300);
    if (soundEnabled)
    {
      tone(pinSpeaker, 860);
      delay(600);
    }
    noTone(pinSpeaker);
  }
}
