#include<Arducation.h>
 
Piezo piezo(8,1910);

void setup()
{              
  Serial.begin(9600);     
}

void loop() {
 piezo.piezoStart();
}


