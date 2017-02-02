#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hashfunction2.h"

#define SIZE_CHAR 50 	// tamanho maximo do word
#define MAX_VETOR 1024 	// tamanho do vetor
#define PIXEL 32		// tamanho de cada pixel
#define MULTIPLI 30		// escala da imagem em relação ao pixel


int vetorP1[MAX_VETOR];	// vetor de palavras em portugues 1
//int vetorP2[MAX_VETOR];	// vetor de palavras em portugues 2
//int vetorE1[MAX_VETOR];	// vetor de palavras em ingles 1
//int vetorE2[MAX_VETOR];	// vetor de palavras em ingles 2
int maxV;				// maior falor do colisoes do hash

void vetor(char filename[SIZE_CHAR], int option);			// monta o velor
void max();				// acha o maior valor
void graphicGeration(char imagename[SIZE_CHAR]);	// cria a imagem
int Color(int vValor);	// calcular a cor
void zerar();

int main(){				// programa principal
						// so chama as funcoes

	// gerar imagem da lista em portugues



	vetor("ListaDePalavrasPT.txt", 1);
	max();
	graphicGeration("PortuguesF1");
	zerar();

	vetor("ListaDePalavrasPT.txt", 2);
	max();
	graphicGeration("PortuguesF2");
	zerar();

	// gerar imagem da lista em ingles


	vetor("ListaDePalavrasEN.txt", 1);
	max();
	graphicGeration("InglesF1");
	zerar();

	vetor("ListaDePalavrasEN.txt", 2);
	max();
	graphicGeration("InglesF2");
	zerar();



	return 0;
}

void vetor(char filename[SIZE_CHAR],int option){			// abre o arquivo .txt e monta o velor
	int i=0;
						// nome do arquivo txt
   	dictionaryHashLinked hash;
	dInit(&hash);		// inicia o hash

	FILE *file = fopen(filename, "r");	// abre o arquivo em modo de leitura
	if(file == NULL){	//verifica se o arquivo foi existe
		printf("Error file doesn't exist\n");
	}else{
		char word[SIZE_CHAR];
		while(fgets(word, SIZE_CHAR, file) != NULL){ //le a linha do arquivo
			i = put(&hash, word, i, option);	// i recebe o valor da posição da palavra
			vetorP1[i]++;				// soma mais um para posicao i
		}
	}
	fclose(file);	//	fecha arquivo
}

void max(){							// procura o maior valor do vetor
	int i=0;
	maxV = vetorP1[0];				// maxV recebe o primeiro valor do vetor

	for(i = 1; i< MAX_VETOR; i++){	// percorre o vetor
		if(maxV < vetorP1[i])		// se o manV for menor que o dado do vetor i
			maxV = vetorP1[i];		// maxV recebe o dado do vetor i
	}
}

void graphicGeration(char imagename[SIZE_CHAR]){			// gera a imagem
	int cor[PIXEL];				// vetor com as cores que vão ser usadas em uma linha
	int i, j, k, x, y, z, b;	// variaveis
	char name[256];				// nome do arquivo;
	k=0;						// atribuindo o valor 0 para a variavel k


    strcpy(name,imagename);
    strcat(name,".ppm\0");

	FILE *ppm = fopen(name, "w+"); //cria arquivo
	if(ppm == NULL){
		printf("Error create file\n");

	}else{
		fprintf(ppm, "%s\n","P3");		// cabecario tipo da ppm
		fprintf(ppm, "%d  %d\n", PIXEL * MULTIPLI, PIXEL * MULTIPLI); // tamanho
		fprintf(ppm, "%d\n",255);	// valor maximo

		for(i = 0; i < PIXEL; i++){		// altura da imagem
			for (j = 0; j < PIXEL; j++, k++){	// loop para colocar o valor das cores
				cor[j] = Color(vetorP1[k]);		// cor
			}
			for(x = 0; x < MULTIPLI; x++){		// loop de multicador da altura
				for (y = 0; y < PIXEL; y++){	// loop da largura
					for (z = 0; z < MULTIPLI; z++){	// loop multiplicado da largura
						fprintf(ppm, "%d  %d  %d ", 255, cor[y], 255);	// escreve no arquivo os dados para criar a imagem
					}
				}
				fprintf(ppm, "\n"); // pula linha do arquivo
			}
		}
	}
	fclose(ppm); //fecha arquivo
}

int Color(int vValor){		// cor
    return 255 -  ((255*vValor)/maxV); //recebe o numero de colisões multiplica pelo falor maximo da cor e depois divide pelo valor maximo do vetor
}


void zerar(){
    int i;

    for(i = 0; i < 1024; i++ ){
        vetorP1[i]=0;
    }
}
