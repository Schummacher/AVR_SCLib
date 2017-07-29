/*
 * PID.h
 *
 * Created: 2017/7/28 下午 8:23:55
 *  Author: schummacher
 */ 


#ifndef PID_H_
#define PID_H_

#include <stdint-gcc.h>

typedef struct PID
{
	int16_t  SetPoint;
	int32_t SumError; 
	float  Proportion;
	float  Integral;
	float  Derivative;
	int16_t LastError;
	int16_t PrevError;
} PID;

int16_t IncPIDCalc(int16_t NextPoint, PID *sptr);
int16_t LocPIDCalc(int16_t NextPoint, PID *sptr);


#endif /* PID_H_ */