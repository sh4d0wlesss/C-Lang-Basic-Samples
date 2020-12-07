#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned int gun;
	unsigned int ay;
	unsigned int yil;
}tarih;

typedef struct{
	char isim[20];
	char tcno[20];
	tarih dt;
}kisi;

void dosyayaz(char filename[]){
	int gun,ay,yil,n;
	char isim[20],tcno[20];
	int i;
	kisi p;
	FILE *fp;
	
	fp=fopen(filename,"wb");
	if(fp==NULL){
		printf("dosya acilamadi!!! \n");
		exit (0);
		
	}
	
	printf("kisi sayisini giriniz=  ");
	scanf("%d",&n);
	
	printf("sýrayla bilgileri giriniz ... \n");
	
	for(i=0;i<n;i++){
		printf("%d inci kisinin ismi =   ",i);
		scanf("%s",p.isim);
		printf("%d inci kisinin tc nosu =   ",i);
		scanf("%s",p.tcno);
		printf("%d inci kisinin dogum gunu =   ",i);/// bitfield tanýmlarsan tarih structerini eriþemezsin çünkü bitfieldlarýn adresine eriþilmez
		scanf("%d",&p.dt.gun);
		printf("%d inci kisinin dogum ayi =    ",i);
		scanf("%d",&p.dt.ay);
		printf("%d inci kisinin dogum yili =   ",i);
		scanf("%d",&p.dt.yil);
		
		fwrite(&p,sizeof(kisi), 1, fp);
	}
	fclose(fp);	
}


void dosyaoku(FILE *fp){
	kisi p;
	int i;
	
	printf("kisiler ve bilgileri \n");
	
	fseek(fp,0,SEEK_SET);
	fread(&p,sizeof(kisi),1,fp);
	
	while (!feof(fp)){
		printf("%s   %s   %d.%d.%d \n",p.isim,p.tcno,p.dt.gun,p.dt.ay,p.dt.yil);
		fread(&p,sizeof(kisi),1,fp);
		
	}
	

}

int main(){
	FILE *fs;
	char c[50];
	printf("dosya adini gir");
	scanf("%s",&c);
	dosyayaz(c);
	int x,boyut,konum;
	fs=fopen(c,"r+b");
	kisi sp;
	if(fs==NULL){
		printf("dosya acilamadi");
		exit(1);
	}
	
	dosyaoku(fs);
	
	printf("\n");
	printf("kacinci kisinin bilgilerini istiyorsunuz ?  ");
	scanf("%d",&x);
	
	boyut=(x-1)*sizeof(kisi);
	konum=fseek(fs,boyut,SEEK_SET);
	
	fread(&sp,sizeof(kisi),1,fs);
	printf("kisinin bilgileri:  ");
	printf("%s  %s   %d.%d.%d",sp.isim,sp.tcno,sp.dt.gun,sp.dt.ay,sp.dt.yil);
	
	
	return 0;

}
