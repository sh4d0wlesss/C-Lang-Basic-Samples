#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i,n;
	int dizi[100];
	dizi[0]=1;
	dizi[1]=1;
	
	printf("Kacinci fibonacci sayisisni istiyorsunuz?");
	scanf("%d",&n);
	
	for(i=2;i<n;i++){
		dizi[i]=dizi[i-1]+dizi[i-2];
	}
	
	printf("oluþturulan fibonacci serisi =  ");
	for(i=0;i<n;i++){
		printf("%d ",dizi[i]);
	}
	
	return 0;
}
