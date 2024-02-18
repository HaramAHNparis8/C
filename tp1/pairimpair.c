#include<stdio.h>


int main(void){

int a;

printf("entrer un nombre que vous voulez savoir c'est pair ou impaire: ");
scanf("%d", &a);
if(a % 2 == 0){

printf("c'est un pair");

}
else{

printf("c'est un impair");
}


return 0;
}
