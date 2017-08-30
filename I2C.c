/*
 * I2C.c
 *
 * Created: 2016/9/22 12:32:55
 *  Author: dusch
 */ 

#include "I2C.h"

 /******** TWI接口的初始化函数********/
void I2C_Init(void)
{
	TWAR = 0x00;		//MASTER MODE
	TWCR = 0x00;		//CLOSE TWI
	TWBR = 100;			//100
	TWSR = 0x03;		//64
}

void AT24CXX_Write(uint8_t chip_address, uint8_t data_address, uint8_t data)
{
	I2C_START;
	I2C_WAIT;
	I2C_LOAD(chip_address);
	I2C_TRANSMIT;
	I2C_WAIT;
	I2C_LOAD(data_address);
	I2C_TRANSMIT;
	I2C_WAIT;
	I2C_LOAD(data);
	I2C_TRANSMIT;
	I2C_WAIT;
	I2C_STOP;
}

uint8_t AT24CXX_Read(uint8_t chip_address, uint8_t data_address)
{
	uint8_t data;
	I2C_START;
	I2C_WAIT;
	I2C_LOAD(chip_address);
	I2C_TRANSMIT;
	I2C_WAIT;
	I2C_LOAD(data_address);
	I2C_TRANSMIT;
	I2C_WAIT;
	I2C_START;
	I2C_WAIT;
	I2C_LOAD(chip_address);
	I2C_TRANSMIT;
	I2C_WAIT;
	I2C_TRANSMIT;
	I2C_WAIT;
	I2C_RECEIVE(data);
	I2C_STOP;
	return data;
}