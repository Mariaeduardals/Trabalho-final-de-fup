#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct {
	char nome[50];
	int ano;
	float premiacao;
}Titulo;

typedef struct{
	char nome[50];
	int idade;
	int equipe;
	char pais[50];
	char jogo[50];
	float salario;
	int quantidadeTitulos;
	Titulo titulos[100];
}Atleta;

Atleta atletas[MAX];
int tamanhoReal = 0;

void preencheTitulo(Titulo *t, int n){
	int i = 0;	
	for(i = 0; i < n; i++){
	
	printf("Informe o nome do titulo: ");
	scanf("%s", t[i].nome);
	
	printf("Ano do titulo: ");
	scanf("%d", &t[i].ano);
	
	printf("Informe a premiacao: ");
	scanf("%f", &t[i].premiacao);
	if(t[i].premiacao < 30000){
		printf("Premiacoes validas apenas acima de R$ 30.000. Informe novamente: ");
		scanf("%f", &t[i].premiacao);
	}
	
    }
	setbuf(stdin, NULL);
	
  
}
void mostraTitulo(Titulo *t, int n){
	int i;
	for(i=0; i<n; i++){
		if(strcmp(t[i].nome,"NULL") != 0){
			printf("\n-----------------------\n");
			printf("Nome do titulo: %s\n", t[i].nome);
			printf("Ano do titulo: %d\n", t[i].ano);
			printf("Valor da premiacao do titulo: %.2f\n", t[i].premiacao);
			printf("-----------------------\n");
		}
	}
}
int pegarPosicao(char * nome){
	int i;
	for(i = 0; i < tamanhoReal; i++){
		if(strcmp(atletas[i].nome, nome) == 0){
			return i;
		}
	}
	return -1;
}
void preencheAtleta(){
		printf("Informe seu nome: ");
		scanf("%s", atletas[tamanhoReal].nome);
			
		printf("Insira sua idade: ");
		scanf("%d", &atletas[tamanhoReal].idade);
		
		printf("Informe sua equipe: ");
		printf("\nEquipe 1");
		printf("\nEquipe 2");
		printf("\nEquipe 3: ");
		scanf("%d", &atletas[tamanhoReal].equipe);
		
		printf("Informe seu pais: ");
		scanf("%s", atletas[tamanhoReal].pais);
		
		printf("Informe o nome do jogo: ");
		scanf("%s", atletas[tamanhoReal].jogo);
		
		printf("Informe seu salario: ");
		scanf("%f", &atletas[tamanhoReal].salario);
		
		if(atletas[tamanhoReal].salario < 6000){
			printf("Salarios validos apenas acima de R$6.000. Informe novamente: ");
			scanf("%f", &atletas[tamanhoReal].salario);
		}
		int n;
		printf("Digite a quantidade de titulos: ");
		scanf("%d",&n);
		atletas[tamanhoReal].quantidadeTitulos = n;			
		preencheTitulo(atletas[tamanhoReal].titulos,n);
		tamanhoReal++;
		
		setbuf(stdin, NULL);
	
	printf("\nCyber-atleta adicionado com sucesso!\n");
}
void mostraAtleta(){
	int i;
	for(i=0; i<tamanhoReal; i++){
		int nTitulos = sizeof(atletas[i].titulos)/sizeof(atletas[i].titulos[0]);
		if(strcmp(atletas[i].nome,"NULL") != 0){
			printf("\n--------Cyber-atleta---------\n");
			printf("Nome: %s\n", atletas[i].nome);
			printf("Idade: %d anos\n", atletas[i].idade);
			printf("Equipe: %d\n", atletas[i].equipe);
			printf("Pais: %s\n", atletas[i].pais);
			printf("Jogo: %s\n", atletas[i].jogo);
			printf("Salario: %.2f\n", atletas[i].salario);
			mostraTitulo(atletas[i].titulos, atletas[i].quantidadeTitulos);
			printf("--------------------------------");
		}
	}
}
void alteraTitulo(Titulo *t){

	char alterarTitulo[50];
	
	printf("O que do titulo voce deseja alterar ?");
	scanf("%s", alterarTitulo);

	if(strcmp(alterarTitulo,"nome")==0){
		
		printf("Digite o novo titulo: ");
		scanf("%s", t->nome);
	}
	else
	if(strcmp(alterarTitulo, "ano")==0){
		printf("Digite o novo ano: ");
		scanf("%d",&t->ano);
	}
	else
	if(strcmp(alterarTitulo, "premiacao")==0){
		printf("Informe o novo valor da premiacao: ");
		scanf("%.2f", &t->premiacao);
	}
	
	setbuf(stdin, NULL);
}
void alterarAtleta(){
	char nomeAtleta[50];
	int op, posi =-1;
	do {
		printf("Qual atleta deseja alterar ? ");
		scanf("%s",nomeAtleta);
		setbuf(stdin, NULL);
		posi= pegarPosicao(nomeAtleta);
		if (posi == -1){
			printf("Nenhum usuario encontrado. Tente novamente!\n");
		}	
	}while(posi == -1);
			
	setbuf(stdin, NULL);
	do{
		printf("O que deseja editar?\n");
		printf("\n------------\n");
		printf(" 1- Nome: 	  \n");
		printf(" 2- Idade:   \n");
		printf(" 3- Equipe:  \n");
		printf(" 4- Pais: 	  \n");
		printf(" 5- Jogo: 	  \n");
		printf(" 6- Salario: \n");
		printf(" 7- Titulos: \n");
		printf(" 0- Sair:    \n");
		printf("\n------------|\n");
		printf("Opcao: ");
		scanf("%d",&op);

		switch(op){
			case 1:{
				printf("Informe o novo nome a ser inserido: ");
				setbuf(stdin, NULL);
				scanf("%[^\n]",atletas[posi].nome);
				printf("Alterado com sucesso!\n");
				break;
			}
			case 2:{
				printf("Informe a nova idade a ser inserida: ");
				setbuf(stdin, NULL);
				scanf("%d",&atletas[posi].idade);
				printf("Alterado com sucesso!\n");
				break;
			}
			case 3:{
				printf("Informe qual sera a nova equipe a ser inserido: ");
				setbuf(stdin, NULL);
				scanf("%d", &atletas[posi].equipe);
				printf("Alterado com sucesso!\n");
				break;
			}
			case 4:{
				printf("Informe o novo nome do pais a ser inserido: ");
				setbuf(stdin, NULL);
				scanf("%[^\n]", atletas[posi].pais);
				printf("Alterado com sucesso!\n");
				break;
			}
			case 5:{
				printf("Informe o novo nome do jogo a ser inserido: ");
				setbuf(stdin, NULL);
				scanf("%[^\n]",atletas[posi].jogo);
				printf("Alterado com sucesso!\n");
				break;
			}
			case 6:{
				printf("Informe o novo valor para o salario: ");
				setbuf(stdin, NULL);
				scanf("%f", &atletas[posi].salario);
				printf("Alterado com sucesso!\n");
				break;
			}
			case 7:{
				
				int opc;
				setbuf(stdin, NULL);
				do{
					printf("O que deseja editar em titulos?\n");
					setbuf(stdin, NULL);
					printf("\n-----------------\n");
					printf(" 1- Nome do titulo: \n");
					printf(" 2- Ano do titulo: \n");
					printf(" 3- Premiacao:     \n");
					printf(" 4- SAIR           \n");
					printf("\n-----------------\n");

					printf("Opcao: ");
					scanf("%d",&opc);
					setbuf(stdin, NULL);
					switch(opc){

						case 1:{
							printf("Informe o novo titulo: ");
							setbuf(stdin, NULL);
							scanf("%[^\n]", atletas[posi].titulos->nome);
							printf("Alterado com sucesso!\n");
							break;
						}
						case 2:{
							printf("Informe o novo ano do titulo: ");
							setbuf(stdin, NULL);
							scanf("%d", &atletas[posi].titulos->ano);
							printf("Alterado com sucesso!\n");
							break;
						}
						case 3:{
							printf("Informe a nova premiacao: ");
							setbuf(stdin, NULL);
							scanf("%f", &atletas[posi].titulos->premiacao);
							printf("Alterado com sucesso!\n");
							break;
						}
					}
				}while(opc != 4);
			}
			case 8:{
				break;
			}
		}
	}while(op!= 0);	
}

