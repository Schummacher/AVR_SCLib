/*
 * USART.c
 *
 * Created: 2016/9/10 16:29:07
 *  Author: dusch
 */ 

#include "USART.h"

void USART_Init( void )
{
	/* Set baud rate */
	UBRRL=(F_CPU/16/(BAUD+1))%256;
	UBRRH=(F_CPU/16/(BAUD+1))/256;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1 << UCSZ1)|(1 << UCSZ0);
}
void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while (!( UCSRA & (1<<UDRE)));
	/* Put data into buffer, sends the data */
	UDR = data;
}

unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while (!(UCSRA & (1<<RXC)));
	/* Get and return received data from buffer */
	return UDR;
}