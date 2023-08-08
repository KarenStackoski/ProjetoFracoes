/*
	PROJETO FRAÇÕES (MERCADO PRESO 0.0.0.6)
	     
	Autores: Karen Bialescki Stackoski e Jhulia Fermo Fascin
	Criacao: 03/06/2023
	Ultima atualizacao: 04/08/2023
	Descricao: Sistema para Cadastro e Consulta de produtos no estoque e parcelamento da compra dos produtos
	__________
	Alteracoes
	
	04/08/2023 - Karen -> separacao de cabecalhos em funcoes void
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCOES
void cabecalhoMercadoPreso();
void cabecalhoMenuLogin();
void cabecalhoMenuPrincipal();
void cabecalhoMenuProdutos();

main(){
	//VARIÁVEIS
	int opcaoMenu, opcaoProdutos, quantidadeProdutoTotal, quantidadeProdutoAtual, opcaoCadastro, i, quantidadeCadastro, opcaoLogin, resultadoLogin, credentialsMatch, porcentagemEstoque;
	char opcaoParcelas, nomeProduto[50], categoriaProduto[30], opcaoInvalida, buscaCategoria[50], leituraDadosArquivo, sairBusca, user[30], password[20], dbUser[30], dbPassword[20],dbNomeProduto[100], contador, sairCadastro; 
	float precoProduto;
	////////
	
	//ABRINDO ARQUIVO	
	FILE *arquivo = fopen("dadosFracao.txt", "a");
						
	if (arquivo == NULL)
	{
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    /////////
	
		//MENU
		system("cls");
		cabecalhoMercadoPreso();
		cabecalhoMenuLogin();
		scanf("%d",&opcaoLogin);
		system("cls");
		switch(opcaoLogin)
		{
			
			case 1:
				
              //Login  -> Só é possível realizar o cadastro utilizando duas strings iguais (user, password)
			    cabecalhoMercadoPreso();
			    printf("			Ola! Seja bem-vindo ao Mercado Preso! Faca seu login e aproveite.  (='_'=)\n\n\n\n");
				printf("________________________________________________________ENTRAR_________________________________________________________\n\n");
			    printf("	Nome de Usuario: ");
			    scanf("%s", user);
		        printf("	Senha: ");
	     	    scanf("%s",&password);
	     	    
	     	    //Define os valores de entrada
			    strcpy(dbUser, "MercadoP");
			    strcpy(dbPassword, "Louise");
			    system("cls");
			    
			    //compara se os valores digitados são iguais aos valores pré definidos
			    if(strcmp(user, dbUser) == 0 && strcmp(password, dbPassword) == 0) {
			    	
			        credentialsMatch = 1;
			        while(opcaoMenu != 3)
					{
				        cabecalhoMercadoPreso();  
						cabecalhoMenuPrincipal();
						scanf("%i",&opcaoMenu);
						system("cls");
						
						switch(opcaoMenu){
							case 1:
							cabecalhoMercadoPreso();
							cabecalhoMenuProdutos();
							scanf("%i",&opcaoProdutos);
							system("cls");
							
							switch(opcaoProdutos){
								case 1:
									//CADASTRAR PRODUTOS
									cabecalhoMercadoPreso();
									printf("_______________________________________________ 1.1. Cadastrar Produtos _______________________________________________\n\n");
											
									//fazer lógica para auto implementar o id
									printf("Nome do Produto: ");
									scanf("%s",&nomeProduto); 
									printf("Preco: ");
									scanf("%f",&precoProduto);
									printf("Quantidade Total: ");
									scanf("%i",&quantidadeProdutoTotal);
									printf("Categoria: ");
									scanf("%s",&categoriaProduto); 
									
									quantidadeProdutoAtual = quantidadeProdutoTotal; //atribuindo o valor atual incial para depois ir descontando conforme os produtos forem saindo de estoque
									
									porcentagemEstoque = (quantidadeProdutoTotal * 100) / quantidadeProdutoAtual;
									
										//salvando dados em arquivo txt		
										fprintf(arquivo, "\n_____________________________________\n");							    
									    fprintf(arquivo, "Nome Produto: %s\n",nomeProduto);
										fprintf(arquivo, "Categoria: %s\n", categoriaProduto);
										fprintf(arquivo, "Preco: %.2f\n", precoProduto);
										fprintf(arquivo, "Capacidade do estoque: %i", quantidadeProdutoAtual);
										fprintf(arquivo, " de %i\n", quantidadeProdutoTotal);
										fprintf(arquivo, "Porcentagem da capacidade: %i %\n", porcentagemEstoque);
										
										printf("Dados salvos com sucesso!\n");
					    				
				    					fclose(arquivo); // Fecha o arquivo
				
				    					return 0;
				    					
									break;
								case 2:
									//CONSULTAR TODOS OS PRODUTOS
									cabecalhoMercadoPreso();
									printf("_______________________________________________ 1.2. Consultar Produtos _______________________________________________\n\n");
									
									FILE *arquivo = fopen("dadosFracao.txt", "r");
									
									
									if (arquivo == NULL)
									{
										printf("Arquivo nao encontrado.");
										return 1;
									}
									
									while((leituraDadosArquivo = fgetc(arquivo)) != EOF) //EOF-> ler ate o final do arquivo
									{
										printf("%c",leituraDadosArquivo);
										
									}
									
									printf("\n\n\nDigite qualquer tecla para sair: ");
									fflush(stdin);
									scanf("%c",&sairBusca);
									break;
							  	}	
							    break;
				        
					        case 2:
								cabecalhoMercadoPreso();
								printf("_____________________________________________________ 2. Parcelas _____________________________________________________\n\n");
								
							    FILE *arquivo = fopen("dadosFracao.txt", "r");
							
							    if (arquivo == NULL) {
							        printf("Arquivo nao encontrado.");
							        return 1;
							    }
							    
							    contador = 0;
							    
							    while (fgets(dbNomeProduto, sizeof(dbNomeProduto), arquivo) != NULL) {
							        if (strstr(dbNomeProduto, "Nome Produto:") != NULL) {
							            sscanf(dbNomeProduto, "Nome Produto: %[^\n]", nomeProduto);
							            
							            contador ++;
							            
							            printf("    %i.............................................................................................. %s\n", contador, nomeProduto);
							        }
							    }
							
							    fclose(arquivo);
							    return 0;
							
							    printf("\n\nPressione qualquer tecla para sair: ");
							    fflush(stdin);
							    scanf("%c", &sairBusca);
							    break;
				        }
			        	system("cls");
			    	}
			    	printf("Encerrando o programa..."); //mensagem ao sair do programa
			    	printf("\n\n\n\t\t\t\t(=^_^=)    Obrigado por utilizar o Mercado Preso!!!\n\n\n");
		        }
		     	else {
					cabecalhoMercadoPreso();
					printf("_____________________________________________________TENTATIVA DE LOGIN_________________________________________________________\n\n");
				    printf("Usuario ou senha incorretos.\nPressione qualquer tecla para continuar.\n");
				    scanf("%c",&opcaoInvalida);
				    break;
				}
//			case 2:{
				
//				cabecalhoMercadoPreso();
//				printf("_____________________________________________________CADASTRO_________________________________________________________\n\n");  
//				printf("Nome: ");
//			    scanf("%s",&nome);
//			    printf("Ultimo nome: ");
//			    scanf("%s",&sobrenome);
//			    printf("Email: ");
//			    scanf("%s",&email);
//			    printf("Nome de usuario: ");
//			    scanf("%s",&user);
//			    printf("Senha: ");
//			    scanf("%s",&password);
//			    FILE *cadastro = fopen("Usuarios.txt", "a"); // Abre o arquivo em modo de escrita (append)
//			    if (cadastro == NULL) {
//			        printf("Erro ao abrir o banco de dados.");
//			        return 1;
//			    }
//			    fprintf(cadastro, "\n--------------------------------------------------CRIAR UMA NOVA CONTA--------------------------------------------------\n\n"
//				"Nome: %s\nSobrenome: %s\nEmail: %s\nNome de Usuário: %s\nSenha: %s", &nome, &sobrenome, &email, &user, &password); // Escreve as informações no arquivo
//			    fclose(cadastro);
//				break;
//			}
		}
}

void cabecalhoMercadoPreso()
{
	printf("=======================================================================================================================\n");
	printf("                                                    MERCADO PRESO\n");
	printf("                                                      V 0.0.0.6\n");
	printf("=======================================================================================================================\n\n\n");
}

void cabecalhoMenuLogin()
{
	printf("________________________________________________________ MENU _________________________________________________________\n\n");
	printf("      1..................................................................................................... Entrar\n");
	printf("      2................................................................................................... Cadastro\n");
	printf(" > ");
}

void cabecalhoMenuPrincipal()
{
	printf("________________________________________________________ MENU _________________________________________________________\n\n");
	printf("      1................................................................................................... Produtos\n");
	printf("      2................................................................................................... Parcelas\n");
	printf("      3....................................................................................................... Sair\n\n");
	printf(" > ");
}

void cabecalhoMenuProdutos()
{
	printf("_____________________________________________________ 1. Produtos _____________________________________________________\n\n");
	printf("    1........................................................................................... Cadastrar Produtos\n");
	printf("    2........................................................................................... Consultar Produtos\n");
	printf("    3....................................................................................................... Voltar\n\n");
	printf(" > ");
}
