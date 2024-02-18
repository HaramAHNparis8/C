#include<stdio.h>
#include<stdlib.h>

typedef struct Element Element;


struct Element{
     int nombre;
     Element *suivant;
};

typedef struct Liste{
    Element *premier;
    
}Liste;

Liste *initialisation() {
    Liste *liste = malloc(sizeof(*liste));
    
    Element *element = malloc(sizeof(*element));
    
    if (liste == NULL || element == NULL){
        exit(EXIT_FAILURE);
        
    }
    element ->nombre = 0;
    element ->suivant = NULL;
    liste ->premier = element;
    
    return liste;
}
void insertion(Liste *liste , int nvNombre){
    /* Creation du nouvel element */
    
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL){
        
        exit(EXIT_FAILURE);
    }
    nouveau ->nombre = nvNombre;
    /* Insertion de l'element au debut */
    nouveau ->suivant = liste ->premier;
    liste ->premier = nouveau;
}

void insertion_fin(Liste *liste, int nvNombre){
    Element *nouveau = malloc(sizeof(* nouveau));
    if (liste == NULL || nouveau == NULL){
        exit(EXIT_FAILURE);
        
    }
    nouveau ->nombre = nvNombre;
    Element *prem = liste ->premier;
    while (prem->suivant != NULL){
        prem = prem->suivant;
        
    }
    nouveau->suivant=prem->suivant;
    prem->suivant = nouveau;
}
void insertion_position(Liste *liste, int nvNombre , int pos){
    Element *nouveau = malloc(sizeof(* nouveau));
    
    if (liste == NULL || nouveau == NULL){
        exit(EXIT_FAILURE);
    }
    nouveau ->nombre = nvNombre;
    Element *prem = liste ->premier;
    int i=1;
    while ((i<pos-1) && (prem->suivant != NULL)){
        
        prem = prem->suivant;
        i++;
        
    }
    nouveau->suivant=prem->suivant;
    prem->suivant = nouveau;
}
void suppression(Liste *liste){
    if (liste == NULL){
        exit(EXIT_FAILURE);
    }
    if (liste ->premier != NULL){
        Element *aSupprimer = liste->premier;
        liste ->premier = liste ->premier ->suivant;
        free(aSupprimer);
        
    }
    
}

void suppression_fin(Liste *liste){
    if (liste == NULL){
        exit(EXIT_FAILURE);
        
    }
    Element *prem = liste ->premier;
    while (prem->suivant->suivant !=NULL){
        prem=prem->suivant;
        
    }
    prem->suivant=NULL;
    free(prem->suivant);
}

void suppression_position(Liste *liste , int pos){
    if (liste == NULL){
        exit(EXIT_FAILURE);
        
    }
    Element *prem = liste ->premier;
    int i=1;
    while ((i<pos -1) && (prem ->suivant->suivant != NULL)){
        prem=prem->suivant;
        i++;
        
    }
    Element *temp=prem->suivant;
    prem->suivant=temp->suivant;
    free(temp);
}
void afficherListe(Liste *liste){
    if (liste == NULL){
        exit(EXIT_FAILURE);
    }
    Element *actuel = liste ->premier;
    while (actuel != NULL){
        printf("%d -> ", actuel ->nombre);
        actuel = actuel ->suivant;
        
    }
    printf("NULL\n");
}

int main(void){
    Liste *maListe = initialisation();
    insertion(maListe , 4);
    insertion(maListe , 8);
    
    insertion(maListe , 15);
    suppression(maListe);
    afficherListe(maListe);
    return 0;
}

