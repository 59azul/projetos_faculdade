#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Sistema de Controle Acadêmico
1) Cadastrar alunos ( um por vez): nome e RA
2) Cadastrar disciplinas (uma por vez): código e nome
3) Realizar a matrícula dos alunos cadastrados em disciplinas.
4) Imprimir a lista de disciplinas de um aluno
5) Imprimir a lista de alunos em uma disciplina
6) Função para matricular alunos em disciplinas. Matricula cada um dos alunos na lista ALUNOS em todas as disciplinas da lista DISCIPLINAS.
7) Vincular uma lista de professores a uma lista de disciplinas. Cada um dos professores da lista de professores estará vinculado a cada uma das disciplinas da lista de disciplinas.
8) Cancelar matrícula de alunos em disciplinas. Cancelar a matrícula cada um dos alunos na lista ALUNOS de todas as disciplinas da lista DISCIPLINAS.
9) Remover o vínculo de cada um dos professores na lista professores a cada uma das disciplinas na lista DISCIPLINAS; */


typedef struct aluno taluno;
typedef struct disciplinas tdisciplinas;
typedef struct professores tprofessores;

struct aluno{
    int ra;
    char nome[50];
    int codDisciplinas[50];
    
};

struct disciplinas{
    int cod;
    char nome[50];
};

struct professores{
    int codProfessores;
    char nome[50];
    int codDisciplinas[50];
};

void cadastraAluno(taluno *aluno, char nomeAluno[50], int ra){
    strcpy(aluno->nome, nomeAluno);
    aluno->ra = ra;
}

void cadastraDisciplina(tdisciplinas *disciplina, char nomeDisciplina[50], int cod){
    strcpy(disciplina->nome, nomeDisciplina);
    disciplina->cod = cod;
}

void imprimeAlunos(taluno alunos[]){
    int contador=0;
    
    while(contador<50){
        if(alunos[contador].ra==0){
            break;
        }
        printf("RA: %d\n", alunos[contador].ra);
        printf("Nome: %s\n", alunos[contador].nome);
        contador++;
    }
}

int main(void){
    int opcao=1;
    taluno alunos[50];
    tdisciplinas disciplinas[50];
    tprofessores professores[50];
    char nomeDigitado[50];
    int  codDigitado;
    int contAlunos=0, contDisciplinas=0;
    
    while(opcao != 0){
        do {
	    printf("\n");
            printf("(0) Finalizar o programa\n");
            printf("(1) Cadastrar alunos\n");
            printf("(2) Cadastrar disciplinas\n");
            printf("(3) Realizar a matricula dos alunos cadastrados em disciplinas\n");
            printf("(4) Imprimir a lista de disciplinas de um aluno\n");
            printf("(5) Imprimir a lista de alunos em uma disciplina\n");
            printf("(6) Matricular todos os alunos em todas as disciplinas\n");
            printf("(7) Vincular lista de professores a uma lista de disciplinas\n");
            printf("(8) Cancelar a matricula de todos os alunos em todas as disciplinas\n");
            printf("(9) Remover o vinculo de cada um dos professores a todas as disciplinas\n");
	    printf("Opcao: ");
            scanf("%d", &opcao);
	    printf("\n");
            if ((opcao<0) || (opcao>10))
                printf("Opcao invalida!\n");
        } while ((opcao<0) || (opcao>10));
        switch (opcao){
            case 0:
                printf("Finalizando o programa.\n");
                return 0;
            case 1:
                printf("Digite o ra do aluno a ser cadastrado: ");
                __fpurge(stdin);
                scanf("%d", &codDigitado);
                printf("Digite o nome do aluno a ser cadastrado: ");
                __fpurge(stdin);
                fgets(nomeDigitado, 50, stdin);
                cadastraAluno(&alunos[contAlunos], nomeDigitado, codDigitado);
                contAlunos++;
                break;
            case 2:
                printf("Digite o codigo da disciplina: ");
                __fpurge(stdin);
                scanf("%d", &codDigitado);
                printf("Digite o nome da disciplina a ser cadastrada: ");
                __fpurge(stdin);
                fgets(nomeDigitado, 50, stdin);
                cadastraDisciplina(&disciplinas[contDisciplinas], nomeDigitado, codDigitado);
                contDisciplinas++;
                break;
            
            case 10:
                imprimeAlunos(alunos);
                break;
        }
        
        
    }
    
    return 0;
}
