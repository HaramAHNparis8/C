#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define nb_taile 5
//exercices 1-1

int entreztaille(){
	int n = 0;
	printf("entrez la taille \n");
	scanf("%d",&n);
	return n;
}

int entrezlaval(){
	int val = 0;
	printf("entrez la valeur de tableau \n");
	scanf("%d",&val);

	return val;
}

void affichage(){
    int taille = 0, i;
    
    taille = entreztaille();
    
    int* tab = malloc(taille * sizeof(int));
    
    for(i = 0; i < taille; i++){
        tab[i] = entrezlaval();
    }
    
    for(i = 0; i < taille; i++){
        
        printf("%d  ",tab[i]);
    }


}

//exercies 1-2

int *affiche_miroir(int* tab, int nb_taile){
    int i, j = 0;
    
    int* tab_nouveau = malloc(nb_taile * sizeof(int));
    for(i = nb_taile - 1; i >=0; i--){
        tab_nouveau[j] = tab[i];
        j++;
    }
    return tab_nouveau;
}

//exercices 1-3

int combien_positif(int* tab, int taille){
    int res = 0, i;
    
    for(i = 0; i < taille; i++){
        if(tab[i] >= 0){
            res++;
        }
    }
    
    return res;
}

int *constitu_tab(int* tab, int taille){
    int n = combien_positif(tab, taille);
    int j = 0;
    int* tab_re_con = malloc(n * sizeof(int));
    if(taille == 0){
        exit(0);
    }
 
    for(int i = 0; i < taille; i++){
        if(tab[i] >= 0){
            tab_re_con[j] = tab[i];
            j++;
            
        }
    }
    
    return tab_re_con;
}

char *chiffrement_Cesar(char* tab, int taille, int k){
    int i;
    char *res = malloc(taille * sizeof(char));
    for(i = 0; i < taille; i++){
        res[i] = tab[i] + k;
    }
    
    return res;
    
}
// exercices2


typedef struct tableau{
    
    int taille;
    int *tableau;
    
}tableau;

tableau creationtab(tableau t){
    int i;
    tableau res;
    res.taille = t.taille;
    res.tableau = malloc(res.taille * sizeof(int));
    
    for(i = 0; i < res.taille; i++){
        res.tableau[i] = i + 1;
    }
    return res;
    
}


void echange(int* a, int* b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    
}

void tri(tableau t){
    
    int i,j;
    
    for(i = 0; i < t.taille;i++){
        
        for(j = 0; j < t.taille; j++){

            if(t.tableau[i] < t.tableau[j]){
                echange(&t.tableau[i],&t.tableau[j]);
            }
        }
    }
    
}

tableau tri_à_bulles(tableau t){
    tableau res;
    res.tableau = malloc(res.taille * sizeof(int));
    res.taille = t.taille;
    tri(t);
    int i;
    
    for(i = 0; i < t.taille; i++){
        res.tableau[i] = t.tableau[i];
    }
    return res;
    
}


int est_trie(tableau t){
    int i,val;

    val = t.tableau[0];
    for(i = 0; i < t.taille; i++){
        if(val > t.tableau[i]){
            
            return 0;
        }
        val = t.tableau[i];
    }
    
    return 1;
    
}

void insère_element(tableau t){
    int i,j,tmp;
    
    for(i = 0; i < t.taille; i++){
        tmp = t.tableau[i];
        j = i - 1;
        while (j >= 0 && t.tableau[j] > tmp){
            t.tableau[j + 1] = t.tableau[j];
            j--;
        }
        t.tableau[j + 1] = tmp;
    }

    
}

tableau tableau_insère_x(tableau t){
    tableau res;
    res.tableau = malloc(res.taille * sizeof(int));
    res.taille = t.taille;
    insère_element(t);
    
    int i;
    
    for(i = 0; i < t.taille; i++){
        res.tableau[i] = t.tableau[i];
    }
    return res;

}

void affichage_tab_int(tableau t){
    int i;
    
    for(i = 0; i < t.taille; i++){
        printf("%d  ", t.tableau[i]);
    }
    return;
}

//exercices 3




void liberer2d(int **tab, int nbligne, int nbcolonne){
    
    int i;
    
    for(i = 0; i < nbcolonne; i++){
        free(tab[i]);
    }
    free(tab);
    
}

