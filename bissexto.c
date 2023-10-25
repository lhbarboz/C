#include <stdio.h>

struct data{
	int dia, mes, ano;
};

int bissexto(struct data d){
	if (((d.ano%4==0) && (d.ano%100!=0)) || (d.ano%400==0)){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	struct data d;
	printf("Digite uma data (dd/mm/aaaa): ");
	scanf("%d/%d/%d", &d.dia,&d.mes,&d.ano);
	if (bissexto(d) == 1){
		printf("É bissexto\n");
	}
	else{
		printf("Não é bissexto\n");
	}

	return 0;
}