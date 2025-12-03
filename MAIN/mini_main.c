#include<lpc214x.h>
#include"types.h"
#include"mini_keypad.h"
#include"lcd.h"
#include"rtc.h"
#include"mini_alarm_rtc.h"
#include"mini_interrupt.h"
#include"mini_adc.h"
#include"mini_defines.h"
#include"pin_connect_block.h"
#include"delay.h"
#include"mini_alarm.h"

s32 hour,min,sec,date,month,year,day;
u32 adcDVal,temp,ChNo=1;
//u8 bell[]={0x04,0x0E,0x0E,0x0E,0x01F,0x00,0x0E,0x00};
f32 eAR;
volatile u8 ShowMenu = 0; //Global and volatile(modified in ISR)
//u32 alaram_hour = 0,alaram_min = 0,ent_flag = 0;
extern u32 key;
u32 i;																										 
//void Menu(void);

int main()
{
Init_ADC();
Init_LCD();
Init_KPM();
Init_Interrupt();
RTC_Init();
SetRTCTimeInfo(15,35,00);
IODIR0|=1<<0;
SetRTCDateInfo(29,10,2025);
SetRTCDay(1);
while(1)
{	 
if(ShowMenu == 0)
{
/*--- Line 1:time+Day ---*/
CmdLCD(GOTO_LINE1_POS0);
GetRTCTimeInfo(&hour,&min,&sec);
DisplayRTCTime(hour,min,sec);
GetRTCDay(&day);
CmdLCD(GOTO_LINE1_POS0+10);
DisplayRTCDay(day);

/* --- Line 2:Date + Temperature --- */
CmdLCD(GOTO_LINE2_POS0);
GetRTCDateInfo(&date,&month,&year);
DisplayRTCDate(date,month,year);
Read_ADC(ChNo,&adcDVal,&eAR);
temp=(u32)(eAR*100.0f);
CmdLCD(GOTO_LINE2_POS0+12);
U32LCD(temp);
CharLCD(0XDF); /* Degree Symbol */
CharLCD('C');
check_alarm();
/* Alaram check(when seconds == 0 to trigger once per mintute)*/
/*if(HOUR==alaram_hour && MIN==alaram_min)
		{
			if(Alarm_Ring==0)
			{  
			 BuildCGRAM(bell,8);
			 CmdLCD(GOTO_LINE1_POS0+15);
		      CharLCD(0);
			 IOSET0=1<<0;
			if((IOPIN0>>22&1)==0)//switch for stop the alarm
			{	
		    	IOCLR0=1<<0;
			   CmdLCD(GOTO_LINE1_POS0+15);
			   CharLCD(' ');
			   Alarm_Ring=1;
			}

			}											 
			   //CharLCD(' ');
	}
		else
	  	{	
				CmdLCD(GOTO_LINE1_POS0+15);
			   CharLCD(' ');
				Alarm_Ring=0;
		} */
    } 
    }
    }
/* ====MENU =====*/
void Menu(void)
{
while(1)
{
CmdLCD(CLEAR_LCD);
StrLCD("1.Edit RTC");
CmdLCD(GOTO_LINE2_POS0);
StrLCD("2.ALARM 3.EXIT");
key=(u8)KeyScan();
while(ColScan()==0);/* Wait Release */
CmdLCD(CLEAR_LCD);
CharLCD(key);
switch(key)
{
case '1':edit(&hour,&min,&sec,&day,&date,&month,&year);
		break;

case '2':Alarm();
		break;

case '3':CmdLCD(0X01);
		 return;
}
}
}
