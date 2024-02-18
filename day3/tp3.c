#include <stdio.h>

#define TAILLE 20

//exercice 1

int code_A(void){

int tab [TAILLE] = {0};
for (int i=0;i<TAILLE;i++){
printf("%d \n",tab[i]);
}

return 0;
}


int code_b(void){ 
	double tab[15];
	for (int i=0; i<15; i++){
		tab[i] = i+1;
		printf("La valeur de la premiere case est %lf. \n",tab[0]);
		printf("La valeur de la derniere case est %lf. \n",tab[14]);
	}
	return 0;
}


//exercice 2
int* tableau_à_0_de_100(){ //la fonction pour créer des tableaux pour les execrises 2
    static int tableau_100[10][10]; //la déclaration des tableaux
    int i,j;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            tableau_100[i][j] = i * 10 + j; //stocker les valeur à 0 de 100
        }
    }
    return (int*)tableau_100;
}
void affichage(){ //la fonction pour afficher des tableaus exercices 2
	int i,j;
    int(*tab)[10] = (void*)tableau_à_0_de_100(); //recevoir l'adresse des tableaux crée dans la fonction tableau_à_0_de_100

	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++ ){
            
			printf("%d\t", tab[i][j]);
		}
		printf("\n");
	}

}

//exercices 3

int entrerlavaleur(){ //la fonction pour demander 10 nombre à l'utilisateur
    int n = 0;
    printf("enter dix nombres");
    scanf("%d", &n);
    return n;
    
}

int* créationtableau() { //la fonction pour créer des tableaux après avoir entré dix valeurs par utilisateur
    static int tableau[10];
    int i, nb = 0;

    for(i = 0; i < 10; i++){
        nb = entrerlavaleur(); // la compilation de la fonction entrer la valeur
        tableau[i] = nb;

    }

    return tableau;
}


void affichage_ex3(int nb){ // la fonction pour afficher minimum, maximum et tous les valeurs des tableaux entrée
    int i,max = 0,mini = 0;
    int* num = créationtableau();

    max = num[0];
    mini = num[0];

    for(i = 0; i < nb; i++){
        if(max < num[i]){
            max = num[i];
        }
    }
    printf("le nombre maximum %d\n", max);

    for(i = 0; i < nb; i ++){
        if(mini > num[i]){
            mini = num[i];
        }
    }
    printf("le nombre minimum  %d\n", mini);

    for(i = 0; i < nb; i++){
        printf("%d ",num[i]);
    }
}

int min(int nb){ // la fonction pour tester l'algorithme
    int i,min;
    int* num = créationtableau();
    min = num[0];
    for(i = 0; i < nb; i++){
        if(min > num[i]){
            min = num[i];
        }
    }
    return min;
}

int maxi(int nb){ // la fonction pour tester l'algorithme
    int i,max;
    int* num = créationtableau();
    max = num[0];
    for(i = 0; i < nb; i++){
        if(max < num[i]){
            max = num[i];
        }
    }
    return max;
    
}

//exercices 4
int* tableau_Pa_création() { // la création des tableaux
//    static int tableau_P[10] = {1,2,3,4,5,5,4,3,2,1};
//    static int tableau_P[10] = {0,1,2,3,4,5,6,7,8,9};
    
    return tableau_P;
}

void affiche_tab_pandrome(int nb){ //testez des tableaux sont bien créés.
    int* v = tableau_Pa_création();
    int i;
    
    for(i = 0; i < nb; i++){
        printf("%d ", v[i]);
    }
    
}

int estpalindrome(int nb, int* tab){ // la fonction pour tester des tableaux sont palindrome ou pas
    // si c'est vrai la fonction retourne 1 sinon 0
    int i, res = 1;
//    int* v = tableau_Pa_création();
    
    for(i = 0; i < (nb/2); i++){
        if(v[i] != v[nb - (i + 1)]){
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

//exercices 5

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

//exercies 6


void nb_occur_affiage(int taille, char text[taille], char caractère){
    int num = 0, i;
    
    
    for(i = 0; i <taille; i++){
        
        printf("%c\t", text[i]);
        
        if(text[i] == caractère){ // compter le nombre des éléments pareils
            num ++;
        }
        
        
    }
    printf("\n");
    
    printf("le nombre de caractère %c est %d\n", caractère, num);
}

void shuffle(int* a, int* b){ //la fonction pour changer l'ordre des éléments des tableaux
    int p = 0;
    
    p = *a;
    *a = *b;
    *b = p;
    
}

int* tableauinversion(){ //la fonction pour créer des tableaux pour les execrises 7
    static int tableauinversion[5][5];
    int i,j;
    
    for(i = 0; i < 5; i++){
        
        for(j = 0; j < 5; j++){
            
            tableauinversion[i][j] = i * 10 + j;
        }
    }
    
    return (int*)tableauinversion;
}

void rangment(int nb){ //la founction pour ranger les tableaux mais dans cette fonction, il faut toujours allumer la fonction shuffle
    int (*n)[5] = (void*)tableauinversion();
    int i,j;
    for(i = 0; i < nb; i++){
        for(j = i; j < nb; j++){
            shuffle(&n[i][j],&n[j][i]); //la fonction pour changer l'ordre
            }
        }
    
}

void affichage_2_dimension(int nb){ //la fonction pour afficher des tableaux.
    int (*n)[5] = (void*)tableauinversion();
    int i,j;
    
    rangment(nb); // pour tester, exécultez après avoir allumé ou éteindu ce ligne
    
    for(i = 0; i < nb; i++){
        for(j = 0; j < nb; j++){
            printf("%d\t", n[i][j]);
        }
        printf("\n");
    }
                   
                   }



int pascal_recursivité(int a, int b){
    if (a == 0 || b == 0 || a == b)
        return 1;
    else
        return pascal_recursivité(a - 1, b) + pascal_recursivité(a - 1, b - 1);
}

int* tableaupascal(){ //la fonction pour créer des tableaux pour les execrises 8
    static int tableaupascal[6][6];
    int i,j,nb = 5;
    
    for(i = 0; i <= nb; i++){
        for(j = 0; j <= nb; j++){
            tableaupascal[i][j] = pascal_recursivité(i,j);
        }
    }
    return (int*)tableaupascal;
}

int main(void){
    int a[10] = {1,2,3,4,5,5,4,3,2,1},i,j;
    char text[] = {'I','w','i','l','l',
        'd','a','n','c','e','d','a','n','c','e',
        'w','i','t','h','m','y','h','a','n','d'
    };
    int (*nb)[6] = (void*)tableaupascal();
    
//    printf("%d",entrerlavaleur());
//	affichage();
//    affichage_ex3(10);
//    printf("le plus grand : %d",maxi(10)); // si vous voulez tester l'algorithme maximum, allumez cette fonction
//    printf("le plus petit %d",min(10));// si vous voulez tester l'algorithme minimum, allumez cette fonction
    tableau_Palindrome(10);
    
    
//    printf("%d", fib(5)); //testez la fonction de fibonnacci
//    affichage_fib_tab();
//    nb_occur(24,text,'w');
//    nb_occur(24,text,'a');
//    affichage_2_dimension(5);
  

//    for (i = 0; i <= 5; i++){
//        for (j = 0; j < i; j++){
//            printf("%d   ", nb[i][j]);
//            printf("%d ",pascal_recursivité(i,j)); //testez la fonction de pascal en forme de récursivité
    //pour tester final
    //il faut éteindre ce ligne
//        }
//        printf("\n");
//    }
    return 0;
}
