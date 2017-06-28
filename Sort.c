/*
 * Sort.c
 *
 * Created: 2017/6/28 10:05:41
 *  Author: dusch
 */ 

#include "Sort.h"

void Shellsort(uint8_t A[ ], uint8_t N)
{
	uint8_t i, j, Increment, Tmp;
	for (Increment = N / 2; Increment > 0; Increment /= 2)
	{
		for (i = Increment; i < N; i++)
		{
			Tmp = A[i];
			for (j = i; j >= Increment; j -= Increment)
			{
				if (Tmp < A[j - Increment])
				A[j] = A[j - Increment];
				else
				break;
			}
			A[j] = Tmp;
		}
	}
}