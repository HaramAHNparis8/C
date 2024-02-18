#include<stdio.h>
#include<math.h>

//M_PI

float fois(float n){

	return n * n;
}

int main(void){

	float r = 0, res = 0;
	printf("entrez le valeur :");
	scanf("%f", &r);

	res = (fois(r)) * M_PI;
	printf("%f", res);


}

