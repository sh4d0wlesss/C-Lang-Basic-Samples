#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct{
	int item[MAX];
	int top;
}STACK;
// ----------  fonksiyonlar�n prototipleri -----------
int hangislem(int*,int*,char);
int isEmpty(STACK*);
int isFull(STACK*);
int push(int,STACK*);
int pop(STACK*, int*);
int peek(STACK*, int*);
void ekranayazsayi(STACK*);
void ekranayazisaret(STACK*);
int desiyap(int,int,int);
int tmp=0;
// ---------------  main fonksiyon -------------------
int main() {
	STACK *isaret;
	STACK *sayi;
	char dizi[100];
	int *x,*y,*z;
	int k;
	int enson=0,n,i;
	int say1, say2,sonuc;
	x=(int*)malloc(sizeof(int));
	y=(int*)malloc(sizeof(int));
	z=(int*)malloc(sizeof(int));
	isaret=(STACK*)calloc(1,sizeof(STACK));
	sayi=(STACK*)calloc(1,sizeof(STACK));
	
	printf("lutfen islemi giriniz:  ");//diziye i�lemi yazma
	scanf("%s",&dizi);
	
	n=strlen(dizi);//dizinin uzunlu�unu alma
	printf("string uzunlugu =  %d\n\n",n);
	

	for(i=0;i<n;i++){
		if(dizi[i]=='('){ //  gelen eleman�n a� parantez olma durumu
			push((int)'(',isaret);
		}
		else if(dizi[i]=='+' || dizi[i]=='-'){ // gelen eleman�n +  veya - olma durumu
			if(isEmpty(isaret)){
				push((int)dizi[i],isaret);	
			}
			else{
				peek(isaret,x);
				if(*x=='(' ){
					push((int)dizi[i],isaret);
				}
				else{
					pop(sayi,y);
					pop(sayi,z);
					pop(isaret,&k);
					sonuc=hangislem(z,y,(char)k);
					push(sonuc,sayi);
					push((int)dizi[i],isaret);
				}
			}	
		}
		else if(dizi[i]>='0' && dizi[i]<='9'){   // gelen eleman�n say� olma durumu
			if(dizi[i+1]>='0' && dizi[i+1]<='9'){
				tmp=desiyap(tmp,dizi[i]-'0',1);
			}
			else{	
				tmp=desiyap(tmp,dizi[i]-'0',0);
				push(tmp,sayi);	
				tmp=0;
			}		
		}
		else if(dizi[i]=='*' || dizi[i]=='/'){  // gelen eleman�n �arpma veya b�lme olma durumu
			if(isEmpty(isaret)){
				push((int)dizi[i],isaret);	
			}
			else{
				peek(isaret,x);
				if(*x=='*' || *x=='/'){
					pop(sayi,y);
					pop(sayi,z);
					pop(isaret,&k);
					sonuc=hangislem(z,y,(char)k);
					push(sonuc,sayi);
					push((int)dizi[i],isaret);		
				}
				else{
					push((int)dizi[i],isaret);
				}
			}
		}
		else if(dizi[i]==')'){  // gelen eleman�n kapa parantez olma durumu
			while(peek(isaret,x) && *x!='('){
				pop(sayi,y);
				pop(sayi,z);
				pop(isaret,&k);
				sonuc=hangislem(z,y,(char)k);
				push(sonuc,sayi);
			}
			pop(isaret,x);
		}
		ekranayazsayi(sayi);
		ekranayazisaret(isaret);
		printf("\n\n ------------- yerlestirme veya islem yapildi-------------");
	}
	
	// diziyi alma i�leri bitince stackdeki eleman ve say�lar� cekerek i�lemleri yapma ve sonucland�rma
	while(!isEmpty(isaret) && !isEmpty(sayi)){
		pop(sayi,y);
		pop(sayi,z);
		pop(isaret,&k);
		sonuc=hangislem(z,y,(char)k);	
		push(sonuc,sayi);	
	}
	peek(sayi,&enson);
	printf("\n\n Girilen islemin sonucu:  %d \n\n",enson);	
	printf(" *********************  FARUK ARSLAN 16011032   *********************");
	return 0;
}
//fONKS�YONLAR
//******************** stack bo� mu ?**************************************
int isEmpty(STACK *s){
	if(s->top==0)
		return 1;
	else 
		return 0;
}
//********************** stcak dolu mu? ************************************
int isFull(STACK *s){
	if(s->top == MAX)
		return 1;
	else
		return 0;
}
//********************** stack'e eleman g�nderme ************************************
int push(int x, STACK *s){
	if(isFull(s))
		return 0;
	else{
		s->item[s->top]=x;
		s->top++;
		return 1;
	}			
}
//*************************  stackden eleman �ekme   *********************************
int pop(STACK *s, int *x){
	if(isEmpty(s))
		return 0;
	else{
		s->top--;
		*x=s->item[s->top];
		return 1;
	}
}
//*****************************stack�n en �st�ndeki elemana bakma *****************************
int peek(STACK *s, int *x){
	int adr;
	if(isEmpty(s))
		return 0;
	else{
		adr=s->top-1;
		*x=s->item[adr];
		return 1;
	}
}
//************************ gelen i�arete g�re hangi i�lem oldugunu bulup i�lemi yap�p sonucu d�nd�rme **********************************

int hangislem(int *x, int *y,char a){
	int sonuc;
	if(a=='+'){
		sonuc=(*x) + (*y);
		}
	if(a=='-'){
		sonuc=(*x)-(*y);
		}
	if(a=='*'){
		sonuc=(*x) * (*y);
		}
	if(a=='/'){
		sonuc=(*x)/(*y);
		}
	return sonuc;
}
//************************* sayi stack�n�n mevcut durumunu ekrana basma *********************************
void ekranayazsayi(STACK *s){
	int i;
	printf("\nSayi stackinin durumu: ");
	while(s->item[i]!=0){
		printf("%d  ",s->item[i]);
		i++;
	}
	i=0;
}
//*************************** i�aret stack�n�n mevcut durumunu ekrana basma *******************************
void ekranayazisaret(STACK *s){
	int i;
	printf("\nIsaret stackinin durumu: ");
	while(s->item[i]!=0){
		printf("%c  ",s->item[i]);
		i++;
	}
	printf("\n");
	i=0;
}
//************************gelen say�y� gerekiyorsa desimal yapma **********************************
int desiyap(int tmp,int eleman,int select){
	if(select==1){
		tmp=tmp+eleman;
		tmp=tmp*10;
		return tmp;
	}
	if(select==0){
		tmp=tmp+eleman;
		return tmp;
	}
	
}
