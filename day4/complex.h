#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct complex{
	float real;
	float imag;

}complex;
complex saisi(void);
void affiage(complex z);
complex addtion(complex z, complex w);
void affiage_addition(complex z);
complex multi(complex z, complex w);
void affiage_mul(complex z);
float module(complex z);
