#include<Arducation.h>
 
 DCMotor dcmotor(6);

void setup()
{              
  Serial.begin(9600);     
}

void loop() {
 dcmotor.dcmotorStart();
}

