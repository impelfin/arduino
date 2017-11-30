#include<Arducation.h>
 
ReedSensor reedSensor(3);

void setup()
{              
  Serial.begin(9600);     
}

void loop() {
 reedSensor.reedSensorStart();
}