void colonne(int **tab, int j, int nbcolonne){
    int i;
    
    for(i = 0; i < nbcolonne; i++){
        printf("%d  ", tab[j][i]);
    }
    
}
int** tab2D(int **tab, int nbligne, int nbcolonne){
    int **tab2d = malloc(nbligne * sizeof(int*));
    int i,j;
    for(i = 0; i < nbligne; i++){
        tab2d[i] = malloc(nbcolonne * sizeof(int));
    }
    
    for(i = 0; i < nbligne; i++){
        for(j = 0; j < nbcolonne; j++){
            if(tab[i][j] % 2 == 0){
                tab2d[i][j] = tab[i][j];
            }
            else{
                tab[i][j] = 0;
                tab2d[i][j] = tab[i][j];
            }
        }
    }
    return tab2d;
}
int sum(int* a){
    int res=0;
    res += *a;
    
    return res;
}

int** tab2d_plus_co(int **tab, int nbligne, int nbcolonne){
    int **tab2d = malloc(nbligne * sizeof(int*));
    int i,j, res = 0,taille = 0;
    taille = nbcolonne + 1;
    for(i = 0; i < nbligne; i++){
        tab2d[i] = malloc(taille * sizeof(int));
    }
    for(i = 0; i < nbligne; i++){

        for(j = 0; j < nbcolonne; j++){

            tab2d[i][j] = tab[i][j];
        }
    }
    
    for(i = 0; i < nbligne; i++){
        for(j = 0; j <= nbcolonne; j++){
            res += tab2d[i][j];
            if(j == nbcolonne){
                tab2d[i][j] = res;
            }
        }
    }

    return tab2d;
}

void affichage2d(int **tab,int nbLigne, int nbColonne){
    int i, j;
    
    for(i = 0; i < nbLigne; i++){
        for(j = 0; j <= nbColonne; j++){
            printf("%d  ",tab[i][j]);
            
        }
        printf("\n");
    }
    
}

//exercices3

typedef struct{
    int degree;
    int *coef;
} polynome;

int entrezlavaldegre(){
    int n = 0;
    printf("entrez la valeur de degree :");
    scanf("%d", &n);
    
    return n;
    
}
int entrezlavaldecoef(){
    int n = 0;
    printf("entrez la valeur de coef dans l'ordre croissant :");
    scanf("%d", &n);
    
    return n;
}

polynome saisie_polynome(polynome p){
    int i,taille = 0;
    
    polynome res;
    p.degree = entrezlavaldegre();
    res.degree = p.degree;
    taille = res.degree + 1;
    
    res.coef = malloc(taille * sizeof(int));
    
    for(i = 0; i < taille; i++){
        res.coef[i] = entrezlavaldecoef();
    }
    
    return res;
    
    
}
polynome somme_polynome(polynome P, polynome Q){
    polynome res;
    int i,taille;
    taille = P.degree + 1;
    res.coef = malloc(taille * sizeof(int));
    
    for(i = 0; i < taille; i++){
        res.coef[i] = P.coef[i] + Q.coef[i];
    }
    return res;
    
}

void affichage_polynome(polynome p){
    int i;
    for(i = 0; i < p.degree + 1; i++){
        if(i == 0){
            printf("P(X) = %d ", p.coef[0]);
        }
        else{
            printf("+%dx^%d ",p.coef[i],i);
        }
    }
    
}

//j'ai pas bien compris exercies 4 - 5. Écrireunefonctionvoid derivee(polynome *P)quiprendenparamètreunpointeur sur polynome, et qui change la variable contenue à l'adresse P en le polynôme dérivé du précédent.
//alors j'ai sauté cet exercice désolé.
int valeurtaille(){
    int n = 0;
    printf("choissez la taille de plateau");
    scanf("%d",&n);
    return n;
}

typedef struct{
    char* tabl;
    int nbligne_e;
    int nbcolonne_e;
} board;


void affiche_board(board b, char**tab, char* eche){//la fonction pour afficher le bord.
    int i, j;
    for(i = 0; i < b.nbligne_e; i++){
        for(j = 0; j < b.nbcolonne_e; j++){
            tab[i][j] = eche[0];
        }
    }
    for(i = 0; i < b.nbligne_e; i++){
        for(j = 0; j < b.nbcolonne_e; j++){
            printf("%c",tab[i][j]);
        }
        printf("\n");
    }
    
}


