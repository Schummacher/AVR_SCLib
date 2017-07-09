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



/******* data processing *******/

typedef union _ADC_DATE				//Defining a consortium is easier to break down the different parts of the data
{
	struct					//A 16bit data into two 8bit data
	{
		unsigned low : 8;					
		unsigned high : 8;
	} half;
	unsigned short all;			//Decomposed 16bit data
} ADC_DATE;

#endif /* ADC_H_ */
