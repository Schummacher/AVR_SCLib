/*
 * MyLcd.c
 *
 * Created: 2017/1/19 16:45:50
 *  Author: dusch
 */ 

#include "LCD.h"

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

void my_display_6(uint8_t x, uint8_t y, uint8_t i)
{
	char base[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	LocateXY(x, y);
	LCD_Wdat('0');
	LCD_Wdat('x');
	LCD_Wdat(base[i / 16]);
	LCD_Wdat(base[i % 16]);
}