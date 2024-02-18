#include<stdio.h>

int nth(int *tab,int nth_t, int nb){
	
	if(tab[nth_t] == nb){

		return nth_t;
	
	}
	else{

        return nth(tab,nth_t - 1,nb);

	
	}


}
int main(void){

	int tab[10];
	int i;

	for(i = 0; i < 10; i++){
		tab[i] = 10 - i;
	}
	for(i = 0; i < 10; i++){
		printf("%d ", tab[i]);
	}
    printf("\n");
    printf("%d",nth(tab,10 - 1, 10));
    
    
    return 0;

}
