#include <stdio.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

int PI_Pin_1 = 2;
int PI_Pin_2 = 3;
int PI_Pin_3 = 4;
int PI_Pin_4 = 5;
int w10 = 0;
int w50 = 0;
int w100 = 0;
int w500 = 0;
int val = digitalRead(2);

void setup()
{
  Serial.begin(9600);

  pinMode(PI_Pin_1, INPUT_PULLUP);
  pinMode(PI_Pin_2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(PI_Pin_1), count10, RISING);
  attachInterrupt(digitalPinToInterrupt(PI_Pin_2), count50, RISING);

  lcd.init();
  lcd.backlight();
}

void loop()
{
  Serial.println(w10);
  Serial.print(val);
  
  unsigned int total = 10*w10 + 50*w50 + 100*w100 + 500*w500;
  lcd.setCursor(1,0);
  lcd.print("Total : ");
  lcd.print(total);

}

void count10()
{
    w10++;
}

void count50()
{
  w50++;
}
 

