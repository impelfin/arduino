#include<Arducation.h>
 
 Infrared infrared(7);

void setup()
{              
  Serial.begin(9600);     
}

void loop() {
 infrared.infraredStart();
}


