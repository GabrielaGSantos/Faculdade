
#ifndef DICTIONARYHASHLINKED_H_
#define DICTIONARYHASHLINKED_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define KEY_SIZE 50
#define HASH_TABLE_SIZE 1024

typedef struct no {
	struct no *next;
	char key[KEY_SIZE];
    void *value;
}no;

typedef struct dictionaryHashLinked {
    no *hashTable[HASH_TABLE_SIZE];
    int size;
}dictionaryHashLinked;

void  dInit		  (dictionaryHashLinked *dict);
int   hashFunction1(char key[KEY_SIZE]);
int   hashFunction2(char key[KEY_SIZE]);
void* getValue	  (dictionaryHashLinked *dict, char key[KEY_SIZE], int option);
int   put		  (dictionaryHashLinked *dict, char key[KEY_SIZE], void *value, int option);
void  removeByKey (dictionaryHashLinked *dict, char key[KEY_SIZE], int option);
int   dIsEmpty	  (dictionaryHashLinked *dict);
int   dSize		  (dictionaryHashLinked *dict);
void  dShow		  (dictionaryHashLinked *dict);
char  name 		  (char option);

void dInit (dictionaryHashLinked *dict) {
	int i;
	for (i = 0; i < HASH_TABLE_SIZE; i++)
		dict->hashTable[i] = NULL;
	dict->size = 0;
}

int hashFunction1(char key[KEY_SIZE]) {
	int i, acumulator = 0;

	for ( i = 0; i < KEY_SIZE; i++)
		acumulator += key[i]*((i+3)/(2+i));

	return acumulator%HASH_TABLE_SIZE;
}

int hashFunction2(char key[KEY_SIZE]) { // esse é teste tem que fazer ainda
	int i, acumulator = 0;

	for ( i = 0; i < KEY_SIZE; i++)
		acumulator += key[i]*(i+1);
		//acumulator += key[i]*((i+3)/(2+i));

	return acumulator%HASH_TABLE_SIZE;
}

void* getValue (dictionaryHashLinked *dict, char key[KEY_SIZE],int option) {

	no *aux;
	if(option == 1){

		for (aux = dict->hashTable[hashFunction1(key)]; aux!=NULL; aux=aux->next)
			if (strcmp(key,aux->key)==0) return aux->value;
	}else{
		if (option == 2){
			for (aux = dict->hashTable[hashFunction2(key)]; aux!=NULL; aux=aux->next)
				if (strcmp(key,aux->key)==0) return aux->value;
		}
	}

	return NULL;
}

int put	(dictionaryHashLinked *dict, char key[KEY_SIZE], void *value, int option) {
    int hash;
	if (option == 1){
		hash = hashFunction1(key);
	}else{
		if(option == 2){
			hash = hashFunction2(key);
		}
	}


	if (dict->hashTable[hash] == NULL) {
		no *new = (no*)malloc(sizeof(no));
		if (new == NULL) return 0;
		strcpy(new->key,key);
		new->value = value;
		new->next = NULL;
		dict->hashTable[hash] = new;
		dict->size++;
		return hash;
	}

	no *aux;
	for (aux = dict->hashTable[hash]; aux->next!=NULL && strcmp(key,aux->next->key)>0; aux=aux->next);

	if (aux->next != NULL && strcmp(aux->next->key,key)==0) return -1; // ja existe essa chave

	no *new = (no*)malloc(sizeof(no));
	if (new == NULL) return 0;
	strcpy(new->key,key);
	new->value = value;

	new->next = aux->next;
	aux->next = new;

	dict->size++;

	return hash;
}

void removeByKey (dictionaryHashLinked *dict, char key[50], int option) {

    int hash;

	if (option == 1){
		hash = hashFunction1(key);
	}else{
		if(option == 2){
			hash = hashFunction2(key);
		}
	}

	if (dict->hashTable[hash] == NULL) return;

	if (dict->hashTable[hash]->next == NULL && strcmp(key,dict->hashTable[hash]->key)==0) {
				free(dict->hashTable[hash]);
				dict->size--;
				return;
	}

	no *aux;
	for (aux = dict->hashTable[hash]; aux->next!=NULL && strcmp(key,aux->next->key)!=0; aux=aux->next);

	if (aux->next!=NULL && strcmp(key,aux->next->key)==0) {
		no *noRem = aux->next;
		aux->next = noRem->next;
		free (noRem);
		dict->size--;
	}
}

int dIsEmpty (dictionaryHashLinked *dict) {
	return dict->size==0;
}

int dSize (dictionaryHashLinked *dict) {
	return dict->size;
}

void dShow	(dictionaryHashLinked *dict) {
	int i;
	for ( i = 0; i < HASH_TABLE_SIZE; i++) {
		no *aux;
		for (aux = dict->hashTable[i]; aux!=NULL; aux=aux->next)
			printf("%s -> ", aux->key);
		printf("\n");
	}

}

#endif
