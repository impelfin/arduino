#include<Arducation.h>
 
 TemperatureSensor temperatureSensor(0);

void setup()
{              
  Serial.begin(9600);     
}

void loop() {
 temperatureSensor.temperatureSensorStart();
}
