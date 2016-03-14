#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Dados
{
	int ra;
	char nome[50];
	float nota;
	bool cadastrado = false;
};

void cadastro(Dados alunos[])
{
	int i = 0, escolha = 0;

	printf("\nINSERIR UM CADASTRO \n");
	for (i = 0; i < MAX; i++)
	{
		if (alunos[i].cadastrado == false)
		{
			printf("Digite o nome do aluno: ");
			scanf(" %s", alunos[i].nome);
			printf("Digite o RA do aluno: ");
			scanf("%d", &alunos[i].ra);
			printf("Digite a nota do aluno: ");
			scanf("%f", &alunos[i].nota);
			alunos[i].cadastrado = true;

			printf("Realizar um novo cadastro? (1-Sim,2-Nao): ");
			scanf("%d", &escolha);
			if (escolha == 2)
			{
				break;
			}
		}
	}
}

void remover_cadastro(Dados alunos[])
{
	int i = 0, escolha = 0, ra = 0;

	printf("\nREMOCAO DE CADASTRO \n");
	do
	{
		printf("Digite o RA do aluno que deseja remover: ");
		scanf("%d", &ra);

		for (i = 0; i < MAX; i++)
		{
			if (ra == alunos[i].ra)
			{
				alunos[i].cadastrado = false;
				break;
			}
			else
			{
				if (i == MAX - 1)
				{
					printf("Nenhum aluno encontrado. \n");
				}
			}
		}

		printf("Deseja remover outro cadastro? (1-Sim,2-Nao): ");
		scanf("%d", &escolha);

	} while (escolha != 2);

}

void busca_ra(Dados alunos[])
{
	int i = 0, escolha = 0, ra = 0;

	printf("\nBUSCA POR RA\n");
	do
	{
		printf("Digite o RA do aluno que deseja visualizar: ");
		scanf("%d", &ra);

		for (i = 0; i < MAX; i++)
		{
			if (ra == alunos[i].ra && alunos[i].cadastrado == true)
			{
				printf("nome: %s, RA: %d, nota: %.2f \n", alunos[i].nome, alunos[i].ra, alunos[i].nota);
				break;
			}
			else
			{
				if (i == MAX - 1)
				{
					printf("Nenhum aluno encontrado. \n");
				}
			}
		}

		printf("Deseja visualizar outro cadastro? (1-Sim,2-Nao): ");
		scanf("%d", &escolha);

	} while (escolha != 2);
}

void busca_nome(Dados alunos[])
{
	int i = 0, escolha = 0, ra = 0, resultado;
	char nome[50];

	printf("\nBUSCA POR NOME \n");
	do
	{
		printf("Digite o nome do aluno que deseja visualizar: ");
		scanf(" %s", nome);

		for (i = 0; i < MAX; i++)
		{
			resultado = strcmp(alunos[i].nome, nome);

			if (resultado == 0 && alunos[i].cadastrado == true)
			{
				printf("nome: %s, RA: %d, nota: %.2f \n", alunos[i].nome, alunos[i].ra, alunos[i].nota);
				break;
			}
			else
			{
				if (i == MAX - 1)
				{
					printf("Nenhum aluno encontrado. \n");
				}
			}
		}

		printf("Deseja visualizar outro cadastro? (1-Sim,2-Nao): ");
		scanf("%d", &escolha);

	} while (escolha != 2);
}

void exibir_dados(Dados alunos[])
{
	int i = 0, escolha = 0, ra = 0;

	printf("\nEXIBICAO DE CADASTROS \n");
	for (i = 0; i < MAX; i++)
	{
		if (alunos[i].cadastrado == true)
		{
			printf("nome: %s, RA: %d, nota: %.2f \n", alunos[i].nome, alunos[i].ra, alunos[i].nota);
		}
		else
		{
			if (i == MAX - 1)
			{
				printf("Nenhum aluno encontrado. \n");
			}
		}
	}
}


void main()
{
	Dados alunos[MAX];
	int escolha;

	do
	{
		printf("CADASTRO DE ALUNOS \n\n");
		printf("1 - Inserir o cadastro de um aluno. \n");
		printf("2 - Remover o cadastro de um aluno. \n");
		printf("3 - Buscar aluno por RA. \n");
		printf("4 - Buscar aluno por nome. \n");
		printf("5 - Exibir dados de todos os alunos cadastrados. \n");
		printf("6 - Sair. ");
		printf("\n\nEscolha uma opcao:  ");
		scanf("%d", &escolha);

		switch (escolha)
		{
			case 1:	cadastro(alunos);
			break;
			case 2:	remover_cadastro(alunos);
			break;
			case 3:	busca_ra(alunos);
			break;
			case 4:	busca_nome(alunos);
			break;
			case 5:	exibir_dados(alunos);
			break;
			default: printf("Fim do programa!\n");
			break;
		}

		printf("\n");

	} while (escolha != 6);



	system("pause");
}