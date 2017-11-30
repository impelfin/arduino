#define OFF 0
#define ON 1


#define Bit_out 12
#define CLK 11
#define CLR 10
#define LEDON 9

byte i, j , temp, val;

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(Bit_out, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(CLR, OUTPUT);
  pinMode(LEDON, OUTPUT);

  pinMode(13, OUTPUT);  // used to test-debug various sections of code

  digitalWrite(LEDON, OFF);  //HIGH tuns on LEDs
  digitalWrite(CLK, OFF); 
  digitalWrite(CLR, HIGH); // active LOW
}

void loop() {

  for (i=0; i<=256; i++)  {
    digitalWrite(13, ON);
    val = i;
    for (j=1; j<=8; j++)  {
      // to right change B00000001 to B10000000
      temp = val & B00000001; // to count in binary from left 
      // to invert the output bit pattern change temp to !temp
      digitalWrite(Bit_out, temp); 
      pulsout(CLK, 10); 
      // to count in binary from left to right change the above to val = val << 1;
      val = val >> 1; // shift one place right same as divide by 2
    
    }  // next j

    digitalWrite(13,OFF);
    digitalWrite(LEDON, ON);
    delay(400);
    digitalWrite(LEDON, OFF);
  } // next i

} 

// inverts state of pin, delays, then reverts state back
void    pulsout(byte x, int y)   {
  byte z = digitalRead(x);
  z = !z;
  digitalWrite(x, z);
  delayMicroseconds(y);
  z = !z; // return to original state
  digitalWrite(x, z);
  return;
} // end pulsout()
