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
	uint8_t display[3];				//Create an array to hold each digit
	i = i * map_value_3 / 255;			//In order to improve the speed of the calculation of "i = i / 255 * map_value_3;" optimized to "i = i * map_value_3 / 255;"
	display[0] = i / 100 + 48;			//hundreds are stored in display[0]
	display[1] = i % 100 / 10 + 48;			//Ten are stored in display[1]
	display[2] = i % 10 + 48;			//Bit are stored in display[2]
	LocateXY(x, y);					//Determine the coordinates displayed on 1602
	LCD_Wdat(display[0]);				//1602 display
	LCD_Wdat(display[1]);
	LCD_Wdat(display[2]);
}

void my_display_4(uint8_t x, uint8_t y, uint32_t i)
{
	uint8_t display[4];				//Create an array to hold each digit
	i = i * map_value_4 / 1023;			//In order to improve the speed of the calculation of "i = i / 1023 * map_value_4;" optimized to "i = i * map_value_4 / 1023;"
	display[0] = i / 1000 + 48;			//Thousands of bits are stored in display[0]
	display[1] = i % 1000 / 100 + 48;		//Hundreds are stored in display[1]
	display[2] = i % 100 / 10 + 48;			//Ten are stored in display[2]
	display[3] = i % 10 + 48;			//Bit are stored in display[3]
	LocateXY(x, y);					//Determine the coordinates displayed on 1602
	LCD_Wdat(display[0]);				//1602 display
	LCD_Wdat(display[1]);
	LCD_Wdat(display[2]);
	LCD_Wdat(display[3]);
}
