#include<stdio.h>

void test(){
	float a = 1.1, b = 0.1, s = 0;
	//int a = 1, b = 2, s = 0;
	s = a + b;
	s *= 10;
	if(s == 12){
		printf("Ture");
	}	
	else{
		printf("false");
	}
}


int main(){
	test();
}
