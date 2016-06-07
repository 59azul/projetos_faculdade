/*
Integrante 1 - Nome: Daniel Augusto Silveira Ramos__________ RA : 15589500
Integrante 2 - Nome: Julio Ferro Neto_______________________ RA : 15265135
Integrante 3 - Nome: Augusto Scarelli Silva_________________ RA : 15049711
Integrante 4 - Nome:Danilo Luis Lopes Raymundo Paixão_______ RA : 15051659
Resultados obtidos :
Projeto básico : 100 % concluído - Obs : ____________________________________
(x) Opcional 1 - Obs : concluido_____________________________________________
( ) Opcional 2 - Obs : ______________________________________________________
( ) Opcional 3 - Obs : ______________________________________________________
( ) Opcional 4 - Obs : ______________________________________________________
( ) Opcional 5 - Obs : ______________________________________________________
*/

#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include <stdio.h>
#include <stdlib.h>


//ARVORE DE CADASTROS
struct Node
{
	char nome[50];
	unsigned long int cpf;
	struct telefone *numeros;
	struct Node *dir, *esq;
};
typedef struct Node node;

//LISTA DE TELEFONES
struct telefone
{
	unsigned long int numero;
	struct telefone *prox;
};
typedef struct telefone Fone;


//FUNÇÕES PRINCIPAIS
void incluirCadastro(node **LISTA);
void removerCadastro(node **LISTA);
void alterarCadastro(node **LISTA);
void buscaCadastro(node *LISTA);
void exibirEmOrdem(node *pRaiz);

//OPCIONAIS
void buscaNomeTelefone(node *pRaiz);
void exibeNomeTelefone(node *pRaiz, char nome[], unsigned long int telefone, int opcao);

//FUNÇÕES AUXILIARES
//Inicializa a Arvore de Cadastros
void criaVazia(node **LISTA);

//Funções da Lista de Cadastros
void inserir(node **pRaiz, unsigned long int cpf, node *novo);
void remover(node **pRaiz, unsigned long int cpf);
node *MaiorDireita(node **no); //continuação da função de remover
int procura_cpf(node *LISTA, unsigned long int cpf);

//Funções para Lista de Telefones
void adicionaTelefone(Fone **num);
void removerTelefone(Fone **num);
int procurarTelefone(Fone *num, unsigned long int numero);

int main(void) //-------------------------------------------------------------------------------------
{
	node *LISTA = (node *)malloc(sizeof(node));
	int opt;

	if (!LISTA)
	{
		printf("Sem memoria disponivel!\n");
		return 0;
	}

	criaVazia(&LISTA);

	do
	{
		//TÓPICOS DO PROJETO BÁSICO
		printf("LISTA TELEFONICA\n\n");
		printf("1. Incluir um novo assinante;\n");
		printf("2. Remover um assinante;\n");
		printf("3. Alterar informacoes de um assinante;\n");
		printf("4. Busca de um assinante a partir do seu CPF;\n");
		printf("5. Listagem de todos os assinantes ordenados por CPF;\n");
		//ADICIONAR TÓPICOS EXTRAS AQUI
		printf("6. Listagem por parte do nome ou telefone;\n");
		printf("0. Sair.\n");
		printf("opcao:  "); scanf("%d", &opt);

		switch (opt)
		{
		case 1:
			printf("\nINCLUIR CADASTRO\n");
			incluirCadastro(&LISTA);
			printf("\n\n");
			break;

		case 2:
			printf("\nREMOVER CADASTRO\n");
			removerCadastro(&LISTA);
			printf("\n\n");
			break;

		case 3:
			printf("\nALTERAR CADASTRO\n");
			alterarCadastro(&LISTA);
			printf("\n\n");
			break;

		case 4:
			printf("\nBUSCAR CADASTRO\n");
			buscaCadastro(LISTA);
			printf("\n\n");
			break;

		case 5:
			printf("\nEXIBIR CADASTROS\n");
			exibirEmOrdem(LISTA);
			printf("\n\n");
			break;

			//ADICIONAR TÓPICOS EXTRAS AQUI
		case 6:
			printf("\nLISTAGEM POR NOME/TELEFONE\n");
			buscaNomeTelefone(LISTA);
			printf("\n\n");
			break;


		case 0:
			printf("\n\nFim do programa.\n");
			break;

		default:
			printf("Comando invalido\n\n");
		}

	} while (opt);

	free(LISTA);
	return 0;
}


