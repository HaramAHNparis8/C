#include<stdio.h>
#include<math.h>
#include <time.h>
#include <stdlib.h>

int entrerlevaleur(){
    int n = 0;
    printf("entrer le nombre :");
    scanf("%d", &n);
    
    return n;
    
}

int pgcd (int a, int b){

	if(a == b){

	return a;
	}
	else{
		if(a > b){
		return pgcd(a - b, b);
		}
		else{

		return pgcd(b - a, a);
		}
	}
}


int ex3_re(int n){

	if(n == 0){
		return 1;
	}
    else{
        return pow(2, n) + ex3_re(n - 1);
    }
}

int ex3_for(int n, int v){
    int i, sum = 1, val = 1;
    for(i = 0; i < n; i++){
        val *= v;
        sum += val;


    }

    return sum;
}

//char aski(){
//    int i,j, a = 64;
//    j = a - 16;
//    for(i = 0; i <= 25; i++){
//        printf("%c code %d\n", a+=1, a);
//    }
//    for(i = 0; i < 9; i++){
//        printf("%c code %d\n", j+=1, j);
//    }
//    return printf("");
//
//}

int estinterval(){
    int a = 0;
    printf("entrez le nombre à partir de 1 à 10 : \n");

    do{
        a = entrerlevaleur();

    } while(a < 1 || a > 10);

    return a;
}

int tabledemulti(){
    int i = 0, a = 0;

    a = estinterval();

    while(i < 10){
        printf("%d x %d = %d\n",a,i, a * i);
        i++;
    }
    return printf("");


}

int randoms(){
    int r = 0;
    srand(time(NULL));
    r = rand() % 101;

    return r;

}
//
int vérification(){

    int n = 0, b =0, i = 0;

    n = randoms();
    
    printf("le nombre caché : %d\n", n); // vérifier la valeur de n randoms
    
    
    b = entrerlevaleur();

    while(1){

        if(n == b){
            printf("vous avez gagné en %d essaie", i);
            break;
        }
        else if(n < b){
            printf("%d est supérieur. Veuillez ré-entrer le nombre \n", b);
            b = 0;
            b = entrerlevaleur();
            i++;
        }
        else{
            printf("%d est inférieur. Veuillez ré-entrer le nombre \n", b);
            b = 0;
            b = entrerlevaleur();
            i++;
        }
        }
    return printf("");

    }
    
    
int cmchifre(int n){

    if(n == 0){
        return 0;
    }
    else{

        return 1 + cmchifre(n/10);
    }

}

int puissance(int n, int v){
    int j, q = 1;
    for(j = 0; j < n; j++){
        q *= v;
    }

    return q;

}
 

int S(int a){
    int i = 0,s = 0;
    i = cmchifre(a);

    while(a != 0){
               s+= puissance(i,a % 10);
               a = a/10;
           }

    return s;
}

int estnarcissique(int n){
    int sum = 0, i = 0;


    sum = S(n);

    if(sum == n){
        return n;
    }
    else{
        return 0;
    }
    return printf("");
}
//
int affiche(){
    int n = 0,i, t = 0;

    n = entrerlevaleur();

    for(i = 0; i <= n; i++){
        t = estnarcissique(i);
        if(t == 0){
            continue;
        }
        else{
            printf("tous les nombres entiers (%d)\n", t);
        }
    }

    return printf("");

}


int ex_8_1(int n){
    int i,j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("*");
        }
        printf("\n");
    }
    return printf("");
}

int ex_8_2(int n){
    int i,j;
    for(i = n; i > 0; i--){
        for(j = i; j > 0; j--){
            printf("*");
        }
        printf("\n");
    }
    return printf("");
}


int ex8_3(int n){
    int i,j,p,q;
    for(i = 0; i < n; i++){
        for(j = 0; j <= i; j++){
            printf("*");
        }
    printf("\n");
    }
    for(p = n - 1; p > 0; p--){
        for(i = n; i > p; i--){
            printf(" ");
        }
        for(q = p; q > 0; q--){
            printf("*");
        }
        printf("\n");
    }
    return printf("");
}



void ex9(){
    int N = 0, i;
    N = entrerlevaleur();
    while(N>1){
          for(i=2; i<=N; i++){
              if(N%i==0){
                  printf("%d\n", i);
                  N = N/i;
                  break;
              }
          }
      }
}

                   
                   





                   
                   
                   
                   
                   
    


int main(void){
    int n = 0, ex7 = 0;
//    printf("%d", entrerlevaleur()); ///tester la valeur est saisi
    
//	printf("%d/n", pgcd(12, 18));
//    printf("%d/n", pgcd(22, 121));
    
//    n = entrerlevaleur(); // pour exercies 3
//    printf("%d",ex3_re(n));
//    printf("%d\n",ex3_for(n,2));
//    aski();
//
//    printf("%d", estinterval()); // testez le nombre saisi est un chiffre entre 1 et 10
//    tabledemulti();
//    printf("%d\n",randoms());
//    printf("%d", vérification());
//    ex7 = entrerlevaleur();
//    printf("%d",cmchifre(ex7));
//    printf("%d",puissance(3,2));// vérifier la fonction puissance
//    printf("%d",S(153));// vérifier sum de la multiplication de chaque chiffre p
//    printf("%d",estnarcissique(153)); //vérifier c'est un chiffre narcissique
//    affiche();

//    ex_8_1(4);
//    ex_8_2(5);
//    ex8_3(4);
    ex9();
    return 0;
}
