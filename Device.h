/*
 * Device.h
 *
 * Created: 2016/12/18 10:50:09
 *  Author: dusch
 */ 


#ifndef DEVICE_H_
#define DEVICE_H_

#include "ADC.h"
#include "EEPROM.h"
#include "I2C.h"
#include "LCD.h"
#include "PWM.h"
#include "USART.h"
#include "MyLcd.h"

/************************************************************************/
/* bit control typedef                                                  */
/************************************************************************/
struct ass_8{
	unsigned zero:1;
	unsigned one:1;
	unsigned two:1;
	unsigned three:1;
	unsigned four:1;
	unsigned five:1;
	unsigned six:1;
	unsigned seven:1;
};

struct ass_16{
	unsigned zero:1;
	unsigned one:1;
	unsigned two:1;
	unsigned three:1;
	unsigned four:1;
	unsigned five:1;
	unsigned six:1;
	unsigned seven:1;
	unsigned eight:1;
	unsigned nine:1;
	unsigned ten:1;
	unsigned eleven:1;
	unsigned twelve:1;
	unsigned thirteen:1;
	unsigned fourteen:1;
	unsigned fifteen:1;
	
};

union ash_8{
	uint8_t all;
	struct ass_8 bit;
};

union ash_16{
	uint16_t all;
	struct ass_16 bit;
};

typedef union ash_8 bit_8;
typedef union ash_16 bit_16;

#define LSL(x, y) x=x<<y
#define LSR(x, y) x=x>>y

#define MAX(a, b) a>b?a:b
#define MIN(a, b) a<b?a:b

#define SEI asm("sei");
#define CLI asm("cli");

#endif /* DEVICE_H_ */