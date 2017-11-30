#include "BlinkLED.h"
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
#define Delay 100

void setup()
{
  for(int i = 0; i <= 7; i++)
    pinMode(ledPins[i], OUTPUT); // declare LED pins as output
}

void loop()
{
  for(int i = 0; i <= 7; i++)
    BlinkLED(ledPins[i], Delay);
  for(int i = 6; i >= 1; i--)
    BlinkLED(ledPins[i], Delay);
  for(int i = 0; i <= 7; i+=2)
    BlinkLED(ledPins[i], Delay);
  for(int i = 1; i <= 7; i+=2)
    BlinkLED(ledPins[i], Delay);
  for(int i = 5; i >= 0; i-=2)
    BlinkLED(ledPins[i], Delay);
  for(int i = 6; i >= 0; i-=2)
    BlinkLED(ledPins[i], Delay);
  for(int i = 7; i >= 0; i--)
    BlinkLED(ledPins[i], Delay);
  for(int i = 1; i <= 7; i++)
    BlinkLED(ledPins[i], Delay);
}
