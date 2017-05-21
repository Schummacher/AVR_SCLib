/*
 * PWM.c
 *
 * Created: 2016/9/13 18:46:48
 *  Author: dusch
 */ 

#include "PWM.h"

void Timer_Init(void){
// 	TCCR0 = (0<<FOC0)|(1<<WGM01)|(1<<WGM00)|(1<<COM01)|(0<<COM00)|(0<<CS02)|(0<<CS01)|(1<<CS00);
// 	OCR0 = 0;

	TCCR2 = (0<<FOC2)|(0<<WGM21)|(1<<WGM20)|(1<<COM21)|(0<<COM20)|(0<<CS22)|(0<<CS21)|(1<<CS20);
	OCR2 = 0;
	
	TCCR1A |= (1 << COM1A1) | (0 << COM1A0) | (1 << COM1B1) | (0 << COM1B0) | (1 << WGM10);
	TCCR1B |= (1 << WGM12) | (1 << CS10);
	OCR1A = 0;
	OCR1B = 0;
}