//FUÇÕES PRINCIPAIS -------------------------------------------------------------------------------

void incluirCadastro(node **LISTA)
{
	node *tmp, *novo = (node *)malloc(sizeof(node));
	Fone *num = (Fone *)malloc(sizeof(Fone));
	int resultado1 = 0, resultado2 = 1;
	char opcao;

	//Inicia variaveis
	tmp = (*LISTA);
	num = NULL;

	//Recebendo os valores do novo cadastro
	printf("Digite o nome: ");
	__fpurge(stdin);
	fgets(novo->nome, 50, stdin);
	printf("Digite o CPF: ");
	scanf("%lu", &novo->cpf);
	novo->dir = NULL;
	novo->esq = NULL;

	if (!(*LISTA))
	{
		do  //caso a arvore de cadastros esteja vazia, o novo nó será atribuido como raiz da arvore
		{
			printf("Deseja cadastrar um novo numero de telefone? (s/n): ");
			__fpurge(stdin);
			scanf(" %c", &opcao);
			if (opcao == 's')
			{
				adicionaTelefone(&num); //Função que insere um novo numero na lista de telefones do cadastro
				resultado2 = 1;
			}
			else
			{
				if (opcao == 'n')
				{
					resultado2 = 0;
				}
				else
				{
					printf("Opcao invalida!\n");
				}
			}
		} while (resultado2 == 1);

		novo->numeros = num;
		(*LISTA) = novo;
		printf("Cadastro efetuado.");
	}
	else
	{	// Caso a lista não esteja vazia, o programa chama a função que verifica se o cadastro ja existe
		resultado1 = procura_cpf(tmp, novo->cpf);
		if (resultado1 == 1)
		{
			printf("Erro! CPF ja existente.");
		}
		else
		{
			do
			{
				printf("Deseja cadastrar um novo numero de telefone? (s/n): ");
				__fpurge(stdin);
				scanf(" %c", &opcao);
				if (opcao == 's')
				{
					adicionaTelefone(&num); //Função que insere um novo numero na lista de telefones do cadastro
					resultado2 = 1;
				}
				else
				{
					if (opcao == 'n')
					{
						resultado2 = 0;
					}
					else
					{
						printf("Opcao invalida!\n");
					}
				}
			} while (resultado2 == 1);
			novo->numeros = num;
			tmp = (*LISTA); //tmp recebe a arvore de cadastros para ser percorrida
			inserir(&tmp, novo->cpf, novo);  // Função que insere um novo cadastro
			printf("Cadastro efetuado.");
		}
	}

}


void removerCadastro(node **LISTA)
{
	unsigned long int cpf;

	printf("Digite o CPF que deseja remover: ");
	scanf("%lu", &cpf);
	remover(LISTA, cpf); //Fuñção recursiva que remove cadastros
}


