/*
Basic Digital Output - Dual Shift Register #2
This example uses 3 Digital Output Pins to Control 16 Digital Output Signals from Dual Shift Registers
8 LED are on the outputs on each the Shift Registers.
This example will do a binary increment on Byte 1 and binary decrement on Byte 2
Author: David M. Auld
Date: 14th October 2009
*/
int dataPin = 2;              // The Serial Data Pin to the Shift Register
int latchPin = 3;             // The Latch Pin to the Shift Register
int clockPin = 4;             // The Clock Pin to the Shift Register
int value = 0;
int value2 = 0;
void setup()
{
  pinMode(dataPin, OUTPUT);    // Configure Digital Pins
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);  
}
void loop() 
{
    for (int n=0; n < 256; n++)
    {
      value = n;                  //increment
      value2 = 255-n;            //decrement
      writeOutput();
      delay(250);
    }
}
void writeOutput()
{
    digitalWrite(latchPin, LOW);                       // Pull latch LOW to send data
    shiftOut(dataPin, clockPin, MSBFIRST, value);      // Send the data byte 1
    shiftOut(dataPin, clockPin, MSBFIRST, value2);     // Send the data byte 2
    digitalWrite(latchPin, HIGH);                      // Pull latch HIGH to stop sending data
}
