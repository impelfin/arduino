#include <IRremote.h>
   
int IR_PIN = 11;

IRrecv irDetect( IR_PIN );
decode_results irIn ;                     

void setup ( ) {
  Serial.begin( 9600 );
  irDetect.enableIRIn ( ) ;
}

void loop ( ) {
  if ( irDetect.decode(&irIn ) ) {
    decodeIR ( );
    Serial.println(String(irIn.value, HEX));
    irDetect.resume ( );
  }
}

void decodeIR ( ) {
  switch(irIn.value) {
  case 0xFF629D: 
    Serial.println( " Up Arrow " );
    break;
  case 0xFF22DD: 
    Serial.println( " Left Arrow " );
    break;
  case 0xFF02FD: 
    Serial.println( "OK" );
    break;
  case 0xFFC23D: 
    Serial.println ( " Right Arrow " ) ;
    break;
  case 0xFFA857: 
    Serial.println ( " Down Arrow " ) ;
    break ;
  case 0xFF6897: 
    Serial.println ( " 1 " ) ;
    break;
  case 0xFF9867: 
    Serial.println ( " 2 " ) ;
    break;
  case 0xFFB04F : 
    Serial.println ( " 3 " ) ;
    break ;
  case 0xFF30CF : 
    Serial.println ( " 4 " ) ;
    break;
  case 0xFF18E7 : 
    Serial.println ( " 5" ) ;
    break;
  case 0xFF7A85 : 
    Serial.println ( " 6 " ) ;
    break;
  case 0xFF10EF : 
    Serial.println ( " 7" ) ;
    break;
  case 0xFF38C7: 
    Serial.println ( " 8" ) ;
    break;
  case 0xFF5AA5: 
    Serial.println ( "9 " ) ;
    break;
  case 0xFF42BD: 
    Serial.println ( "* " ) ;
    break;
  case 0xFF4AB5 :   
    Serial.println ( "0 " );
    break;
  case 0xFF52AD: 
    Serial.println ( " # " ) ;
    break;
  default:
    break;
  }
}
