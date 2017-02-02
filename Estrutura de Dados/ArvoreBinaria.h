#ifndef ARVOREBINARIALINKEDLIST_H_
#define ARVOREBINARIA_LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	void *data;
	struct No *left;    
    struct No *right;
}No;

typedef struct iArvBin {
    No *root;
    int size;
}iArvBin;

void init(iArvBin *arv);
int add(iArvBin *arv, void *data);
No* busca(No *no, void *data);
int size(iArvBin *arv);
//int remove(iArvBin *arv, int data);
void show(iArvBin *arv, int opcao);
void showPreOrd(No *root);
void showPosOrd(No *root);
void showInOrd(No *root);

void init(iArvBin *arv){
	arv->root = (No*) malloc (sizeof(No));
	arv->size = 0;
}

int add(iArvBin *arv, void *data){
	No *novo =(No*) malloc (sizeof(No));
	novo->data = data;
	
 	if(arv->size == 0){
		arv->root = novo;
	}else{
		No *aux = arv->root;
		busca(aux, data);
				
		if(!aux->right) aux->right = novo;
			else{
				if(!aux->left) aux->left = novo;
				else{
					busca(aux, data);
				}				
			}
	}	
	arv->size++;
}

No* busca(No *no, void *data){
	No *aux;
	if(data >= no->data){
		for(aux = no->right; aux->data <= data || aux->right; aux = aux->right);
	}
	else{
		for(aux = no->left; aux->data <= data || aux->left; aux = aux->left);
	}
	return no;
}

int size(iArvBin *arv){
	return arv->size;
}

void show(iArvBin *arv, int opcao){	
	if(arv->size==0) printf("\nArvore vazia\n");
	else{
		switch(opcao){
			case 1:
				showInOrd(arv->root);
				break;
			case 2:
				showPreOrd(arv->root);
				break;
			case 3:
				showPosOrd(arv->root);
				break;
			default: break;				
		}
	}
}

void showPreOrd(No *root){
	if (root == NULL) return;
    printf("%d\n", root->data); 
    showPreOrd(root->left);
    showPreOrd(root->right);
	
}
void showPosOrd(No *root){
	if (root == NULL) return;
    showPosOrd(root->left);
    showPosOrd(root->right);
    printf("%d\n", root->data); 
}

void showInOrd(No *root){
	if (root == NULL) return;
    showInOrd(root->left);
    printf("%d\n", root->data); 
    showInOrd(root->right);
	
}

#endif

