#include "WProgram.h"
void setup();
void loop();
int switchPin = 7;
int value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
}

void loop() {
  if (LOW == digitalRead(switchPin)){
    Serial.print("$CLEAR\r\n");
    Serial.print("$GO 1 4\r\n");
    Serial.print("$PRINT RobotBase \r\n");
    Serial.print("$GO 2 2\r\n");
    Serial.print("$PRINT Hello World!\r\n");
    Serial.print("$CURSOR 1 1\r\n");
  }
}


int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

