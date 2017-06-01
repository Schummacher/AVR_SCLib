/*
 * Complex.c
 *
 * Created: 2017/6/1 PM 9:16:42
 *  Author: schummacher
 */ 


#include "Complex.h"

cint8_t cadd(cint8_t val1, cint8_t val2)
{
	val1.re = val1.re + val2.re;
	val1.im = val1.im + val2.im;
	return val1;
}

cint8_t csub(cint8_t val1, cint8_t val2)
{
	val1.re = val1.re - val2.re;
	val1.im = val1.im - val2.im;
	return val1;
}