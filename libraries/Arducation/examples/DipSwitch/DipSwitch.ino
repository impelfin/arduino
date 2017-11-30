#include<Arducation.h>
 
 DipSwitch dipSwitch(10);

void setup()
{              
  Serial.begin(9600);     
}

void loop() {
 dipSwitch.dipSwitchStart();
}

