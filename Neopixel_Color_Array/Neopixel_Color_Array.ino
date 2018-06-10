#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(64, PIN, NEO_GRB + NEO_KHZ800);

//colors to make things easier

uint32_t C0 = strip.Color(0, 0, 0); //black
uint32_t C1 = strip.Color(255, 255, 255); //white
uint32_t C2 = strip.Color(255, 0, 0); //red
uint32_t C3 = strip.Color(255, 135, 0); //orange
uint32_t C4 = strip.Color(255, 255, 0); //yellow
uint32_t C5 = strip.Color(0, 255, 0);//green
uint32_t C6 = strip.Color(0, 0, 255); //blue
uint32_t C7 = strip.Color(0, 255, 255); //cyan
uint32_t C8 = strip.Color(128, 0, 128); //purple
uint32_t C9 = strip.Color(139, 99, 108); //pink

int MyColors [9] = {C1, C2, C3, C4, C5, C6, C7, C8, C9}; //put the colors in an array

int d = 1;

int b = 1;

int j = 0; 

void setup() {
strip.begin();
strip.setBrightness(30); // no searing the eyes plox
}

void loop() {
   uint8_t  i;
   uint32_t t;
   
   for(j=0; j<10; j++) { // randomly flash colors around. Shortened cause I thought the next bit was mucked up. 
      i = random(8);
      d = MyColors[i];
      strip.setPixelColor(i, d);
      strip.show();
      delay(100);
      strip.setPixelColor(i, 0);
   }

   for(j=0; j<100; j++) { //step through the colors and pixels 
      for(i=0; i<9; i++) {
         b = MyColors[i];
         strip.setPixelColor(i, b);
         strip.show();
         delay(10);
         strip.setPixelColor(i,C0);
         strip.show();
      }
   }
}
