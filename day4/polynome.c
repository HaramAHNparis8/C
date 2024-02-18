#include<stdio.h>
#include<math.h>
#include<stdlib.h>


typedef struct polynome{
    float a,b,c;
    
}polynome;


polynome saisie(){
    polynome toto;
    
    printf("entrez la valeur de polynome pour a :\n");
    scanf("%f",&toto.a);
    printf("\nentrez la valeur de polynome pour b :\n");
    scanf("%f",&toto.b);
    printf("\nentrez la valeur de polynome pour c :\n");
    scanf("%f",&toto.c);
    printf("\n");
    
    return toto;
    
}


void racine(polynome z){
    float delta, x0, x1,x2;
    delta = z.b * z.b -(4 * z.a * z.c);
    if(delta < 0){
        printf("polynome n'a pas de racines\n");
    }
    else if(delta == 0){
        x0 = z.b/(z.a * 2 * -1);
        printf("la racine du polynome est : %f\n", x0);
    }
    else{
        x1 = -(z.b -sqrt(delta))/ 2 * z.a;
        x2 = -(z.b +sqrt(delta))/ 2 * z.a;
        printf("les racines sont : %f %f\n",x1 ,x2);
    }
}


void affichage_poly(polynome z){

    printf("P(n) = %f n*n + %fn + %f",z.a,z.b,z.c);

    
}

int main(void){
    polynome z;
    
    z = saisie();
    affichage_poly(z);
    racine(z);
    
}




