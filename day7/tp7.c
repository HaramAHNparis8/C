#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1000
void entrelenom(){
    
    FILE* fp = fopen("test.txt","w");
    char entre[100] = "";
    printf("entrez le nom : ");
    scanf("%s",entre);
    fputs(entre,fp);
    
    fclose(fp);
    
}
void affichage_le_contenu(){
    FILE * fp1 = fopen("exo2.txt","r");
    char fichier[max] = "";
    fread(fichier, 1, max, fp1);
    printf("%s", fichier);
    
    fclose(fp1);
}

void compter_nb_char(){
    int nb_mot = 0, nb_ligne = 0, nb_carctère = 0, nb_tmp = 0;
    char tmp;
    FILE * open_fille = fopen("test.txt","r");
    while(fscanf(open_fille, "%c", &tmp) != EOF){
        if(tmp == ' ' || tmp == '\n' || tmp == '\t' || tmp == '.' || tmp == ',' || tmp == '!'|| tmp == NULL){
            nb_tmp = 1;
        }
        else{
            nb_tmp = 0;
        }
        if(nb_tmp == 1){
            nb_mot++;
        }

        if(tmp == '\n'){
            nb_ligne++;
        }
        if(tmp >= '!' || tmp <='~'){
            if(tmp == ' '){
                continue;
                
            }
//            else if(tmp == 'é' || tmp == 'è' || tmp == 'ë' || tmp == 'à' || tmp == 'ô' || tmp == 'œ'){
//                nb_carctère--;
//
//            }
            // s'il y a l'accent, le compteur compte deux caractère ou trois caracrète alors on fait une fonction pour mépriser l'accent, mais le système ne comprend pas l'accent de français.
            nb_carctère++;
        }
    }
    fclose(open_fille);
    printf("le nombre de caractère : %d\n", nb_carctère);
    printf("le nombre de ligne : %d\n", nb_ligne);
    printf("le nombre de mot %d",nb_mot);
}

void compter_nb_occurance(char occ){
    int nb_occur = 0;
    FILE * open_fille = fopen("test.txt","r");
    char tmp;
    while(fscanf(open_fille, "%c", &tmp) != EOF){
        if(tmp == occ){
            nb_occur++;
            
        }
    }
    printf("le nombre de caractère %d", nb_occur);
}
void création_fichier(int cb_personne){//pour tester merci pour supprimer le fichier du ex5.txt
    FILE * fp = fopen("ex5.txt","w");
    int i,age = 0;
    char nom[20] = "",prenom[15] = "";
    for(i = 0; i < cb_personne; i++){
        
        printf("entrez le nom : \n");
        scanf("%s",nom);
        fputs(nom,fp);
        printf("entrez le prénom : \n");
        scanf("%s",prenom);
        fputs(prenom,fp);
        printf("Quel age avez-vous ? \n");
        scanf("%d", &age);
        fprintf(fp , "%d\n", age);
        
        
    }
    fclose(fp);

}

void retouver_info(){
    char tmp[1000],tmp_2[1000];
    FILE * fp1 = fopen("ex5.txt","r");
    FILE * fp2 = fopen("ex6.txt","r");
    while(1){
        char *p1 = fgets(tmp,1000,fp1);
        char *p2 = fgets(tmp_2,1000,fp2);
        
        if(p1 == NULL || p2 == NULL){
            break;
        }
        
        if(strcmp(p1,p2) == 0){
            printf("le nom et le prénom ont déjà eu");
        
        }
        else{
            printf("c'est un nouveau prénom ou nom");
            
        }
    }
    
    fclose(fp1);
    fclose(fp2);
    
}



int main(void){
    
    //entrelenom();
    //affichage_le_contenu();
    //compter_nb_char();
    //compter_nb_occurance('e');
//    création_fichier(1);
    retouver_info();
    
    
	return 0;
}
