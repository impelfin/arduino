#include<Arducation.h>
 
Pressure pressure(0);

void setup()
{              
  Serial.begin(9600);     
}

void loop() {
 pressure.pressureStart();
}

