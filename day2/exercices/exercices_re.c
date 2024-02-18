#include<stdio.h>




int mystre(int n){
if(n == 0){

return 0;
}
else if(n % 2 == 0){
	
	return n +  mystre(n - 1); 
}
else{

	return mystre(n - 1);
}



}

int somme(int n){

	if(n == 0){
	
	return 0;
	}
	else{
	
	return n + somme(n - 1);
	
	}


}

int puissance(int n){
	if(n == 0){
	
	return 1;
	}
	
	else{
	
	return n * puissance(n - 1);
	}


}

int sommefors(int n){
    int res = 0;
    for(int i = 0; i <= n; i++){
        res += i;
        
    }
    return res;

}

int somme_while(int n){
    int res = 0, i = 1;
    while(i <= n){
        res += i;
        i++;
    }
    return res;
    
    
}
int deintervallleAnombre(int a, int b){
    int n = 0;
    do{
        printf("entrer le valeur entre %d et %d ",a,b);
        scanf("%d", &n);
    } while(n < a || n > b);
    
    return n;
    
    
}
int main(void){
	
	
	//printf("le valeur de mystre (%d)",mystre(3));
	//printf("le valeur de somme (%d)", somme(4));
	//printf("le valeur de puissance (%d)", puissance(4));
//	printf("le valeur entree : %d",nombrecompris);
    
//    int n = 0;
//
//
//    while(n < 1 || n > 10){
//        printf("entrer le nombre de l'entier a partir de 0 et 10 :");
//        scanf("%d", &n);
//        }
//    printf("le valeur de nombre entrée(%d)",n);
//
//    printf("le valeur de sommefor (%d)",sommefors(5));
//    printf("le valeur de sommewhile (%d)",somme_while(5));
    printf("le valeur de de intervalle (%d)",deintervallleAnombre(1,10));
}
