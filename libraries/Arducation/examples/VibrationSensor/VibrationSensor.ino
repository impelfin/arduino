#include<Arducation.h>
 
 VibrationSensor vibrationSensor(9);

void setup()
{              
  Serial.begin(9600);     
}

void loop() {
 vibrationSensor.vibrationSensorStart();
}

