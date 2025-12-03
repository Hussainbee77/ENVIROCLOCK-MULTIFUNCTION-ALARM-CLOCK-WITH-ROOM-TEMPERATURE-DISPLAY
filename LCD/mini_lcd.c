#include<lpc21xx.h>
#include"lcd_defines.h"
#include"types.h"
#include"delay.h"
#include"lcd.h"
#include"defines.h"

extern volatile u8 ShowMenu;
/* --- LCD --- */
void WriteLCD(u8 byte)
{
        //select write operation
        IOCLR0=1<<LCD_RW;
        //write byte to lcd data pins
        WRITEBYTE(IOPIN0,LCD_DATA,byte);
        //provide high to low pulse
        IOSET0=1<<LCD_EN;
        delayUS(1);
        IOCLR0=1<<LCD_EN;
        delayMS(2);
}

void CmdLCD(u8 cmdByte)
{
        //set rs pin for cmd/inst reg
  IOCLR0=1<<LCD_RS;
  //write cmd byte to cmd reg
  WriteLCD(cmdByte);
}

void Init_LCD(void)
{
        //cfg p0.8(d0) to p0.15(d7),
        //p0.16(rs),p0.17(rw),p0.18(en) 
        //as gpio output pins
        IODIR0|=((0xFF<<LCD_DATA)|
                 (1<<LCD_RS)|(1<<LCD_RW)|(1<<LCD_EN));

        //power on delay
        delayMS(15);
        CmdLCD(0x30);
        delayMS(4);
        delayUS(100);
        CmdLCD(0x30);
        delayUS(100);
        CmdLCD(0x30);
        CmdLCD(MODE_8BIT_2LINE);
        CmdLCD(DSP_ON_CUR_ON);
        CmdLCD(CLEAR_LCD);
        CmdLCD(SHIFT_CUR_RIGHT);
}
void CharLCD(u8 asciiVal)
{				 
        //sel data reg
        IOSET0=1<<LCD_RS;
        //write ascii value via data reg to ddram
        WriteLCD(asciiVal);
}

void StrLCD(s8 *str)
{
        while(*str)
                CharLCD(*str++);
}

void U32LCD(u32 n)
{
        s32 i=0;
        u8 a[10];
        if(n==0)
        {
                CharLCD('0');
        }
        else
        {
          while(n>0)
    {
                  a[i++]=(n%10)+48;
      n/=10;
    }
    for(--i;i>=0;i--)
      CharLCD(a[i]);
        }
}
void BuildCGRAM(u8 *p,u8 nBytes)
{
	u32 i;
	CmdLCD(GOTO_CGRAM_START);
	IOSET0=1<<LCD_RS;
	for(i=0;i<nBytes;i++)
	{
	WriteLCD(p[i]);
	}
	CmdLCD(GOTO_LINE1_POS0);
}
