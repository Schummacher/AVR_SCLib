/*
 * PID.c
 *
 * Created: 2017/7/28 下午 8:24:05
 *  Author: schummacher
 */ 

#include "PID.h"

int16_t IncPIDCalc(int16_t NextPoint, PID *sptr)
{
	int16_t iError, iIncpid;
	iError = sptr->SetPoint - NextPoint;
	iIncpid = sptr->Proportion * iError - sptr->Integral   * sptr->LastError + sptr->Derivative * sptr->PrevError;
	sptr->PrevError = sptr->LastError;
	sptr->LastError = iError;
	return(iIncpid);
}


int16_t LocPIDCalc(int16_t NextPoint, PID *sptr)
{
	int16_t  iError, dError;

	iError = sptr->SetPoint - NextPoint;
	sptr->SumError += iError;
	dError = iError - sptr->LastError;
	sptr->LastError = iError;
	return(sptr->Proportion * iError + sptr->Integral * sptr->SumError	+ sptr->Derivative * dError);        //微分项
}