void alterarCadastro(node **LISTA)
{
	node *tmp, *novo = (node *)malloc(sizeof(node));
	Fone *num = (Fone *)malloc(sizeof(Fone));
	int resultado1 = 0, resultado2 = 1, opcao;
	unsigned long int cpf;
	char escolha;

	tmp = (*LISTA);


	printf("Digite o CPF do cadastro que deseja alterar: ");
	scanf("%lu", &cpf);

	resultado1 = procura_cpf(tmp, cpf);// Somente verifica se o cadastro existe no sistema

	if (resultado1 == 1)
	{
		while (tmp != NULL) //Percorre a arvore até chegar no cadastro caso exista
		{
			if (tmp->cpf == cpf)
			{
				break;
			}
			if (cpf > tmp->cpf)
			{
				tmp = tmp->dir;
			}
			if (cpf < tmp->cpf)
			{
				tmp = tmp->esq;
			}
		}
		//Opções de alteração no cadastro
		printf("\nEscolha a opcao que deseja realizar:\n");
		printf("1. Incluir um novo numero de telefone\n");
		printf("2. Remover um numero de telefone\n");
		printf("3. Alterar nome do assinante\n");
		printf("opcao:  "); scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			adicionaTelefone(&tmp->numeros);
			do //Loop para adicionar um novo numero de telefone
			{
				printf("Deseja cadastrar um novo numero de telefone? (s/n): ");
				__fpurge(stdin);
				scanf(" %c", &escolha);
				if (escolha == 's')
				{
					resultado2 = 1;
					adicionaTelefone(&tmp->numeros);
				}
				else
				{
					if (escolha == 'n')
					{
						resultado2 = 0;
					}
					else
					{
						printf("Opcao invalida!");
					}
				}
			} while (resultado2 == 1);
			printf("Alteracao concluida.");
			break;

		case 2:
			removerTelefone(&tmp->numeros);
			do //Loop para remover um novo numero de telefone
			{
				printf("Deseja cadastrar um novo numero de telefone? (s/n): ");
				__fpurge(stdin);
				scanf(" %c", &escolha);
				if (escolha == 's')
				{
					resultado2 = 1;
					removerTelefone(&tmp->numeros);
				}
				else
				{
					if (escolha == 'n')
					{
						resultado2 = 0;
					}
					else
					{
						printf("Opcao invalida!");
					}
				}
			} while (resultado2 == 1);
			printf("Alteracao concluida.");
			break;

		case 3: //Altera o nome do cadastro
			printf("Digite o novo nome: ");
			__fpurge(stdin);
			fgets(tmp->nome, 50, stdin);
			printf("Alteracao concluida.");
			break;

		default:
			printf("Comando invalido\n\n");
		}

	}
	else
	{
		printf("Cadastro não encontrado!");
	}

}


void buscaCadastro(node *LISTA)
{
	node *tmp = (node *)malloc(sizeof(node));
	unsigned long int cpf;
	int resultado = 0, resultado2 = 0;

	printf("Digite o CPF do cadastro que deseja encontrar: ");
	scanf("%lu", &cpf);

	tmp = LISTA;
	resultado = procura_cpf(tmp, cpf); //Procura cadastro no sistema

	if (resultado == 1)
	{
		while (tmp != NULL) // Percorre a arvore até chegar no cadastro desejado caso exista
		{
			if (tmp->cpf == cpf)
			{
				printf("nome: %s, CPF: %lu \n", tmp->nome, tmp->cpf);
				break;
			}
			if (cpf > tmp->cpf)
			{
				tmp = tmp->dir;
			}
			if (cpf < tmp->cpf)
			{
				tmp = tmp->esq;
			}
		}
	}
	else
	{
		printf("Cadastro não encontrado!");
	}
}


void exibirEmOrdem(node *pRaiz)
{
	if (pRaiz != NULL)
	{
		exibirEmOrdem(pRaiz->esq); //Percorre a arvore até o ultimo nó esquerdo
		printf("\nnome: %s, CPF: %lu", pRaiz->nome, pRaiz->cpf); //Printa o nó
		exibirEmOrdem(pRaiz->dir); //Percorre o lado direto do nó
	}
}


void buscaNomeTelefone(node *pRaiz)
{
	int opcao;
	unsigned long int telefone;
	char nome[50];

	printf("\nEscolha a opcao que deseja realizar:\n");
	printf("1. Buscar cadastros por parte do nome;\n");
	printf("2. Buscar cadastos por telefone.\n");
	printf("opcao:  "); scanf("%d", &opcao);

	switch (opcao)
	{
	case 1:
		printf("Digite o nome que deseja buscar: ");
		__fpurge(stdin);
		fgets(nome, 50, stdin);
		printf("\nCadastros encontrados: \n");
		exibeNomeTelefone(pRaiz, nome, 0, 1);
		break;

	case 2:
		printf("Digite o telefone que deseja buscar: ");
		scanf(" %lu", &telefone);
		printf("\nCadastros encontrados: \n");
		exibeNomeTelefone(pRaiz, nome, telefone, 2);
		break;

	default:
		printf("Opcao invalida!");
		break;
	}

}