void affiche_board_enu(board b,char**tab ,char* eche){

    int i, j;
    for(i = 0; i < b.nbligne_e; i++){
        for(j = 0; j < b.nbcolonne_e; j++){
            if(i == 0 && j == 0|| i == 0 && j == 7 || i == 7 && j == 0 || i == 7 &&
               j == 7){
                tab[i][j] = eche[2];
            }
            else if(i == 0 && j == 1|| i == 0 && j == 6 || i == 7 && j == 1 || i ==7  &&
                    j == 6){
                tab[i][j] = eche[3];
            }
            else if(i == 0 && j == 2|| i == 0 && j == 5 || i == 7 && j == 2 || i ==7  &&
                    j == 5){
                tab[i][j] = eche[4];
            }
            else if(i == 0 && j == 3|| i == 7 && j == 3){
                tab[i][j] = eche[6];
            }
            else if(i == 0 && j == 4|| i == 7 && j == 4){
                tab[i][j] = eche[5];
            }
            else if(i == 1 || i == 6){
                tab[i][j] = eche[1];
                
            }
            else{
                tab[i][j] = eche[0];
            }
    }
}
        for(i = 0; i < b.nbligne_e; i++){
            for(j = 0; j < b.nbcolonne_e; j++){
                printf("%c  ",tab[i][j]);
            }
            printf("\n");
        }

}


int entre_nb_ligne(){
    int n;
    printf("entrez la valeur de ligne");
    scanf("%d",&n);
    return n;
}
void change(char* a, char* b){
    char tmp;
    tmp = *a;
    *b = *a;
    *a = tmp;
}

int king(int n){
    while(1){
        printf("le rois ne bouge pas comme ça c'est hors-limite\n re-entrez la val ");
        scanf("%d", &n);
        if(n <= 1){
            return n;
        }
    }
}
int queen(int n,board b){
    while(1){
        printf("la reine ne bouge pas comme ça c'est hors-limite\n re-entrez la val ");
        scanf("%d", &n);
        if(n < b.nbligne_e){
            return n;
        }
    }
}
int rook(int n, board b){
    while(1){
        printf("rook ne bouge pas comme ça c'est hors-limite\n re-entrez la val ");
        scanf("%d", &n);
        if(n < b.nbligne_e){
            return n;
        }
    }
        
    }

int pont(int n){
    while(1){
        if(n == 1){
            printf("pont ne bouge pas comme ça c'est hors-limite\n re-entrez la val ");
            scanf("%d", &n);
            return n;
            
        }
    }
}

int bouge_eche(){
    int n;
    printf("entrez la val");
    scanf("%d", &n);
    
    return n;
}
char entre(){
    char n;
    printf("entrez le nom de la eche par exemple pont est p\n");
    scanf("%c",&n);
    return n;
    
}

void ajouter_piece(char** tab, board b){
    char n;
    int linge = 0,colonne = 0, bg_i = 0, bg_j = 0, i,j;
    n = entre();
    
    if(n == 'p'){
        printf("choissez ligne et colonne situé pont");
        linge = bouge_eche();
        colonne = bouge_eche();
        bg_i = bouge_eche();
        bg_j = bouge_eche();
        change(&tab[linge][colonne],&tab[bg_i][bg_j]);
        
    }
    


}

void affichage_ajoute_piece(char** tab, board b){
    ajouter_piece(tab, b);
    int i,j;
    for(i = 0; i < b.nbligne_e; i++){
        for(j = 0; j < b.nbcolonne_e; j++){
            printf("%c  ", tab[i][j]);
            
        }
        printf("\n");
    }
    
}








