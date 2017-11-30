#include "BlinkLED.h" 
const int FirstLedPin = 3; // choose the pin for each of the LEDs
const int SecondLedPin = 4;
const int ThirdLedPin = 5;

void setup()
{
  pinMode(FirstLedPin, OUTPUT); // declare LED pins as output
  pinMode(SecondLedPin, OUTPUT); // declare LED pins as output
  pinMode(ThirdLedPin, OUTPUT); // declare LED pins as output
}

void loop()
{
  // flash each of the LEDs for 1000 milliseconds (1 second)
  BlinkLED(FirstLedPin, 1000);
  BlinkLED(SecondLedPin, 1000);
  BlinkLED(ThirdLedPin, 1000);
}
