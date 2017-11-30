#include "STC_NEW_8051.H"
#include "MZTX06A.h"


void MCU_Init()
 {
 	P0M1=0xff;
 	//P1M1=0x0f;
 	//P2M1=0xff;
 	P3M1=0x20;
 	P4M0=0x0A;
	P0=0xff;
    P1=0xff;
   	P2=0xff;
   	P3=0xff;
   	P4=0xff;
#ifdef STC_SPI
	AUXR1 |= 0x20;
	SPCTL = 0xDC;	//Ö÷»ú£¬ºöÂÔSS,CPU_CLK/4 
#endif
	PWM = 0;
}

void main(void)
{
	uint i;


  	MCU_Init();
	while(1)
	{
  		LCD_Init();
		LCD_test();
		
		LCD_QQ();
		
		LCD_clear(0xffff);
		
		for(i=2;i<8;i++)
		{
			DisplayGB2312(i-2,i*2,0);
		}
		DisplayString("2009",4,0);
		DisplayString(  "08",10,0);
		DisplayString(  "22",14,0);
		DisplayString(  "23",18,0);
		DisplayString(  "44",22,0);
		DisplayString(  "22",26,0);
		
		LCD_clear(0);
		
		DisplayString("MZTX06A testing!",0,0);
		
	}
}