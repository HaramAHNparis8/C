#include<stdio.h>
#include <string.h>

void somme_prod(int* a, int* b){

	int c = *a;
	* a = c * *b;
	* b = c * *b;

}


//void affichage(){
//    int i;
//    double tab[10];
//
//    for(i = 0; i < 10; i++){
//        tab[i] = i;
//
//        printf("valeur de tab[%d] : %lf%p, adresse %p\n",i,tab[i],&tab[i]);
//
//    }
//
//}

void min_max_pointeur(int *tab, int taille, int *min, int *max){
    int i;
    *min = tab[0];
    *max = tab[0];
    for(i = 0; i < taille; i++){
        if(tab[i] < *min){
            *min = tab[i];
        }
        if(tab[i] > *max){
            *max = tab[i];
        }
    }
}

void nb_de_lettre(char * tab, char caractère){
    int i,n = 0;
    
    for(i = 0; i < 132; i++){
        if(caractère == tab[i]){
            
            n ++;
        }
    }
    printf("%d", n);


}

int est_voyelle(char* text,char voyelle){
    
    int i;
    for(i = 0; i < 10; i++){
        if(voyelle == 'a'||
           voyelle == 'e'||
           voyelle == 'i'||
           voyelle == 'o'||
           voyelle == 'u'||
           voyelle == 'A'||
           voyelle == 'E'||
           voyelle == 'I'||
           voyelle == 'O'||
           voyelle == 'U'
           
           ){
            return 1;
        }
        else{
            
            return 0;
        }
    }
    return printf("");
    
}

void remplace_voyelle1_1(char * text, int taille){
    int c, i;
    //sur mon mac il ajoute une caractère que j'ai pas mis après avoir executé s'il y a le même erreur, mondifie le code.
    for(i = 0; i < taille; i++){
        
        c = est_voyelle(text, text[i]);
        if(c == 1){
            text[i] = '_';
            printf("%c\n", text[i]);
        }
        else{
            printf("%c\n", text[i]);
        }
        
    }

}

void remplace_voyelle1_2(char * text){
    int c, i, taille = strlen(text);
    
    for(i = 0; i < taille; i++){
        
        c = est_voyelle(text, text[i]);
        if(c == 1){
            text[i] = '_';
            printf("%c", text[i]);
        }
        else{
            printf("%c", text[i]);
        }
        
    }

}


int main(){
    char list_voyelle[] = {'A','E','I','O','U','a','e','i','o','u'};
//    int taille = strlen(list_voyelle);
    char list_char[] ="Everybody looking for somebody";
    int taille = strlen(list_char);
//    char str[132];
//    printf("entrez votre text (sans espace)");
//    scanf("%s",str);
//    printf("%s",str);
    
//	int a = 5;
//	int b = 2;
//
//	printf("valeur de a : %d \n", a);
//	printf("valeur de b : %d \n", b);
//
//	somme_prod(&a, &b);
//
//	printf("valeur de a : %d \n", a);
//	printf("valeur de b : %d \n", b);
//    affichage();
//    int tab[10] = {1,5,19,50,2,3,25,12,10};
//    int min = -1000;
//    int max = -1000;
//    min_max_pointeur(tab,10,&min,&max);
//    printf("la val de min : %d",min);
//    printf("la val de max : %d",max);
//    nb_de_lettre(str,'e');
//    printf("%d\n",est_voyelle(list_voyelle,'A'));
//    printf("%d\n",est_voyelle(list_voyelle,'d'));
//    remplace_voyelle1_1(list_voyelle,taille);
    remplace_voyelle1_2(list_char);
    return 0;

}
