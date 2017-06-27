/*
 * Stack.h
 *
 * Created: 2017/6/13 20:05:01
 *  Author: dusch
 */ 


#include "Stack.h"

void Push(uint8_t *num, uint8_t data)
{
	uint8_t pt = *num;
	*(num + pt) = data;
	pt++;
	*num = pt;
}

uint8_t Pop(uint8_t *num)
{
	uint8_t pt = *num;
	pt--;
	uint8_t temp = *(num + pt);
	*(num + pt) = 0;
	*num = pt;
	return temp;
}

void Clean(uint8_t *num)
{
	*num = 1;
}