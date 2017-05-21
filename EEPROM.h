/*
 * EEPROM.h
 *
 * Created: 2016/9/18 19:35:16
 *  Author: dusch
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "avr/interrupt.h"

void EEPROM_write(unsigned int uiAddress, unsigned char ucData);
unsigned char EEPROM_read(unsigned int uiAddress);



#endif /* EEPROM_H_ */