/*
 * LCD.c
 *
 * Created: 2017/1/17 11:34:43
 *  Author: dusch
 */ 

#include "LCD.h"

/******FUN of comand******/
void LCD_Wcmd(uint8_t cmd)
{
	DDR=0xFF;
	RS_0;
	RW_0;
	EN_0;
	PORT=cmd;
	_delay_us(40);
	EN_1;
	_delay_us(40);
	EN_0;
}

/******FUN of data******/
void LCD_Wdat(uint8_t dat)
{
	DDR=0xFF;
	RS_1;
	RW_0;
	EN_0;
	PORT= dat;
	_delay_us(40);
	EN_1;
	_delay_us(40);
	EN_0;
}

/******FUN of clear scream******/
void LCD_Clr()
{
	LCD_Wcmd(0x01);
	_delay_ms(5);
}

/******FUN of INIT******/
void LCD_Init()
{
	_delay_ms(15);            //wait power stable
	LCD_Wcmd(0x38);          //16*2 display 5*7 lattice 8 bit data
	_delay_ms(10);
	LCD_Wcmd(0x38);
	_delay_ms(10);
	LCD_Wcmd(0x38);
	_delay_ms(10);
	LCD_Wcmd(0x0c);          //turn on display, turn of cursor
	_delay_ms(10);
	LCD_Wcmd(0x06);          //move cursor
	_delay_ms(10);
	LCD_Wcmd(0x01);          //clear mono of LCD
	_delay_ms(10);
}

/******FUN of locate******/
void LocateXY(uint8_t x,uint8_t y)
{
	if (y == 0)             //display 0th row
	{
		LCD_Wcmd(0x80 + x);
	}
	else                    //display 1st row
	{
		LCD_Wcmd(0xC0 + x);
	}
}

/******FUN of transmit string******/
void LCD_Write_Str(uint8_t x,uint8_t y,uint8_t *s)
{
	LocateXY(x,y);          //locate cursor
	while (*s)
	{
		LCD_Wdat( *s);
		s ++;
	}
}

/******FUN of tansmit char******/
void LCD_Write_Char(uint8_t x,uint8_t y,uint8_t data)
{
	LocateXY(x,y);          //locate cursor
	LCD_Wdat(data);
}
