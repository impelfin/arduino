#include <Adafruit_NeoPixel.h>

#define PIN            6
#define NUMPIXELS      56
#define COUNT 8
#define COL 7
#define ROW 6

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

uint32_t C0 = 0x000000; //Black
uint32_t C1 = 0xFFFFFF; //White
uint32_t C2 = 0xFF0000; //Red
uint32_t C3 = 0x00FF00; //Green
uint32_t C4 = 0x0000FF; //Blue
uint32_t C5 = 0xFFFF00; //Yellow
uint32_t C6 = 0x00FFFF; //Cyan
uint32_t C7 = 0xFF00FF; //Magenta
uint32_t C8 = 0x800000; //Maroon
uint32_t C9 = 0x808000; //Olive
uint32_t C10 = 0x800080; //Purple
uint32_t C11 = 0x008080; //Teal

uint32_t MyColors[12] = {C0, C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11}; //put the colors in an array

uint8_t data[COL][ROW];
uint8_t counton = 0;
boolean flag=0;
int led;
unsigned char e[8];

uint32_t color = MyColors[0]; 

void display_PixelColor(int led, uint32_t color) {
      pixels.setPixelColor(led, color);
      pixels.show(); 
      delay(100); 
}

int data_create() {   
  int i = random(COL); 
  if(flag == 0) flag = 1; else flag = 0;
  int j = empty_check(i);
  if(j != 0x1F && data[i][j] == 8) {
    data[i][j] = flag;
    led = led_count(i,j);
    Serial.print("col = " );
    Serial.println(i);
    Serial.print("row = " );
    Serial.println(j);
    Serial.print("led = " );
    Serial.println(led);
    Serial.println("++++++++++++++++"); 
    j = e[i]++;
    return led;
  } else {
    data_create();
  }  
}

int empty_check(int i) {
  return e[i];
}

int led_count(int i, int j) {
  return i * 8 + j;
}

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels.setBrightness(20);
  for(int i=0; i<COL; i++) {
      for(int j=0;j<ROW;j++) {
            data[i][j] = 8;  
      }
      e[i] = 0x00;
  }
  Serial.println("###################");
  Serial.println(" Program Start~!!");
  Serial.println("###################");
}

void loop() {  
  led = data_create();
  counton++;
  if(flag == 0) color = MyColors[7]; else color = MyColors[6];
  display_PixelColor(led, color);
  Serial.print("Led = " );
  Serial.println(led);
  Serial.print("Count on = " );
  Serial.println(counton);
  Serial.print("Flag = " );
  Serial.println(flag);
  Serial.println("----------------");
  delay(50);
  if(counton == 42) {
    counton = 0;
    for(int i=0; i<COL; i++) {
      for(int j=0;j<ROW;j++) {
            data[i][j] = 8;  
      }
      e[i] = 0x00;
    }
    delay(2000);
    pixels.clear();
  }
}


