#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Projeto de cadastro de alunos, disciplinas e professores.
*   Tarefas:
*   - Cadastro de alunos
*   - Cadastro de disciplinas
*   - Cadastro de professores
*   - Matricular um conjunto de alunos em um conjunto de disciplinas
*   - Cancelar a matricula de um conjunto de alunos em um conjunto de disciplinas
*   - Vincular um conjunto de professores à um conjunto de disciplinas
*   - Imprimir lista de todos os alunos
*   - Imprimir lista de todas as disciplinas
*   - Imprimir lista de todos os professores
*   - Imprimir lista de alunos matriculados em uma disciplina
*   - Imprimir lista de disciplinas que um aluno está matriculado
*   - Imprimir lista de professores vinculados à uma disciplina
*   - Imprimir lista de disciplinas ministradas por um professor
*/

typedef struct alunos talu;
typedef struct disciplinas tdisc;
typedef struct professores tprof;

struct alunos
{
    int ra;
    char nome[50];
};

struct disciplinas
{
    int cod;
    char nome[50];
    int cod_alunos[50];
    int cod_prof[50];
};

struct professores
{
    int cod;
    char nome[50];
};

int procuraAluno(talu alunos[50], int ra) // Função procura se o ra inserido já existe, se sim, a função retorna -1, se não, retorna a primeira posição disponível
{
    for(int i = 0; i < 50; i++)
    {
        if()
    }
    
    
}

void cadastro_aluno(talu alunos[50])
{
    int ra;
    char nome[50];
    
    printf("Digite o RA do aluno que quer cadastrar: ");
    __fpurge(stdin);
    //fflush(stdin);
    scanf("%d", &ra);
    
    printf("Digite o nome do aluno a ser cadastrado: ")
    __fpurge(stdin);
    //fflush(stdin);
    fgets(nome, 50, stdin);
    
    
    
}



int main()
{
    talu alunos[50];
    tdisc disciplinas[50];
    tprof professores[50];
    int opcao = 1;
    

    while(opcao)
    {
        printf("O que deseja fazer? \n");
        printf("1- Cadastro de alunos\n");
        printf("2- Cadstro de disciplinas\n");
        printf("3- Cadastro de professores\n");
        
        printf("0- Sair\n");
        
        scanf("%d", &opcao);
        
        
    }



    return 0;
}
