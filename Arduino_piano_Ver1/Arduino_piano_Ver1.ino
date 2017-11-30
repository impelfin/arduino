////////////////////////////////////////////
// IR_Piano
// 2016_07_03
// Ver_1.0
// 작성자 : 이동훈
//
///////////////////////////////////////////
#include "pins_Arduino.h"
#include <MsTimer2.h>

#define Ir1 A0
#define Ir2 A1
#define Ir3 A2
#define Ir4 A3
#define Ir5 A4
#define Ir6 A5
#define Ir7 A6
#define Ir8 A7

#define Press1  1022
#define Press2  1022
#define Press3  1021
#define Press4  1019
#define Press5  1021
#define Press6  1022
#define Press7  1021
#define Press8  1019

const int Datapin = 11;
const int Latchpin = 12;
const int Clockpin = 13;

const int Normal = 9;
const int Save = 6;
const int Play = 5;

const int Buzzer = 3;
const int note[] = {2093,2349,2637,2793,3136,3520,3951,4186};

int f_Normal = 0;
int f_Save = 0;
int f_Play = 0;

int f_Ir1 = 0;
int f_Ir2 = 0;
int f_Ir3 = 0;
int f_Ir4 = 0;
int f_Ir5 = 0;
int f_Ir6 = 0;
int f_Ir7 = 0;
int f_Ir8 = 0;

int f_Ir = 0;

int Music[255] = {};
int Size = 0;

int i = 0;
int j = 0;
int k = 0;

int Chet_Normal = 0;
int Chet_Save = 0;
int Chet_Play = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(Ir1, INPUT); pinMode(Ir2, INPUT); pinMode(Ir3, INPUT); pinMode(Ir4, INPUT); 
  pinMode(Ir5, INPUT); pinMode(Ir6, INPUT); pinMode(Ir7, INPUT); pinMode(Ir8, INPUT);
  pinMode(Buzzer, OUTPUT);

  pinMode(Datapin, OUTPUT); pinMode(Latchpin, OUTPUT); pinMode(Clockpin, OUTPUT);

  //pinMode(Normal, INPUT); pinMode(Save, INPUT); pinMode(Play, INPUT);

  

  for(i = 0; i<255; i++)
  { Music[i] = 0; }

  Serial.begin(9600);

  MsTimer2::set(100, Check_Mod); // 300ms period
  MsTimer2::start();

  Do_74HC_P(0,0,0,0,0,0,0,0);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Normal_Mode();
  
  Save_Mode();
  
  Play_Mode();

  Test_Prog();
  delay(100);
}

void Check_Mod ()
{
  Chet_Normal = digitalRead(Normal);
  Chet_Play =  digitalRead(Play);
  Chet_Save =  digitalRead(Save);
  
  if( Chet_Normal != HIGH )
  { 
     Chet_Normal++;
     //if(Chet_Normal > 20)
     //{
          f_Normal = 1; f_Save = 0; f_Play = 0;
          Check_Change_Mod(); Chet_Normal=0;
     //}
     //else return;
  }
  else if ( Chet_Save != HIGH )
  { 
     Chet_Save++;
     //if(Chet_Save > 20)
     //{
          f_Normal = 0; f_Save = 1; f_Play = 0;
          Check_Change_Mod(); Chet_Save=0;
     //}
     //else return;
  }
  else if( Chet_Play != HIGH )
  { 
     Chet_Play++;
     //if(Chet_Play > 20)
     //{
          f_Normal = 0; f_Save = 0; f_Play = 1;
          Check_Change_Mod(); Chet_Play=0;
     //}
    // else return;
  }
  else return;
    
}

void Check_Change_Mod (void)
{
  tone(Buzzer,note[1],100); tone(Buzzer,note[4],100); tone(Buzzer,note[7],100);
}

void Do_74HC_P (int a, int b, int c, int d, int e, int f, int g, int h)
{
   digitalWrite (Latchpin , LOW);
 
  digitalWrite (Clockpin, LOW);
  digitalWrite (Datapin, a);  
  digitalWrite (Clockpin, HIGH);
 
  digitalWrite (Clockpin, LOW);
  digitalWrite (Datapin, b);  
  digitalWrite (Clockpin, HIGH);
 
  digitalWrite (Clockpin, LOW);
  digitalWrite (Datapin, c);  
  digitalWrite (Clockpin, HIGH);
 
  digitalWrite (Clockpin, LOW);
  digitalWrite (Datapin, d);  
  digitalWrite (Clockpin, HIGH);
 
  digitalWrite (Clockpin, LOW);
  digitalWrite (Datapin, e);  
  digitalWrite (Clockpin, HIGH);
 
  digitalWrite (Clockpin, LOW);
  digitalWrite (Datapin, f);  
  digitalWrite (Clockpin, HIGH);
 
  digitalWrite (Clockpin, LOW);
  digitalWrite (Datapin, g);  
  digitalWrite (Clockpin, HIGH);
 
  digitalWrite (Clockpin, LOW);
  digitalWrite (Datapin, h);  
  digitalWrite (Clockpin, HIGH);
 
  digitalWrite (Latchpin, HIGH);
  
}

