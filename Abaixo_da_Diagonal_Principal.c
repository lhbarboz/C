/* Leia um caractere maiúsculo, que indica uma operação que deve ser realizada e uma matriz M[12][12]. 
Em seguida, calcule e mostre a soma ou a média considerando somente aqueles elementos que estão abaixo 
da diagonal principal da matriz, conforme ilustrado abaixo (área verde).

Entrada
A primeira linha de entrada contem um único caractere Maiúsculo O ('S' ou 'M'), indicando a operação 
(Soma ou Média) que deverá ser realizada com os elementos da matriz. Seguem os 144 valores de ponto 
flutuante que compõem a matriz.

Saída
Imprima o resultado solicitado (a soma ou média), com 1 casa após o ponto decimal.*/

#include <stdio.h>

int main(void){
	//Definir variaveis
	int linha, coluna;
	char o;
	float matriz[12][12],soma,media;

	//Definir se será soma ou média
	scanf("%c\n", &o);

	//Receber os valores da matriz
	for (linha=0;linha<12;linha++){
		for (coluna=0;coluna<12;coluna++){
			scanf("%f", &matriz[linha][coluna]);
		}
	}

	//Calcular a soma
	for (linha=1;linha<12;linha++){
		for (coluna=0;coluna<linha;coluna++){
			soma+= matriz[linha][coluna];
		}
	}

	//Calcular a média
	media=soma/66;

	//Imprimir de acordo se foi soma ou média
	if (o=='S'){
		printf("%.1f\n", soma);
	}
	else{
		printf("%.1f\n", media);
	}

	return 0;
}