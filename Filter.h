/*
 * Filter.h
 *
 * Created: 2017/7/28 下午 5:58:48
 *  Author: YWL
 */ 


#ifndef FILTER_H_
#define FILTER_H_

#include <stdint-gcc.h>
#include "Sort.h"

#define FilterLen 16

uint16_t Filter_Average(uint16_t * bArray);
uint16_t Filter_middle(uint16_t * bArray);


#endif /* FILTER_H_ */
