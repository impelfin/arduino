#include<Arducation.h>
 
 Potentiometer potentiometer(0);

void setup()
{              
  Serial.begin(9600);     
}

void loop() {
 potentiometer.potentiometerStart();
}



