#include<stdio.h>
#include<math.h>
typedef struct complex{
	float real;
	float imag;

} complex;

complex saisi(void){
	complex z;
	
	printf("entrez la partie réelle : \n");
    scanf("%f",&z.real);
    
    printf("entrez la partiel imaginaire :");
    scanf("%f",&z.imag);
    
    return z;
}


void affiage(complex z){
    printf("le nombre complex est %f +i %f. \n",z.real,z.imag);
    
    
}

complex addtion(complex z, complex w){
    complex res;
    
    res.real = z.real + w.real;
    
    res.imag = z.imag + w.imag;
    
    return res;
}

void affiage_addition(complex z){
    
    printf("le nombre des resultats : %f +i %f \n",z.real,z.imag);
    
}

complex multi(complex z, complex w){
    complex res;
    
    res.real = (z.real * w.real) - (z.imag * w.imag);
    res.imag = (z.real * w.imag) + (w.real * z.imag);
        
    return res;
}


void affiage_mul(complex z){
    
    printf("le nombre de résulat : %f + i%f\n",z.real,z.imag);
}

float module(complex z){
    return sqrt((z.real * z.real) + (z.imag * z.imag));
}

// à cause de problème de système impossible de faire un exercice de makefile
int main (void){
    complex z;
    z.real = 2.0;
    z.imag = 3.0;
    
    complex w;
    w.real = 3.0;
    w.imag = 4.0;
    
//    complex add = addtion(z,w);
//    z = saisi();
//    affiage(z);
//    addtion(1.2,2.3);
//    affiage_addition(add);
//    complex mul = multi(z,w);
//    affiage_mul(mul);
    float modulo;
    modulo = module(z);
    printf("%f", modulo);
    
    return 0;





}
