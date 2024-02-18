#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//void affiche(int* v, int taille){
//	int i;
//
//	for(i = 0; i < taille; i++){
//
//		printf("%d  ", v[i]);
//	}
//
//
//}

void affiche_2d(int** v1, int taille, int colonne){
    int i,j;
    
    for(i = 0; i < taille; i++){
        for(j = 0; j < colonne; j++){
            printf("%d ", v1[i][j]);
            
        }
        printf("\n");
    }
}

void remplace_impaire(int* v, int taille){
    int i;
    
    for(i = 0; i < taille; i++){
        if(v[i] % 2 !=0 ){
            v[i] = 0;
            
        }
        
    }
    
}

void affiche(int v[], int taille){
    int i;
    remplace_impaire(v,taille);

    for(i = 0; i < taille; i++){

        printf("%d  ", v[i]);
    }


}

typedef struct personne{
    char nom[20];
    char prenom[20];
    int codepostal;
    char ville[20];
}personne;
personne saisie_personne(){
    personne P;
    char saisie[50];
    int nbrue, codepostal;
    printf("Entrez le nom de la personne : \n");
    scanf("%s",saisie);
    strcpy(P.nom,saisie);
    printf("Entrez le prénom de la personne : \n");
    scanf("%s",saisie);
    strcpy(P.prenom,saisie);
    printf("Entrez le code postal : \n");
    scanf("%d",&codepostal);
    P.codepostal=codepostal;
    printf("Entrez la ville : \n");
    scanf("%s",saisie);
    strcpy(P.ville,saisie);
    return P;
}
int main(void){
	//int n = 10;
	//int *p;

	//*p = n;

	//printf("%d", *p);
	int v[3] = {0,1,2};
    int* v2[3] = {v,v,v};

	affiche(v,3);
//    affiche_2d(v2,3,3);

}
