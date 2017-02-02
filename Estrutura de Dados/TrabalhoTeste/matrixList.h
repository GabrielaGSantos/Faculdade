#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 50
#define MATRIX_HW 32

typedef struct Node {
	struct Node *next;
	char key[KEY_SIZE];
} Node;

typedef struct List {
	Node *first;
	Node *last;
	int colisoes;
} List;

typedef struct MatrixHash {
	List listMatrix[MATRIX_HW][MATRIX_HW];
} MatrixHash;

void init(MatrixHash *matrix);
int funcaoHash(char key[KEY_SIZE]);
int add(MatrixHash *matrix, char key[KEY_SIZE]);

void init(MatrixHash *matrix) {
	int i, j;
	for (i = 0; i < MATRIX_HW; i++) {
		for (j = 0; j < MATRIX_HW; j++) {
			matrix->listMatrix[i][j].first = NULL;
			matrix->listMatrix[i][j].last = NULL;
			matrix->listMatrix[i][j].colisoes = 0;
		}
	}
}

int funcaoHash(char key[KEY_SIZE]){
	int i, acumulator = 0;

	for (i = 0; i < KEY_SIZE; i++)
		acumulator += key[i]*(i+1);

	return acumulator%MATRIX_HW;
}

int add(MatrixHash *matrix, char key[KEY_SIZE]){
	int hash = funcaoHash(key);
	int linha = hash/32;
	int coluna = hash - (linha*32);
	
	Node *new = (Node*)malloc(sizeof(Node));
	if (new == NULL) return 0;
	strcpy(new->key,key);
	new->next = NULL;
	
	if(matrix->listMatrix[linha][coluna].first == NULL)
		matrix->listMatrix[linha][coluna].first = matrix->listMatrix[linha][coluna].last = new;				
	else{
		matrix->listMatrix[linha][coluna].last->next = new;
		matrix->listMatrix[linha][coluna].last = new;		
	}
	
	matrix->listMatrix[linha][coluna].colisoes++;
	
}


