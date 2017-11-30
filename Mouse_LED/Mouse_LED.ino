
const int RIGHT_LED = 12;      // the pin that the LED is attached to
const int LEFT_LED = 13;      // the pin that the LED is attached to

void setup()
{
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize the ledPin as an output:
  pinMode(RIGHT_LED, OUTPUT);
  pinMode(LEFT_LED, OUTPUT);
}

void loop() 
{
  byte ON_OFF;

  // check if data has been sent from the computer:
  if (Serial.available()) 
  {
    // read the most recent byte (which will be from 0 to 255):
    ON_OFF = Serial.read();
    // set the brightness of the LED:
    analogWrite(RIGHT_LED, ON_OFF);
    analogWrite(LEFT_LED, ON_OFF);
  }
}