void Do_Led_P (int a)
{
  if( a == 0 ) return; 
  else if( a == 1 ){ Do_74HC_P(1,0,0,0,0,0,0,0); }
  else if( a == 2 ){ Do_74HC_P(0,1,0,0,0,0,0,0); }
  else if( a == 3 ){ Do_74HC_P(0,0,1,0,0,0,0,0); }
  else if( a == 4 ){ Do_74HC_P(0,0,0,1,0,0,0,0); }
  else if( a == 5 ){ Do_74HC_P(0,0,0,0,1,0,0,0); }
  else if( a == 6 ){ Do_74HC_P(0,0,0,0,0,1,0,0); }
  else if( a == 7 ){ Do_74HC_P(0,0,0,0,0,0,1,0); }
  else if( a == 8 ){ Do_74HC_P(0,0,0,0,0,0,0,1); }
  else { Do_74HC_P(0,0,0,0,0,0,0,0); }
}

void Check_Ir ()
{
  if( analogRead(Ir1) < Press1)
  { /*noTone(Buzzer);*/ f_Ir = 1; tone(Buzzer,note[0]);  }
  else if( analogRead(Ir2) < Press2)
  { /*noTone(Buzzer);*/ f_Ir = 2; tone(Buzzer,note[1]);  }
  else if( analogRead(Ir3) < Press3)
  { /*noTone(Buzzer);*/ f_Ir = 3; tone(Buzzer,note[2]);  }
  else if( analogRead(Ir4) < Press4)
  { /*noTone(Buzzer);*/ f_Ir = 4; tone(Buzzer,note[3]);  }
  else if( analogRead(Ir5) < Press5)
  { /*noTone(Buzzer);*/ f_Ir = 5; tone(Buzzer,note[4]);  }
  else if( analogRead(Ir6) < Press6)
  { /*noTone(Buzzer);*/ f_Ir = 6; tone(Buzzer,note[5]);  }
  else if( analogRead(Ir7) < Press7)
  { /*noTone(Buzzer);*/ f_Ir = 7; tone(Buzzer,note[6]);  }
  else if( analogRead(Ir8) < Press8)
  { /*noTone(Buzzer);*/ f_Ir = 8; tone(Buzzer,note[7]);  }
  else 
  { noTone(Buzzer);  }
}

void Normal_Mode ()
{
  
  if(!f_Normal) return;
  Serial.print(" Normal Mode Start " );
  Check_Ir();
  Do_Led_P(f_Ir);
  Test_Prog();
  delay(100);
}

void Check_Ir_S ()
{
  if( analogRead(Ir1) < Press1)
  { Music[Size] = 0; Size++; f_Ir = 1; }
  else if( analogRead(Ir2) < Press2)
  { Music[Size] = 1; Size++; f_Ir = 2; }
  else if( analogRead(Ir3) < Press3)
  { Music[Size] = 2; Size++; f_Ir = 3; }
  else if( analogRead(Ir4) < Press4)
  { Music[Size] = 3; Size++; f_Ir = 4; }
  else if( analogRead(Ir5) < Press5)
  { Music[Size] = 4; Size++; f_Ir = 5; }
  else if( analogRead(Ir6) < Press6)
  { Music[Size] = 5; Size++; f_Ir = 6; }
  else if( analogRead(Ir7) < Press7)
  { Music[Size] = 6; Size++; f_Ir = 7; }
  else if( analogRead(Ir8) < Press8)
  { Music[Size] = 7; Size++; f_Ir = 8; }
  else 
  { return;  }
}

void Full_Save ()
{
  if(Size >= 255)
  {
    f_Save = 0; tone(Buzzer,note[4], 500);
  }
}
void Save_Mode ()
{
  if(!f_Save) return;

  Serial.print(" Save Mode Start " );
  
  Check_Ir_S();
  Do_Led_P(f_Ir);

  Full_Save();
}


void Play_Mode ()
{
  if(!f_Play) return;

  Serial.print(" Play Mode Start " );

  for(j=0; j >= Size; j++)
  {
    tone(Buzzer,note[Music[j]]);
    Do_Led_P(Music[j] + 1);
    delay(500);  
  }
  Size = 0;
  Do_74HC_P(0,0,0,0,0,0,0,0);
}


void Test_Prog (void)
{

  if( ( f_Normal == 1 ) || ( f_Save == 1 ) || (f_Play == 1 ) ) return;
  Serial.print("Input IR Data : ");
  Serial.print(analogRead(Ir1)); Serial.print("  "); Serial.print(analogRead(Ir2));Serial.print("  "); Serial.print(analogRead(Ir3)); Serial.print("  "); Serial.print(analogRead(Ir4)); Serial.print("  ");
  Serial.print(analogRead(Ir5)); Serial.print("  "); Serial.print(analogRead(Ir6));Serial.print("  "); Serial.print(analogRead(Ir7)) ;Serial.print("  "); Serial.print(analogRead(Ir8)); Serial.print("  ");

  Serial.print("\n");
  //Serial.print( "\n f_Ir Vel : " );
  //Serial.print(f_Ir);
  //Serial.print( "\n");
  //Serial.print( f_Normal ); Serial.print("  "); Serial.print( f_Save ); Serial.print("  "); Serial.print( f_Play );
  //Serial.print("\n");

  //Serial.print(Chet_Normal); Serial.print(" ");Serial.print(Chet_Save); Serial.print(" ");Serial.print(Chet_Play); Serial.print(" ");
  //Serial.print("\n");

  //Serial.print(digitalRead(Normal));  Serial.print(" ");  Serial.print(digitalRead(Save));  Serial.print(" ");  Serial.print(digitalRead(Play));  Serial.print(" ");
  //Serial.print("\n");
}




























  


