#include<stdio.h>
#include <stdlib.h>

double entreval(){
	double val;
	printf("entrez la valeur de matrice : \n");
	scanf("%lf",&val);

	return val;
}

int entreznb_ligne(){
    int taille;
    printf("entrez le nombre de ligne : \n");
    scanf("%d", &taille);
    
    return taille;
}

int entreznb_colonne(){
    int taille;
    printf("entrez le nombre de colonne : \n");
    scanf("%d", &taille);
    
    return taille;
}
int entreznb_fait_pareil(){
    int taille;
    printf("entrez le nombre de ligne ou colonne : \n");
    scanf("%d", &taille);
    
    return taille;
}

int entre_fois_puissance(){
    int n = 0;
    printf("entrez le nombre de puissance");
    scanf("%d", &n);
    return n;
}

double** tab1creation(int nbLigne, int nbColonne){
    double **tab2d = malloc(nbLigne * sizeof(double *));
    int i,j, res = 0, taille = 0;
    taille = nbColonne + 1;
    for(i = 0; i < nbLigne; i++){
        tab2d[i] = malloc(taille * sizeof(double));
    }
    
    for(i = 0; i < nbLigne; i++){
        
        for(j = 0; j < nbColonne; j++){
            
            tab2d[i][j] = entreval();
            
        }
        
    }
    
    return tab2d;
    
}
 


double** res_tab(int nb_ligne,int nb_colonne){
    double **tab2d = malloc(nb_colonne * sizeof(double *));
    int i,j, taille = 0,re_taille = 0;
    
    taille = nb_ligne + 1;//
    for(i = 0; i < nb_ligne; i++){//
        tab2d[i] = malloc(taille * sizeof(double));
        
    }
    return tab2d;
    
}

int quelleioperation(){
    int n = 0;
    printf("entrez le nombre que vous voulez opérer\n");
    printf("1.addtion 2.sustraction 3. multiplication 4. puissance \n");
    scanf("%d",&n);
    
    return n;
}

int fait_pareil(){
    int taille_re_entreer;
    printf("ce matrice n'est pas possible d'opération veuillez re-entrer\n");
    taille_re_entreer = entreznb_fait_pareil();
        
    return taille_re_entreer;
}

double add_operation(double **tab_1, double **tab_2, int i, int j){
    double res = 0;//afin de minaliser l'erreur de la calcue dans le cas de décimal périodique
    res += tab_1[i][j] + tab_2[i][j];
    return res;
    
}
double sus_operation(double **tab_1, double **tab_2, int i, int j){
    double res = 0;//afin de minaliser l'erreur de la calcue dans le cas de décimal périodique
    
    res += tab_1[i][j] - tab_2[i][j];
    
    return res;

    

}



void operation_add(double** tab2d,double** tab_1, double** tab_2,int nb_ligne,int nb_colonne){
    int i,j;
    for(i = 0; i < nb_ligne; i++){
        for(j = 0; j < nb_colonne;j++){
            tab2d[i][j] = add_operation(tab_1,tab_2,i,j);
            
        }
        
    }
}

void affichage_tab1(double **tab_1,int nb_ligne_tab1,int nb_colonne_tab1){
    int i,j;
    
    
    for(i = 0; i < nb_ligne_tab1; i++){
        
        for(j = 0; j < nb_colonne_tab1;j++){
            printf("%f ", tab_1[i][j]);
            
        }
        printf("\n");
    }
    
}


void operation_sus(double **tab2d,double **tab_1, double **tab_2,int nb_ligne_tab1,int nb_colonne_tab1){
    int i, j;
    
    for(i = 0; i < nb_ligne_tab1; i++){

        for(j = 0; j < nb_ligne_tab1;j++){
            tab2d[i][j] = sus_operation(tab_1,tab_2,i,j);
        }
    }
}

