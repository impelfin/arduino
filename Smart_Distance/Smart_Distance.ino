//HeaderFile
#include <NewPing.h>
#include <MsTimer2.h>
#include <SoftwareSerial.h>
//Define File
#define Buzzer 9
#define HLED 10
#define ECHO_PIN 11
#define TRIGGER_PIN 12
#define MAX_DISTANCE 200
//Vers File
int Dis = 0;
int f_HLED = 0;
int f_Buzzer = 0;
int f_HLED_State = 1;
int f_Buzzer_State = 1;
int SetDis = 20;
int f_BT_Order = 0;
int DTime = 200;
char Data = 0x00;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
SoftwareSerial BT(2,3);

void setup() 
{
  Serial.begin(9600); // Open serial monitor at 9600 baud to see ping results.
  BT.begin(9600);
  pinMode(HLED, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  MsTimer2::set(50, BT_Check);// 10ms period
  MsTimer2::start();
}

void loop() 
{
  Check_Sonar();
  delay(DTime);
  Alert();
}

void BT_Check (void)
{
  //if(BT.available())
  //{
    Data = BT.read();
    Serial.println(Data);
  //}
  
  if(Data == 'x') // 모든 알람 없음
  {
    f_BT_Order = 1;
    Data = 0x00;
  }
  else if( Data == 'o')
  {
    f_BT_Order = 0;
    Data = 0x00;
  }
  
  if(Data == '1') // 100ms 주기 점멸
  {  DTime = 100; Data = 0x00; }// 100ms period
  else if( Data == '2') // 200ms 주기 점멸
  {  DTime = 200; Data = 0x00; }// 200ms period
  else if( Data == '3') // 300ms 주기 점멸
  {  DTime = 400; Data = 0x00; }// 400ms period
  else if( Data == '4') // 경고 거리 10cm
  { SetDis = 10; Data = 0x00; }
  else if( Data == '5') // 경고 거리 20cm
  { SetDis = 20; Data = 0x00; }
  else if( Data == '6') // 경고 거리 30cm
  { SetDis = 30; Data = 0x00; }
  
}

void Check_Sonar (void)
{
  //delay(100);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  BT.println(sonar.ping_cm());
  Dis = sonar.ping_cm();
  /*
  for(int i = 0; i<3; i++)
  {
    Dis = Dis + sonar.ping_cm();
  }
  Dis = Dis / 3;
  */
  if( (SetDis < Dis) || (Dis == 0) )
  { f_Buzzer = 0; f_HLED = 0; }
  else
  { f_Buzzer = 1; f_HLED = 1; }
}

void Alert (void)
{
  if((f_HLED == 1) && (f_BT_Order == 0))
  { 
    if(f_HLED_State == 1) {    digitalWrite(HLED, LOW); f_HLED_State = 0;  }
    else { digitalWrite(HLED, HIGH); f_HLED_State = 1;  }
  }
  else
  { digitalWrite(HLED, LOW);  }

  if((f_Buzzer == 1) && (f_BT_Order == 0))
  {
    if(f_Buzzer_State == 1) { digitalWrite(Buzzer, HIGH); f_Buzzer_State = 0;  }
    else { digitalWrite(Buzzer, LOW); f_Buzzer_State = 1;  }
  }
  else
  { digitalWrite(Buzzer, LOW);  }
  
}


