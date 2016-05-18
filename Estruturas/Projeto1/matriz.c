#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#define MAX 50

// Augusto Scarelli Silva 				RA: 15049711
// Daniel Augusto Silveira Ramos 		RA: 15589500
// Danilo Luís Lopes Raymundo Paixão	RA: 15051659
// Júlio Ferro Neto						RA: 15265135

struct lista_matriz {
	char nome[20];
	int linhas;
	int colunas;
	float matriz[MAX][MAX];
	Matriz *prox;
};

void criaVazia(Matriz **pLista)
{
	*pLista = NULL;
}


void criaMatriz(Matriz **pLista, char nome[], int linhas, int colunas)
{
	int i = 0, j = 0, erro = 0, resultado = 1, saida = 0;
	Matriz *tmp, *novo = (Matriz *)malloc(sizeof(Matriz));


	tmp = *pLista;

	//Procura se o nome passado por parâmetro já existe na lista
	if (tmp != NULL)
	{
		do
		{
			resultado = strcmp(tmp->nome, nome);
			//se o atual nome da lista é igual ao parâmetro, retorna ERRO e sai do loop
			if (resultado == 0)
			{
				printf("ERRO");
				erro = 1;
				saida = 1;
			}
			//se não for igual, verifica se chegou ao final da lista pra saber se continua no loop
			else
			{
				if (tmp->prox == NULL)
				{
					saida = 1;
				}
				else
				{
					tmp = tmp->prox;
				}
			}

		} while (saida != 1);
	}

	//Se não foi identificado o erro no nome, verifica se a quantidade de linhas e colunas é valida
	if (erro != 1)
	{
		if (linhas > 50 && linhas < 1)
		{
			printf("ERRO");
			erro = 1;
		}
		else
		{
			if (colunas > 50 && colunas < 1)
			{
				printf("ERRO");
				erro = 1;
			}
		}
	}

	//Se não foi identificado erro nos parâmetros, irá fazer a passagem deles para o novo nó da lista
	if (erro != 1)
	{
		tmp = *pLista;
		strcpy(novo->nome, nome);
		novo->linhas = linhas;
		novo->colunas = colunas;
		novo->prox = NULL; //Nó sempre adicionado no fim da lista**

						   //Verifica se a lista está vazia
		if (!(*pLista))
		{
			(*pLista) = novo;
		}
		else
		{
			//Verifica se a lista possui apenas uma matriz
			if (tmp->prox == NULL)
			{
				tmp->prox = novo;
			}
			else
			{
				//Se houver varias matrizes, irá procurar o ultimo elemento
				while (tmp->prox != NULL)
				{
					tmp = tmp->prox;
					if (tmp->prox == NULL)
					{
						tmp->prox = novo;
						break;
					}
				}
			}
		}

		printf("OK"); //Retorno
	}

}


void destroiMatriz(Matriz **pLista, char nome[])
{
	Matriz *tmp, *aux;
	int excluido = 0, resultado = 1, saida = 0;

	//Se a lista estiver vazia, retorna erro
	if (!(*pLista))
	{
		printf("ERRO");
	}
	else
	{
		tmp = (*pLista);
		aux = (*pLista);

		//Vai procurar pela matriz que deseja remover
		do
		{
			//Vai verificar se a atual matriz da lista é a desejada
			resultado = strcmp(tmp->nome, nome);
			if (resultado == 0)
			{
				//Verifica se a matriz desejada é a primeira da lista
				if (tmp == (*pLista))
				{
					//Se for a primeira, passa a ponta da lista para a próxima matriz
					(*pLista) = (*pLista)->prox;
					free(tmp);
					printf("OK");
					excluido = 1;
					saida = 1;
				}
				//Se não for a primeira, utiliza a auxiliar para excluir do meio ou final
				else
				{
					aux->prox = tmp->prox;
					free(tmp);
					printf("OK");
					excluido = 1;
					saida = 1;
				}
			}
			//Verifica se chegou ao final da lista pra saber se continua no loop
			else
			{
				if (tmp->prox == NULL)
				{
					saida = 1;
				}
				else
				{
					aux = tmp;
					tmp = tmp->prox;
				}
			}

		} while (saida != 1);

		//Se o elemento desejado para a exclusão não for identificado, retorna ERRO
		if (excluido == 0)
		{
			printf("ERRO");
		}

	}
}


