/* Leia um caractere maiúsculo, que indica uma operação que deve ser realizada e uma matriz M[12][12]. 
Em seguida, calcule e mostre a soma ou a média considerando somente aqueles elementos que estão na área 
direita da matriz, conforme ilustrado abaixo (área verde).

Entrada
A primeira linha de entrada contem um único caractere Maiúsculo O ('S' ou 'M'), indicando a operação 
(Soma ou Média) que deverá ser realizada com os elementos da matriz. Seguem os 144 valores de ponto 
flutuante que compõem a matriz.

Saída
Imprima o resultado solicitado (a soma ou média), com 1 casa após o ponto decimal.*/

#include <stdio.h>

int main(void){
	//Declarar as variaveis
	char o;
	int linha,coluna;
	double matriz[12][12],soma=0,media=0;

	//Definir se sera soma ou média
	scanf("%c", &o);

	//Receber valores da matriz
	for (linha=0;linha<12;linha++){
		for (coluna=0;coluna<12;coluna++){
			scanf("%lf", &matriz[linha][coluna]);
		}
	}

	//Calcular soma (divide em duas partes)
	//primeira parte
	for (linha = 1; linha < 6; linha++) {
		for (coluna = 11; coluna> 11-linha; coluna--) {
			soma += matriz[linha][coluna];
		}
    }

	//segunda parte
	for (linha = 6; linha < 11; linha++) {
		for (coluna=linha+1; coluna<12; coluna++) {
			soma += matriz[linha][coluna];
		}
    }

	//Calcular média
	media = soma/30.0;

	//Imprimir resultado se for soma ou média
	if (o=='S'){
		printf("%.1lf\n", soma);
	}
	else{
		printf("%.1lf\n", media);
	}

	return 0;
}