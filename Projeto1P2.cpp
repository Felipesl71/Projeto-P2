#include<stdio.h>

struct pedido
{
    char nomePes[15];
	char nomePed[30];
    char CPF[15];
    char numPed[10];
    char qtdPed[50];
    char valorped[200];
    int cod;
}TPedido[200];



void cardapio(){
	printf("Lanchonete do Alcides");
	printf("\n Cachorro quente");
	printf("\n Hanburguer");
	printf("\n Coxinha");
	printf("\n X tudo");
}

void realizarpedido(){
	
	
}

float conta(){
	
}

void alterarpedido(){
	
}
void excluir(){
	
}


main(){
	int op;
	do{
	
		printf("\tMenu");
		printf("\n1- Mostrar cardapio ");
		printf("\n2- Realizar pedido ");
		printf("\n3- Conta ");
		printf("\n4- Alterar pedido");
		printf("\n5- Excluir pedido");
		printf("\n6- Sair");
		printf("\nInforme a opcao desejada:");
		scanf("%d",&op);
		if(op == 1){
			cardapio();
		}else if(op == 2){
			}
		else if(op == 3){
			
			}
		else if(op == 4){
			}
		else if(op == 5){
			}
		else if(op == 6){
			
				printf("Creditos xxxx");
				printf("Saindo do programa!");
				
			}	
	}while(op != 6 || op>6 );
	
}
	