void imprimeMatriz(Matriz *matriz, char nome[])
{
	int i, j, sair = 0, resultado = 1;
	Matriz *tmp;

	tmp = matriz;

	if (!matriz)
	{
		printf("ERRO\n");
	}
	else
	{
		do
		{
			resultado = strcmp(tmp->nome, nome);
			if (resultado == 0)
			{
				for (i = 0; i < tmp->linhas; i++)
				{
					for (j = 0; j < tmp->colunas; j++)
					{
						printf("%4.2f ", tmp->matriz[i][j]);
					}

					printf("\n");
				}
				sair = 1;
			}
			else
			{
				if (tmp->prox != NULL)
				{
					tmp = tmp->prox;
				}
				else
				{
					printf("ERRO\n");
					sair = 1;
				}
			}

		} while (sair != 1);

	}
}


void atribuirElemento(Matriz **pLista, char nome[], int linhas, int colunas, float valor)
{
	int i = 0, j = 0, resultado = 1, saida = 0;
	Matriz *tmp;

	tmp = *pLista;

	if (tmp != NULL)
	{
		do
		{
			//Verifica se existe a matriz passada
			resultado = strcmp(tmp->nome, nome);
			//Se existe, verifica se chegou no fim da lista para continuar o loop
			if (resultado == 0)
			{
				if (linhas <= tmp->linhas && linhas > 0 && colunas <= tmp->colunas && colunas > 0)
				{
					tmp->matriz[linhas - 1][colunas - 1] = valor;
					printf("OK");
					saida = 1;
				}
				else
				{
					printf("ERRO");
					saida = 1;
				}
			}

			//se não existir, retorna erro
			else
			{
				if (tmp->prox != NULL)
				{
					tmp = tmp->prox;
				}
				else
				{
					printf("ERRO");
					saida = 1;
				}
			}
		} while (saida != 1);
	}
}


void atribuirLinha(Matriz **pLista, char nome[], int linha)
{
	Matriz *tmp;
	int i = 0, j = 0, erro = 0, resultado = 1, saida = 0, tamanho;
	char valoresC[MAX];
	float valores[MAX];

	//Verifica se a lista está vazia, se estiver retorna ERRO
	if (!(*pLista))
	{
		printf("ERRO\n");
	}
	else
	{
		tmp = (*pLista);

		//Irá procurar se a matriz ja existe
		do
		{
			resultado = strcmp(tmp->nome, nome);

			if (resultado == 0)
			{
				//Se a matriz desejada for encontrada, ira fazer as validações necessarias
				if ((linha > tmp->linhas) || (linha < 1))
				{
					printf("ERRO\n");
					saida = 1;
				}
				else
				{
					i = 0;

					while (saida != 1)
					{
						scanf(" %s", &valoresC);
						tamanho = strlen(valoresC);
						if (valoresC[tamanho - 1] == '#')
						{
							//verifica se os valores condizem com o numero de colunas da matriz
							if (i > tmp->colunas)
							{
								printf("ERRO\n");
								saida = 1;
								erro = 1;
							}
							saida = 1;
						}
						else
						{
							valores[i] = atof(valoresC);
							i++;
						}
					}
					//se as validaçoes anteriores forem falsas ele ira atribuir a linha 
					if (erro != 1)
					{
						for (j = 0; j < i; j++)
						{
							tmp->matriz[linha - 1][j] = valores[j];
						}
						printf("OK\n");
						saida = 1;
					}
				}
			}
			//Se a matriz desejada não for a atual, irá verificar se chegou no fim da lista
			else
			{
				//Se não existir, vai verificar se chegou ao fim da lista
				if (resultado != 0)
				{
					if (tmp->prox != NULL)
					{
						tmp = tmp->prox;
					}
					else
					{
						saida = 1;
					}
				}
			}

		} while (saida != 1);
	}
}


