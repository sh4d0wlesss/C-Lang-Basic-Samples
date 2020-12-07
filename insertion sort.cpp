#include <stdio.h>
#include <stdlib.h>
//insertion sort faruk arslan

int main(){
	
	int *dizi;
	int i,j,tmp,n;
	
	printf("dizinin eleman sayisini giriniz: ");
	scanf("%d",&n);
	
	dizi=int*malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++){
		
		printf("%d inci elemani gir: ",i+1);
		scanf("%d",&dizi[i]);
	}
	
	for(i=1;i<n;i++) {
		
		tmp=dizi[i];
		j=i-1;
		while(j>=0 && dizi[j]>tmp) {
			
			dizi[j+1]=dizi[j];
			j=j-1;
				
			}	
			
			dizi[j+1]=tmp;
		}		
	
	
	for(i=0;i<n;i++){
		
		printf("%d ",dizi[i]);
	}
	
	
	return 0;
	
}
