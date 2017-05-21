/*
 * PWM.h
 *
 * Created: 2016/9/13 18:47:13
 *  Author: dusch
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "avr/io.h"

#define OPEN_OC2 TCCR2=(0<<FOC2)|(0<<WGM21)|(1<<WGM20)|(1<<COM21)|(0<<COM20)|(0<<CS22)|(0<<CS21)|(1<<CS20)
#define OPEN_OC1 \
	TCCR1A |= (1 << COM1A1) | (0 << COM1A0) | (1 << COM1B1) | (0 << COM1B0) | (1 << WGM10);\
	TCCR1B |= (1 << WGM12) | (1 << CS10)
#define CLOSE_OC2 TCCR2=0
#define CLOSE_OC1 TCCR1A=0;TCCR2=0

void Timer_Init(void);

#endif /* PWM_H_ */