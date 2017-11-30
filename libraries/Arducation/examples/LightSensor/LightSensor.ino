#include<Arducation.h>
 
 LightSensor lightSensor(0);

void setup()
{              
  Serial.begin(9600);     
}

void loop() {
 lightSensor.lightSensorStart();
}



