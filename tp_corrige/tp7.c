#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void exercice1(){
    char nom_fichier[20];
    printf("Entrez le nom du fichier : \n");
    scanf("%s",nom_fichier);
    printf("Nom du fichier : %s",nom_fichier);
    FILE* fichier = fopen(nom_fichier, "w");
    if (fichier != NULL){
        int i=0;
        while (i<10){
            char chaine[100];
            printf("Entrez une phrase à écrire dans le fichier : \n");
            fgets(chaine,100,stdin);
            fprintf(fichier, "%s",chaine);
            i++;
        }
        fclose(fichier);
    }
}

void exercice2(){
    FILE* fichier = fopen("exo2.txt", "r");
    int numero_ligne=1;
    int caractere=0;
    int compteur;
    if (fichier != NULL){
        while (caractere != EOF){
            compteur=0;
            printf("%d\t",numero_ligne);
            while ((compteur<80) && (caractere != EOF)){
        	    caractere = fgetc(fichier); 
                printf("%c", caractere);
                compteur++;
            }
        printf("\n");
        numero_ligne+=1;  
        } 
        fclose(fichier);
    }
}

void exercice3(){
    FILE* fichier = fopen("exo3.txt", "r");
    int nb_car=0;
    int nb_mot=0;
    int nb_lignes=0;
    if (fichier != NULL){
        int caractere =0;
        while (caractere != EOF){
        	caractere = fgetc(fichier); 
            nb_car++;
            if ((caractere == '\n') || (caractere == ' '))
                nb_mot++;
            if (caractere == '\n')
                nb_lignes++;
        }
        fclose(fichier);
    }
    printf("Nombre de caractères : %d. \n",nb_car);
    printf("Nombre de mots : %d. \n", nb_mot);
    printf("Nombre de lignes : %d. \n", nb_lignes);
}

void exercice4(){
    int i=0;
    char alphabet[26];
    char frequence[26]={0};
    char lettre = 'a';
    for (int i=0;i<26;i++){
        alphabet[i]=lettre;
        lettre++;
    }
    FILE* fichier = fopen("exo4.txt", "r");
    if (fichier != NULL){
        int caractere =0;
        while (caractere != EOF){
        	caractere = fgetc(fichier); 
            i=0;
            while((i<26) && (caractere != alphabet[i])){
                i++;
            }
            if (i<26)
                frequence[i]++;
        }
        lettre ='a';
        for (int j=0;j<26;j++){
            printf("Fréquence d'apparition de %c : %d. \n",lettre,frequence[j]);
            lettre++;
        }
        fclose(fichier);
    }
}

void exercice5(){
    int nb_personne;
    char nom[20];
    char prenom[20];
    int age;
    char numero[10];
    printf("Combien de personnes souhaitez-vous ajouter au répertoire : \n");
    scanf("%d",&nb_personne);
    FILE* fichier = fopen("exo5.txt", "w");
    if (fichier != NULL){
        for (int i=0;i<nb_personne;i++){
            fprintf(fichier,"---- CONTACT %d ---- : \n",i+1);
            printf("Entrez le nom de la personne : \n");
            scanf("%s",nom);
            fprintf(fichier, "Nom : %s \n", nom);
            printf("Entrez le prénom de la personne : \n");
            scanf("%s",prenom);
            fprintf(fichier, "Prénom : %s \n", prenom);
            printf("Entrez l'âge de la personne : \n");
            scanf("%d",&age);
            fprintf(fichier, "Age : %d \n", age);
            printf("Entrez le numéro de la personne : \n");
            scanf("%s",numero);
            fprintf(fichier, "Numéro : %s \n",numero);
        } 
        fprintf(fichier,"---------");
        fclose(fichier);  
    }
}

void exercice6(){
    char nom[20];
    int compteur=0;
    FILE* fichier = fopen("exo5.txt", "r");
    if (fichier != NULL){
        printf("Entrez le nom de la personne dont vous souhaitez les informations :");
        scanf("%s",nom);
        int taille = strlen(nom)+1; // On ajoute 1 pour tenir compte du bit de fin de chaîne !
        char *chaine=malloc(taille*sizeof(char));
        // Première partie : on va chercher la chaîne demandée par l'utilisateur dans le fichier, avec un 
        // compteur pour déterminer où elle se trouve.
        while (strcmp(chaine,nom)!=0){
            fgets(chaine,taille,fichier);
            if (fgetc(fichier)!='\n'){
                fseek(fichier,1-taille,SEEK_CUR);
                compteur++;
            }
            else{
                compteur+=taille;
                /* Car il faut compter tous les mots de longueur taille qui contiendront le \n */
            }
        }
        // On rembobine et on remplace le curseur là où il faut.
        rewind(fichier);
        fseek(fichier,compteur-strlen("Nom : ")-1,SEEK_CUR);
        char caractere =0;
        while (caractere != '-'){
            caractere = fgetc(fichier); 
            printf("%c", caractere);
        }
        fclose(fichier);
    }
}

/* Correction exercice 7 - Fibonacci */
int minimum(int a,int b){
    if(a>=b)
        return b;
    else
        return a;
}

/* Une fonction qui va lire les valeurs déjà calculées, jusqu'au plus petit entre le
max (qui est l'indice jusqu'au quel on a déjà calculé dans le fichier) et le n demandé
par l'utilisateur */
int import(int* tab, int n){
    FILE *fichier = fopen("exo7.txt","r");
    int max;
    if (fichier != NULL){
        fscanf(fichier,"%d",&max);
        int l = minimum(max,n);
        for(int i=0; i<l; i++){
            fscanf(fichier,"%d",&(tab[i]));
        }
        fclose(fichier);
    }
    return max;
}

/* Une fonction qui va écrire dans le fichier en ajoutant les valeurs successives
des tab[i] pour i de 0 à s inclus. */
void export(int *tab,int s){
    FILE *fichier= fopen("exo7.txt","w");
    if (fichier != NULL){
        fprintf(fichier,"%d \n",s);
        for (int i=0; i<= s; i++){
            fprintf(fichier,"%d \n",tab[i]);
        }
        fclose(fichier);
    }
}

/* La fonction qui calcule les coefficients de Fibonacci lorsque nécessaire. */
int fib_aux(int *tab, int n){
    if (tab[n]!=0)
        return tab[n];
    else{
        int a=fib_aux(tab,n-1);
        int b=fib_aux(tab,n-2);
        tab[n]=a+b;
        return tab[n];
    }
}

/* La fonction qui fait le travail final : on importe les données déjà calculées dans
le fichier. Si max renvoyé par import est plus grand que le n, on a déjà calculé la valeur
et il suffit de renvoyer l'élément tab[n] qui correspond à F(n). Sinon, il faut continuer
à écrire dans le fichier les éléments du tableau non calculés, en appelant la fonction fib_aux
pour calculer les termes manquants. */
int fib_incr(int n){
    int *tab = malloc((n+1)*sizeof(int));
    int max=import(tab,n+1);
    if (max >= n)
        return tab[n];
    else{
        int res=fib_aux(tab,n);
        export(tab,n);
        return res;
    }
}

int main(){
    //exercice1();
    //exercice2();
    //exercice3();
    //exercice4();
    //exercice5();
    //exercice6();

    int n=20;
    int fib = fib_incr(n);
    printf("Valeur de Fibonacci(%d) : %d. \n",n,fib);

    return 0;
}
