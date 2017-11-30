#include <intrins.h>
#include "STC_NEW_8051.H"
#include "MZTX06A.h"
#include "ascii hex(8x16).h"
#include "GB2312.h"
#include "qqp.h"

uint color[]={0xf800,0x07e0,0x001f,0xffe0,0x0000,0xffff,0x07ff,0xf81f};

//=============================================
void Delay(unsigned int t)
{
	unsigned int n,m;
	for(n=0;n<t;n++)
		for(m=0;m<600;m++);
}


void delay_ms(uint t)
{
	uchar i,j;
	while(--t)
	{
		j=8;
		while(--j)
			while(--i);
	}
}
void DLY()
{
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}

void LCD_WR_REG(uint index)
{
	uchar i;

	SPI_CS = 0;
	SPI_RS = 0;
#ifdef STC_SPI
	SPDAT = index>>8;
	while(!(SPSTAT&0x80));
	SPSTAT =0xC0;
	SPDAT = (uchar)index;
	while(!(SPSTAT&0x80));
	SPSTAT =0xC0;
#else
	for(i=0;i<16;i++)
	{
		SPI_SCL = 0;
		SPI_SCI = (bit)(index&0x8000);
		index=index<<1;
		SPI_SCL=1;
	}
#endif
	SPI_CS = 1;
}

void LCD_WR_CMD(uint index,uint val)
{
	uchar i;

	SPI_CS = 0;
	SPI_RS = 0;
#ifdef STC_SPI
	SPDAT = index>>8;
	while(!(SPSTAT&0x80));
	SPSTAT =0xC0;
	SPDAT = (uchar)index;
	while(!(SPSTAT&0x80));
	SPSTAT =0xC0;
#else
	for(i=0;i<16;i++)
	{
		SPI_SCL = 0;
		SPI_SCI = (bit)(index&0x8000);
		index=index<<1;
		SPI_SCL=1;
	}
#endif
	//SPI_CS = 1;
	SPI_RS = 1;	
	//SPI_CS = 0;
#ifdef STC_SPI
	SPDAT = val>>8;
	while(!(SPSTAT&0x80));
	SPSTAT =0xC0;
	SPDAT = (uchar)val;
	while(!(SPSTAT&0x80));
	SPSTAT =0xC0;
#else
	for(i=0;i<16;i++)
	{
		SPI_SCL = 0;
		SPI_SCI = (bit)(val&0x8000);
		val=val<<1;
		SPI_SCL=1;
	}
#endif
	SPI_CS = 1;
}

void LCD_WR_Data(uint val)
{
	uchar i;
#ifdef STC_SPI
	SPDAT = val>>8;
	while(!(SPSTAT&0x80));
	SPSTAT =0xC0;
	SPDAT = (uchar)val;
	while(!(SPSTAT&0x80));
	SPSTAT =0xC0;
#else
	//SPI_CS = 0;
	for(i=0;i<16;i++)
	{
		SPI_SCL = 0;
		SPI_SCI = (bit)(val&0x8000);
		val=val<<1;
		SPI_SCL=1;
	}
#endif
	//SPI_CS = 1;
}
uint SPI_RD_REG16(uint index)
{
	return index;
}

