#include<stdio.h>


int main(void){

int a = 0;
printf("entrer le nombre: ");
scanf("%d", &a);

float b = 0.55556 *( a - 32);

printf("%d F coresspond a : %f C", a, b);

return 0;
}
