#include <stdio.h>
#include <stdlib.h>

typedef struct taluno aluno;
struct taluno{
    int ra;
    char nome[50];
    struct taluno *prox;
};

void cadastroAluno(aluno *inicio)
{
    char nome[50];
    int ra;
    
    printf("Digite o ra do aluno a ser cadastrado: ");

}

int main(void)
{
    aluno aux;

    return 0;
}
