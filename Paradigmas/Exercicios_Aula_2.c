#include <stdlib.h>
#include <stdio.h>

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

typedef struct
{
    int ra;
    char nome[50];
} talunos;
typedef struct{
    int codigo;
    char nome[50];
}tdisciplinas;



void cadastro_Alunos(talunos aluno)
{
    printf("Digite o ra do aluno: ");
    scanf("%d", &aluno.ra);
    
    printf("Digite o nome do aluno: ");
    __fpurge(stdin);
    fgets(aluno.nome, 50, stdin);
    
    
    
}

void cadastro_Disciplinas(tdisciplinas disciplina){
    printf("Digite o codigo da disciplina: ");
    scanf("%d", &disciplina.codigo);
    
    printf("Digite o nome da disciplina: ");
    __fpurge(stdin);
    fgets(disciplina.nome, 50, stdin);
    
    
    
}


int main(void)
{
    talunos aluno[50];
    tdisciplinas disciplina[50];
    
    int i, verifica=1;
    
    
    for(i=0;i<50;i++){
        cadastro_Alunos(aluno[i]);
        printf("Deseja cadastrar mais um aluno? 1-sim, 0-nao ");
        scanf("%d", &verifica);
        if(verifica==0){
            i=50;
        }
        
        
    }
    
    
    for(i=0;i<50;i++){
        cadastro_Disciplinas(disciplina[i]);
        printf("Deseja cadastrar mais uma disciplina? 1-sim, 0-nao ");
        scanf("%d", &verifica);
        if(verifica==0){
            i=50;
        }
        
        
    }
    
    
    
    
    
    return 0;
}