#include "math.h" 
#include "fft.h" 

void conjugate_complex(int n, complex in[], complex out[])
{
	int i = 0;
	for (i = 0; i<n; i++)
	{
		out[i].Im = -in[i].Im;
		out[i].Re = in[i].Re;
	}
}

void c_abs(complex f[], float out[], int n)
{
	int i = 0;
	float t;
	for (i = 0; i<n; i++)
	{
		t = f[i].Re * f[i].Re + f[i].Im * f[i].Im;
		out[i] = sqrt(t);
	}
}


void c_plus(complex a, complex b, complex *c)
{
	c->Re = a.Re + b.Re;
	c->Im = a.Im + b.Im;
}

void c_sub(complex a, complex b, complex *c)
{
	c->Re = a.Re - b.Re;
	c->Im = a.Im - b.Im;
}

void c_mul(complex a, complex b, complex *c)
{
	c->Re = a.Re * b.Re - a.Im * b.Im;
	c->Im = a.Re * b.Im + a.Im * b.Re;
}

void c_div(complex a, complex b, complex *c)
{
	c->Re = (a.Re * b.Re + a.Im * b.Im) / (b.Re * b.Re + b.Im * b.Im);
	c->Im = (a.Im * b.Re - a.Re * b.Im) / (b.Re * b.Re + b.Im * b.Im);
}

void Wn_i(int n, int i, complex *Wn, char flag)
{
	Wn->Re = cos(2 * PI*i / n);
	if (flag == 1)
		Wn->Im = -sin(2 * PI*i / n);
	else if (flag == 0)
		Wn->Im = -sin(2 * PI*i / n);
}

//傅里叶变化  
void FFT(int N, complex f[])
{
	complex t, wn;//中间变量  
	int i, j, k, m, n, l, r, M;
	int la, lb, lc;
	/*----计算分解的级数M=log2(N)----*/
	for (i = N, M = 1; (i = i / 2) != 1; M++);
	/*----按照倒位序重新排列原信号----*/
	for (i = 1, j = N / 2; i <= N - 2; i++)
	{
		if (i<j)
		{
			t = f[j];
			f[j] = f[i];
			f[i] = t;
		}
		k = N / 2;
		while (k <= j)
		{
			j = j - k;
			k = k / 2;
		}
		j = j + k;
	}

	/*----FFT算法----*/
	for (m = 1; m <= M; m++)
	{
		la = pow(2, m); //la=2^m代表第m级每个分组所含节点数       
		lb = la / 2;    //lb代表第m级每个分组所含碟形单元数  
						//同时它也表示每个碟形单元上下节点之间的距离  
						/*----碟形运算----*/
		for (l = 1; l <= lb; l++)
		{
			r = (l - 1) * pow(2, M - m);
			for (n = l - 1; n<N - 1; n = n + la) //遍历每个分组，分组总数为N/la  
			{
				lc = n + lb;  //n,lc分别代表一个碟形单元的上、下节点编号       
				Wn_i(N, r, &wn, 1);//wn=Wnr  
				c_mul(f[lc], wn, &t);//t = f[lc] * wn复数运算  
				c_sub(f[n], t, &(f[lc]));//f[lc] = f[n] - f[lc] * Wnr  
				c_plus(f[n], t, &(f[n]));//f[n] = f[n] + f[lc] * Wnr  
			}
		}
	}
}

//傅里叶逆变换  
void IFFT(int N, complex f[])
{
	int i = 0;
	conjugate_complex(N, f, f);
	FFT(N, f);
	conjugate_complex(N, f, f);
	for (i = 0; i<N; i++)
	{
		f[i].Im = (f[i].Im) / N;
		f[i].Re = (f[i].Re) / N;
	}
}

void DFT(complex *data, complex *X, int K)
{
	complex tmp1, tmp2;
	int k, h;
	double p;
	for (k = 0; k < K; k++)
	{
		tmp1.Re = 0;
		tmp1.Im = 0;
		for (h = 0; h < K; h++)
		{
			p = (double)((k * h) % K);
			tmp2.Re = cos(-2 * PI * p / K);
			tmp2.Im = sin(-2 * PI * p / K);
			tmp1.Re += data[h].Re * tmp2.Re - data[h].Im * tmp2.Im;
			tmp1.Im += data[h].Im * tmp2.Re + data[h].Re * tmp2.Im;
		}
		X[k].Re = tmp1.Re;
		X[k].Im = tmp1.Im;
	}
}