double** tab_res_add_sus(double **tab_1, double **tab_2, int nb_ligne_tab1, int nb_colonne_tab1, int nb_ligne_tab2,int nb_colonne2,int nb_operation){
    int i,j;
    double **tab2d = res_tab(nb_ligne_tab1,nb_colonne_tab1);
    
    affichage_tab1(tab_1,nb_ligne_tab1,nb_colonne_tab1);
    
    printf("tab1 \n");
    printf("\n");
    
    affichage_tab1(tab_2,nb_ligne_tab2,nb_colonne2);
    
    printf("tab2 \n");
    printf("\n");
    if(nb_operation == 1){
        operation_add(tab2d,tab_1,tab_2,nb_ligne_tab1,nb_colonne_tab1);
    }
    else if(nb_operation == 2){
        operation_sus(tab2d,tab_1,tab_2,nb_ligne_tab2,nb_colonne2);
        
    }
    
            
    
    return tab2d;
}

double multiplication_opertaiton(double **tab_1, double **tab_2, int i, int j,int nb_colonne_tab1){
    double res = 0;
    int p;
    for(p = 0; p < nb_colonne_tab1; p++){
        
        res += tab_1[i][p] * tab_2[p][j];
    }
        
     
    return res;
}

void operation_mul(double** tab2d,double** tab_1,double **tab_2,int nb_ligne_tab1, int nb_colonne_tab1){
    
    int i,j;
    for(i = 0; i < nb_ligne_tab1; i++){
        
        for(j = 0; j < nb_colonne_tab1; j++){
            tab2d[i][j] = multiplication_opertaiton(tab_1,tab_2,i,j,nb_colonne_tab1);
             
        }
        printf("\n");
        
    }
    printf("\n");
    
}


double** tab_res_mul(double** tab_1,double **tab_2,int nb_ligne_tab1, int nb_colonne_tab1, int nb_ligne_tab2,int nb_colonne2,int nb_operation){
    double **tab2d = res_tab(nb_ligne_tab1,nb_colonne_tab1);
    int i,j;
    
    printf("tab1\n");
    affichage_tab1(tab_1,nb_ligne_tab1,nb_colonne_tab1);
    printf("\n");
    printf("tab2\n");
    affichage_tab1(tab_2,nb_ligne_tab2,nb_colonne2);
    printf("\n");
    
    operation_mul(tab2d,tab_1,tab_2,nb_ligne_tab1,nb_colonne_tab1);
    
    
    return tab2d;



}
void puissance_1(double**tab2d,double**tab_1,int nb_ligne,int nb_colonne){
    int i,j;
    
    for(i = 0; i < nb_ligne; i++){

        for(j = 0; j < nb_colonne; j++){
            tab2d[i][j] = tab_1[i][j];
        }
    }
}

void puissance_2(double**tab2d,double**tab_1,int nb_ligne,int nb_colonne){
    int j,p;
    
    for(j = 0; j < nb_ligne; j++){
        
        for(p = 0; p < nb_colonne; p++){
            
            tab2d[j][p] = multiplication_opertaiton(tab_1,tab_1,j,p,nb_colonne);
        }
    }
}

void puissance_plus2(double**tab2d,double**tab_1,double **tab2d_f,int nb_ligne,int nb_colonne,int nb_puissance){
    
    int i,j,p;
    
    for(i = 0; i < nb_ligne; i++){

        for(j = 0; j < nb_colonne; j++){

            tab2d[i][j] = tab_1[i][j];
        }
    }
    
    for(i = 0; i < nb_puissance - 1; i++){
        
        for(j = 0; j < nb_ligne; j++){
            
            for(p = 0; p < nb_colonne; p++){

                tab2d_f[j][p] = multiplication_opertaiton(tab2d,tab_1,j,p,nb_colonne);
            
            }
        }
        for(j = 0; j < nb_ligne; j++){
            for(p = 0; p < nb_colonne; p++){
                tab2d[j][p] = tab2d_f[j][p];
            }
        }
        
    }
    
}

double** tab_res_puissance(double**tab_1,int nb_ligne,int nb_colonne){
    double **tab2d = res_tab(nb_ligne,nb_colonne);
    double **tab2d_f = res_tab(nb_ligne,nb_colonne);
    int i,j,p,nb_puissance = 0;
    double res = 0;
    
    nb_puissance = entre_fois_puissance();
    if(nb_puissance == 1){
        puissance_1(tab2d,tab_1,nb_ligne,nb_colonne);
        
    }
    else if(nb_puissance == 2){
    
        puissance_2(tab2d,tab_1,nb_ligne,nb_colonne);
    }
    else{
        
        puissance_plus2(tab2d,tab_1,tab2d_f,nb_ligne,nb_colonne,nb_puissance);
        
    }

    
    return tab2d;
    
    
    
}



    

