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
    int cod;
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

void cadastraProfessor(tprofessores *professor, char nomeProfessor[50], int cod){
    strcpy(professor->nome, nomeProfessor);
    professor->cod = cod;
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

void imprimeDisciplinas(tdisciplinas disciplinas[]){
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

void imprimeProfessores(tprofessores professores[]){
    int contador=0;
    
    while(contador<50){
        if(professores[contador].cod==0){
            break;
        }
        printf("Codigo: %d\n", professores[contador].cod);
        printf("Nome: %s\n", professores[contador].nome);
        contador++;
    }
}

void matriculaAlDiscTodos(taluno alunos[], tdisciplinas disciplinas[]){
    int cont=0,i=0;
    
    while(cont<50){
        if(alunos[cont].ra==0){ // Sai do loop quando encontra o último aluno cadastrado
            break;
        }
        while(i<50){
            if(disciplinas[i].cod==0){ // Sai do loop quando encontra a última disciplina cadastrada
                break;
            }
            alunos[cont].codDisciplinas[i] = disciplinas[i].cod;
            
            i++;
        }
        
        i=0;
        cont++;
    }
}

void imprimeAlDisc(taluno aluno, tdisciplinas disciplinas[]){
    int cont=0, i=0;
    
    while(cont <50){
        if(aluno.codDisciplinas[cont]==0){
            break;
        }
        while(i<50){
            if(disciplinas[i].cod == aluno.codDisciplinas[cont]){
                printf("Codigo da disciplina: %d\n", disciplinas[i].cod);
                printf("Nome da disciplina: %s\n", disciplinas[i].nome);
                break;
            }
            
            i++;
        }
        i=0;
        cont++;
    }
}

void imprimeDiscAl(taluno alunos[], int cod){
    int i=0, j=0;
    
    for(i=0;i<50;i++){
        if(alunos[i].ra==0) break;
        for (j = 0; j < 50; j++) {
            if(alunos[i].codDisciplinas[j]==cod){
                printf("RA do aluno: %d\n", alunos[i].ra);
                printf("Nome do aluno: %s\n", alunos[i].nome);
                break;
            }
        }
        
        
    }
    
}

void matriculaAlDisc(taluno alunos[], tdisciplinas disciplinas[]){
    int ra,cod, numAluno, numDisciplina, i=0;
    
    printf("Digite o ra do aluno a ser matriculado: ");
    __fpurge(stdin);
    // fflush(stdin);
    scanf("%d", &ra);
    printf("Digite o codigo da disciplina em que ele sera matriculado: ");
    __fpurge(stdin);
    // fflush(stdin);
    scanf("%d", &cod);
    
    numAluno = procuraAluno(alunos, ra);
    
    
    if( (numAluno>=0) ){
        while(i<50){
            if(alunos[numAluno].codDisciplinas[i]==0){
                alunos[numAluno].codDisciplinas[i] = cod;
                break;
            }
            
            i++;
        }
    }
    
    
}

int procuraDisciplina(tdisciplinas disciplinas[], int cod){
    int i=0;
    
    while(i<50){
        if(disciplinas[i].cod==0){
            break;
        }
        if(disciplinas[i].cod==cod){
            return i;
        }
        
        i++;
    }
    return -1;
}

int procuraAluno(taluno alunos[], int cod){
    int i=0;
    
    while(i<50){
        if(alunos[i].ra==0){
            break;
        }
        if(alunos[i].ra==cod){
            return i;
        }
        
        i++;
    }
    return -1;
}

void vincProfDisc(tdisciplinas disciplinas[], tprofessores professores[]){
    int cont=0,i=0;
    
    while(cont<50){
        if(professores[cont].cod==0){ // Sai do loop quando encontra o último professor cadastrado
            break;
        }
        while(i<50){
            if(disciplinas[i].cod==0){ // Sai do loop quando encontra a última disciplina cadastrada
                break;
            }
            professores[cont].codDisciplinas[i] = disciplinas[i].cod;
            
            i++;
        }
        
        i=0;
        cont++;
    }
}

void remAlDisc(taluno alunos[]){
    int i=0, j=0;
    
    for (i = 0; i < 50; i++) {
        for(j=0; j<50; j++){
            alunos[i].codDisciplinas[j]=0;
        }
    }
}

void remProfDisc(tprofessores professores[]){
    int i=0, j=0;
    
    for (i = 0; i < 50; i++) {
        for(j=0; j<50; j++){
            professores[i].codDisciplinas[j]=0;
        }
    }
}

int main(void){
    int opcao=1;
    taluno alunos[50];
    tdisciplinas disciplinas[50];
    tprofessores professores[50];
    char nomeDigitado[50];
    int  codDigitado;
    int contAlunos=0, contDisciplinas=0, contProfessor=0;
    
    while(opcao != 0){
        do {
	    printf("\n");
            printf("(0) Finalizar o programa\n");
            printf("(1) Cadastrar alunos\n");
            printf("(2) Cadastrar disciplinas\n");
            printf("(3) Cadastrar professores\n");
            printf("(4) Realizar a matricula dos alunos cadastrados em disciplinas\n");
            printf("(5) Imprimir a lista de disciplinas de um aluno\n");
            printf("(6) Imprimir a lista de alunos em uma disciplina\n");
            printf("(7) Matricular todos os alunos em todas as disciplinas\n");
            printf("(8) Vincular lista de professores a uma lista de disciplinas\n");
            printf("(9) Cancelar a matricula de todos os alunos em todas as disciplinas\n");
            printf("(10) Remover o vinculo de cada um dos professores a todas as disciplinas\n");
	    printf("Opcao: ");
            scanf("%d", &opcao);
	    printf("\n");
            if ((opcao<0) || (opcao>10))
                printf("Opcao invalida!\n");
        } while ((opcao<0) || (opcao>10));
        switch (opcao){
            case 0: // Finaliza o programa caso seja escolhida a opção 0
                printf("Finalizando o programa.\n");
                return 0;
            case 1: // Cadastra um aluno através de uma função
                printf("Digite o ra do aluno a ser cadastrado: ");
                __fpurge(stdin);
                // fflush(stdin);
                scanf("%d", &codDigitado);
                printf("Digite o nome do aluno a ser cadastrado: ");
                __fpurge(stdin);
                // fflush(stdin);
                fgets(nomeDigitado, 50, stdin);
                cadastraAluno(&alunos[contAlunos], nomeDigitado, codDigitado);
                contAlunos++;
                break;
            case 2: // Cadastra uma disciplina através de uma função
                printf("Digite o codigo da disciplina: ");
                __fpurge(stdin);
                // fflush(stdin);
                scanf("%d", &codDigitado);
                printf("Digite o nome da disciplina a ser cadastrada: ");
                __fpurge(stdin);
                // fflush(stdin);
                fgets(nomeDigitado, 50, stdin);
                cadastraDisciplina(&disciplinas[contDisciplinas], nomeDigitado, codDigitado);
                contDisciplinas++;
                break;
            case 3: // Cadastra um professor através de uma função
                printf("Digite o codigo do professor: ");
                __fpurge(stdin);
                // fflush(stdin);
                scanf("%d", &codDigitado);
                printf("Digite o nome do professor a ser cadastrado: ");
                __fpurge(stdin);
                // fflush(stdin);
                fgets(nomeDigitado, 50, stdin);
                cadastraProfessor(&disciplinas[contProfessor], nomeDigitado, codDigitado);
                contProfessor++;
                break;
            case 4:
                matriculaAlDisc(alunos, disciplinas);
                break;
            case 5:
                printf("Digite o ra do aluno: ");
                __fpurge(stdin);
                // fflush(stdin);
                scanf("%d", &codDigitado);
                codDigitado = procuraAluno(alunos, codDigitado);
                if(codDigitado>=0){
                    imprimeAlDisc(alunos[codDigitado], disciplinas);
                }
                break;
            case 6:
                printf("Digite o codigo da disciplina: ");
                __fpurge(stdin);
                // fflush(stdin);
                scanf("%d", &codDigitado);
                imprimeDiscAl(alunos, codDigitado);
                break;
            case 7:
                matriculaAlDiscTodos(alunos, disciplinas);
                break;
            case 8:
                vincProfDisc(disciplinas, professores);
                break;
            case 9:
                remAlDisc(alunos);
                break;
            case 10:
                remProfDisc(professores);
                break;
            /*
            case 11:    // Imprime as listas de alunos, professores e disciplinas para debug
                imprimeAlunos(alunos);
                imprimeDisciplinas(disciplinas);
                imprimeProfessores(professores);
                break; */
        }
        
        
    }
    
    return 0;
}
