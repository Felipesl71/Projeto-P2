#include<stdio.h>
#include <stdlib.h>
#define senha 34

struct pratos
{
	char nomePrt[10];
	float valorPrt;
	int codpt,vazio;
}TPrato[20];

struct pedido
{
    char nomePes[15];
	char nomePed[30];
    char CPF[15];
    int qtdPed,vazio,cod;
    struct TPrato;
}TPedido[200];

int verifica_cod( int cod ); // VERIFICADOR DE C�DIGO

int tamanhoArray();// tamanho

int tamanhoArraypt();

void realizarpedido();// cadastro de pedido

void admin();// acesso do administrador

float conta();// Conta de cada cliente

void cardapio();// Mostra card�pio
    
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
			system("pause");
			system("cls");		
			
		}else if(op == 2){
			 printf("\nRealizando pedido\n");
             realizarpedido();
             system("pause");
			 system("cls");	
            
			}
		else if(op == 3){
			conta();
			system("pause");
			system("cls");	
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

int verifica_cod( int cod ){ // VERIFICADOR DE C�DIGO
    int cont = 0;

    while ( cont <= 200 )
    {
        if ( TPedido[cont].cod == cod )
            return(0);

        cont++;
    }

    return(1);

}
int verifica_codpt( int codpt ){ // VERIFICADOR DE C�DIGO PRATO
    int cont = 0;

    while ( cont <= 200 )
    {
        if ( TPrato[cont].codpt == codpt )
            return(0);

        cont++;
    }

    return(1);

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
int tamanhoArraypt(){
	int cont = 0;
	for(int i= 0; i<200; i++){
		if(TPrato[i].codpt != NULL){
			cont++;
		}
	}
	return cont;
	
}



void realizarpedido(){
	int op;
    do{
    	int codaux,retorno,codaux2, retorno2;
		printf("\nEntre com um codigo para seu pedido: \n");
        scanf("%d",&codaux);
		fflush(stdin);
        retorno = verifica_cod( codaux );
		if(retorno ==1){
			int tamA, codped_aux;
			tamA = tamanhoArray(); 		
			TPedido[tamA].cod = codaux;
        	printf("\nDigite seu nome: ");
        	gets(TPedido[tamA].nomePes);
        	printf("\n");
        	cardapio();
        	printf("\n");
        	printf("\nDigite seu pedido por codigo: ");
        	scanf("%d",&codped_aux);
        	fflush(stdin);
        	int achou = 0;
			for(int i = 0; i<200; i++){
			
	        	if(codped_aux == TPrato[tamA].codpt){
	        		printf("\nDigite a quantidade do seu pedido: ");
	        		scanf("%d",&TPedido[tamA].qtdPed);
	        		printf("\nVoce escolheu %d unidades da opcao %s,\nseu pedido foi efetuado com sucesso.\n\n",TPedido[tamA].qtdPed,TPrato[tamA].nomePrt);
	        		achou = 1;
					break; 
				}
			}
			
			if(achou = 0){
				printf("Prato nao se encontra no nosso cardapio");
			}
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
    	int codptaux,retorno2;
		printf("\nEntre com um codigo para seu prato: \n");
        scanf("%d",&codptaux);
		fflush(stdin);
        retorno2 = verifica_codpt( codptaux );
		if(retorno2 ==1){
			int tamB;
			tamB = tamanhoArraypt(); 		
			TPrato[tamB].codpt = codptaux;
        	printf("\nDigite o nome do prato: ");
        	gets(TPrato[tamB].nomePrt);
        	printf("\n");
        	printf("\nDigite o valor do prato: ");
        	scanf("%f",&TPrato[tamB].valorPrt);
        	printf("\nSr. Alcides, voce cadastrou o prato %s ,com o valor de R$%1.1f,\n\n",TPrato[tamB].nomePrt,TPrato[tamB].valorPrt);
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
  printf("As senha est� incorreta, voltando ao menu inicial\n");

}

void cardapio(){
	int i;
    for(i=0;i< 200;i++){
        if(TPrato[i].codpt != NULL){
            printf("\nCodigo do prato: %d\tNome do prato: %s \tValor do prato: R$%1.1f\n\n\n",TPrato[i].codpt,TPrato[i].nomePrt,TPrato[i].valorPrt);
		}
	}

}

float conta(){

    int i;
    float conta_a;
    for(i=0;i< 200;i++){
        if(TPedido[i].cod != NULL){
        	conta_a = (float)TPrato[i].valorPrt*TPedido[i].qtdPed;
        	printf("\nCliente da mesa %d\nNome do pessoa: %s \nNome da pedido: %s\nQuantidade do pedido: %d\nConta do Cliente:%1.1f\n\n",TPedido[i].cod,TPedido[i].nomePes,TPrato[i].nomePrt,TPedido[i].qtdPed,conta_a);
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
    printf("\nNome do cliente: %s \Pedido: %s\nQuantidade: %d\n\n", TPedido[tamA].nomePes,TPedido[tamA].nomePed,TPedido[tamA].qtdPed);
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
