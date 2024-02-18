#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Exercice 1 -- Questions de cours 
n est une variable de type entière, initialisée à 10;
p est un pointeur sur un entier, il contient donc l'adresse d'une variable entière
Pour que p contienne l'adresse de n : p=&n;
Pour modifier la valeur de la variable contenue à l'adresse p, on écrit *p=...

3 étapes de l'allocation dynamique :
1- On alloue l'espace mémoire nécessaire (en terme de nombre d'octets) avec malloc
2- On vérifie que l'allocation a fonctionné en testant si le pointeur renvoyé
par malloc vaut NULL
3- On libère l'espace mémoire alloué lorsque l'on en a plus besoin
*/

int affiche_tab1D(int *tab, int taille){
    for (int i=0;i<taille;i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
}

int affiche_tab2D(int **tab, int nbL, int nbC){
    for (int i=0;i<nbL;i++){
        for (int j=0;j<nbC;j++){
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
}

void echange(int *a, int *b){
    int c=*a;
    *a=*b;
    *b=c;
}

/* Exercice 2 */
int *remplace_impair(int *tab, int taille){
    int *res=malloc(taille*sizeof(int));
    if (res==NULL){
        exit(0);
    }
    for (int i=0;i<taille;i++){
        if ((tab[i]%2)==1){
            res[i]=0;
        }
        else{
            res[i]=tab[i];
        }
    }
    return res;
}

/* Exercice 3 */
void remplace_impair2(int *tab, int taille){
    for (int i=0;i<taille;i++){
        if ((*(tab+i)%2)==1){
            *(tab+i)=0;
        }
    }
}

/* Exercice 4 */
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

void affiche_personne(personne P){
    printf("Nom : %s \n",P.nom);
    printf("Prénom : %s \n",P.prenom);
    printf("Code postal : %d \n",P.codepostal);
    printf("Ville : %s \n",P.ville);
}

void changer_adresse(personne *P){
    int codepostal;
    char ville[20];
    printf("Entrez le nouveau code postal : \n");
    scanf("%d",&codepostal);
    P->codepostal=codepostal;
    printf("Entrez la nouvelle ville : \n");
    scanf("%s",ville);
    strcpy(P->ville,ville);
}

/* Exercice 5 */
char *supprime_lettre(char *text, int taille, char x){
    int nbchar =0;
    for (int i=0;i<taille;i++){
        if (text[i]!=x){
            nbchar++;
        }
    }
    char *res=malloc(nbchar*sizeof(char));
    if (res==NULL){
        exit(0);
    }
    int j=0;
    for (int i=0;i<taille;i++){
        if (text[i]!=x){
            res[j]=text[i];
            j++;
        }
    }
    return res;
}

int main(){
    /*
    int tab[7]={1,2,3,4,5,6,7};
    int *remp=remplace_impair(tab,7);
    affiche_tab1D(remp,7);

    affiche_tab1D(tab,7);
    remplace_impair2(tab,7);
    affiche_tab1D(tab,7);
    */

    personne P=saisie_personne();
    affiche_personne(P);

    changer_adresse(&P);
    affiche_personne(P);
   

    char text[50]="La programmation imperative, c'est super !";
    printf("Taille du texte : %ld \n",strlen(text));
    char *rem_e=supprime_lettre(text,strlen(text),'e');
    printf("%s",rem_e);
}
