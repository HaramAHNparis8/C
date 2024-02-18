#include<stdio.h>




#define MA_MACRO(X, Y) X+19*Y
int entrerlavaleur(){
    int note = 0;
    printf("entrer la note de dix");
    scanf("%d", &note);
    return note;
}
 

int main(void){
//    int notedonnée[10], note = 0,i, s = 0;
//    float moy = 0;
//
//    for(i = 0; i < 10; i++){
//        note = entrerlavaleur();
//        notedonnée[i]= note;
//
//    }
//    for(i = 0; i < 10; i++){
//        printf ("%d\n",notedonnée[i]);
//    }
//    for(i = 0; i < 10; i++){
//        s += notedonnée[i];
//    }
//    moy = (float) s /10;
//    printf("%f\n",moy);
    int* nums = getNumbers();
    for(int i=0; i<6; i++) printf("%d ", nums[i]);
    
    return 0;

}