//FUNÇÕES AUXILIARES ------------------------------------------------------------------------------

void criaVazia(node **pLista)
{
	*pLista = NULL; //Inicializa a arvore
}


void inserir(node **pRaiz, unsigned long int cpf, node *novo)
{
	if (*pRaiz == NULL) //Insere o nó na arvore
	{
		*pRaiz = (node *)malloc(sizeof(node));
		*pRaiz = novo;
	}
	else
	{
		if (cpf < (*pRaiz)->cpf)
		{
			inserir(&(*pRaiz)->esq, cpf, novo); // Procura a posição do lado esquerdo
		}
		if (cpf >(*pRaiz)->cpf)
		{
			inserir(&(*pRaiz)->dir, cpf, novo); // Procura a posição do lado direito
		}
	}
}


void remover(node **pRaiz, unsigned long int cpf)
{
	if (*pRaiz == NULL)
	{
		printf("Cadastro não encontrado!");
	}
	else
	{
		if (cpf < (*pRaiz)->cpf)
		{
			remover(&(*pRaiz)->esq, cpf); // Procura no lado esquerdo da arvore
		}
		else
		{
			if (cpf >(*pRaiz)->cpf)
			{
				remover(&(*pRaiz)->dir, cpf); // Procura no lado direito
			}
			else
			{    // Caso encontre o cadastro
				node *pAux = *pRaiz; //cria uma variavel auxiliar para verificar os "filhos" do nó
				if (((*pRaiz)->esq == NULL) && ((*pRaiz)->dir == NULL))
				{	// se nao houver filhos...exclui o nó atual
					free(pAux);
					(*pRaiz) = NULL;
					printf("Remocao concluida.");
				}
				else
				{     //Se o nó só tem o filho da direita
					if ((*pRaiz)->esq == NULL)
					{	//Insere o primeiro nó da direita no lugar do nó atual
						(*pRaiz) = (*pRaiz)->dir;
						pAux->dir = NULL;
						free(pAux); pAux = NULL;
						printf("Remocao concluida.");
					}
					else
					{    //Se o nó só tem filho da esquerda
						if ((*pRaiz)->dir == NULL)
						{	//Insere o primeiro nó da esquerda no lugar do nó atual
							(*pRaiz) = (*pRaiz)->esq;
							pAux->esq = NULL;
							free(pAux); pAux = NULL;
							printf("Remocao concluida.");
						}
						else
						{   // Se o nó tem filhos dos dois lados
							//Escolhi um nó do lado direito(o maior) para substituir o nó atual
							pAux = MaiorDireita(&(*pRaiz)->esq);
							//se vc quiser usar o Menor da esquerda, 
							//so o que mudaria seria isso: pAux = MenorEsquerda(&(*pRaiz)->direita);
							pAux->esq = (*pRaiz)->esq; // Passa a subarvore do antigo lado esquerdo para o nó atual
							pAux->dir = (*pRaiz)->dir; // Passa a subarvore do antigo lado direito para o nó atual
							(*pRaiz)->esq = (*pRaiz)->dir = NULL;
							free((*pRaiz));  *pRaiz = pAux;  pAux = NULL; //Libera o espaço do antigo nó
							printf("Remocao concluida.");
						}
					}
				}
			}
		}
	}
}


