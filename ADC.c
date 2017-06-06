/*
 * ADC.c
 *
 * Created: 2016/11/14 20:05:01
 *  Author: dusch
 */ 

#include "avr/io.h"
#include "ADC.h"

uint8_t ADC_Date(uint8_t i)
{
	ADMUX = 0x60 + i;			//Vref = AVCC, result of adc right shift
	ADCSRA = 0xC6;				//begin change time is 1/64
	while(!(ADCSRA & (1 << ADIF)));		//wite compleat
	ADCSRA |= (1 << ADIF);			//clear ADC INTRRUPT FLAG
	return ADCH;
}

uint16_t ADC_Average_Get(uint8_t pin)
{
	uint8_t temp = 0;
	for (uint8_t i = 0; i < 8; i++)
	{
		uint16_t j = ADC_Date(pin);
		j /= 8;
		temp += j;
	}
	return temp;
}
