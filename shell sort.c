#include <stdio.h>

int main(){
	
	int n,k,i,j,tmp,x,y;
	int *dizi;
	printf("dizinin eleman sayisini giriniz: ");
	scanf("%d",&n);
	
	dizi=(int*)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++){
		printf("%d nci elemani giriniz : ",i+1);
		scanf("%d",&dizi[i]);
	}
	
	k=n/2;
	
	while(k!=0){
		for(i=k;i<n;i++) {
		y=i;
			for(x=i-k;x>=0;x=x-k ) {
				if(dizi[y]<dizi[x]){
					tmp=dizi[x];
					dizi[x]=dizi[y];
					dizi[y]=tmp;
					y=x;
				}
			
			}	
			
	
		}		
	
	k=k/2;	
	}
	
	for(i=0;i<n;i++){
		printf("%d ",dizi[i]);
	}
	
	
	
	
}
