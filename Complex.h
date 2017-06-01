/*
 * Complex.h
 *
 * Created: 2017/6/1 PM 9:17:07
 *  Author: schummacher
 */ 


#ifndef COMPLEX_H_
#define COMPLEX_H_

#include "Device.h"

typedef struct Char_Complex
{
	uint8_t re;
	uint8_t im;
} char_complex;

typedef char_complex cint8_t;

cint8_t cadd(cint8_t val1, cint8_t val2);
cint8_t csub(cint8_t val1, cint8_t val2);

#endif /* COMPLEX_H_ */