void atribuirColuna(Matriz **pLista, char nome[], int coluna)
{
	Matriz *tmp;
	int i = 0, j = 0, erro = 0, resultado = 1, saida = 0;
	char valoresC[MAX];
	float valores[MAX];

	//Verifica se a lista está vazia, se estiver retorna ERRO
	if (!(*pLista))
	{
		printf("ERRO\n");
	}
	else
	{
		tmp = (*pLista);

		//Irá procurar se a matriz ja existe
		do
		{
			resultado = strcmp(tmp->nome, nome);

			if (resultado == 0)
			{
				//Se a matriz desejada for encontrada, ira fazer as validações necessarias
				if ((coluna > tmp->colunas) || (coluna < 1))
				{
					printf("ERRO\n");
					saida = 1;
				}
				else
				{
					i = 0;

					while (saida != 1)
					{
						scanf(" %c", &valoresC[0]);
						if (valoresC[0] == '#')
						{
							//verifica se os valores condizem com o numero de linhas da matriz
							if (i > tmp->linhas)
							{
								printf("ERRO\n");
								saida = 1;
								erro = 1;
							}
							saida = 1;
						}
						else
						{
							valores[i] = atof(valoresC);
							i++;
						}
					}
					//se as validaçoes anteriores forem falsas ele ira atribuir a coluna 
					if (erro != 1)
					{
						for (j = 0; j < i; j++)
						{
							tmp->matriz[j][coluna - 1] = valores[j];
						}
						printf("OK\n");
						saida = 1;
					}
				}
			}
			//Se a matriz desejada não for a atual, irá verificar se chegou no fim da lista
			else
			{
				//Se não existir, vai verificar se chegou ao fim da lista
				if (resultado != 0)
				{
					if (tmp->prox != NULL)
					{
						tmp = tmp->prox;
					}
					else
					{
						saida = 1;
					}
				}
			}

		} while (saida != 1);
	}
}


void transporMatriz(Matriz **pLista, char nome[])
{
	Matriz *tmp, *aux, *transposta = (Matriz *)malloc(sizeof(Matriz));
	int i = 0, j = 0, erro = 0, resultado = 1, saida = 0, saida2 = 0;
	char nome_transposta[20];

	//Verifica se a lista está vazia, se estiver retorna ERRO
	if (!(*pLista))
	{
		printf("ERRO");
	}
	else
	{
		tmp = (*pLista);
		aux = (*pLista);

		//Irá procurar a matriz que deseja transpor na lista
		do
		{

			resultado = strcmp(tmp->nome, nome);
			if (resultado == 0)
			{
				//Se a matriz desejada for encontrada, irá verificar se o nome da transposta ja existe
				fflush(stdin);
				scanf(" %s", &nome_transposta);
				do
				{
					resultado = strcmp(aux->nome, nome_transposta);
					//Se ja existir, retorna ERRO e encerra o loop 2
					if (resultado == 0)
					{
						erro = 1;
						saida2 = 1;
					}
					else
					{
						//Se não existir, vai verificar se chegou ao fim da lista
						if (resultado != 0)
						{
							if (aux->prox != NULL)
							{
								aux = aux->prox;
							}
							else
							{
								saida2 = 1;
							}
						}
					}
				} while (saida2 != 1);

				//Após terminar a verificação do nome da transposta, encerra o loop 1
				saida = 1;

			}
			//Se a matriz desejada não for a atual, irá verificar se chegou no fim da lista
			else
			{
				if (tmp->prox == NULL)
				{
					saida = 1;
				}
				else
				{
					tmp = tmp->prox;
				}
			}

		} while (saida != 1);

		//Se foi verificado irregularidade, retorna ERRO
		if (erro == 1)
		{
			printf("ERRO");
		}
		else
		{
			//Se não, irá passar os parâmetros para a nova matriz
			aux->prox = transposta;
			strcpy(transposta->nome, nome_transposta);
			transposta->linhas = tmp->colunas;
			transposta->colunas = tmp->linhas;
			transposta->prox = NULL;

			//transposição
			for (i = 0; i < tmp->linhas; i++)
			{
				for (j = 0; j < tmp->colunas; j++)
				{
					transposta->matriz[j][i] = tmp->matriz[i][j];
				}
			}
			//printf("OK");
			imprimeMatriz(transposta, transposta->nome);
		}

	}
}


