#include<stdio.h>

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
