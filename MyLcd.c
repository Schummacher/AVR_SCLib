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
void my_display_3(uint8_t x, uint8_t y, uint32_t i)
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

void my_display_4(uint8_t x, uint8_t y, uint32_t i)
{
	uint8_t display[4];
	i = i * 255 / 255;
	display[0] = i / 1000 + 48;
	display[1] = i % 1000 / 100 + 48;
	display[2] = i % 100 / 10 + 48;
	display[3] = i % 10 + 48;
	LocateXY(x, y);
	LCD_Wdat(display[0]);
	LCD_Wdat(display[1]);
	LCD_Wdat(display[2]);
	LCD_Wdat(display[3]);
}