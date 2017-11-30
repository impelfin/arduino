#include <SoftwareSerial.h>

int BTS_RX = 2;
int BTS_TX = 3;
SoftwareSerial BT(BTS_RX,BTS_TX);
char Order;

int Throtel=0;
bool f_Start;
int f_Order1, f_Order2;

const int Engin_L = 11; //좌 우 엔진 변수 선언
const int Engin_R = 10;

void Start_Engin()
{
  if(!f_Start) return;
  f_Start = false;
  
  BT.println("Stating Engen No 1");
  delay(500);
  analogWrite(Engin_L , 250);

  delay(2100);
  analogWrite(Engin_L, 100);

  delay(1100);
  BT.println("Engen No 1 start!!");
  BT.println("Stating Engen No 2");
  delay(100);

  analogWrite(Engin_R, 250);

  delay(2100);
  analogWrite(Engin_R, 100);

  delay(1100);
  
  BT.println("Engen No 2 start!!");  
  delay(100);
  BT.println("Ready for TakeOff!");
  
}

void Key_Scan()
{
  while(BT.available() == 0);
  Order = BT.read(); 
  /*
   * for 10sec take_off (t)
   * for 10sec landing  (a)
   * 
   *  Throtel up, doun, (u, d) 
   *  Turn Right, Left  (r, l)
   */
  if( Order == 't' || Order == 'a' )
  { f_Order1=1; }
  else if( Order == 'u' || Order == 'd' || Order == 'r' || Order == 'l'|| Order == 'c')
  { f_Order2=1; }
  else
  BT.println("Wrong Order");
  
}

void Key_Proc_()
{
  if((!f_Order1) && (!f_Order2)) return;
  f_Order1=f_Order2=0;
  

  if(Order == 't'){ BT.println("Take_Off");  analogWrite(Engin_R, 250); analogWrite(Engin_L, 250);  BT.println("MAX Power 5sec"); delay(5000); }
  else if(Order == 'a'){ BT.println("Landing"); analogWrite(Engin_R, 100); analogWrite(Engin_L, 100);  BT.println("MIN Power 5sec"); delay(5000);}
  else if(Order == 'u'){BT.println("Power_Up"); Throtel=Throtel+10; if(Throtel >= 240){Throtel=240; BT.println("Max Power");} analogWrite(Engin_R, Throtel); analogWrite(Engin_L, Throtel); BT.print(Throtel);}
  else if(Order == 'd'){BT.println("Power_Down"); Throtel=Throtel-10; if(Throtel<= 120){Throtel=120; BT.println("Min Power");} analogWrite(Engin_R, Throtel); analogWrite(Engin_L, Throtel); BT.print(Throtel);}
  else if(Order == 'r'){BT.println("Turn Right"); analogWrite(Engin_R, 150); analogWrite(Engin_L, 240);}
  else if(Order == 'l'){BT.println("Turn Left"); analogWrite(Engin_R, 240); analogWrite(Engin_L, 150); }
  else if(Order == 'c'){BT.println("Center"); analogWrite(Engin_R, Throtel); analogWrite(Engin_L, Throtel); BT.print(Throtel); }
//  Order='null';
  
}

void setup(){
  
  Serial.begin(9600);
  BT.begin(9600);
  
  Serial.println("Serial is Ready");
  BT.println("Bluetooth ready");

  Throtel=150;
  f_Start = true;
  f_Order1=1;
  f_Order2=1;
}

void loop(){
  Start_Engin();
  Key_Scan();
  Key_Proc_();

}
