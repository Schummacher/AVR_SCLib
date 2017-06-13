/*
 * Stack.h
 *
 * Created: 2017/6/13 20:05:01
 *  Author: dusch
 */ 


#ifndef STACK_H_
#define STACK_H_

#define CREAT_POOL(NAME, LONG) uint8_t NAME [LONG + 1] = {1}

void POP(uint8_t *num, uint8_t data);
uint8_t PUSH(uint8_t *num);

#endif /* ADC_H_ */