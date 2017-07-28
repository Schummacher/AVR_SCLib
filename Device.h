/*
 * Device.h
 *
 * Created: 2016/12/18 10:50:09
 *  Author: dusch
 */ 


#ifndef DEVICE_H_
#define DEVICE_H_

/******note off you want******/
#include "ADC.h"          //ADC reading
#include "EEPROM.h"       //internal reading and writeing
#include "I2C.h"          //I2C BUS contral
#include "USART.h"        //USART RS232 BUS contral
#include "LCD.h"          //Basic LCD contral
#include "MyLcd.h"        //LCD contral pro
#include "Sort.h"
#include "List.h"
#include "Filter.h"
#include "PID.h"

#define LSL(x, y) x=x<<y
#define LSR(x, y) x=x>>y

#define MAX(a, b) a>b?a:b
#define MIN(a, b) a<b?a:b

#define SEI asm("sei");
#define CLI asm("cli");

#endif /* DEVICE_H_ */
