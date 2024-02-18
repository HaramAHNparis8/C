#include<stdio.h>
#include<stdlib.h>


typedef struct ELE ELE;

struct ELE{
	int nombre;
	ELE *suivant;

};

typedef struct Liste{
	ELE * premier;
}Liste;

Liste *initial(){
	Liste * liste = malloc(sizeof(*liste));
	ELE * element = malloc(sizeof(*element));

	if(liste == NULL || element == NULL){
		exit(EXIT_FAILURE);
	}

	element -> nombre = 0;
	element -> suivant = NULL;
	liste -> premier = element;

	return liste;
}


void inseration(Liste * liste, int nb_val){
	ELE * nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL){
        
        exit(EXIT_FAILURE);
    }
	nouveau -> nombre = nb_val;
	nouveau -> suivant = liste -> premier;
	liste -> premier = nouveau;

}


void suppression(Liste * liste){
	ELE *asupprimer = malloc(sizeof(*asupprimer));
    
    if (liste == NULL){
        exit(EXIT_FAILURE);
        
    }
    if(liste == NULL){
        asupprimer = liste->premier;
        liste->premier = liste ->premier->suivant;
        free(asupprimer);
    }
}

void cons(Liste * liste, int nb_val){
    ELE * nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL){
        
        exit(EXIT_FAILURE);
    }
    nouveau -> nombre = nb_val;
    nouveau -> suivant = liste -> premier;
    liste -> premier = nouveau;
    
    
}
int car(Liste *liste){
    if (liste == NULL){
        exit(EXIT_FAILURE);
    }
    ELE * car = liste -> premier;
    
    return car -> nombre;
}

ELE* cdr(Liste * liste){
    if(liste == NULL){
        exit(EXIT_FAILURE);
    }
    ELE * cdr = liste -> premier;
    return  cdr -> suivant;

    
}
// j'ai essayé à trouver la solution sur l'internet mais je n'ai pas réussi. je suis désolé

Liste* reverseList(Liste* list) {
    if (list->premier == NULL || list->premier->suivant == NULL) {
        return list;
    }

    ELE* current = list->premier;
    ELE* next = current->suivant;
    list->premier = reverseList((Liste*)malloc(sizeof(Liste)))->premier;
    current->suivant = NULL;
    next->suivant = current;

    return list;
}
void afficher(Liste *liste){
    if (liste == NULL){
        exit(EXIT_FAILURE);
    }
    ELE * affiche = liste -> premier;
    while(affiche != NULL){
        printf("%d-> ",affiche-> nombre);
        affiche = affiche ->suivant;
        
    }
    
}





int main(void){
    int a[4] = {0,1,2,3};
    Liste *maListe = initial();
    cons(maListe , 4);
    cons(maListe , 8);
    cons(maListe, 15);

//    int frist = car(maListe);
//    printf("%d", frist);
//    ELE* rest = cdr(maListe);
//    while(rest != NULL){
//        printf("%d ",rest -> nombre);
//        rest = rest -> suivant;
//    }
//
//    afficher(maListe);
    Liste* list = (Liste*)malloc(sizeof(Liste));
    ELE* temp = (ELE*)malloc(sizeof(ELE));
    temp->nombre = 1;
    temp->suivant = NULL;
    list->premier = temp;

    temp = (ELE*)malloc(sizeof(ELE));
    temp->nombre = 2;
    temp->suivant = NULL;
    list->premier->suivant = temp;
    temp = (ELE*)malloc(sizeof(ELE));
    temp->nombre = 3;
    temp->suivant = NULL;
    list->premier->suivant->suivant = temp;

    Liste* reversedList = reverseList(list);

    ELE* current = reversedList->premier;
    while (current != NULL) {
        printf("%d ", current->nombre);
        current = current->suivant;
        }

    
}
