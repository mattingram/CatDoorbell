// Uses a PIR sensor to detect movement, buzzes a buzzer
// more info here: http://blog.makezine.com/projects/pir-sensor-arduino-alarm/
// email me, John Park, at jp@jpixl.net
// based upon:
// PIR sensor tester by Limor Fried of Adafruit
// tone code by michael@thegrebs.com

 
int ledPin = 13;                // choose the pin for the LED
int inputPin = 7;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int pinSpeaker = 3;             //Set up a speaker on a PWM pin (digital 9, 10, or 11)
bool alarmEnabled = true;
bool debug = true;

void setup() {
  //pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);       // declare sensor as input
  pinMode(pinSpeaker, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  val = digitalRead(inputPin);  // read input value
    
  if (val == HIGH)
  {
    if (alarmEnabled)
    {
      for(int i=0; i < 3; i++)
      {
        meow();
      }
    }
//    delay(150); // added to prevent the device from retriggering too fast, but apparently this causes us to skip some reads.
    
    if (pirState == LOW)
    {
      // we have just turned on
      // We only want to print on the output change, not state
      pirState = HIGH;
      if (debug) Serial.println("Motion detected!");
    }
  }
  else
  {
    noTone(pinSpeaker);
    //delay(300);   // added to prevent the device from retriggering too fast, but apparently this causes us to skip some reads.
    if (pirState == HIGH)
    {
      // We only want to print on the output change, not state
      pirState = LOW;
      if (debug) Serial.println("Motion ended!");
    }
  }
}


void meow()
{
  if (debug) Serial.println("Meow");
  tone(pinSpeaker, 1060);
  delay(100);
//  delay(300);
  tone(pinSpeaker, 860);
  delay(100);
//  delay(600);
  noTone(pinSpeaker);
}
