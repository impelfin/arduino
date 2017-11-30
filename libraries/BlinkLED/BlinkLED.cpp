#include "Arduino.h"
#include "BlinkLED.h"

void BlinkLED(int pin, int duration)
{
	digitalWrite(pin, HIGH); // turn LED on
	delay(duration);
	digitalWrite(pin, LOW); // turn LED off
	delay(duration);
}