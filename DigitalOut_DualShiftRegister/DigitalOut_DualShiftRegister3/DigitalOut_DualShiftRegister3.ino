/*
Basic Digital Output - Dual Shift Register #3
This example uses 3 Digital Output Pins to Control 16 Digital Output Signals from Dual Shift Registers
8 LED are on the outputs on each the Shift Registers.
This example will do a 16-Bit binary increment.
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
      value2 = n;                  //Outer Loop Byte 2
      for (int m=0; m < 256; m++)
      {
        value = m;                 //Inner Loop Byte 1
        delay(25);
        writeOutput();
      }
    }
}
void writeOutput()
{
    digitalWrite(latchPin, LOW);                       // Pull latch LOW to send data
    shiftOut(dataPin, clockPin, MSBFIRST, value);      // Send the data byte 1
    shiftOut(dataPin, clockPin, MSBFIRST, value2);     // Send the data byte 2
    digitalWrite(latchPin, HIGH);                      // Pull latch HIGH to stop sending data
}
