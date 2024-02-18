#include<stdio.h>

int main(void) {
//abc sont inutiles alors on supprime
int a = 5;
int b = 2;
int c = (a / b);
int d, e;
printf("entrez deux valeurs : ");
scanf ("%d %d", &d, &e);

int s = a + d + e;
int m = s - a;

printf("%d\n", s);
printf("%d", m);
return 0;



}
