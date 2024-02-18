#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int entreznb_ligne(){
    int val;
    
    printf("entrez le nombre de ligne");
    scanf("%d",&val);
    
    return val;
}
int entreznb_colonne(){
    int val;
    
    printf("entrez le nombre de colonne");
    scanf("%d",&val);
    
    return val;
}

double entreval(){
	double val;
	printf("entrez la valeur de matrice : \n");
	scanf("%lf",&val);

	return val;
}

void swap(double *a, double *b){
    double tmp = 0;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void remplir_tab(double** tab, int nb_ligne, int nb_colonne){
    
    int i,j,nb_L,nb_C;
    nb_L = nb_ligne * 2;
    nb_C = nb_colonne * 2;
    
    for(i = 0; i < nb_L; i++){
        
        for(j = nb_C / 2; j < nb_C; j++){
            if(abs(i - j) == 3){
                tab[i][j] = 1;
            }
            else{
                tab[i][j] = 0;
            }
        }
        
    }
    
    for(i = nb_L / 2; i < nb_L; i++){
        for(j = 0; j < nb_C; j++){
            if(abs(i - j) == 3){
                tab[i][j] = 1;
            }
            else if(i == j){
                tab[i][j] = 1;
                
            }
            else{
                tab[i][j] = 0;
            }
            
            
        }
    }
    
}

double **tmp_res_matrix(int nb_ligne,int nb_colonne){
    
    int nb_L,nb_C,i;
    nb_L = nb_ligne * 2;
    nb_C = nb_colonne * 2;
    double **tab2d_f = malloc(nb_L * sizeof(double *));
    
    
    for(i = 0; i < nb_C; i++){
        tab2d_f[i] = malloc(nb_C * sizeof(double));

    }
    remplir_tab(tab2d_f,nb_ligne,nb_colonne);
    
    return tab2d_f;
    
    
}
void swap_tab(double **tab, int nb_ligne,int nb_colonne){
    int i,j,q;
    
    for(i = 0; i < nb_ligne; i++){

        for(j = 0; j < nb_colonne; j++){


                if(fabs(tab[i][j]) == 1){

                    for(q = 0; q < nb_colonne ; q ++){

                        swap(&tab[j][q], &tab[i][q]);
                    }
                
                }
            
            }
        
        }
    
}
void rangment(double** tab2d,int nb_ligne,int nb_colonne){
    
    int i,j;
    for(i = 0; i < nb_ligne; i++){
        for(j = i; j < nb_colonne; j++){
            swap(&tab2d[i][j],&tab2d[j][i]);
            }
        }
    
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

void faitun(double **tab2d, double **tmp2d,int nb_ligne,int nb_colonne){
    
    int i,j,p,s = 0;;

    double res = 0, invers_number = 0;
    
    for(i = 0; i < nb_ligne; i++){
        for(j = 0; j < nb_ligne; j++){
            
            if(i == j  && tab2d[i][j] != 1 && tab2d[i][j] != 0){
                
                for(p = 0; p < nb_colonne; p++){
                    
                    if(tab2d[i][i] < 0 ){
                        invers_number =  - 1 / tab2d[i][i];
                        tmp2d[i][p] = tab2d[i][p] * invers_number;
                        


                        }
                    
                    else if(tab2d[i][i] > 0){
                       
                        invers_number = 1 / tab2d[i][i];
                     
                        tmp2d[i][p] = tab2d[i][p] * invers_number;
                        s+=1;
            

                            }

                    }
                    

                }
                
            }
        }
    for(i = 0; i < nb_ligne; i++){
        for(j = 0; j < nb_colonne; j++){
            if(i == j && tmp2d[i][j] == -1){
                for(p = 0; p < nb_colonne; p++){
                    tmp2d[i][p] *= -1;
                }

            }


        }
    }
    
    for(i = 0; i < nb_ligne; i++){
        for(j = 0; j < nb_ligne; j++){
            if(i == j && tab2d[i][j] != 1 && tab2d[i][j] != 0 ){
                for(p = 0; p < nb_colonne; p++){
                    
                    tab2d[j][p] = tmp2d[j][p];
                    
                    }
            }
        }
    }
}


    


int estun(double **tab_1,int nb_ligne,int nb_colonne){
    int i,j,s = 0;

    for(i = 0; i < nb_ligne; i++){
        for(j = 0; j < nb_colonne; j++){
            if(i == j && tab_1[i][j] == 1){
                s +=1;
            }

            }

        }
    if(s == nb_colonne){
        return 1;
    }
    return 0;

    }
//1,0,3 0,1,2 0.5,-0.375,1
void opération_inverse(double **tab2d, int nb_ligne, int nb_colonne){
    int i,j,q,res_nb_colonne;
    double **tmp = tmp_res_matrix(nb_ligne,nb_colonne);
    double **tmp2 = tmp_res_matrix(nb_ligne,nb_colonne);
    res_nb_colonne = nb_colonne * 2;
    for(i = 0; i < nb_ligne; i++){
        
        for(j = 0; j < nb_colonne; j++){
         
            
            if(i!=j){
            
                
                    for(q = 0; q < res_nb_colonne; q++){
//
                        tmp[q][j] = tab2d[q][j] - (tab2d[i][j] * tab2d[q][i]);
                        faitun(tmp,tmp2,nb_ligne,nb_colonne);
                       
//
                    }
               
            
            }
            
        }
       
    }
   
    for(i = 0; i < res_nb_colonne; i++){
        for(j = 0; j < nb_ligne; j++){
            
            
            tab2d[i][j] = tmp[i][j];
        }
        
    }
    for(i = 0; i < nb_ligne; i++){
        printf("{");
        for(j = 0; j < nb_colonne; j++){
            printf("%.0f ,",tab2d[i][j]);
        }
        printf("}\n");
        printf("\n");
    }


}

double **res_tab(int nb_ligne,int nb_colonne){
    double **tab_utilisateur = tab1creation(nb_ligne,nb_colonne);
    double **tab_calcul = tmp_res_matrix(nb_ligne,nb_colonne);
    int i,j,res_nb_ligne,res_nb_colonne;
    res_nb_ligne = nb_ligne * 2;
    res_nb_colonne = res_nb_colonne * 2;
    
    for(i = 0; i < nb_ligne; i++){
        for(j = 0; j < nb_colonne; j++){
            
            tab_calcul[i][j] = tab_utilisateur[i][j];
            
        }
    }
    swap_tab(tab_calcul,nb_ligne,nb_colonne);
    rangment(tab_calcul,res_nb_ligne,res_nb_colonne);
    opération_inverse(tab_calcul,nb_ligne,nb_colonne);
    return tab_calcul;
    
    
}

int main(void){
	int i,j,res,nb_colonne, nb_ligne;
    nb_ligne = entreznb_ligne();
    nb_colonne = entreznb_colonne();
    res = nb_colonne * 2;
//    double**tab1 = tab1creation(3,3);
    double**tab3 = res_tab(nb_ligne,nb_colonne);
//    remplir_tab(tab1,3,3);
    
//    opération_inverse(tab1,nb_ligne,nb_colonne);

    

    for(i = 0; i < res; i++){
        for(j = 0; j < res; j++){

            printf("%.f  ",tab3[i][j]);
        }
        printf("\n");
    }

	 return 0;
}
