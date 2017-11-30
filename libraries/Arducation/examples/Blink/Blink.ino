#include<Arducation.h>
 
Blink blink(13);

void setup()
{              
  Serial.begin(9600);     
}

void loop() {
 blink.blinkStart();
}

