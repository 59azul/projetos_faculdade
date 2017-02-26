#include <stdio.h>
#include <stdlib.h>

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
}

struct disciplinas
{
    int cod;
    char nome[50];
    int cod_alunos[50];
    int cod_prof[50];
}

struct professores
{
    int cod;
    char nome[50];
}


int main()
{
    talu


    printf("O que deseja fazer? \n");



    return 0;
}
