#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

/* Déclaration de la structure liste chaînée */
typedef struct Element Element;
struct Element{
    int nombre;
    Element *suivant;
};


typedef struct Liste{
    Element *premier;
}Liste;

/* Fonction d'initialisation */
Liste *initialisation(int nbr) {
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));
    if (liste == NULL || element == NULL){
        exit(EXIT_FAILURE);
    }
    element->nombre = nbr;
    element->suivant = NULL;
    liste->premier = element;
    return liste;
}

/* Fonction d'affichage */
void afficherListe(Liste *liste){
    if (liste == NULL)
        exit(EXIT_FAILURE);
    Element *actuel = liste->premier;
    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

/* Fonction de copie d'une liste chaînée */
Liste copy_list(Liste l){
    Element *actuel=l.premier;
    Liste temp;
    temp.premier = malloc(sizeof(Element*));
    Element *prem=temp.premier;
    prem->nombre=actuel->nombre;
    while (actuel->suivant != NULL){
        prem->suivant=malloc(sizeof(Element*));
        actuel = actuel->suivant;
        prem=prem->suivant;
        prem->nombre=actuel->nombre;
    }
    return temp;
}


/* Exercice 1 - Fonctions d'insertion au début puis à la fin, de suppression
au début puis à la fin. Attention, ces fonctions utilisent du passage par adresse;
elles ne renvoient pas une liste mais modifient la liste passée en argument. */
void insertion(Liste *liste, int nvNombre){
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
        exit(EXIT_FAILURE);
    nouveau->nombre = nvNombre;
    /* Insertion de l'element au debut */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void insertion_fin(Liste *liste, int nvNombre){
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
        exit(EXIT_FAILURE);
    nouveau->nombre = nvNombre;
    Element *prem = liste->premier;
    while (prem->suivant != NULL){
        prem = prem->suivant;
    }
    nouveau->suivant=prem->suivant;
    prem->suivant = nouveau;
}

void suppression(Liste *liste){
    if (liste == NULL)
        exit(EXIT_FAILURE);
    if (liste->premier != NULL){
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

void suppression_fin(Liste *liste){
    if (liste == NULL)
        exit(EXIT_FAILURE);
    Element *prem = liste->premier;
    while (prem->suivant->suivant != NULL){
        prem=prem->suivant;
    }
    prem->suivant=NULL;
    free(prem->suivant);
}

/* Exercice 2 */
/* La fonction cons correspond à la fonction d'insertion d'un élément au début. */
void cons(int nvNombre, Liste *liste){
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
        exit(EXIT_FAILURE);
    nouveau->nombre = nvNombre;
    /* Insertion de l'element au debut */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

int car(Liste *liste){
    if (liste== NULL){
        printf("La liste est vide et n'a pas de premier élément. \n");
        exit(EXIT_FAILURE);
    }
    return liste->premier->nombre;
}

/* La fonction cdr revient à supprimer l'élément en début de liste, donc elle est déjà écrite -- mais cette
fois on veut une fonction qui renvoie une liste, et ne pas modifier la liste de départ ! Pour se faire,
il faut travailler sur une copie de la liste dont l'adresse est passée en paramètre -> voir la fonction
cdr_copie. La fonction cdr_modif réalise la modification de la liste à l'adresse passée en paramètre. 
--> Pour appeler cdr_modif, on utilise cdr_modif(maListe), et maListe sera modifiée.
--> Pour appeler cdr_copie, on utilise Liste *reste = cdr_copie(maListe);
On aura alors deux listes : maListe qui est toujours l'originale, puis reste qui est une autre liste
contenant le reste de maListe.
*/

void cdr_modif(Liste *liste){
    if (liste == NULL)
        exit(EXIT_FAILURE);
    if (liste->premier != NULL){
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

Liste *cdr_copie(Liste *l){
    Liste copie=copy_list(*l);
    if (copie.premier == NULL){
        exit(EXIT_FAILURE);
    }
    else{
        Element *aSupprimer=copie.premier;
        copie.premier=copie.premier->suivant;
        free(aSupprimer);
    }
    Liste *res=&copie;
    return res;
}

Liste *append(Liste *l1, Liste *l2){
    if (l1 == NULL){
        return l2;
    }
    /* Si on ne veut pas modifier la liste contenue à l'adresse l1, il faut
    travailler avec une copie de la première liste. */
    Liste copie_first=copy_list(*l1);
    Liste *concat=&copie_first;
    Element *prem=concat->premier;
    while (prem->suivant != NULL){
        prem=prem->suivant;
    }
    prem->suivant=l2->premier;
    return concat;
}

/* Exercice 3 */
Liste *miroir(Liste *l){
    if (l->premier == NULL){
        return NULL;
    }
    Liste *debut = initialisation(car(l));
    /* Si on ne veut pas modifier la liste à l'adresse l, il faut utiliser une copie */
    Liste *reste=cdr_copie(l);
    if (reste->premier==NULL){
        return debut;
    }
    else{
        Liste *res = append(miroir(reste),debut);
        return res;
    }
}

Liste *neg_to_pos(Liste *l){
    if (l->premier==NULL){
        return NULL;
    }
    Liste *debut = initialisation(abs(car(l)));
    /* Si on ne veut pas modifier la liste à l'adresse l, il faut utiliser une copie */
    Liste *reste = cdr_copie(l);
    if (reste->premier==NULL){
       return debut;
    }
    else{
        Liste *res = append(debut,neg_to_pos(reste));
        return res;
    }
}

/* Exercice 4 */
Liste *array_to_list(int *tab, int taille){
    Liste *res=initialisation(tab[0]);
    Element *prem=res->premier;
    for (int i=1;i<taille;i++){
        prem->suivant=malloc(sizeof(Element*));
        prem=prem->suivant;
        prem->nombre=tab[i];
    }
    return res;
}

int *list_to_array(Liste *l){
    /* On doit commencer par compter le nombre d'éléments de l, pour l'allocation
    dynamique de la taille du tableau */
    int nb_elem=0;
    Element *actuel=l->premier;
    while(actuel !=NULL){
        actuel=actuel->suivant;
        nb_elem++;
    }
    actuel=l->premier;
    int *res=malloc(nb_elem*sizeof(int));
    for (int i=0;i<nb_elem;i++){
        res[i]=actuel->nombre;
        actuel=actuel->suivant;
    }
    return res;
}

void afficher_tab(int *tab, int taille){
    for (int i=0;i<taille;i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
}

/* Fonction de tri à bulle */
int *tri_bulle(int *tab, int taille){
    int *tri=malloc(taille*sizeof(int));
    for (int i=0;i<taille;i++){
        tri[i]=tab[i];
    }
    int changement=1;
    int aux;
    while (changement>0){
        changement=0;
        for (int i=0;i<taille-1;i++){
            if (tri[i]>tri[i+1]){
                aux=tri[i];
                tri[i]=tri[i+1];
                tri[i+1]=aux;
                changement+=1;
            }
        }
    }
    return tri;
}

Liste *list_sort(Liste *l){
    Liste copie=copy_list(*l);
    Liste *add_copie=&copie;
    /* On doit aussi retrouver le nombre d'éléments pour connaître la taille du tableau */
    int nb_elem=0;
    Element *actuel=l->premier;
    while(actuel !=NULL){
        actuel=actuel->suivant;
        nb_elem++;
    }
    int *tab=tri_bulle(list_to_array(add_copie),nb_elem);
    Liste *liste_sorted=array_to_list(tab,nb_elem);
    return liste_sorted;
}

/* Exercice 5 - Listes doublement chaînées */
typedef struct DbElement DbElement;
struct DbElement{
    int nombre;
    DbElement *suivant;
    DbElement *precedent;
};


typedef struct DbListe{
    DbElement *premier;
    DbElement *dernier;
}DbListe;

/* Fonction d'initialisation */
DbListe *initialisation_db(int nbr) {
    DbListe *liste = malloc(sizeof(*liste));
    DbElement *element = malloc(sizeof(*element));
    if (liste == NULL || element == NULL){
        exit(EXIT_FAILURE);
    }
    element->nombre = nbr;
    element->suivant = NULL;
    element->precedent = NULL;
    liste->premier = element;
    liste->dernier = NULL;
    return liste;
}

/* Fonction d'affichage */
void afficherListe_db(DbListe *liste){
    if (liste == NULL)
        exit(EXIT_FAILURE);
    DbElement *actuel = liste->premier;
    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

/* Insertion en début de liste : l'élément précédent l'ancien premier devient le nouveau; sinon
tout est comme avant */
void insertion_db(DbListe *liste, int nvNombre){
    DbElement *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
        exit(EXIT_FAILURE);
    nouveau->nombre = nvNombre;
    /* Insertion de l'element au debut */
    liste->premier->precedent = nouveau;
    nouveau->suivant = liste->premier;
    liste->premier=nouveau;
}

/* Ici, il suffit de dire que l'élément précédant le nouveau est le dernier de la liste, 
autrement dit le dernier qu'on parcourt dans la boucle while. */
void insertion_fin_db(DbListe *liste, int nvNombre){
    DbElement *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
        exit(EXIT_FAILURE);
    nouveau->nombre = nvNombre;
    DbElement *prem = liste->premier;
    while (prem->suivant != NULL){
        prem = prem->suivant;
    }
    nouveau->precedent=prem;
    prem->suivant = nouveau;
    nouveau->suivant=NULL;
    liste->dernier=nouveau;
}

/* La suppression en tête de liste est similaire, il faut juste ajouter que l'élément précédant le
suivant du premier vaut NULL */
void suppression_db(DbListe *liste){
    if (liste == NULL)
        exit(EXIT_FAILURE);
    if (liste->premier != NULL){
        DbElement *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        liste->premier->precedent = NULL;
        free(aSupprimer);
    }
}

/* Pour la suppression en fin de liste, rien à modifier concernant les éléments précédents: le pointeur
vers le précédent du dernier sera conservé même si ce dernier devient NULL. */
void suppression_fin_db(DbListe *liste){
    if (liste == NULL)
        exit(EXIT_FAILURE);
    DbElement *prem = liste->premier;
    while (prem->suivant->suivant != NULL){
        prem=prem->suivant;
    }
    liste->dernier=prem;
    prem->suivant=NULL;
    free(prem->suivant);
}

/* Exercice 6 - Arbres binaires */

/* On crée la structure adaptée à un arbre binaire : un arbre binaire est composé d'une racine, entière, et
de deux fils -- gauche et droit. On va donc avoir un champ pour la racine, puis un pointeur vers le fils
gauche et un pointeur vers le fils droit. */ 

typedef struct BTree BTree;
struct BTree{
    int root;
    BTree *left;
    BTree *right;
};

// Question 1
BTree *init_tree(int nb){
    BTree *tree=malloc(sizeof(*tree));
    if (tree == NULL){
        exit(EXIT_FAILURE);
    }
    tree->root = nb;
    tree->left = NULL;
    tree->right=NULL;
    return tree;
}

// Question 2
void affichage_Btree(BTree *T){
    if (T == NULL){
        printf("NULL");
    }
    BTree *filsg=T->left;
    BTree *filsd=T->right;
    printf("(%d ",T->root);
    if (filsg == NULL)
        printf(" () ");
    else 
        affichage_Btree(filsg);
    if (filsd == NULL)
        printf(" () ");
    else
        affichage_Btree(filsd);
    printf(") ");
}

// Question 3
void insert_tree(BTree *T, int nvNombre, int gd){
    BTree *feuille=init_tree(nvNombre);
    if (gd==0){
        while (T->left != NULL){
            T=T->left;
        }
        T->left=feuille;
    }
    else{
        while (T->right != NULL){
            T=T->right;
        }
        T->right=feuille;
    }
}

// Question 4
BTree *attache_arbre(int racine, BTree *filsg, BTree *filsd){
    BTree *res = malloc(sizeof(*res));
    res->root = racine;
    res->left=filsg;
    res->right=filsd;
    return res;
}

// Question 5
int nb_noeuds(BTree *T){
    if (T==NULL){
        return 0;
    }
    else{
        return 1+nb_noeuds(T->left)+nb_noeuds(T->right);
    }
}

// Question 6
int somme_noeuds(BTree *T){
    if (T==NULL){
        return 0;
    }
    else{
        return T->root+somme_noeuds(T->left)+somme_noeuds(T->right);
    }
}

// Question 7
int somme_feuilles(BTree *T){
    if ((T->left == NULL) && (T->right == NULL)){
        return T->root;
    }
    else if (T->left == NULL){
        return somme_feuilles(T->right);
    }
    else if (T->right == NULL){
        return somme_feuilles(T->left);
    }
    else{
        return somme_feuilles(T->left)+somme_feuilles(T->right);
    }
}

// Question 8
int max(int a, int b){
    if (a>=b)
        return a;
    else 
        return b;
}

int hauteur(BTree *T){
    if (T == NULL){
        return 0;
    }
    else{
        return 1+max(hauteur(T->left),hauteur(T->right));
    }
}

// Question 9
int est_abr(BTree *T){
    int res;
    if (T == NULL)
        return 0;
    else if ((T->left == NULL) && (T->right == NULL)){
        return 1;
    }
    else if (T->left == NULL){
        res=((T->root < T->right->root) && est_abr(T->right));
        return res;
    }
    else if (T->right == NULL){
        res=((T->root > T->left->root) && est_abr(T->left));
    }
    else{
        res=((T->root < T->right->root) && est_abr(T->right)\
         && (T->root > T->left->root) && est_abr(T->left));
        return res;
    }
}

// Question 10
BTree* insertion_abr(BTree *T, int x){
    if (T==NULL){
        return attache_arbre(x,NULL,NULL);
    }
    if (x>T->root){
        return attache_arbre(T->root,T->left,insertion_abr(T->right,x));
    }
    if (x < T->root){
        return attache_arbre(T->root,insertion_abr(T->left,x),T->right);
    }
}

// A debuguer
void insertion_abr2(BTree *T, int x){
    BTree *arbre;
    if (T==NULL){
        arbre=malloc(sizeof(BTree*));
        arbre->root=x;
        arbre->left=NULL;
        arbre->right=NULL;
        *T=*arbre;
    }
    else if(x < arbre->root){
        arbre=arbre->left;
        insertion_abr2(arbre,x);
    }
    else if (x > arbre->root){
        arbre=arbre->right;
        insertion_abr2(arbre,x);
    }
}

int main(){
    /* Tests Exercice 1 
    Liste *maListe = initialisation(0);
    insertion(maListe, 4);
    insertion(maListe, -8);
    insertion(maListe, 15);
    insertion(maListe, -11);
    insertion(maListe, -7);
    insertion(maListe, 14);
    insertion_fin(maListe,21);
    insertion_fin(maListe,13);
    suppression(maListe);
    suppression_fin(maListe);
    //afficherListe(maListe);
*/
    /* Tests Exercice 2  
    cons(-4,maListe);
    afficherListe(maListe);
    int prem=car(maListe);
    printf("Premier élément : %d \n",prem);
    afficherListe(maListe);
    cdr_modif(maListe);
    Liste *reste=cdr_copie(maListe);
    afficherListe(maListe);
    afficherListe(reste);
*/
    /* Tests Exercice 3
    Liste *maListe2 = initialisation(0);
    cons(2,maListe2);
    cons(-6,maListe2);
    afficherListe(maListe);
    afficherListe(maListe2);
    Liste *fusion = append(maListe,maListe2);

    afficherListe(fusion); 
    Liste *rev=miroir(fusion);
    afficherListe(rev);
    afficherListe(fusion); 

    Liste *neg=neg_to_pos(fusion);
    afficherListe(neg);
    afficherListe(fusion); 
*/

    /* Tests Exercice 4 
    int tab[10]={3,18,7,12,46,25,87,54,13,17};
    Liste *list=array_to_list(tab,10);
    afficherListe(list);
    int *array=list_to_array(list);
    afficher_tab(tab,10);
    afficher_tab(array,10);
    afficherListe(list);

    int *tri=tri_bulle(tab,10);
    afficher_tab(tri,10);

    Liste *sort=list_sort(list);
    afficherListe(sort);
    */

    /* Tests Exercice 5 
    DbListe *maListe=initialisation_db(0);
    afficherListe_db(maListe);
    insertion_db(maListe,11);
    insertion_db(maListe,8);
    insertion_db(maListe,5);
    insertion_db(maListe,7);
    afficherListe_db(maListe);
    //printf("Valeur du premier élément : %d \n",maListe->premier->nombre);
    //printf("Valeur de l'élément suivant : %d \n",maListe->premier->suivant->nombre);
    DbElement *element = maListe->premier->suivant;
    //printf("Valeur de l'élement précédant le suivant : %d \n",element->precedent->nombre);

    insertion_fin_db(maListe,14);
    insertion_fin_db(maListe,2);
    afficherListe_db(maListe);
    DbElement *element2=maListe->premier->suivant->suivant->suivant;
    //printf("Valeur de element2: %d \n",element2->nombre);
    //printf("Valeur de l'élément précédent : %d \n",element2->precedent->nombre);
    //printf("Valeur de l'élément suivant : %d \n",element2->suivant->nombre);

    suppression_db(maListe);
    suppression_db(maListe);
    afficherListe_db(maListe);
    DbElement *element3 = maListe->premier;
    //printf("Valeur de element3 : %d \n",element3->nombre);
    //printf("Valeur de l'élément suivant : %d \n",element3->suivant->nombre);
    //printf("Vérification que le précédent est bien NULL : %p \n",element3->precedent);

    suppression_fin_db(maListe);
    suppression_fin_db(maListe);
    afficherListe_db(maListe);
    DbElement *element4=maListe->premier->suivant->suivant;
    printf("Valeur de l'élément précédent : %d \n",element4->precedent->nombre);
    DbElement *element5=maListe->dernier;
    printf("Valeur du dernier élément : %d \n",element5->nombre);
    */

    /* Tests Exercice 6 */
    BTree *arbre=init_tree(5);
    affichage_Btree(arbre);
    printf("\n");
    insert_tree(arbre,10,0);
    affichage_Btree(arbre);
    printf("\n");
    printf("Valeur du fils gauche : %d \n",arbre->left->root);
    insert_tree(arbre,4,1);
    affichage_Btree(arbre);

    printf("Nombre de noeuds : %d \n",nb_noeuds(arbre));
    printf("Somme des noeuds : %d \n",somme_noeuds(arbre));
    printf("Somme des feuilles : %d \n",somme_feuilles(arbre));

    BTree *arbre2=init_tree(3);
    insert_tree(arbre2,2,0);

    BTree *fusion=attache_arbre(7,arbre,arbre2);
    affichage_Btree(fusion);
    printf("\n");

    printf("Hauteur de arbre : %d \n",hauteur(arbre));
    printf("Hauteur de fusion : %d \n",hauteur(fusion));

    printf("fusion est abr ? %d \n", est_abr(fusion));
    BTree *abr = init_tree(5);
    insert_tree(abr,4,0);
    insert_tree(abr,6,1);
    affichage_Btree(abr);
    printf("\n");
    printf("abr est abr ? %d \n", est_abr(abr));

    BTree *ajout=insertion_abr(abr,3);
    affichage_Btree(ajout);
    printf("\n");
    return 0;
}
