/*Júlio César usava um sistema de criptografia, agora conhecido como Cifra de César, que 
trocava cada letra pelo equivalente em duas posições adiante no alfabeto (por exemplo, 
'A' vira 'C', 'R' vira 'T', etc.). Ao final do alfabeto nós voltamos para o começo, isto é 
'Y' vira 'A'. Nós podemos, é claro, tentar trocar as letras com quaisquer número de posições.

Entrada
A entrada contém vários casos de teste. A primeira linha de entrada contém um inteiro N que 
indica a quantidade de casos de teste. Cada caso de teste é composto por duas linhas. A primeira 
linha contém uma string com até 50 caracteres maiúsculos ('A'-'Z'), que é a sentença após ela ter 
sido codificada através desta Cifra de César modificada. A segunda linha contém um número que varia 
de 0 a 25 e que representa quantas posições cada letra foi deslocada para a direita.

Saída
Para cada caso de teste de entrada, imprima uma linha de saída com o texto decodificado (transformado 
novamente para o texto original) conforme as regras acima e o exemplo abaixo.*/
#include <stdio.h>

int main(void){
	//definir variaveis
	int n,posicoes,i,j=0;
	char sentenca[51];

	//definir quantidade de testes
	scanf("%d", &n);

	for (i=0;i<n;i++){ //pra cada teste
		//receber sentença apos ela ser codificada
		scanf(" %[^\n]", sentenca);

		//receber quantas posicoes cada letra foi deslocada para a direita
		scanf("%d", &posicoes);

		//descodificar
		while (sentenca[j]!='\0'){
			sentenca[j]= 'A'+(sentenca[j]-'A'-posicoes+26)%26;
			j++;
		}

		//imprimir para cada caso, o texto descodificado
		printf("%s\n", sentenca);
		j=0;
	}

	return 0;
}