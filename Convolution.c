//Author: Schummacher
//Data: 2017-09-23


#include "Convolution.h"

void Convolution(sequence *y, sequence *x, sequence *h)
{
	for (int i = 0; i < x->length; i++)
		for (int j = 0; j < h->length; j++)
			*(y->data + i + j) += *(x->data + i) * *(h->data + j);
}
