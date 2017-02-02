#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrixList.h"

#define SIZE_CHAR 50
#define MATRIX 32
#define MULT 30


void espalhamento(char file[SIZE_CHAR], MatrixHash *list);
void ppm(char *imagem, MatrixHash *matrix);

void main() {
	int lista;
	
	printf("\nAbrir arquivo: ");
	printf("\n1: palavras-ingles");
	printf("\n2: palavras-portugues\n");
	scanf("%d", &lista);
	
	MatrixHash list; 
  	init(&list);
  	
	switch(lista){
		case 1:
			espalhamento("palavras-ingles.txt", &list);
			printf("\nCriando arquivo ppm\n");
			ppm("Imagem-ingles", &list);
			break;
		case 2:
			espalhamento("palavras-portugues.txt", &list);
			printf("\nCriando arquivo ppm\n");
			ppm("Imagem-portugues", &list);
			break;
	}
	

}

void espalhamento(char file[SIZE_CHAR], MatrixHash *list){
	FILE *arquivo;
	
	arquivo = fopen(file, "r");
	if(arquivo == NULL) printf("\nERRO!!!");
	else{
		char word[SIZE_CHAR];
		while(fgets(word, SIZE_CHAR, arquivo) != NULL){
			add(list, word);
		}
	}	
	fclose(arquivo);
	
}

void ppm(char *imagem, MatrixHash *matrix){
	int i, j, k, w; //contadores
	
	strcat(imagem, ".ppm");
	FILE *img = fopen(imagem, "w");

	if(img == NULL) printf("\nERRO AO CRIAR IMAGEM\n");
	
	else{
		fprintf(img, "\n%s", "P3");
		fprintf(img, "\n%d %d", MULT*MATRIX, MULT*MATRIX);
		fprintf(img, "\n%d\n", 255);
		
		for(i=0; i<MATRIX; i++){
			for(k=0; k<MULT; k++){
				for(j=0; j<MATRIX; j++){
					for(w=0; w< MULT; w++){
						fprintf(img, "%d %d %d ", 255, 10 ,255);
					}
				} fprintf(img, "\n");
			}
		}
	}
	fclose(img);
}