void somarMatriz(Matriz *pLista, char nome[], char nome2[], char nome3[])
{
	Matriz *tmp, *aux, *aux2, *novo = (Matriz *)malloc(sizeof(Matriz));
	int i, j, resultado = 1, saida = 0, erro = 0;

	tmp = pLista;
	aux = pLista;
	aux2 = pLista;

	if (!pLista)
	{
		printf("ERRO");
	}
	else
	{
		do
		{
			resultado = strcmp(tmp->nome, nome);
			if (resultado == 0)
			{
				do
				{
					resultado = strcmp(aux->nome, nome2);
					if (resultado == 0)
					{
						do
						{
							resultado = strcmp(aux2->nome, nome3);
							if (resultado == 0)
							{
								printf("ERRO");
								erro = 1;
								saida = 1;
							}
							else
							{
								if (aux2->prox == NULL)
								{
									saida = 1;
								}
								else
								{
									aux2 = aux2->prox;
								}
							}

						} while (saida != 1);
					}
					else
					{
						if (aux->prox == NULL)
						{
							printf("ERRO");
							erro = 1;
							saida = 1;
						}
						else
						{
							aux = aux->prox;
						}
					}

				} while (saida != 1);
			}
			else
			{
				if (tmp->prox == NULL)
				{
					printf("ERRO");
					erro = 1;
					saida = 1;
				}
				else
				{
					tmp = tmp->prox;
				}
			}
		} while (saida != 1);

		if (((tmp->linhas) != (aux->linhas)) || ((tmp->colunas) != (aux->colunas)))
		{
			printf("ERRO");
			erro = 1;
		}

		if (erro != 1)
		{
			strcpy(novo->nome, nome3);
			novo->linhas = tmp->linhas;
			novo->colunas = tmp->colunas;
			novo->prox = NULL;
			aux2->prox = novo;

			for (i = 0; i < (novo->linhas); i++)
			{
				for (j = 0; j < (novo->colunas); j++)
				{
					novo->matriz[i][j] = tmp->matriz[i][j] + aux->matriz[i][j];
				}
			}
			//printf("OK");
			imprimeMatriz(novo, novo->nome);
		}
	}
}

void dividirMatriz(Matriz *pLista, char nome[], char nome2[], char nome3[])
{
	Matriz *tmp, *aux, *aux2, *novo = (Matriz *)malloc(sizeof(Matriz));
	int i, j, resultado = 1, saida = 0, erro = 0;

	tmp = pLista;
	aux = pLista;
	aux2 = pLista;

	if (!pLista)
	{
		printf("ERRO");
	}
	else
	{
		do
		{
			resultado = strcmp(tmp->nome, nome);
			if (resultado == 0)
			{
				do
				{
					resultado = strcmp(aux->nome, nome2);
					if (resultado == 0)
					{
						do
						{
							resultado = strcmp(aux2->nome, nome3);
							if (resultado == 0)
							{
								printf("ERRO");
								erro = 1;
								saida = 1;
							}
							else
							{
								if (aux2->prox == NULL)
								{
									saida = 1;
								}
								else
								{
									aux2 = aux2->prox;
								}
							}

						} while (saida != 1);
					}
					else
					{
						if (aux->prox == NULL)
						{
							printf("ERRO");
							erro = 1;
							saida = 1;
						}
						else
						{
							aux = aux->prox;
						}
					}

				} while (saida != 1);
			}
			else
			{
				if (tmp->prox == NULL)
				{
					printf("ERRO");
					erro = 1;
					saida = 1;
				}
				else
				{
					tmp = tmp->prox;
				}
			}
		} while (saida != 1);

		if (((tmp->linhas) != (aux->linhas)) || ((tmp->colunas) != (aux->colunas)))
		{
			printf("ERRO");
			erro = 1;
		}

		for (i = 0; i < (aux->linhas); i++)
		{
			for (j = 0; j < (aux->colunas); j++)
			{
				if (aux->matriz[i][j] == 0)
				{
					printf("ERRO");
					erro = 1;
					break;
				}
			}
		}

		if (erro != 1)
		{
			strcpy(novo->nome, nome3);
			novo->linhas = tmp->linhas;
			novo->colunas = tmp->colunas;
			novo->prox = NULL;
			aux2->prox = novo;

			for (i = 0; i < (novo->linhas); i++)
			{
				for (j = 0; j < (novo->colunas); j++)
				{
					novo->matriz[i][j] = tmp->matriz[i][j] / aux->matriz[i][j];
				}
			}
			//printf("OK");
			imprimeMatriz(novo, novo->nome);
		}
	}
}


