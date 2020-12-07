#include <stdio.h>
#include <stdlib.h>

struct list *createlist();
void ekleme_son(struct list *, struct list *);
void ekleme_bas(struct list *, struct list *);
struct list{
	int data;
	struct list	*next; 
};

int main(void){
	
		int i,n;	
		struct list *root,*p,*ek1;
		
		root=createlist();
		root->data=15;
		ek1->data=20;
		ek1->next=NULL;
		ekleme_son(root,ek1);
		
		for(p=root;p!=NULL;p=p->next){
			printf("%d \n",p->data);
		}
	
	
		
	
		return 0;
}

////////////////////////////////////liste olusturma///////////////////////////////

struct list *createlist(){
	
	struct list *p;
	p=(struct list*)malloc(sizeof(struct list*));
	if(p==NULL){
		printf("malloc patladý gg \n");
		exit(-1);
		
	}
	p->next=NULL;
	return p;
}

////////////////////////////////////listenin sonuna eleman ekleme///////////////////////////////

void ekleme_son(struct list *root, struct list *ek1){
	struct list *p;
	for(p=root;p->next!=NULL;p=p->next);
	p->next=ek1;
	
}










