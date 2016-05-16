#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

//STRUCT DE MATRIZES
typedef struct lista_matriz Matriz;
struct lista_matriz {
	char nome[20];
	int linhas;
	int colunas;
	int matriz[MAX][MAX];
	Matriz *prox;
};


//FUNÇÕES
void criaVazia(Matriz **pLista);
void criaMatriz(Matriz **pLista, char nome[], int linhas, int colunas);
void destroiMatriz(Matriz **pLista, char nome[]);
void transporMatriz(Matriz **pLista, char nome[]);
void somaMatriz(Matriz *pLista1, char nome[], Matriz *pLista2, char nome2[]);
void atribuirElemento(Matriz **pLista, char nome[], int linhas, int colunas, int valor);


void main()
{
	Matriz *LISTA;
	char opt[3], nome[20];
	int resultado = 1, sair = 0, linhas, colunas, valor;

	//INICIALIZA LISTA
	criaVazia(&LISTA);

	//Loop do menu
	do
	{
		fflush(stdin);
		scanf(" %s", &opt);

		//CRIAR MATRIZ
		resultado = strcmp(opt, "CM");
		if (resultado == 0)
		{
			fflush(stdin);
			scanf(" %s", &nome);
			scanf("%d %d", &linhas, &colunas);
			criaMatriz(&LISTA, nome, linhas, colunas);
			printf("\n\n");
			resultado = 1;
		}


		//DESTRUIR MATRIZ
		resultado = strcmp(opt, "DM");
		if (resultado == 0)
		{
			fflush(stdin);
			scanf(" %s", &nome);
			destroiMatriz(&LISTA, nome);
			printf("\n\n");
			resultado = 1;
		}


		//IMPRIMIR MATRIZ
		resultado = strcmp(opt, "IM");
		if (resultado == 0)
		{
			printf("\n\n");
			resultado = 1;
		}


		//ATRIBUIR ELEMENTO À MATRIZ
		resultado = strcmp(opt, "AE");
		if (resultado == 0)
		{
			fflush(stdin);
			scanf("%s", &nome);
			printf("Insira um Valor:\n");
			scanf("%i", &valor);
			scanf("%i %i", &linhas, &colunas);
			atribuirElemento(&LISTA, nome, linhas, colunas, valor);
			printf("\n\n");
			resultado = 1;
		}


		//ATRIBUIR UMA LINHA À MATRIZ
		resultado = strcmp(opt, "AL");
		if (resultado == 0)
		{

			printf("\n\n");
			resultado = 1;
		}


		//ATRIBUIR UMA COLUNA À MATRIZ
		resultado = strcmp(opt, "AC");
		if (resultado == 0)
		{

			printf("\n\n");
			resultado = 1;
		}


		//TRANSPOR MATRIZ
		resultado = strcmp(opt, "TM");
		if (resultado == 0)
		{
			fflush(stdin);
			scanf(" %s", &nome);
			transporMatriz(&LISTA, nome);
			printf("\n\n");
			resultado = 1;
		}


		//SOMAR DUAS MATRIZES
		resultado = strcmp(opt, "SM");
		if (resultado == 0)
		{

			printf("\n\n");
			resultado = 1;
		}


		//DIVIDIR UMA MATRIZ POR OUTRA (ELEMENTO A ELEMENTO)
		resultado = strcmp(opt, "DV");
		if (resultado == 0)
		{

			printf("\n\n");
			resultado = 1;
		}


		//MULTIPLICAR UMA MATRIZ POR OUTRA
		resultado = strcmp(opt, "MM");
		if (resultado == 0)
		{

			printf("\n\n");
			resultado = 1;
		}


		//MULTIPLICAR UMA MATRIZ POR OUTRA (ELEMENTO A ELEMENTO)
		resultado = strcmp(opt, "ME");
		if (resultado == 0)
		{
            
            
			printf("\n\n");
			resultado = 1;
		}


		//SAIDA
		resultado = strcmp(opt, "FE");
		if (resultado == 0)
		{
			sair = 2;
		}

	} while (sair != 2);

	free(LISTA);
	//system("pause");
}


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
			printf("OK");

		}

	}
}


void atribuirElemento(Matriz **pLista, char nome[], int linhas, int colunas, int valor)
{
	int i = 0, j = 0, erro = 0, resultado = 1, saida = 0;
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
					tmp->matriz[linhas][colunas] = valor;
					printf("%i", tmp->matriz[linhas][colunas]);
					saida = 1;
				}
				else
				{
					printf("ERRO");
					erro = 1;
					saida = 1;
				}
			}

			//se não existir, retorna erro
			else
			{

				printf("ERRO");
				erro = 1;
				saida = 1;

			}
		} while (saida != 1);
	}
}

/*void somaMatriz(Matriz *pLista1, char nome[], Matriz *pLista2, char nome2[])
{
int i = 0, j = 0,  erro = 0, resultado = 1, saida = 0, saida2 = 0;
Matriz *tmp, *novo = (Matriz *)malloc(sizeof(Matriz)), *aux, *tmp2, *aux2;
char nome_Soma[20];

//Verifica se a lista está vazia, se estiver retorna ERRO
if (!(pLista1))
{
printf("ERRO");
}
else
{
tmp = (pLista1);
aux = (pLista1);

//Irá procurar se a primeira matriz existe
do
{

resultado = strcmp(tmp->nome, nome);
if (resultado == 0)
{
//Irá procurar se a segunda matriz existe
tmp2 = (pLista2);
aux2 = (pLista2);

do
{
resultado = strcmp(tmp2->nome, nome);
if (resultado == 0)
{
//Se ambas as matrizes existirem
fflush(stdin);
scanf(" %s", &nome_Soma);
do
{
resultado = strcmp(aux->nome, nome_Soma);
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
}



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


}
}*/

