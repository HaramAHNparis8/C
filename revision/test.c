#include<stdio.h>

#define taille 5


int entreval(){
	int n;
	printf("entre val :\n");
	scanf("%d", &n);
	
	return n;

}



void affiage(){
	int tab[10];
	int i;

	for(i = 0; i < 10; i++){
		tab[i] = entreval();
	}
	for(i = 0; i < 10; i++){
		printf("%d\n", tab[i]);
	}


}

int paire_impaire(int n){
	if(n%2 == 0){
		return 1;
	}
	else{
	
	return n;
	}
	
}

int recursivite_produit(int n){
	if(n == 0){
		
		
		return 1;
	}

	else{

		return paire_impaire(n) * recursivite_produit(n - 1);
	}

}

int for_boucle(int n){

	int i, s = 1;

	for(i = 0; i <= n; i++){
		if(i%2 == 0){
			continue;
		}
		else{
			s *= i;
		}

	}

	return s;

}

void affichage_1(){

	int n = 0, i, j;

	printf("entrez la valeur : \n");
	scanf("%d", &n);

	for(i = n; i > 0; i--){
		for(j = n; j > 0; j--){
			//printf("j intial : %d",j);
			printf("%d",i);
		}
		printf("\n");
	}


}

int permier_indice(int n, int v[], int taille){
	int i,res = 0;

	for(i = 0; i < taille; i++){
		if(n == v[i]){

			return res;
		}
		else if(i != taille && n != v[i]){
			res++;
		}
		else{
			return -1;
		}
	
	}
}
int estpalindrome(int nb, int* tab){ // la fonction pour tester des tableaux sont palindrome ou pas
    // si c'est vrai la fonction retourne 1 sinon 0
    int i, res = 1;
//    int* v = tableau_Pa_création();
    
    for(i = 0; i < (nb/2); i++){
        if(tab[i] != tab[nb - (i + 1)]){
            res = 0;
        }
    }
    
    return res;
    
}
void tableau_Palindrome(int nb, int* tab){  // la fonction pour afficher si c'est vrai ou pas
    
    int n = 0,  res, i;

    res = estpalindrome(nb,tab);
    
    if(res == 1){
        printf("c'est Palindrome");
    }
    else{
        printf("c'est pas Palindrome");
    }
   
    
}

int fib(int n){ // la fonction pour fibonnaccie
    
    if(n==0 || n==1)
        return 1;
    return fib(n-1)+fib(n-2);
}

int entrerlenombredefib(){
    int n;
    printf("entrer le nombre pour fibo");
    scanf("%d",&n);
    return n;
}

int* fib_tab(){
    
    static int fib_tab[TAILLE];
    int i, n = 0;
    
    n = entrerlenombredefib();
    
    while(1){// après avoir l'exécution la fonction entrerlenombredefib, vérifie que la tailles est suffisante,
        //si la taille n'est pas suffisante, la fonction redemande à entrer le nombre à l'utilisateur.
        //si la taille est suffisant, la fonction returne l'adresse des tableux créé et la boucle est finie.
        if(n <= TAILLE){
            for(i = 0; i < n; i++){
                fib_tab[i] = fib(i);
                
            }
            
            return fib_tab;
            break;
    }
        else{
            printf("Tableau trop petit,Veuillez re-saisir");
            n = 0;
            n = entrerlenombredefib();
            
        }
    }
}

void affichage_fib_tab(){ // la fonction pour afficher des tableaux de fibonnaccis
    
    int i;
    int* num;
    num = fib_tab();
    for(i = 0; i < TAILLE; i++){
        printf("%d\n",num[i]);
    }
}

int main(){
	int v[6] = {1,2,3,3,2,1};
	//printf("%d\n", recursivite_produit(7));
	//affichage_1();
	//affiage();
	//printf("%d",for_boucle(5));	
//	printf("%d",permier_indice(6,v,6));
    tableau_Palindrome(6,v);

}
