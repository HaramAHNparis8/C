#include<stdio.h>
#include<math.h>
#define MAX 5
#include<stdlib.h>

int recursivit_re(int n){
	if(n == 0){


		return 0;
	}

	else{
	
	
	return sqrt(n) + recursivit_re(n - 1);
	
	}


}

int recursivit_for(int n){
	int s = 0, i;

	for(i = 0; i <= n; i++){

		s+= sqrt(i);
		printf("%d\n",i);
	
	}
	return s;

}

int entreval(){
    int n = 0;
    printf("Entrez la valeur\n");
    scanf("%d", &n);
    
    return n;
}

int* creation(){
    
    static int tab[10];
    int i, n;
    
    for(i = 0; i < 10; i++){
        n = entreval();
        tab[i] = n;
    }
    
    return tab;
}
float moyen(int nb){
    int* tab = creation();
    int i;
    float s =0;
    
    for(i = 0; i < nb; i++){
        s += tab[i];
    }
    printf("sum :%f\n", s);
    return s / nb;
}

int plusproche(int nb){
    int* tab = creation();
    int i, proche;
    float moy;
    
    moy = moyen(10);
    proche = tab[0];
    
    for(i = 0; i < nb; i++){
        if(abs(proche - moy) > abs(tab[i] - moy)){
            proche = tab[i];
            
        }
    }
    
    return proche;
}

void affiage(){
    int moy = moyen(10);
//    printf("moyen : %d", moy);
    printf("%d", plusproche(10));

}

int tabl(){
    int n = 0, i, max = 0, sec = 0;
    int tab[10];
    
    for(i = 0; i < 10; i++){
        n = entreval();
        tab[i] = n;
    }
    
    max = tab[0];
    
    for(i = 0; i < 10; i++){
        if(max < tab[i]){
            sec = max;
            max = tab[i];
            
        }
        else if(max > tab[i] && sec < tab[i]){
            sec = tab[i];
        }
    }
    
    return sec;
}

int tableinf(int v[],int nb){
    int i, s = 0;
    for(i = 0; i < nb; i++){
        if(nb >v[i]){
            s++;
        }
       
    }
    return s;
}

void swap(int* a, int* b){
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void inversion(int v[], int nb){
    int i, j = nb - 1;
    
    for(i = 0; i < nb /2; i++){

        swap(&v[i], &v[j]);
        j--;
    }
    for(i = 0; i < nb; i++){
        printf("%d\n", v[i]);
    }
}

int recursi_puissance(int n, int p){
    if(n == 0){
        return 1;
    }
    else{
        return p * recursi_puissance(n - 1, p);
    }
}

//int somme(int n, int p){
//    if(p == 0){
//        return 0;
//    }
//    else{
//
//        return recursi_puissance(n,p) + somme(n, p - 1);
//    }
//}

int for_puiss(int n, int p){
    int i, s = 0;
    
    for(i = 0; i <= p; i++){
        s += recursi_puissance(n,i);
    }
    return s;
}


int main(void){
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int b[10] = {};
    
//    for(int i = 0; i < 10; i++){
//
//    }
//	int arr[MAX];
//	int i;
//	int inputNum, min = 99999999;
//	int d, k;
//
//	//입력 부분
//	for(i=0 ; i<MAX ; i++)
//	{
//		printf("%2d번째 수를 입력 : ", i+1);
//		scanf("%d", &arr[i]);
//	}
//
//	printf("\n입력한 수는 ");
//	for(i=0 ; i<MAX ; i++)	printf("%d ", arr[i]);
//
//	//특정 수 입력
//	printf("\n\n임의수 입력 : ");
//	scanf("%d", &inputNum);
//
//
//	//검사
//	for( i=0 ; i<MAX ; i++)
//	{
//		if(arr[i] > inputNum)
//		{
//			d=arr[i]-inputNum;
//		}
//
//		if(arr[i] < inputNum)
//		{
//			d=inputNum-arr[i];
//		}
//
//		if(d<min)
//		{
//			min = d;
//			k = arr[i];
//		}
//	}
//
//	printf("가장 가까운 수는 : %d\n", k);

	//printf("%d",recursivit_re(144));
	//printf("%d\n", recursivit_for(144));
//    printf("%d\n",tabl());
//    printf("%d",tableinf(a,3));
//    inversion(a,10);
//    printf("%d",recursi_puissance(4,3));
//    printf("%d",somme(3,3));
//    printf("%d",for_puiss(2,4));
    affiage();
    return 0;
}
