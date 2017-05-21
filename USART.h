/*
 * USART.h
 *
 * Created: 2016/9/10 16:30:30
 *  Author: dusch
 */ 


#ifndef USART_H_
#define USART_H_

#define BAUD 9600
#define F_CPU 12000000UL
#include <avr/interrupt.h>

void USART_Init( void );
void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void );



#endif /* USART_H_ */