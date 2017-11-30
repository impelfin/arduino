#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#define PIN            5 //네오픽셀DIN
#define PINR           10 //릴레이 전원
#define PINRL          6 //릴레이 동작 전원
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);
SoftwareSerial bluetooth(3,2);

char a = 0;
int br = 150;

int ca = 0;
int cb = 0;
int cc = 0;

void setup() {
  strip.begin();//네오픽셀 사용설정
  strip.setPixelColor(0, strip.Color(0,0,0));//네오픽셀 초기설정
  strip.show();//네오픽셀 설정 적용
  bluetooth.begin(9600);//블루투스 사용설정(software serial)
  Serial.begin(9600);
 
  pinMode(PINR, OUTPUT);
  pinMode(PINRL, OUTPUT);
  
}

void loop() {
  /*
  if(bluetooth.available()>2){//수신받은 블루투스 데이터가 2개 초과일때
    r = bluetooth.read();//첫번째 데이터를 r에 저장
    g = bluetooth.read();//두번째 데이터를 g에 저장
    b = bluetooth.read();//세번째 데이터를 b에 저장
    bluetooth.flush();//통신내용 초기화
    strip.setPixelColor(0, strip.Color(r,g,b));//수신받은 데이터를 토대로 색상 설정
    for(int i=0;i<8;i++)strip.setPixelColor(i,strip.Color(r,g,b));
    strip.show();//네오픽셀에 적용용

  }

  */
  if(bluetooth.available())
  {
    a = bluetooth.read();
    Serial.println(a);
  }
  if( a == '1') { digitalWrite(PINR, HIGH); digitalWrite(PINRL, HIGH); }
  else if( a == '0' ) { digitalWrite(PINR, LOW); digitalWrite(PINRL, LOW); }
  else if( a == '2') 
  {   
    strip.setPixelColor(0, strip.Color(255,255,255));//수신받은 데이터를 토대로 색상 설정
    for(int i=0;i<8;i++)strip.setPixelColor(i,strip.Color(255,255,255));
    strip.show();
    ca = 255; cb = 255; cc = 255;
  }//네오픽셀에 적용용} //white
  else if( a == '3') 
  {   
    strip.setPixelColor(0, strip.Color(255,94,0));//수신받은 데이터를 토대로 색상 설정
    for(int i=0;i<8;i++)strip.setPixelColor(i,strip.Color(255,94,0));
    strip.show();
    ca = 255; cb = 94; cc = 0;
  }//네오픽셀에 적용용} //yellow
  else if( a == '4') 
  {   
    strip.setPixelColor(0, strip.Color(0,0,255));//수신받은 데이터를 토대로 색상 설정
    for(int i=0;i<8;i++)strip.setPixelColor(i,strip.Color(0,0,255));
    strip.show();
    ca = 0; cb = 0; cc = 255;
  }//네오픽셀에 적용용} //blue
  else if( a == '5') 
  {   
    strip.setPixelColor(0, strip.Color(0,0,0));//수신받은 데이터를 토대로 색상 설정
    for(int i=0;i<8;i++)strip.setPixelColor(i,strip.Color(0,0,0));
    strip.show();
    ca = 0; cb = 0; cc = 0;
  }//네오픽셀에 적용용} //off
  else if( a == '6')
  {
     br = br + 50;
     if( br >= 255){ br = 250;}
     strip.setBrightness(br);
     strip.setPixelColor(0, strip.Color(ca,cb,cc));//수신받은 데이터를 토대로 색상 설정
     for(int i=0;i<8;i++)strip.setPixelColor(i,strip.Color(ca,cb,cc));
     strip.show();
  } // 밝기 증가
  else if( a == '7')
  {
    br = br - 50;
    if( br <= 10) { br = 10; }
    strip.setBrightness(br);
    strip.setPixelColor(0, strip.Color(ca,cb,cc));//수신받은 데이터를 토대로 색상 설정
    for(int i=0;i<8;i++)strip.setPixelColor(i,strip.Color(ca,cb,cc));
    strip.show();
  } // 밝기 감소

  //Serial.println(bluetooth.read());
 // delay(100);
}
