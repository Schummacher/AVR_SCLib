/*
 * Stack.h
 *
 * Created: 2017/6/13 20:05:01
 *  Author: dusch
 */ 


#ifndef STACK_H_
#define STACK_H_

#define CREAT_POOL(NAME, LONG) uint8_t NAME [LONG + 1] = {1}

#define _STACK_LENGTH 16
#define _DEFULT LITTLE_BITCH
#define STACK_INIT CREAT_POOL(_DEFULT,_STACK_LENGTH)
#define PUSH(VAL) Push(_DEFULT,VAL)
#define POP(VAL) VAL=Pop(_DEFULT)
#define CLEAN Clean(_DEFULT)

void Pop(uint8_t *num, uint8_t data);
uint8_t Push(uint8_t *num);
void Clean(uint8_t *num);

#endif /* ADC_H_ */