/*
 * I2C.c
 *
 * Created: 2017/8/15 PM 5:24:28
 *  Author: schummacher
 */ 

#include "I2C.h"

void I2C_Init(void)
{
	TWCR = 0x00;
	TWBR = 100;
	TWSR = 0x03;
}

void I2C_Slave(uint8_t address)
{
	TWAR = (address << 1) | 0x01;
}

void I2C_Master(void)
{
	TWAR = 0x00;
}

void I2C_Wait(void)
{
	while (! (TWCR & (1 << TWINT)));
}