code uint gamma[][2]=
{
	0x2132,	0x5343 ,
	0x2141,	0x1021 ,
	0x0006,	0x0003 ,
	0x1411,	0x0011 ,
	0x100B,	0x050a ,
	0x2132,	0x4342 ,
	0x2242,	0x1100 ,
	0x0006,	0x0003 ,
	0x3421,	0x1201 ,
	0x0B07,	0x050a ,
};
void LCD_Init()
{
	SPI_RST=0;
	delay_ms(20);
	SPI_RST=1;
	delay_ms(20);

	LCD_WR_CMD( 0x000, 0x0001 ); /* oschilliation start */
	delay_ms( 10 );
	/* Power settings */  	
	LCD_WR_CMD( 0x100, 0x0000 ); /*power supply setup*/	
	LCD_WR_CMD( 0x101, 0x0000 ); 
	LCD_WR_CMD( 0x102, 0x3110 ); 
	LCD_WR_CMD( 0x103, 0xe200 ); 
	LCD_WR_CMD( 0x110, 0x009d ); 
	LCD_WR_CMD( 0x111, 0x0022 ); 
	LCD_WR_CMD( 0x100, 0x0120 ); 
	delay_ms( 20 );

	LCD_WR_CMD( 0x100, 0x3120 );
	delay_ms( 80 );
	/* Display control */   
	LCD_WR_CMD( 0x001, 0x0100 );
	LCD_WR_CMD( 0x002, 0x0000 );
	LCD_WR_CMD( 0x003, 0x1230 );
	LCD_WR_CMD( 0x006, 0x0000 );
	LCD_WR_CMD( 0x007, 0x0101 );
	LCD_WR_CMD( 0x008, 0x0808 );
	LCD_WR_CMD( 0x009, 0x0000 );
	LCD_WR_CMD( 0x00b, 0x0000 );
	LCD_WR_CMD( 0x00c, 0x0000 );
	LCD_WR_CMD( 0x00d, 0x0018 );
	/* LTPS control settings */   
	LCD_WR_CMD( 0x012, 0x0000 );
	LCD_WR_CMD( 0x013, 0x0000 );
	LCD_WR_CMD( 0x018, 0x0000 );
	LCD_WR_CMD( 0x019, 0x0000 );

	LCD_WR_CMD( 0x203, 0x0000 );
	LCD_WR_CMD( 0x204, 0x0000 );

	LCD_WR_CMD( 0x210, 0x0000 );
	LCD_WR_CMD( 0x211, 0x00ef );
	LCD_WR_CMD( 0x212, 0x0000 );
	LCD_WR_CMD( 0x213, 0x013f );
	LCD_WR_CMD( 0x214, 0x0000 );
	LCD_WR_CMD( 0x215, 0x0000 );
	LCD_WR_CMD( 0x216, 0x0000 );
	LCD_WR_CMD( 0x217, 0x0000 );
	#define YT	1
	// Gray scale settings
	LCD_WR_CMD( 0x300, 0x5343);
	LCD_WR_CMD( 0x301, 0x1021);
	LCD_WR_CMD( 0x302, 0x0003);
	LCD_WR_CMD( 0x303, 0x0011);
	LCD_WR_CMD( 0x304, 0x050a);
	LCD_WR_CMD( 0x305, 0x4342);
	LCD_WR_CMD( 0x306, 0x1100);
	LCD_WR_CMD( 0x307, 0x0003);
	LCD_WR_CMD( 0x308, 0x1201);
	LCD_WR_CMD( 0x309, 0x050a);

	/* RAM access settings */ 
	LCD_WR_CMD( 0x400, 0x4027 );
	LCD_WR_CMD( 0x401, 0x0000 );
	LCD_WR_CMD( 0x402, 0x0000 );	/* First screen drive position (1) */   	
	LCD_WR_CMD( 0x403, 0x013f );	/* First screen drive position (2) */   	
	LCD_WR_CMD( 0x404, 0x0000 );

	LCD_WR_CMD( 0x200, 0x0000 );
	LCD_WR_CMD( 0x201, 0x0000 );
	
	LCD_WR_CMD( 0x100, 0x7120 );
	LCD_WR_CMD( 0x007, 0x0103 );
	delay_ms( 10 );
	LCD_WR_CMD( 0x007, 0x0113 );
}

void LCD_test()
{
	uint temp,num,i;
	uchar n;
		
	LCD_WR_CMD(0x210,0x00);
	LCD_WR_CMD(0x212,0x0000);
	LCD_WR_CMD(0x211,0xEF);
	LCD_WR_CMD(0x213,0x013F);

	LCD_WR_CMD(0x200,0x0000);
	LCD_WR_CMD(0x201,0x0000);
		
	LCD_WR_REG(0x202);
	SPI_CS = 0;
	SPI_RS = 1;
	for(n=0;n<8;n++)
	{
	    temp=color[n];
		for(num=40*240;num>0;num--)
		{
			LCD_WR_Data(temp);
		}
	}
	for(n=0;n<3;n++)
	{
		LCD_WR_CMD(0x210,0x00);
		LCD_WR_CMD(0x212,0x0000);
		LCD_WR_CMD(0x211,0xEF);
		LCD_WR_CMD(0x213,0x013F);

		LCD_WR_CMD(0x200,0x0000);
		LCD_WR_CMD(0x201,0x0000);
		
		LCD_WR_REG(0x202);
		SPI_CS = 0;
		SPI_RS = 1;
	    temp=color[n];
		for(i=0;i<240;i++)
		{
			for(num=0;num<320;num++)
			{
		  		LCD_WR_Data(temp);
		  	}
		}
	}
	SPI_CS = 1;
}

