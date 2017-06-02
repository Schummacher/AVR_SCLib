/*
 * Complex.c
 *
 * Created: 2017/6/1 PM 9:16:42
 *  Author: schummacher
 */ 


#include "Complex.h"

cint8_t cadd(cint8_t val_1, cint8_t val_2)
{
	val_1.re = val_1.re + val_2.re;
	val_1.im = val_1.im + val_2.im;
	return val_1;
}

cint8_t csub(cint8_t val_1, cint8_t val_2)
{
	val_1.re = val_1.re - val_2.re;
	val_1.im = val_1.im - val_2.im;
	return val_1;
}