#include<stdio.h>
#define N 5


typedef struct ecran {
	
	float pixel;
	float pouces;
	float dpi;
}ecran;


ecran saisi(){
	ecran e;
	printf("Entrez la val :\n");
	scanf("%f %f %f \n", &e.pixel, &e.pouces, &e.dpi);

	return e;
}

void enregistrer(ecran *tab, int taille){
	int i;

	for(i = 0; i < taille; i++){
		printf("i = %d\n", i);
		tab[i] = saisi();
	}
}

void affichage_ecran(ecran e, int i){
	printf("Ecran %d : %f pixel %f pouce %f dpi", i, e.pixel, e.pouces, e.dpi);

}

void affichage(ecran *tab, int taille){
	int i;

	printf("\nStock : \n");
	affichage_ecran(tab[0],1);
	for(i = 1; i < N; i++){
		affichage_ecran(tab[i], i + 1);
	}

}

int main(){
	ecran tab[N];
	enregistrer(tab,N);
	affichage(tab,N);


	return 0;


}
