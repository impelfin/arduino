#include<Arducation.h>
 
 TactSwitch tactSwitch(10);

void setup()
{              
  Serial.begin(9600);     
}

void loop() {
 tactSwitch.tactSwitchStart();
}


