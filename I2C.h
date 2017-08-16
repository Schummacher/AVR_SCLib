/*
 * I2C.h
 *
 * Created: 2017/8/15 下午 5:24:38
 *  Author: schummacher
 */ 


#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>
#include <util/twi.h>
#include <stdint.h>

void I2C_Init(void);
void I2C_Slave(uint8_t address);
void I2C_Master(void);
void I2C_Start(void);
void I2C_Wait(void);
void I2C_Write(uint8_t address_data);
void I2C_Stop(void);

#define I2C_START \
do \
{\
	TWCR = (1 << TWINT)|(1 << TWSTA)|(1 << TWEN);\
} while (0)

#define  I2C_STOP \
do \
{\
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);\
} while (0)

#define I2C_WRITE(ADDRESS_DATA) \
do \
{\
	TWDR = ADDRESS_DATA;\
	TWCR = (1<<TWINT)|(1<<TWEN);\
	while (! (TWCR & (1 << TWINT)));\
} while (0)

#endif /* I2C_H_ */