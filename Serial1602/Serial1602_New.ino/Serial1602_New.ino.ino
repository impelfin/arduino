template<class T> inline Print &operator <<(Print &obj, T arg) { obj.print(arg); return obj; }

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3);
int tmp, hum;

void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
/*
  mySerial.print("$CLEAR\r\n");
  mySerial.print("$GO 1 1\r\n");
  mySerial.print("$PRINT Bigfoot \r\n");
 
  mySerial.print("$GO 2 4\r\n");
  mySerial.print("$PRINT Hello World!\r\n");
  delay(1000); 
*/
}
 
void loop()
{
  char inChar;
  tmp=12; hum=65;
  inChar = tmp;
  mySerial.print("$CLEAR\r\n");
  mySerial.print("$HOME \r\n");
  mySerial.print("$PRINT TEMP =  \r\n");
  mySerial.print("$PRINT");
  mySerial.print(inChar);
  mySerial.print("\r\n");
  delay(1000);
}
