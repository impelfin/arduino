/*
Example sketch for interfacing with the DS1302 timekeeping chip.

Copyright (c) 2009, Matt Sparks
All rights reserved.

http://quadpoint.org/projects/arduino-ds1302
*/
#include <stdio.h>
#include <string.h>
#include <DS1302.h>
#include <LiquidCrystal.h>

/* Set the appropriate digital I/O pin connections */
uint8_t CE_PIN   = 11; //Pin RST
uint8_t IO_PIN   = 12;//Pin DAT
uint8_t SCLK_PIN = 13; //Pin CLK

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

/* Create a DS1302 object */
DS1302 rtc(CE_PIN, IO_PIN, SCLK_PIN);

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

/* Create buffers */
char buf[50];
char day[50];
char cul1[20]={0};
char cul2[20]={0};


void print_time()
{
  /* Get the current time and date from the chip */
  Time t = rtc.time();

  /* Name the day of the week */
  memset(day, 0, sizeof(day));  /* clear day buffer */
  switch (t.day) {
    case 1:
      strcpy(day, "Sun");
      break;
    case 2:
      strcpy(day, "Mon");
      break;
    case 3:
      strcpy(day, "Tue");
      break;
    case 4:
      strcpy(day, "Wed");
      break;
    case 5:
      strcpy(day, "Thu");
      break;
    case 6:
      strcpy(day, "Fri");
      break;
    case 7:
      strcpy(day, "Sat");
      break;
  }

  /* Format the time and date and insert into the temporary buffer */
  snprintf(buf, sizeof(buf), "%s %04d/%02d/%02d %02d:%02d:%02d",
           day,
           t.yr, t.mon, t.date,
           t.hr, t.min, t.sec);
  
  sprintf(cul1, "%04d/%02d/%02d", t.yr, t.mon, t.date);
  sprintf(cul2, "%02d:%02d:%02d %s", t.hr, t.min, t.sec, day);
 
  
  /* Print the formatted string to serial so we can see the time */
 Serial.println(buf);
 lcd.setCursor(0,0);
 lcd.print(cul1);

 
 lcd.setCursor(0,1);
 lcd.print(cul2);

}

void setup()
{
  Serial.begin(9600);
 lcd.begin(16, 2);              // start the library
  /* Initialize a new chip by turning off write protection and clearing the
     clock halt flag. These methods needn't always be called. See the DS1302
     datasheet for details. */
  //rtc.write_protect(false);
  //rtc.halt(false);

  /* Make a new time object to set the date and time */
  /*   Tuesday, May 19, 2009 at 21:16:37.            */
  //Time t(2014, 3, 4, 17, 3, 40, 3);

  /* Set the time and date on the chip */
  //rtc.time(t);
  
}

/* Loop and print the time every second */
void loop()
{
  print_time();
  delay(1000);
}
