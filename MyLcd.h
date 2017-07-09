/*
 * MyLcd.h
 *
 * Created: 2017/1/19 18:42:28
 *  Author: dusch
 */ 


#ifndef MYLCD_H_
#define MYLCD_H_

#include "avr/io.h"
#include "MyLcd.h"
#define map_value_3 255										//The ADC sampling value from 0 ~ 255 mapping to 0 ~ map_value_3
#define map_value_4 1023									//The ADC sampling value from 0 ~ 1023 mapping to 0 ~ map_value_4

void my_display_3(uint8_t x, uint8_t y, uint32_t i);
void my_display_4(uint8_t x, uint8_t y, uint32_t i);

extern uint8_t display[3];

#endif /* MYLCD_H_ */
