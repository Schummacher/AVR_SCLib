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
#include <stdint-gcc.h>

void my_display_3(uint8_t x, uint8_t y, uint32_t i);
void my_display_4(uint8_t x, uint8_t y, uint32_t i);
void my_display_6(uint8_t x, uint8_t y, uint8_t i);

extern uint8_t display[3];

#endif /* MYLCD_H_ */