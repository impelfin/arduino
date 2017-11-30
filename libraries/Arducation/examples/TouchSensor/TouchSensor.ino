#include<Arducation.h>
 
 TouchSensor touchSensor(9);

void setup()
{              
  Serial.begin(9600);     
}

void loop() {
 touchSensor.touchSensorStart();
}
