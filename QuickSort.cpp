#include <stdio.h>

void QuickSort(int, int, int[]);
void swap(int* , int*);
int partition(int, int, int[]);

int main() {
	int dizi[8]={5,8,6,9,7,3,1,4};
	int left=0;
	int right=8;
	QuickSort(left,right,dizi);
	int i=0;
	for(i=0;i<8;i++){
		printf(" %d",dizi[i]);
	}
	
	return 0;
}

void swap(int *x, int *y){
	int tmp=*x;
	*x=*y;
	*y=tmp;
}

void QuickSort(int L, int R, int dizi[]){
	
	if(L<R){
		int pivot=partition(L, R, dizi);
		QuickSort(L, pivot-1, dizi);
		QuickSort(pivot+1, R, dizi);
	}
}

int partition(int L, int R, int dizi[]){
	int pivot=dizi[L];
	int i=L;
	int j=R+1;
	do{
		do{i=i+1;} while(i<j && dizi[i]<=pivot);
		do{j=j-1;} while(i<j && dizi[j]>pivot);
		
		swap(&dizi[i], &dizi[j]);
	}while(i<=j);
	
	swap(&dizi[i], &dizi[j]);
	swap(&dizi[L], &dizi[j]);
	
	return j;
}










