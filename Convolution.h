//Author: Schummacher
//Data: 2017-09-23

typedef struct
{
	uint8_t length;
	float *data;
} sequence;

void Convolution(sequence *y, sequence *x, sequence *h);
