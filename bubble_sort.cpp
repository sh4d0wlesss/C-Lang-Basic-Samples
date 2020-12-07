#include <stdio.h>
#include <stdlib.h>


int main(void){
	int i,j,n,tmp,dizi[100];
	
	printf("dizinin eleman sayisini giriniz: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		
		printf("dizinin %d 'inci elemaný = ",i+1);
		scanf("%d",&dizi[i]);
		}

	for(i=0;i<n-1;i++){
		
		for(j=0;j<n-i-1;j++){
			
			if(dizi[j]>dizi[j+1]){
			
			tmp=dizi[j];
			dizi[j]=dizi[j+1];
			dizi[j+1]=tmp;
			}
		}
	}

	for(i=0;i<n;i++){
		
		printf("%d  ",dizi[i]);
	}

return 0;



}