void LCD_clear(uint p)
{
	uint i,j;
	LCD_WR_CMD(0x210,0x00);
	LCD_WR_CMD(0x212,0x0000);
	LCD_WR_CMD(0x211,0xEF);
	LCD_WR_CMD(0x213,0x013F);
		
	LCD_WR_CMD(0x200,0x0000);
	LCD_WR_CMD(0x201,0x0000);
	
	LCD_WR_REG(0x202);
	SPI_CS = 0;
	SPI_RS = 1;
	for(i=0;i<320;i++)
	{
		for(j=0;j<240;j++)
		{
		  LCD_WR_Data(p);
		}
	}
	SPI_CS = 1;
}
void LCD_QQ()
{
	uint num;
	uint *p; 
	uchar c,g;
	//显示小QQ图标
   	for(g=0;g<8;g++)
	{
		for(c=0;c<6;c++)
		{
			LCD_WR_CMD(0x210,c*40);
			LCD_WR_CMD(0x212,g*40);
			LCD_WR_CMD(0x211,c*40+39);
			LCD_WR_CMD(0x213,g*40+39);
	
			LCD_WR_CMD(0x200,c*40);
			LCD_WR_CMD(0x201,g*40);
	
			LCD_WR_REG(0x202);
			SPI_CS = 0;
			SPI_RS = 1;
			p = (uint*)gImage_qqp;
   			for(num=0;num<1600;num++)	//
			{		
				LCD_WR_Data(*p++);
			}
			//delay_ms(100);	 	
		}
  	}
	SPI_CS = 1;
}

//8X16点阵的字符显示函数
//参数说明：
//		  casc:字符对应字模中的位置
//         x:显示位置第几列,每行是240/8 ==30列
//         y:显示位置第几行,整屏是320/16==20行

void DisplayChar(uchar casc,uchar postion_x,uchar postion_y)
{
	uchar i,j,b;
	uchar *p;
	
	LCD_WR_CMD(0x210,postion_x*8); 	//x start point
	LCD_WR_CMD(0x212,postion_y*16); 	//y start point
	LCD_WR_CMD(0x211,postion_x*8+7);	//x end point
	LCD_WR_CMD(0x213,postion_y*16+15);	//y end point

	LCD_WR_CMD(0x200,postion_x*8);	
	LCD_WR_CMD(0x201,postion_y*16);
	
	LCD_WR_REG(0x202);
	SPI_CS = 0;
	SPI_RS = 1;
	p=ascii;
	p+=casc*16;
	for(j=0;j<16;j++)
	{
		b=*(p+j);
		for(i=0;i<8;i++)
		{
			if(b&0x80)
			{
				LCD_WR_Data(0xffff);
			}
			else
			{
				LCD_WR_Data(0x0000);
			}
			b=b<<1;
			
		}	
	}
	SPI_CS = 1;
}

void DisplayString(uchar *s,uchar x,uchar y)//英文字符串显示.
{
	while (*s) 
	{ 
		DisplayChar(*s,x,y);
		if(++x>=30)
		{
			x=0;
			if(++y>=20)
			{
				y=0;
			}
		}
		s++;
    }
}

//16X16点阵的汉字显示函数
//参数说明：
//		  gb:汉字对应字模中的位置
//         x:显示位置第几列
//         y:显示位置第几行
void DisplayGB2312(uchar gb,uchar postion_x,uchar postion_y)
{
	uchar i,j,b;
	uchar *p;
	
	LCD_WR_CMD(0x210,postion_x*16); 	//x start point
	LCD_WR_CMD(0x212,postion_y*16); 	//y start point
	LCD_WR_CMD(0x211,postion_x*16+15);	//x end point
	LCD_WR_CMD(0x213,postion_y*16+15);	//y end point

	LCD_WR_CMD(0x200,postion_x*16);	
	LCD_WR_CMD(0x201,postion_y*16);

	LCD_WR_REG(0x202);
	SPI_CS = 0;
	SPI_RS = 1;
	p=GB2312;
	p+=gb*32;
	for(j=0;j<32;j++)
	{
		b=*(p+j);
		for(i=0;i<8;i++)
		{
			if(b&0x80)
			{
				LCD_WR_Data(0xffff);
			}
			else
			{
				LCD_WR_Data(0x0000);
			}
			b=b<<1;
			
		}	
	}
	SPI_CS = 1;
}