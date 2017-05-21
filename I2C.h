/*
 * I2C.h
 *
 * Created: 2016/9/22 12:33:10
 *  Author: dusch
 */ 


#ifndef I2C_H_
#define I2C_H_

#define SLA_W 0xa0
#define SLA_R 0xa1
#include "avr/io.h"

void I2C_Init(void);
void I2C_Write(unsigned char Write_data, unsigned char EE_address);
unsigned char I2C_Read(unsigned char EE_address);


#endif /* I2C_H_ */