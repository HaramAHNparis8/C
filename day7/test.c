#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int main(void) {

 FILE *fp1, *fp2;

 char file1[100], file2[100];

 char buffer1[1000], buffer2[1000];

 printf("첫번쨰 파일 이름: ");

 scanf("%s", file1);

 printf("두번째 파일 이름: ");

 scanf("%s", file2);

 // 첫번째 파일을 읽기 모드로 연다.

 if( (fp1 = fopen(file1, "r")) == NULL ) {

 fprintf(stderr,"원본 파일 %s을 열 수 없습니다.\n", file1);

 exit(1);

 }

 // 두번째 파일을 읽기 모드로 연다.

 if( (fp2 = fopen(file2, "r")) == NULL ) {

 fprintf(stderr,"복사 파일 %s을 열 수 없습니다.\n", file2);

 exit(1);

 }
// 첫번째 파일을 두번째 파일로 복사한다.
 while( 1 ){

 char *p1 = fgets(buffer1, 1000, fp1);

 char *p2 = fgets(buffer2, 1000, fp2);

 if( p1 == NULL || p2 == NULL )

 break;

 if( strcmp(p1, p2)!= 0 ) {

 printf("<< %s", buffer1);

 printf(">> %s", buffer2);
 }

}

fclose(fp1);

fclose(fp2);

return 0;

}
