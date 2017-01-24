#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrixList.h"

#define SIZE_CHAR 50
#define MATRIX 32
#define MULT 30


void espalhamento(char file[SIZE_CHAR]);
void ppm(char imagem[SIZE_CHAR]);

void main() {
	int lista;
	
	printf("\nAbrir arquivo: ");
	printf("\n1: palavras-ingles");
	printf("\n2: palavras-portugues\n");
	scanf("%d", &lista);
	
	switch(lista){
		case 1:
			espalhamento("palavras-ingles.txt");
			printf("\nCriando arquivo ppm\n");
			ppm("Imagem-ingles");
			break;
		case 2:
			espalhamento("palavras-portugues.txt");
			printf("\nCriando arquivo ppm\n");
			ppm("Imagem-portugues");
			break;
	}
	

}

void espalhamento(char file[SIZE_CHAR]){
	FILE *arquivo;
	
	MatrixHash list; 
  	init(&list);
  	
	arquivo = fopen(file, "r");
	if(arquivo == NULL) printf("\nERRO!!!");
	else{
		char word[SIZE_CHAR];
		while(fgets(word, SIZE_CHAR, arquivo) != NULL){
			add(&list, word);
		}
	}	
	fclose(arquivo);
	
}

void ppm(char imagem[SIZE_CHAR]){
	int i, j, k, w; //contadores
	
	strcat(imagem, ".ppm");
	FILE *img = fopen(imagem, "w");

	if(img == NULL) printf("\nERRO AO CRIAR IMAGEM\n");
	
	else{
		fprintf(img, "\n%s", "P3");
		fprintf(img, "\n%d %d", MULT*MATRIX, MULT*MATRIX);
		fprintf(img, "\n%d\n", 255);
		
		for(i=0; i<MATRIX; i++){
			
		}
	}
	fclose(img);
}


