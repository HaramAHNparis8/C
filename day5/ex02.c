#include<stdio.h>


void somme_prod(int* a, int* b){

	int c = *a;
	* a = c * *b;
	* b = c * *b;

}


int main(){
	int a = 5;
	int b = 2;
	
	printf("valeur de a : %d \n", a);
	printf("valeur de b : %d \n", b);
	
	somme_prod(&a, &b);

	printf("valeur de a : %d \n", a);
	printf("valeur de b : %d \n", b);
    
    
    return 0;


}
