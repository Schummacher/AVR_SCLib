/*
 * Stack.h
 *
 * Created: 2017/6/13 20:05:01
 *  Author: dusch
 */ 


#include "Stack.h"

void POP(uint8_t *num, uint8_t data)
{
	uint8_t point_of_num = *num;
	*(num + point_of_num) = data;
	point_of_num  ++;
	*num = point_of_num;
}

uint8_t PUSH(uint8_t *num)
{
	uint8_t point_of_num = *num;
	point_of_num --;
	uint8_t temp = *(num + point_of_num);
	*(num + point_of_num) = 0;
	*num = point_of_num;
	return temp;
}