node *MaiorDireita(node **no)
{
	if ((*no)->dir != NULL)
	{
		return MaiorDireita(&(*no)->dir);
	}
	else
	{
		node *aux = *no;
		if ((*no)->esq != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
		{
			*no = (*no)->esq;
		}
		else
		{
			*no = NULL;
		}
		return aux;
	}
}


int procura_cpf(node *LISTA, unsigned long int cpf)
{
	if (!LISTA) { return 0; } //Se não encontrar nada retorna 0
	if (LISTA->cpf == cpf) { return 1; } //Se encontrar o nó retorna 1
	if (cpf < LISTA->cpf) { return procura_cpf(LISTA->esq, cpf); } //Percorre a arvore do lado esquerdo
	return procura_cpf(LISTA->dir, cpf); //Percorre do lado direito
}


void adicionaTelefone(Fone **num)
{
	Fone *aux, *telefone = (Fone *)malloc(sizeof(Fone));
	int resultado = 0;

	aux = *num;
	// Inicializa o novo nó
	printf("\nDigite o numero: ");
	scanf("%lu", &telefone->numero);
	telefone->prox = NULL;

	resultado = procurarTelefone(aux, telefone->numero); //Procura o nó na lista de telefones

	if (resultado == 1)
	{
		printf("Numero ja cadastrado!\n");
		free(telefone);
	}
	else
	{
		if (!(*num)) //Insere o nó na cabeça da lista caso esteja vazia
		{
			*num = telefone;
			printf("Numero adicionado.\n");
		}
		else
		{
			while (aux != NULL) //Insere o nó no fim da lista
			{
				if (aux->prox == NULL)
				{
					aux->prox = telefone;
					printf("Numero adicionado.\n");
					break;
				}
				else
				{
					aux = aux->prox;
				}
			}
		}
	}
}


void removerTelefone(Fone **num)
{
	Fone *aux, *tmp;
	unsigned long int numero;
	int resultado = 0;

	printf("\nDigite o numero: ");
	scanf("%lu", &numero);

	if (!(*num))
	{
		printf("Lista vazia!\n");
	}
	else
	{
		aux = *num;
		tmp = *num;

		while (tmp != NULL)
		{
			if (tmp->numero == numero) // Encontrou o nó
			{
				if (tmp == aux) // se esta removendo o primeiro da lista
				{
					(*num) = (*num)->prox;
					free(tmp);
					printf("Remocao efetuada.\n");
					resultado = 1;
					break;
				}
				else  // esta removendo do meio da lista
				{
					aux->prox = tmp->prox;  // Refaz o encadeamento
					free(tmp);                // Libera a area do nó
					printf("Remocao efetuada.\n");
					resultado = 1;
					break;
				}
			}
			else  // continua procurando no prox. nó
			{
				aux = tmp;
				tmp = tmp->prox;
			}
		}
	}
	if (resultado != 1)
	{
		printf("Numero nao encontrado!\n");
	}
}


int procurarTelefone(Fone *num, unsigned long int numero)
{
	while (num != NULL) // Enquanto a lista não estiver vazia
	{
		if (num->numero == numero) //Se encontrar o numero retorna 1
		{
			return 1;
		}
		else
		{
			num = num->prox;
		}
	}
	return 0; //Se não encontrar retorna 0
}


void exibeNomeTelefone(node *pRaiz, char nome[], unsigned long int telefone, int opcao)
{
	if (pRaiz != NULL)
	{
		if (opcao == 1)
		{
			exibeNomeTelefone(pRaiz->esq, nome, telefone, opcao);
			char *compara;
			
			compara = strstr(pRaiz->nome, nome);
			if (compara != NULL)
			{
				printf("\nnome: %s, CPF: %lu", pRaiz->nome, pRaiz->cpf); //Printa o nó
			}

			exibeNomeTelefone(pRaiz->dir, nome, telefone, opcao);
		}

		if (opcao == 2)
		{
			exibeNomeTelefone(pRaiz->esq, nome, telefone, opcao);
			Fone *num = pRaiz->numeros;
			while (num != NULL)
			{
				if (num->numero == telefone)
				{
					printf("\nnome: %s, CPF: %lu", pRaiz->nome, pRaiz->cpf); //Printa o nó
					break;
				}
				else
				{
					num = num->prox;
				}
			}
			exibeNomeTelefone(pRaiz->dir, nome, telefone, opcao);
		}
	}

}