void affichage2d(double **tab, int nbLigne, int nbColonne){
    int i, j;
    for(i = 0; i < nbLigne; i++){
        for(j = 0; j < nbColonne; j++){
            printf("%f  ",tab[i][j]);
            
        }
        printf("\n");
        
    }
}


int main(void){
    int nb_ligne1 = 0, nb_colonne1 = 0,i, j,nbLigne = 0,nbColonne = 0,re_taille = 0,nb_operation = 0;

    nb_operation = quelleioperation();
    nb_ligne1 = entreznb_ligne();
    nb_colonne1 = entreznb_colonne();
    nbLigne = entreznb_ligne();
    nbColonne = entreznb_colonne();

    if(nb_operation == 1 || nb_operation == 2){
        if(nb_ligne1 != nbLigne || nb_colonne1 != nbColonne){
            re_taille = fait_pareil();
            nb_ligne1  = re_taille;
            nbLigne = re_taille;
            nb_colonne1= re_taille;
            nbColonne = re_taille;
                
            }

        }
    else if(nb_operation == 3){
        if(nb_colonne1 != nbLigne){
            re_taille = fait_pareil();
            nb_colonne1 = re_taille;
            nbLigne = re_taille;

        }
    }
    if(nb_operation == 1){
        affichage2d(tab_res_add_sus(tab1creation(nb_ligne1,nb_colonne1),tab1creation(nbLigne,nbColonne),nb_ligne1,nb_colonne1,nbLigne,nbColonne,nb_operation),nb_colonne1,nb_ligne1);
    }
    else if(nb_operation == 2){
        affichage2d(tab_res_add_sus(tab1creation(nb_ligne1,nb_colonne1),tab1creation(nbLigne,nbColonne),nb_ligne1,nb_colonne1,nbLigne,nbColonne,nb_operation),nb_colonne1,nb_ligne1);
        
        
    }
    else if(nb_operation == 3){
        affichage2d(tab_res_mul(tab1creation(nb_ligne1,nb_colonne1),tab1creation(nbLigne,nbColonne),nb_ligne1,nb_colonne1,nbLigne,nbColonne,nb_operation),nb_ligne1,nbColonne);
        
    }
    else if(nb_operation == 4){
        affichage2d(tab_res_puissance(tab1creation(nb_ligne1,nb_colonne1),nb_ligne1,nb_colonne1),nb_ligne1,nb_colonne1);
        
        
    }
    
    //testez la fonction
    //    printf("%d",entreval());
    //    printf("%d", entrezlatailles());
    //    printf("%d",vérification_operation_add_sus(1,1,1,1));
//    printf("%d",estun(tab2creation(4,4),4,4));
//    printf("%d",estnonzero(tab2creation(4,4),4,4));
//    affichage2d(tab1creation(nb_ligne1,nb_colonne1),nb_ligne1,nb_colonne1);
//    affichage2d(tab2creation(nbLigne,nbColonne),nbLigne,nbColonne);
//    affichage2d(tab_res_add_sus(tab1creation(nb_ligne1,nb_colonne1),tab2creation(nbLigne,nbColonne),nb_ligne1,nb_colonne1,nbLigne,nbColonne),nb_colonne1,nb_ligne1);
//    affichage2d(tab_res_mul(tab1creation(nb_ligne1,nb_colonne1),tab2creation(nbLigne,nbColonne),nb_ligne1,nb_colonne1,nbLigne,nbColonne,nb_operation),nb_colonne1,nbLigne);
//    multiplication_opertaiton(tab1creation(2,3),tab2creation(3,2),3,3);
//    printf("%d\n",quelleioperation());
//    affichage2d(tab_res_puissance(tab2creation(nb_ligne1,nb_colonne1),nb_ligne1,nb_colonne1),nb_ligne1,nb_colonne1);
 
    
    
    return 0;
}
