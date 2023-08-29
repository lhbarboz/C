/* Escreva um programa que receba o nome, o telefone e a data de nascimento de n pessoas, 
com 1 <= n <= 100, e implemente uma agenda telefônica com duas listagens possíveis: 

(i) uma lista dos nomes, telefones e datas de aniversário das pessoas em ordem
alfabética de nomes e 
(ii) uma lista dos nomes, telefones e datas de aniversário das pessoas em ordem 
crescente de datas de aniversários das pessoas.

Considere que cada nome tenha no máximo 50 caracteres, o telefone é composto por 
um númro inteiro positivo com até 3 dígitos representando o DDD e mais um número 
inteiro de 8 dígitos representando o número do telefone, e a data de nascimento é 
fornecida no formato dd/mm/aaaa. */

#include <stdio.h>
#include <string.h>
#include "DATA_PARA_NUMERO_SEM_NUM.h"

/* Define o n (numero de pessoas), i (usado apenas de referencia no for), opcao (usado pra definir qual agenda será selecionada),
a e b (usado apenas de referência para o for de ordenação) e r (usado para comparar strings no for) */
int n, i, opcao, a, b, r;
int numformula[100];

int main(void){

	//Cria a struct com os dados
	struct{
		char nome[50];
		long int telefone;
		int dia, mes, ano;
	}pessoas[100], aux;

	//Define quantas pessoas serão recebidas
	fflush(stdin);
	printf("Quantas pessoas serão recebidas? ");
	scanf("%d", &n);

	//Recebe os dados
	for (i=0;i<n;i++){
		fflush(stdin);
		printf("Digite o nome: ");
		scanf(" %[^\n]", pessoas[i].nome);

		fflush(stdin);
		printf("Digite o telefone com DDD e sem o 9: ");
		scanf(" %ld", &pessoas[i].telefone);

		fflush(stdin);
		printf("Digite a data de nascimento (dd/mm/aaaa): ");
		scanf("%d/%d/%d", &pessoas[i].dia, &pessoas[i].mes, &pessoas[i].ano);
	}

	//Define qual agenda quer que seja exibido
	fflush(stdin);
	printf("\nOpção 1: ordena em ordem alfabetica de nomes\n");
	fflush(stdin);
	printf("Opção 2: ordena em ordem crescente de datas de aniversários\n");
	fflush(stdin);
	printf("\nQual agenda telefônica você gostaria de ver?\n");

	scanf("%d", &opcao);

	//Opção 1 de agenda telefonica: ordena em ordem alfabetica de nomes
	if (opcao == 1){
		for (a=0;a<n;a++){
			for (b=a+1;b<n;b++){
				r = strcmp(pessoas[a].nome, pessoas[b].nome);
				if (r > 0){
					aux = pessoas[a];
					pessoas[a] = pessoas[b];
					pessoas[b] = aux;
				}
			}
		}
	}

	//Opção 2 de agenda telefonica: ordena em ordem crescente de datas de aniversários
	else if (opcao == 2){
		
		for (i=0;i<n;i++){
			numformula[i] = DATA_PARA_NUMERO_SEM_NUM(pessoas[i].dia,pessoas[i].mes,pessoas[i].ano);
		}

		for (a=0;a<n;a++){
			for (b=a+1;b<n;b++){
				if (numformula[a] > numformula[b]){
					aux = pessoas[a];
					pessoas[a] = pessoas[b];
					pessoas[b] = aux;
				}
			}
		}
	}

	//Imprime a agenda final
	for (i=0;i<n;i++){
		fflush(stdin);
		printf("Nome: %s, Telefone: %011ld, Aniversário: %02d/%02d/%d\n", pessoas[i].nome, pessoas[i].telefone, pessoas[i].dia, pessoas[i].mes, pessoas[i].ano);
	}

	return 0;
}