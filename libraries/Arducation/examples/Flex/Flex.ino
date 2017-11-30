#include<Arducation.h>
 
 Flex flex(0);

void setup()
{              
  Serial.begin(9600);     
}

void loop() {
 flex.flexStart();
}



