/*
 * Filter.c
 *
 * Created: 2017/7/28 下午 5:58:39
 *  Author: YWL
 */ 

#include "Filter.h"

uint16_t Filter_Average(uint16_t * data)
{
	uint16_t tmp;
	
	for(uint8_t i = 0; i < FilterLen; i++)
	{
		tmp += data[i];
	}
	tmp /= FilterLen;
	
	return tmp;
}

uint16_t Filter_middle(uint16_t * data)
{
 	uint16_t tmp;	
// 	for (uint8_t j = 0; j < FilterLen - 1; j ++)
// 	{
// 		for (uint8_t i = 0; i < FilterLen - j - 1; i ++)
// 		{
// 			if (data[i] > data[i + 1])
// 			{
// 				tmp = data[i];
// 				data[i] = data[i + 1];
// 				data[i + 1] = tmp;
// 			}
// 		}
// 	}
	Shellsort_16bit(data, FilterLen);
// 	// 计算中值
// 	if ((FilterLen % 2 > 0))
// 	{
// 		// 数组元素个数为奇数
// 		tmp = data[(FilterLen) / 2];
// 	}
// 	else
// 	{
// 		
// 		// 数组元素个数为偶数
// 		tmp = (data[(FilterLen / 2)-1] + data[FilterLen / 2 ]) / 2;
// 	}
	tmp = (data[(FilterLen / 2)-1] + data[FilterLen / 2 ]) / 2;
	return tmp;
}
