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

void imprimeAlunos(talu alunos[50]){
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

void imprimeDisciplinas(tdisc disciplinas[50]){
    int contador=0;
    
    while(contador<50){
        if(disciplinas[contador].cod==0){
            break;
        }
        printf("Codigo: %d\n", disciplinas[contador].cod);
        printf("Nome: %s\n", disciplinas[contador].nome);
        contador++;
    }
}

int procuraAluno(talu alunos[50], int ra) // Função procura se o ra inserido já existe, se sim, a função retorna 0, se não, retorna 1
{
    int i;
    for(i = 0; i < 50; i++)
    {
        if(alunos[i].ra == 0) return 1;
        if(alunos[i].ra == ra)
        {
            return 0;
        }
    }
    
    return 1;
}

void cadastro_aluno(talu alunos[50], int contador)
{
    int ra, verifica=0;
    char nome[50];
    do{
    
        printf("Digite o RA do aluno que quer cadastrar: ");
        __fpurge(stdin);
        //fflush(stdin);
        scanf("%d", &ra);
        
        verifica = procuraAluno(alunos, ra);
        
        if(verifica)
        {
            printf("Digite o nome do aluno a ser cadastrado: ");
            __fpurge(stdin);
            //fflush(stdin);
            fgets(nome, 50, stdin);
            
            alunos[contador].ra = ra;
            strcpy(alunos[contador].nome, nome);
            
            printf("Aluno cadastrado com sucesso.\n");
        }
        else
        {
            printf("O ra digitado já existe, por favor digite outro ra.\n");
        }
    
    }while(verifica == 0);
    
}

int procuraDisc(tdisc disciplinas[50], int cod)
{
    int i;
    for (i = 0; i < 50; i++) 
    {
        if(disciplinas[i].cod == 0) return 1;
        if(disciplinas[i].cod == cod) return 0;
    }
    return 1;
}

void cadastro_disc(tdisc disciplinas[50], int contador)
{
    int cod, verifica = 0;
    char nome[50];
    
    do{
        printf("Digite o codigo da disciplina que quer cadastrar: ");
        __fpurge(stdin);
        //fflush(stdin);
        scanf("%d", &cod);
        
        verifica = procuraDisc(disciplinas, cod);
        
        if(verifica)
        {
            printf("Digite o nome da disciplina a ser cadastrada: ");
            __fpurge(stdin);
            //fflush(stdin);
            fgets(nome, 50, stdin);
            
            disciplinas[contador].cod = cod;
            strcpy(disciplinas[contador].nome, nome);
            
            printf("Disciplina cadastrada com sucesso.\n");
        }
        else
        {
            printf("O codigo digitado ja existe, por favor digite outro codigo.\n");
        }
        
        
    }while(verifica==0);
    
    
    
}


int main()
{
    talu alunos[50];
    tdisc disciplinas[50];
    tprof professores[50];
    int opcao = 1;
    int contAlunos = 0, contDisc = 0;
    

    while(opcao)
    {
        printf("O que deseja fazer? \n");
        printf("1- Cadastro de alunos\n");
        printf("2- Cadstro de disciplinas\n");
        printf("3- Cadastro de professores\n");
        
        printf("0- Sair\n");
        scanf("%d", &opcao);
        
        switch(opcao)
        {
            case 1: cadastro_aluno(alunos, contAlunos);
            contAlunos++;
            break;
            case 2: cadastro_disc(disciplinas, contDisc);
            contDisc++;
            break;
            case 11: imprimeAlunos(alunos);
            imprimeDisciplinas(disciplinas);
            break;
            default: break;
        }
        
        
        
    }



    return 0;
}
