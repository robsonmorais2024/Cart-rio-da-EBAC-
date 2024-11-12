#include <stdio.h> // Biblioteca de comunica��o com usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��es de textos por regi�o
#include <string.h> // Biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);//%s refere-se o string
	
	strcpy(arquivo, cpf);//Respons�vel por copiar os valores das string

	FILE *file; //destino do arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");//respons�vel por limpar a tela
				
}

int consulta()
{	
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	//in�cio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);//%s refere-se o string
	
	FILE *file;// busca e abre o arquivo
	file = fopen(cpf,"r");// abre o arquivo "r" l� o arquivo
	
	if(file ==NULL)// quando o arquivo nulo
	{
	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");	
	}
		while(fgets(conteudo, 200, file)!=NULL)
	{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
	}	
	
	system("pause");//respons�vel por limpar a tela
	
}

int deletar()
{
	//in�cio cria��o de vari�veis/string
	char cpf[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);//%s refere-se o string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//
	
	if(file== NULL)
	{
	printf("O usu�rio n�o se encontra no sistema!. \n");
	system("pause");//respons�vel por limpar a tela
	}	
	
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");//respons�vel por limpar a tela
			
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("Op��o: "); //fim do menu
            
        scanf("%d", &opcao); //armazenando a escolha do usu�rio
            
        system("cls");
            
        switch(opcao)//in�cio da sele��o do menu
		{
			case 1:
			registro();// chamada de fun��o
			break;
					
			case 2:
			consulta();// chamada de fun��o
			break;
					
			case 3:
			deletar();// chamada de fun��o
			break;
					
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			
		}
            
   } 
            
  
}
