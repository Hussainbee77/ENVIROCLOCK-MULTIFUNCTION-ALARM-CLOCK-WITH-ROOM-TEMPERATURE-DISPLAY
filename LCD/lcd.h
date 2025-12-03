//lcd.h
#include"types.h"
void Init_LCD(void);
void WriteLCD(u8 byte);
void CmdLCD(u8 cmd);
void CharLCD(u8 asciiVal);
void StrLCD(s8 *);
void U32LCD(u32);
void S32LCD(s32);
void F32LCD(f32,u32);
void BuildCGRAM(u8 *,u8);
	   