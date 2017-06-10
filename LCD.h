/*
 * LCD.h
 *
 * Created: 2017/1/17 11:35:30
 *  Author: dusch
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "avr/io.h"
#define F_CPU 8000000UL
#include "util/delay.h"

#define PORT PORTB
#define DDR DDRB
#define PIN PINB
#define RS_0  PORTC &= ~(1 << PC7) 	//RS = 0
#define RS_1  PORTC |= (1 << PC7)	//RS = 1
#define RW_0  PORTD &= ~(1 << PC5)	//RW = 0
#define RW_1  PORTD |= (1 << PC5)	//RW = 1
#define EN_0  PORTC &= ~(1 << PC6)	//EN = 0
#define EN_1  PORTC |= (1 << PC6)	//EN = 1

void LCD_Wcmd(uint8_t cmd);
void LCD_Wdat(uint8_t dat) ;
void LCD_Clr(void)  ;
void LCD_Init(void) ;
void LocateXY(uint8_t x,uint8_t y) ;
void LCD_Write_Char(uint8_t x, uint8_t y, uint8_t data);
void LCD_Write_Str(uint8_t x, uint8_t y, char *s);

#endif /* LCD_H_ */