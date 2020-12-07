#include <stdio.h>
#include <stdlib.h>
struct resim{
	int R;
	int G;
	int B;
};


int main(){
	int i=0,j=0;
	int n=0;
	
	printf("lutfen matris boyutu icin deger giriniz");
	scanf("%d",&n);
///////////////////////////yer ayýr ////////////////////////////	
	struct resim **mat;
	mat =(struct resim**)malloc(sizeof(struct resim*)*n);
	if(mat==NULL){
		printf("allocation error");
		exit (-1);
	}
	for(i=0;i<n;i++){
		mat[i]=(struct resim*)malloc(sizeof(struct resim)*n);
	}
/////////////////////////eleman al////////////////////////////////	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("mat[%d][%d] elemanin R degerini giriniz : ",i,j);
			scanf("%d",&mat[i][j].R);
			printf("mat[%d][%d] elemanin G degerini giriniz : ",i,j);
			scanf("%d",&mat[i][j].G);
			printf("mat[%d][%d] elemanin B degerini giriniz : ",i,j);
			scanf("%d",&mat[i][j].B);
		}
	}
	
	///////////////////////////////////matis þeklinde yaz //////////////////////
	printf("\n R degerleri matrisi: \n\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",mat[i][j].R);	
		}
		printf("\n");
	}
	printf("//////////////////////////////");
	printf("\n G degerleri matrisi: \n\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",mat[i][j].G);	
		}
		printf("\n");
	}
	printf("/////////////////////////////");
	printf("\n B degerleri matrisi: \n\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",mat[i][j].B);	
		}
		printf("\n");
	}
	return 0;
}



