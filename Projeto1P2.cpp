#include<stdio.h>


void cardapio(){
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
	}while(op != 6 || op>6 );
	
}
	