int main(void){
    int i,j ,nbligne = 5, nbcolonne = 4, taille;
	//printf("%d",entreztaille());
	//printf("%d",entrezlaval());
    //affichage();
    
    // exercices 1-2
//    int v[5] = {1,2,3,4,5};
//
//    int *tab_miroir = affiche_miroir(v,5);
//
//    for(i = 0; i < 5; i++){
//        printf("%d  ",tab_miroir[i]);
//    }
    // exercices 1-3
    
//    int tab_v[5] = {1,2,0,2,5};
//    printf("%d\n", combien_positif(tab_v,5));
//    int tab_t = combien_positif(tab_v,5);
//    int *tab_v_p = constitu_tab(tab_v,5);
//
//    for(i = 0; i < tab_t; i++){
//        printf("%d  ", tab_v_p[i]);
//    }
//    char tab_char[12] = {'a','b','c','d','p','s','e','s','p','o','i','r','\0'};
    
//    char tab_char = "abcdpsepoir";
//    int combien_tail_char = 12;
//    printf("%d",combien_tail_char);
//    char* tab_char_re = chiffrement_Cesar(tab_char,combien_tail_char,6);
//    for(i = 0; i < combien_tail_char; i++){
//        printf("%c",tab_char_re[i]);
//    }
    
// exercices 2
//    tableau t;
//    t.taille = 5;
//    t.tableau = malloc(t.taille * sizeof(int));
//    for (int i=0;i<t.taille;i++){
//
//    t.tableau[i] = 6 - i;
//    }
//    affichage_tab_int(creationtab(t));
//    for(i = 0; i < 5; i++){
//        for(j = 0; j < 5; j++){
//            if(tab_v[i] < tab_v[j]){
//
//                echange(&tab_v[i],&tab_v[j]);
//            }
//        }
//    }
//    for(i = 0; i < 5; i++){
//        printf("%d  ", tab_v[i]);
//    }
//    affichage_tab_int(tri_à_bulles(t));
//    printf("%d\n",est_trie(creationtab(t)));
//    printf("\n%d",est_trie(tri_à_bulles(t)));
//    insère_element(t);
//    affichage_tab_int(tableau_insère_x(t));
// exercices 3
//    int **tab = malloc(nbligne*sizeof(int*));
//    for(i = 0; i <nbligne; i++){
//        tab[i] = malloc(nbcolonne * sizeof(int));
//    }
//    for(i = 0; i < nbligne; i++){
//        for(j = 0; j < nbcolonne; j++){
//            tab[i][j] = i + j;
//        }
//    }
//    affichage2d(tab,nbligne,nbcolonne);
//    liberer2d(tab,nbligne,nbcolonne);
//    colonne(tab,2,nbcolonne);
//    affichage2d(tab2D(tab,nbligne,nbcolonne),nbligne,nbcolonne);
//    affichage2d(tab2d_plus_co(tab,nbligne,nbcolonne),nbligne,nbcolonne);

//exercices4
//    polynome p;
//    affichage_polynome(saisie_polynome(p));
    
//    polynome res;
//    res.degree = entrezlavaldegre();
//    taille = res.degree + 1;
//
//    res.coef = malloc(taille * sizeof(int));
//
//    for(i = 0; i < taille; i++){
//        res.coef[i] = entrezlavaldecoef();
//    }
//
//    taille = 0;
//
//    polynome sec;
//    sec.degree = entrezlavaldegre();
//    taille = sec.degree + 1;
//    sec.coef = malloc(taille * sizeof(int));
//    for(i = 0; i < taille; i++){
//        sec.coef[i] = entrezlavaldecoef();
//    }
//    affichage_polynome(res);
//    printf("\n");
//    affichage_polynome(sec);
//
//    affichage_polynome(somme_polynome(res,sec));
    
//exercices 5
    board b;
    char echec[7] = {'.','P','T','F','C','K','R'};
    b.nbligne_e = valeurtaille();//entrez la valeur 8
    b.nbcolonne_e = valeurtaille();//entrez la valeur 8
    char **tab = malloc(b.nbligne_e * sizeof(char*));
    for(i = 0; i < b.nbligne_e; i++){
        tab[i] = malloc(b.nbcolonne_e * sizeof(char));
        
    }
    //    affiche_board(b,tab,echec);
//    affiche_board_enu(b,tab,echec);
    
    for(i = 0; i < b.nbligne_e; i++){
        for(j = 0; j < b.nbcolonne_e; j++){
           
            if(i == 0 && j == 0|| i == 0 && j == 7 || i == 7 && j == 0 || i == 7 &&
               j == 7){

                tab[i][j] = echec[2];
            }
//            printf("i initial : %d, j initial : %d\n %c\n", i,j,tab[i][j]);
            else if(i == 0 && j == 1|| i == 0 && j == 6 || i == 7 && j == 1 || i ==7  &&
                    j == 6){
                tab[i][j] = echec[3];
            }
            else if(i == 0 && j == 2|| i == 0 && j == 5 || i == 7 && j == 2 || i ==7  &&
                    j == 5){
                tab[i][j] = echec[4];
            }
            else if(i == 0 && j == 3|| i == 7 && j == 3){
                tab[i][j] = echec[6];
            }
            else if(i == 0 && j == 4|| i == 7 && j == 4){
                tab[i][j] = echec[5];
            }
            else if(i == 1 || i == 6){
                tab[i][j] = echec[1];

            }
            else{
                tab[i][j] = echec[0];
            }
            

        }
    }
//    affichage_test(tab);
//    king(3);
//    queen(10,b);
    ajouter_piece(tab,b);

   
    
    return 0;
}
