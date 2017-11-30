#include<Arducation.h>
 
UltrasonicWave ultrasonicWave(3,2);

void setup()
{              
  Serial.begin(9600);     
}

void loop() {
 ultrasonicWave.ultrasonicWaveStart();
}


