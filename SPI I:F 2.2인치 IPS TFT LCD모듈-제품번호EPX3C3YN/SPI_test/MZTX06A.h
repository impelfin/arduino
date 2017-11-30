#ifndef _MZTX06A_H_
#define _MZTX06A_H_

#define DATA_H P0
#define DATA_L P2

#define STC_SPI

sbit LCD_CS		= P1^3;
sbit LCD_RS		= P1^2;
sbit LCD_WR		= P1^1;
sbit LCD_RD		= P1^0;
sbit LCD_RST	= P3^5;

sbit SPI_CS		= P3^2;
sbit SPI_RS		= P3^3;
sbit SPI_RST	= P3^6;
sbit SPI_SCI	= P4^1;
sbit SPI_SCL	= P4^3;
sbit PWM 		= P3^4;

sbit KEY1		= P1^4;
sbit KEY2		= P5^3;
sbit KEY3		= P1^5;
sbit KEY4		= P1^6;
sbit KEY5		= P1^7;
void LCD_Init();
void LCD_WR_REG(uint index);
void LCD_WR_CMD(uint index,uint val);

void LCD_WR_Data(uint val);

void LCD_QQ();
void LCD_test();
void LCD_clear(uint p);
void DisplayString(uchar *s,uchar x,uchar y);	//Ó¢ÎÄ×Ö·û´®ÏÔÊ¾.
void DisplayGB2312(uchar gb,uchar postion_x,uchar postion_y);
void delay_ms(uint t);

#endif