void multiplicaUmPorUm(Matriz **pLista)
{
	char nome1[50], nome2[50], nomeF[50];
	Matriz *ma1, *aux,*ma2, *maFinal=(Matriz *)malloc(sizeof(Matriz));
	int comparador, i=0, j=0;
	ma1=*pLista;
	ma2=*pLista;
	aux=*pLista;
	
	fflush(stdin);
	scanf(" %s", &nome1);
	
	// Verifica se a lista está vazia
	if (!(*pLista))
	{
		printf("ERRO");
	}
	// Procura a primeira matriz
	else
	{
		while(ma1)
		{
			comparador = strcmp(ma1->nome, nome1);
			if(comparador==0) // Se encontrar a primeira matriz
			{
				fflush(stdin);
				scanf(" %s", &nome2);
				break;
			}
			if(!(ma1->prox))
			{
				printf("ERRO");
			}
			ma1 = ma1->prox;
			
		}
		while(ma2) // Procura a segunda matriz
		{
			comparador = strcmp(ma2->nome, nome2);
			if(comparador==0)
			{
				fflush(stdin);
				scanf(" %s", &nomeF);
				break;
			}
			if(!(ma2->prox))
			{
				printf("ERRO");
			}
			ma2=ma2->prox;
		}
		while(aux) // Verifica se o nome da matriz de resultado existe
		{
			comparador=strcmp(aux->nome, nomeF);
			if(comparador==0)
			{
				printf("Erro");
				break;
			}
			if(!(aux->prox))
			{
				if((ma1->linhas == ma2->linhas) && (ma1->colunas == ma2->colunas)) // Verifica se o número de linhas e de colunas das duas matrizes escolhidas são iguais
				{
					aux->prox = maFinal; // Inclui a matriz de resultado na lista de matrizes
					strcpy(maFinal->nome, nomeF);
					maFinal->linhas = ma1->linhas;
					maFinal->colunas = ma1->colunas;
					maFinal->prox = NULL;
					for (i = 0; i < maFinal->linhas; i++) 
					{
						for (j = 0; j < maFinal->colunas; j++) 
						{
							maFinal->matriz[i][j] = (ma1->matriz[i][j]) * (ma2->matriz[i][j]); // Faz a multiplicação elemento por elemento das duas matrizes
						}
					}
					break;
				}
				
				
				
				
				
			}
			aux=aux->prox;
			
		}
	}
	
}

void divideUmPorUm(Matriz **pLista)
{
	char nome1[50], nome2[50], nomeF[50];
	Matriz *ma1, *aux,*ma2, *maFinal=(Matriz *)malloc(sizeof(Matriz));
	int comparador, i=0, j=0;
	ma1=*pLista;
	ma2=*pLista;
	aux=*pLista;
	
	fflush(stdin);
	scanf(" %s", &nome1);
	
	// Verifica se a lista está vazia
	if (!(*pLista))
	{
		printf("ERRO");
	}
	// Procura a primeira matriz
	else
	{
		while(ma1)
		{
			comparador = strcmp(ma1->nome, nome1);
			if(comparador==0) // Se encontrar a primeira matriz
			{
				fflush(stdin);
				scanf(" %s", &nome2);
				break;
			}
			if(!(ma1->prox))
			{
				printf("ERRO");
			}
			ma1 = ma1->prox;
			
		}
		while(ma2) // Procura a segunda matriz
		{
			comparador = strcmp(ma2->nome, nome2);
			if(comparador==0)
			{
				fflush(stdin);
				scanf(" %s", &nomeF);
				break;
			}
			if(!(ma2->prox))
			{
				printf("ERRO");
			}
			ma2=ma2->prox;
		}
		while(aux) // Verifica se o nome da matriz de resultado existe
		{
			comparador=strcmp(aux->nome, nomeF);
			if(comparador==0)
			{
				printf("Erro");
				break;
			}
			if(!(aux->prox))
			{
				if((ma1->linhas == ma2->linhas) && (ma1->colunas == ma2->colunas)) // Verifica se o número de linhas e de colunas das duas matrizes escolhidas são iguais
				{
					aux->prox = maFinal; // Inclui a matriz de resultado na lista de matrizes
					strcpy(maFinal->nome, nomeF);
					maFinal->linhas = ma1->linhas;
					maFinal->colunas = ma1->colunas;
					maFinal->prox = NULL;
					for (i = 0; i < maFinal->linhas; i++) 
					{
						for (j = 0; j < maFinal->colunas; j++) 
						{
							maFinal->matriz[i][j] = (ma1->matriz[i][j]) / (ma2->matriz[i][j]); // Faz a multiplicação elemento por elemento das duas matrizes
						}
					}
					
					
					break;
				}
				
				
				
				
				
			}
			aux=aux->prox;
			
		}
	}
	
}