void removeAtletas(){
	char removeNome[50];
	int achou = 0;
	int i, j;
	
	printf("Digite o nome que deseja remover: ");
	scanf("%s", removeNome);
	setbuf(stdin, NULL);
	
	for(i = 0; i < tamanhoReal; i++){
		if(strcmp(atletas[i].nome, removeNome) == 0){
			strcpy(atletas[i].nome, "NULL");
		    atletas[i].idade = 0;
		    atletas[i].equipe = 0;
		    strcpy(atletas[i].pais, "NULL");
		    strcpy(atletas[i].jogo, "NULL");
		    atletas[i].salario = 0.0;
		    
		    for(j =0; j < tamanhoReal; j++){
		    	strcpy(atletas[i].titulos[j].nome, "NULL") ;
		    	atletas[i].titulos[j].ano = 0;
		    	atletas[i].titulos[j].premiacao = 0.0;
			}
			achou =1;
		}	
	}
	if(achou == 1){
		printf("Atleta removido\n");
	}else{
		printf("Atleta nao encontrado\n");
	}
	setbuf(stdin, NULL);
}
void buscaNome(){
	char buscaNome[50];
	int achou = 0, i;
	
	printf("Informe o nome do cyber-atleta que deseja buscar as informacoes: ");
	scanf("%s", buscaNome);
	
	for(i = 0; i < tamanhoReal; i++){
		 if(strcmp(atletas[i].nome, buscaNome) == 0){
		 	printf("\n---------------Cyber-atleta-----------------\n");
			printf("Nome: %s\n", 	atletas[i].nome);
			printf("Idade: %d anos\n",   atletas[i].idade);
			printf("Equipe: %d\n",  atletas[i].equipe);
			printf("Pais: %s\n",    atletas[i].pais);
			printf("Jogo: %s\n",    atletas[i].jogo);
			printf("Salario: %.2f\n", atletas[i].salario);
			mostraTitulo(atletas[i].titulos, atletas[i].quantidadeTitulos);
			printf("\n---------------------------------------------\n");
			achou = 1;
			break;
		 }
	}
	if(achou == 0){
		printf("Cyber-atleta nao encontrado");
	}
}
void buscaPais(){
	char buscaPais[50];
	int achou = 0, i;
	
	printf("Informe o pais que deseja buscar para ver informacoes dos cyber-atleta: ");
	scanf("%s",buscaPais);
	
	for(i = 0; i < tamanhoReal; i++){ 
				
		 if(strcmp(atletas[i].pais, buscaPais) == 0){
			 
		 	printf("\n---------------Cyber-atleta----------\n");
			printf("Nome: %s\n", atletas[i].nome);
			printf("Idade: %d anos\n", atletas[i].idade);
			printf("Equipe: %d\n", atletas[i].equipe);
			printf("Pais: %s\n", atletas[i].pais);
			printf("Jogo: %s\n", atletas[i].jogo);
			printf("Salario: %.2f\n", atletas[i].salario);
			mostraTitulo(atletas[i].titulos, atletas[i].quantidadeTitulos);
			printf("-----------------------------------------");
			printf("\n \n");

			achou =1;			
		 }
	}
	if(achou == 0){
		printf("Nao ha nenhum cyber-atleta deste pais");
	}
}
void buscaTitulo(){
	char buscaTitulo[50];
	int achou = 0, i,j;
	
	printf("Informe por qual titulo deseja saber quais sao os cyber-atletas: ");
	scanf("%s", buscaTitulo);
	
	for(i = 0; i < MAX; i++){
		for(j = 0; j < MAX; j++){
			 if(strcmp(atletas[i].titulos[j].nome, buscaTitulo) == 0){
			 	printf("\n---------Cyber-Atleta--------\n");
				printf("Nome: %s\n", atletas[i].nome);
				printf("Idade: %d anos\n", atletas[i].idade);
				printf("Equipe: %d\n", atletas[i].equipe);
				printf("Pais: %s\n", atletas[i].pais);
				printf("Jogo: %s\n", atletas[i].jogo);
				printf("Salario: %.2f\n", atletas[i].salario);
				printf("--------------------------------");
				printf("\n \n");
				
				achou =1;
				break;
			 }
		}
	}
	if(achou == 0){
		printf("Titulo nao encontrado");
	}
}
void custoSalarios(){
	int equipe, i, achou = 0;
	float somaSalario = 0;
	
	printf("Informe a equipe na qual deseja saber os custos : ");
	scanf("%d", &equipe);
	
	for(i = 0; i < MAX; i++){
		if(atletas[i].equipe == equipe){
			somaSalario += atletas[i].salario;
			achou = 1;
		}
	}
	if(achou == 0){
		printf("Equipe nao encontrada. ");
	}else{
		printf("Custo dos salarios: %.2f", somaSalario);
	}	
}
int main(){
	
	int opcao,i,j;
	
	while(1){
		printf("\n---------Menu----------\n");
		printf("1 - Cadastrar cyber-atleta\n");
		printf("2 - Alterar um cyber-atleta\n");
		printf("3 - Remover umm cyber-atleta\n");
		printf("4 - Buscar um cyber-atleta pelo nome\n");
		printf("5 - Buscar cyber-atletas pelo pais\n");
		printf("6 - Buscar cyber-atletas pelo titulo \n");
		printf("7 - Custos de salario de uma equipe\n");
		printf("8 - Sair\n");
		
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		
		setbuf(stdin, NULL);
		
		switch(opcao){
			case 1:{
				preencheAtleta();
				break;
			}
			case 2:{
				alterarAtleta();
				break;
			}
			case 3:{
				removeAtletas();
				break;
			}
			case 4:{
				buscaNome();
				break;
			}
			case 5:{
				buscaPais();
				break;
			}
			case 6:{
				buscaTitulo();
				break;
			}
			case 7:{
				custoSalarios();
				break;
			}
		}
		if(opcao == 8){
			break;
		}
	}
	return 0;
}
