#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Método da Bisecção

void MetodoBiseccao(float lInferior, float lSuperior, float tolerancia, int interacoes, int interacaoAtual); //Método da bisecçao
float funcao(float x); //função para calcular as raízes

int main(){
	printf("\nInteracao \t Limite Inferior \t Limite Superior \t Xr Atual \t\t Erro");
	MetodoBiseccao(300, 400, 0.00001, 100, 0);
	printf("\n_________________________________________________________________________________________________\n");
	printf("\nInteracao \t Limite Inferior \t Limite Superior \t Xr Atual \t\t Erro");
	MetodoBiseccao(-400, -300, 0.0001, 100, 0);
	return 0;
}


void MetodoBiseccao(float lInferior, float lSuperior, float tolerancia, int interacoes, int interacaoAtual){
	float xr = (lInferior+lSuperior)/2; 
	float erroAtual = (fabs(funcao(xr)));
	
	printf("\n\b\b%d\t\t%f\t\t%f\t\t%f\t\t%f", interacaoAtual, lInferior, lSuperior, xr, erroAtual);
	
	if((funcao(lInferior)*funcao(xr)) < 0){
		lSuperior = xr;
	}
		else if((funcao(lSuperior)*funcao(xr)) < 0)	{
			lInferior = xr;
		}
		else if((funcao(lInferior)*funcao(xr) || funcao(lSuperior)*funcao(xr)) == 0){
			printf("\n\nA raiz e: %f", xr);
			return;
		}			
	else{
		printf("\n\nNao ha raizes entre os intervalos\n");
		return;
	}
	
	if(erroAtual <= tolerancia){
		printf("\n\nA raiz e: %f", xr);
		return;
	}
	else{
		if(interacaoAtual < interacoes){
			MetodoBiseccao(lInferior, lSuperior, tolerancia, interacoes, interacaoAtual+1);	
		}
		else{
			printf("\n\nErro!! Numero maximo de interacoes atingido");
			return;
		}
	}
	
}


float funcao(float x){ //função para calcular as raízes
	return(100*exp(-0.005*x)*cos(sqrt(2000-(pow(x,2)/100))*0.05)-1);
}

