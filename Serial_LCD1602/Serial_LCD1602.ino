#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3);

void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
 /*
  Serial.print("$CLEAR\r\n");
  Serial.print("$GO 1 1\r\n");
  Serial.print("$PRINT Bigfoot \r\n");
 
  Serial.print("$GO 2 4\r\n");
  Serial.print("$PRINT Hello Arduino!\r\n");
 
  delay(1000);
*/
}
 
void loop()
{
  int tmp=12;
  Serial.print("TEMP = "); 
  Serial.println(tmp);
  
  mySerial.print("$CLEAR\r\n");   
  mySerial.print("$GO 1 1\r\n"); 
  mySerial.print("$PRINT TEMP = \r\n");  
  mySerial.print(tmp);
  mySerial.print("\r\n");

  delay(1000);
}
