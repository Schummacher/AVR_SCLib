
/*
 * asm_adc.s
 *
 * Created: 2017/9/1 下午 8:14:42
 *  Author: schummacher
 */ 

 #include <avr/io.h>
 .global asm_ADC_Date

 asm_ADC_Date:

	subi r24, 0xA0
	sts ADMUX, r24
	ldi r24, 0xC6

adc_wait_loop:
	sts ADCSRA, r24
	lds r24, ADCSRA
	sbrs r24, 4
	rjmp adc_wait_loop

	lds r24, ADCSRA
	ori r24, 0x10
	sts ADCSRA, r24

	lds r24, ADCH

	ret
