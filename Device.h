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

#define LSL(x, y) x=x<<y
#define LSR(x, y) x=x>>y

#define MAX(a, b) a>b?a:b
#define MIN(a, b) a<b?a:b

#define SEI asm("sei");
#define CLI asm("cli");

#endif /* DEVICE_H_ */
