/*
 * MyLcd.c
 *
 * Created: 2017/1/19 16:45:50
 *  Author: dusch
 */ 

#include "Device.h"

/************************************************************************/
/* ShuiXianHua and Display                                              */
/************************************************************************/
void my_display(uint8_t x, uint8_t y, uint32_t i)
{
	uint8_t display[3];
	i = i * 255 / 255;
	display[0] = i / 100 + 48;
	display[1] = i % 100 / 10 + 48;
	display[2] = i % 10 + 48;
	LocateXY(x, y);
	LCD_Wdat(display[0]);
	LCD_Wdat(display[1]);
	LCD_Wdat(display[2]);
}

void Welcome(void)
{
	LocateXY(0,0);
	LCD_Wdat(0x58);
	LCD_Wdat(0xE0);
	LCD_Wdat(0x79);
	LCD_Wdat(0xE6);
	LCD_Wdat(0xE3);
	LCD_Wdat(0xDA);
	LCD_Wdat(0xE3);
}