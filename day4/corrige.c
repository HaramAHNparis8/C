#include<stdio.h>
#include<math.h>

#define N 5
#define STOCK 100

typedef enum {jan, fev, mars, avril, mai, juin, juil, aout, sept, oct, nov, dec} mois;

typedef struct date{
	int jours;
	mois mois;
	int annee;


}date;


int jours_ecoules(date d){
	int jour_par_mois[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int i = 0, res = 0;

	if (d.annee % 4 == 0){
		jour_par_mois[1] = 29;
	}
	while (i < d.mois){
		res += jour_par_mois[i];
		i++;
	}

	res += d.jours;
	
	return res;

}


typedef struct ecran{
    float pixel;
    float pouces;
    float dpi;
}ecran;

ecran saisie(void){
    ecran e;
    printf("Entrez les caractéristiques de l'écran : pixels, pouces, dpi :\n");
    scanf("%f %f %f", &e.pixel, &e.pouces, &e.dpi);
    
    return e;
}

int main(void){
	date d;
	d.jours=17;
	d.mois = mars;
	d.annee = 2020;
	int nb = jours_ecoules(d);
	printf("Le nombre de jours écoulés jusqu'au %d/%d/%d est : %d \n",d.jours,d.mois+1,d.annee,nb);


}

