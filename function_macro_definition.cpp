#include<stdio.h>

#define MUL_BY_TWO(a) ((a)+(a))

int main(void){
	int x;
	x=MUL_BY_TWO(5);
	
	printf("%d",x);
	
	return 0;
}
