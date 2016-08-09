#include<stdio.h>
#include <stdlib.h>
struct pedido
{
    char nomePes[15];
	char nomePed[30];
    char CPF[15];
    char qtdPed[50];
    char valorped[200];
    int vazio,cod;
}TPedido[200];

int op;
int verifica_cod( int cod ) // VERIFICADOR DE CÓDIGO
{
    int cont = 0;

    while ( cont <= 200 )
    {
        if ( TPedido[cont].cod == cod )
            return(0);

        cont++;
    }

    return(1);

}

void cardapio(){
	printf("Lanchonete do Alcides");
	printf("\n Cachorro quente");
	printf("\n Hanburguer");
	printf("\n Coxinha");
	printf("\n X tudo");
}

int verifica_pos( void ) //VERIFICADOR DA POSIÇÃO
{
    int cont = 0;

    while ( cont <= 200 )
    {

        if ( TPedido[cont].vazio == 0 )
            return(cont);

        cont++;

    }

    return(-1);

} 

void realizarpedido(int cod,int pos){
	int i;
    do{
    	pos = verifica_pos();
    	TPedido[pos].cod = cod;
        printf("\nDigite seu nome: ");
        gets(TPedido[pos].nomePes);
        printf("\n");
        cardapio();
        printf("\n");
        printf("\nDigite seu pedido ");
        gets(TPedido[pos].nomePed);
        printf("\nDigite a quantidade do seu pedido: ");
        gets(TPedido[pos].qtdPed);
       // TPedido[pos].vazio = 1;
      
        op ==1;
        getchar();
    }while(op==1);
  
	
}

float conta(){
	
}

void alterarpedido(){
	
}
void excluir(){
	
}



main(){
	int op,posicao,codaux,retorno;
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
			 printf("\nVoce selecionou a opcao 2 - Realizar pedido\n");
            posicao=verifica_pos();

                if ( posicao != -1 )
                {

                    printf("\nEntre com um codigo de 1 a 200 para seu pedido: \n");
                    scanf("%d",&codaux);fflush(stdin);

                    retorno = verifica_cod( codaux );

                    if ( retorno == 1 )
                        realizarpedido( codaux, posicao );
                    else{
                        printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
                        getchar();
                       
                        
                    }
			}
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
		 else{
            printf("Opcao invalida, voltando ao menu principal!");
            
           
		}
		
	}while(op != 6 || op<6 );
	
}
	

