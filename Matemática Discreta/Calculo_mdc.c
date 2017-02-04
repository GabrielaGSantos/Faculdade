#include <stdio.h>
#include <stdlib.h>

//Cálculo mdc, algoritmo de euclides

int main() {
	int x, y, resto, a, b, mdc;
	
	printf("\nmdc(X,Y)");
	printf("\nValor de X: ");
	scanf(" %d", &x);
	printf("\nValor de Y: ");
	scanf(" %d", &y);
	
	if(x>y){
		a = x;
		b = y;
	}
	else{
		a = y;
		b = x;
	}
	
	while(b!=0){
		mdc = b;
		resto = a%b;
		a = b;
		b = resto;
	}
	
	printf("\n\n\nO mdc(%d,%d) e: %d", x, y, mdc);
	
	return 0;
}
