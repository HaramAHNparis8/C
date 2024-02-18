#include<stdio.h>


int main(void){
    int a = 0;
    printf("entrer le chiffre que vous voulez lancer le calcul des annees ");
    scanf("%d", &a);
    int annee = 0;
    int semaine = 0;
    int jour = 0;

    annee = a /360;
    a -= annee * 360;
    semaine = a / 7;
    a -= semaine * 7;
    jour = a;
    
    if(annee != 0 && semaine == 0 && jour == 0){
        printf("annee : %d\n", annee);
    }
    else if(annee != 0 && semaine != 0 && jour == 0){
        printf("annee %d semaine : %d", annee ,semaine);
    }
    else{
        printf("annee %d semaine : %d jour : %d", annee,semaine,jour);
    }
}
