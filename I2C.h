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

#define I2C_START TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA)
#define I2C_LOAD(DATA) TWDR = DATA
#define I2C_TRANSMIT TWCR = (1<<TWINT) | (1<<TWEN)
#define I2C_WAIT while(!(TWCR & (1<<TWINT)))
#define I2C_RECEIVE(DATA) DATA = TWDR
#define I2C_STOP TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO)

void I2c_Init(void);
void AT24CXX_Write(uint8_t chip_address, uint8_t data_address, uint8_t data);
uint8_t AT24CXX_Read(uint8_t chip_address, uint8_t data_address);

#endif /* I2C_H_ */