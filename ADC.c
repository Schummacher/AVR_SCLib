/*
 * ADC.c
 *
 * Created: 2016/11/14 20:05:01
 *  Author: dusch
 */ 

#include "avr/io.h"
#include "ADC.h"

unsigned int ADC_Date(unsigned char i)
{
	ADMUX = 0x60 + i;					//Vref = AVCC, result of adc right shift
	ADCSRA = 0xC6;						//begin change time is 1/64
	while(!(ADCSRA & (1 << ADIF)));		//wite compleat
	ADCSRA |= (1 << ADIF);				//clear ADC INTRRUPT FLAG
	return ADCH;
}