/*
 * ADC.h
 *
 * Created: 2016/11/14 20:05:41
 *  Author: dusch
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "avr/io.h"

uint8_t ADC_Date(uint8_t i);
uint16_t ADC_Average_Get(uint8_t pin);

typedef union _ADC_DATE
{
	struct
	{
		unsigned low : 8;
		unsigned high : 8;
	} half;
	unsigned short all;
} ADC_DATE;

#endif /* ADC_H_ */