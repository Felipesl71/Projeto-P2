#include<stdio.h>
#include <stdlib.h>
#define senha 34

struct pratos
{
	char nomePrt[10];
	float valorPrt;
	int codpt;
}TPrato[20];

struct pedido
{
    char nomePes[15];
	char nomePed[30];
    char CPF[15];
    char qtdPed[50];
    char valorped[200];
    int vazio,cod;
}TPedido[200];

int verifica_cod( int cod ); // VERIFICADOR DE CÓDIGO

int verifica_pos( void ); //VERIFICADOR DA POSIÇÃO

int tamanhoArray();// tamanho

void realizarpedido();// cadastro de pedido

void admin();// acesso do administrador

float conta();// Conta de cada cliente

void cardapio();// Mostra cardápio
    
void alterarpedido();

void excluir();



main(){
	int op,posicao,codaux,retorno;
	do{
	printf("\tMenu");
		printf("\n1- Mostrar cardapio ");
		printf("\n2- Realizar pedido ");
		printf("\n3- Conta ");
		printf("\n4- Alterar pedido");
		printf("\n5- Excluir pedido");
		printf("\n6- Admin");
		printf("\n7- Sair");
		printf("\nInforme a opcao desejada:");
		scanf("%d",&op);
		system("cls");
		if(op == 1){
			cardapio();
		}else if(op == 2){
			 printf("\nRealizando pedido\n");
             realizarpedido();
			}
		else if(op == 3){
			conta();
			
			}
		else if(op == 4){
			}
		else if(op == 5){
			excluir();
			}
		else if(op == 6){
			
				admin();
				
			}
		else if(op == 7){
			printf("Creditos xxxx");
				printf("Saindo do programa!");
		}		
		 else{
            printf("Opcao invalida, voltando ao menu principal!");
            
           
		}
		
	}while(op != 7 || op<7 );
	
}

int verifica_cod( int cod ){ // VERIFICADOR DE CÓDIGO
    int cont = 0;

    while ( cont <= 200 )
    {
        if ( TPedido[cont].cod == cod )
            return(0);

        cont++;
    }

    return(1);

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

int tamanhoArray(){
	int cont = 0;
	for(int i= 0; i<200; i++){
		if(TPedido[i].cod != NULL){
			cont++;
		}
	}
	return cont;
	
}



void realizarpedido(){
	int op;
    do{
    	int codaux,retorno;
		printf("\nEntre com um codigo para seu pedido: \n");
        scanf("%d",&codaux);
		fflush(stdin);
        retorno = verifica_cod( codaux );
		if(retorno ==1){
			int tamA;
			tamA = tamanhoArray(); 		
			TPedido[tamA].cod = codaux;
        	printf("\nDigite seu nome: ");
        	gets(TPedido[tamA].nomePes);
        	printf("\n");
        	cardapio();
        	printf("\n");
        	printf("\nDigite seu pedido: ");
        	gets(TPedido[tamA].nomePed);
        	printf("\nDigite a quantidade do seu pedido: ");
        	gets(TPedido[tamA].qtdPed);
        	printf("\nVoce escolheu %s unidades da opcao %s,\nseu pedido foi efetuado com sucesso.\n\n",TPedido[tamA].qtdPed,TPedido[tamA].nomePed);
      		printf("Deseja continuar?(1-continuar, 0-voltar ao menu principal): ");
      		scanf("%d",&op);
		getchar();
	}else{
			printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
            op ==1;
			getchar();
	}
    }while(op==1);
  
	
}

void admin(){
	int senha_aux; 
	printf("Informe a senha: ");
	scanf("%d",&senha_aux);
	fflush(stdin);
if (senha_aux == senha) {
  printf("A senha confere, bem vindo Alcides!\n\n");
  int op;
    do{
    	int codptaux,retorno;
		printf("\nEntre com um codigo para seu prato: \n");
        scanf("%d",&codptaux);
		fflush(stdin);
        retorno = verifica_cod( codptaux );
		if(retorno ==1){
			int tamB;
			tamB = tamanhoArray(); 		
			TPrato[tamB].codpt = codptaux;
        	printf("\nDigite o nome do prato: ");
        	gets(TPrato[tamB].nomePrt);
        	printf("\n");
        	printf("\nDigite o preço do prato: ");
        	scanf("%f",&TPrato[tamB].valorPrt);
        	printf("\nSr. Alcides, voce cadastrou o prato %s ,com o valor de %1.1f,\n cadastro realizado com sucesso\n\n",TPrato[tamB].nomePrt,TPrato[tamB].valorPrt);
      		printf("Deseja continuar?(1-continuar, 0-voltar ao menu principal): ");
      		scanf("%d",&op);
		getchar();
	}else{
			printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
            op ==1;
			getchar();
	}
    }while(op==1);
  
  
  
}
else
  printf("As senha está incorreta, voltando ao menu inicial\n");

}

void cardapio(){

}

float conta(){

    int i;
    for(i=0;i< 200;i++){
    	
        if(TPedido[i].cod != NULL){
        	printf(" %d",TPedido[i].cod);
            printf("\nNome do pessoa: %s \nNome da pedido: %s\nQuantidade do pedido: %s\n\n", TPedido[i].nomePes,TPedido[i].nomePed,TPedido[i].qtdPed);
		}
	}
}


void alterarpedido(){
	
}
void excluir(){
	char flag;
	do{
	int cod2, cont,retorno2,tamA;
    char resp;
    printf("\nEntre com o codigo do registro que deseja excluir: \n");
    scanf("%d", &cod2);
    fflush(stdin);
	retorno2 = verifica_cod( cod2 );
	tamA = tamanhoArray(); 
            printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", TPedido[tamA].nomePes,TPedido[tamA].nomePed,TPedido[tamA].qtdPed);
            getchar();
            printf("\nDeseja realmente exlucir? s/n: ");
            scanf("%s",&resp);
            if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    TPedido[tamA].vazio= 0;
                    TPedido[tamA].cod = NULL;
                    printf("\nExclusao feita com sucesso\n");
                }
                else if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclusao cancelada!\n");
                    
                    }
		printf("Deseja continuar a excluir?(1-continuar, 0-voltar ao menu principal): ");
      		scanf("%c",&flag);
		getchar();
	
 }while( flag == '1');
   }
