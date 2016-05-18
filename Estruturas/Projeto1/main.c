#include <stdio.h>
#include "matriz.h"

// Augusto Scarelli Silva 				RA: 15049711
// Daniel Augusto Silveira Ramos 		RA: 15589500
// Danilo Luís Lopes Raymundo Paixão	RA: 15051659
// Júlio Ferro Neto						RA: 15265135

void main()
{
	Matriz *LISTA;
	char opt[3], nome[20], nome2[20], nome3[20];
	int resultado = 1, sair = 0, linhas, colunas;
	float valor;

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
			fflush(stdin);
			scanf(" %s", &nome);
			imprimeMatriz(LISTA, nome);
			printf("\n\n");
			resultado = 1;
		}


		//ATRIBUIR ELEMENTO À MATRIZ
		resultado = strcmp(opt, "AE");
		if (resultado == 0)
		{
			fflush(stdin);
			scanf(" %s", &nome);
			scanf("%d %d %f", &linhas, &colunas, &valor);
			atribuirElemento(&LISTA, nome, linhas, colunas, valor);
			printf("\n\n");
			resultado = 1;
		}


		//ATRIBUIR UMA LINHA À MATRIZ
		resultado = strcmp(opt, "AL");
		if (resultado == 0)
		{
			fflush(stdin);
			scanf(" %s", &nome);
			scanf("%d", &linhas);
			atribuirLinha(&LISTA, nome, linhas);
			printf("\n\n");
			resultado = 1;
		}


		//ATRIBUIR UMA COLUNA À MATRIZ
		resultado = strcmp(opt, "AC");
		if (resultado == 0)
		{
			fflush(stdin);
			scanf(" %s", &nome);
			scanf("%d", &colunas);
			atribuirColuna(&LISTA, nome, colunas);
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
			fflush(stdin);
			scanf(" %s", &nome);
			fflush(stdin);
			scanf(" %s", &nome2);
			fflush(stdin);
			scanf(" %s", &nome3);
			somarMatriz(LISTA, nome, nome2, nome3);
			printf("\n\n");
			resultado = 1;
		}


		//DIVIDIR UMA MATRIZ POR OUTRA (ELEMENTO A ELEMENTO)
		resultado = strcmp(opt, "DV");
		if (resultado == 0)
		{
			fflush(stdin);
			scanf(" %s", &nome);
			fflush(stdin);
			scanf(" %s", &nome2);
			fflush(stdin);
			scanf(" %s", &nome3);
			dividirMatriz(LISTA, nome, nome2, nome3);
			printf("\n\n");
			resultado = 1;
		}


		//MULTIPLICAR UMA MATRIZ POR OUTRA
		resultado = strcmp(opt, "MM");
		if (resultado == 0)
		{
			fflush(stdin);
			scanf(" %s", &nome);
			fflush(stdin);
			scanf(" %s", &nome2);
			fflush(stdin);
			scanf(" %s", &nome3);
			multiplicarMatriz(LISTA, nome, nome2, nome3);
			printf("\n\n");
			resultado = 1;
		}


		//MULTIPLICAR UMA MATRIZ POR OUTRA (ELEMENTO A ELEMENTO)
		resultado = strcmp(opt, "ME");
		if (resultado == 0)
		{
			fflush(stdin);
			scanf(" %s", &nome);
			fflush(stdin);
			scanf(" %s", &nome2);
			fflush(stdin);
			scanf(" %s", &nome3);
			multiplicarElementosMatriz(LISTA, nome, nome2, nome3);
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
