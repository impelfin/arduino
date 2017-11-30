#include <Wire.h>

#define LED_PIN 7 
byte x = 0; 

// ====================================================== 

void setup() 
{ 
  Wire.begin(); // Start I2C Bus as Master 
  pinMode(LED_PIN, OUTPUT); 
  digitalWrite(LED_PIN, LOW); 

} 

// ====================================================== 

void loop() 
{ 
  Wire.beginTransmission(9); // transmit to device #9 
  Wire.write(x); // sends x 
  Wire.endTransmission(); // stop transmitting 
  x++; 
  if (x > 5) x=0; 
  delay(450); 
} 
// ==================== end of file ==================== 

