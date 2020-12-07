#include <stdio.h>
#include <stdlib.h>
#define max_size 100
int main(void){
	int i,j,n,tmp,indis,min,dizi[max_size];
	
	printf("dizinin eleman sayisini giriniz: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		
		printf("dizinin %d 'inci elemani = ",i+1);
		scanf("%d",&dizi[i]);
		}
		
	for(i=0;i<n-1;i++){
		min=dizi[i];
		indis=i;
		
		for(j=i+1;j<n;j++){
			
			if(dizi[j]<min){
				min=dizi[j];
				indis=j;
			}
			
		}
		tmp=dizi[i];
		dizi[i]=min;
		dizi[indis]=tmp;
		
	}
	
		for(i=0;i<n;i++){
		
		printf("%d  ",dizi[i]);
	}

		
}