void multiplicarMatriz(Matriz *pLista, char nome[], char nome2[], char nome3[])
{
	Matriz *tmp, *aux, *aux2, *novo = (Matriz *)malloc(sizeof(Matriz));
	int i, j, k, resultado = 1, saida = 0, erro = 0;
	float acumulador = 0, A = 0, B = 0;

	tmp = pLista;
	aux = pLista;
	aux2 = pLista;

	if (!pLista)
	{
		printf("ERRO");
	}
	else
	{
		do
		{
			resultado = strcmp(tmp->nome, nome);
			if (resultado == 0)
			{
				do
				{
					resultado = strcmp(aux->nome, nome2);
					if (resultado == 0)
					{
						do
						{
							resultado = strcmp(aux2->nome, nome3);
							if (resultado == 0)
							{
								printf("ERRO");
								erro = 1;
								saida = 1;
							}
							else
							{
								if (aux2->prox == NULL)
								{
									saida = 1;
								}
								else
								{
									aux2 = aux2->prox;
								}
							}

						} while (saida != 1);
					}
					else
					{
						if (aux->prox == NULL)
						{
							printf("ERRO");
							erro = 1;
							saida = 1;
						}
						else
						{
							aux = aux->prox;
						}
					}

				} while (saida != 1);
			}
			else
			{
				if (tmp->prox == NULL)
				{
					printf("ERRO");
					erro = 1;
					saida = 1;
				}
				else
				{
					tmp = tmp->prox;
				}
			}
		} while (saida != 1);

		if ((tmp->colunas) != (aux->linhas))
		{
			printf("ERRO");
			erro = 1;
		}

		if (erro != 1)
		{
			strcpy(novo->nome, nome3);
			novo->linhas = tmp->linhas;
			novo->colunas = aux->colunas;
			novo->prox = NULL;
			aux2->prox = novo;

			for (i = 0; i < (novo->linhas); i++)
			{
				for (j = 0; j < (novo->colunas); j++)
				{
					for (k = 0; k < (tmp->colunas); k++)
					{
						A = tmp->matriz[i][k];
						B = aux->matriz[k][j];
						acumulador +=  A * B;
					}
					novo->matriz[i][j] = acumulador;
					acumulador = 0;
				}
			}
			//printf("OK");
			imprimeMatriz(novo, novo->nome);
		}
	}
}


void multiplicarElementosMatriz(Matriz *pLista, char nome[], char nome2[], char nome3[])
{
	Matriz *tmp, *aux, *aux2, *novo = (Matriz *)malloc(sizeof(Matriz));
	int i, j, resultado = 1, saida = 0, erro = 0;

	tmp = pLista;
	aux = pLista;
	aux2 = pLista;

	if (!pLista)
	{
		printf("ERRO");
	}
	else
	{
		do
		{
			resultado = strcmp(tmp->nome, nome);
			if (resultado == 0)
			{
				do
				{
					resultado = strcmp(aux->nome, nome2);
					if (resultado == 0)
					{
						do
						{
							resultado = strcmp(aux2->nome, nome3);
							if (resultado == 0)
							{
								printf("ERRO");
								erro = 1;
								saida = 1;
							}
							else
							{
								if (aux2->prox == NULL)
								{
									saida = 1;
								}
								else
								{
									aux2 = aux2->prox;
								}
							}

						} while (saida != 1);
					}
					else
					{
						if (aux->prox == NULL)
						{
							printf("ERRO");
							erro = 1;
							saida = 1;
						}
						else
						{
							aux = aux->prox;
						}
					}

				} while (saida != 1);
			}
			else
			{
				if (tmp->prox == NULL)
				{
					printf("ERRO");
					erro = 1;
					saida = 1;
				}
				else
				{
					tmp = tmp->prox;
				}
			}
		} while (saida != 1);

		if (((tmp->linhas) != (aux->linhas)) || ((tmp->colunas) != (aux->colunas)))
		{
			printf("ERRO");
			erro = 1;
		}

		if (erro != 1)
		{
			strcpy(novo->nome, nome3);
			novo->linhas = tmp->linhas;
			novo->colunas = tmp->colunas;
			novo->prox = NULL;
			aux2->prox = novo;

			for (i = 0; i < (novo->linhas); i++)
			{
				for (j = 0; j < (novo->colunas); j++)
				{
					novo->matriz[i][j] = tmp->matriz[i][j] * aux->matriz[i][j];
				}
			}
			//printf("OK");
			imprimeMatriz(novo, novo->nome);
		}
	}
}