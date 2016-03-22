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
    scanf("%d", &ra);
    
    
    inicio->ra = ra;
    
    printf("Digite o nome do aluno: ");
    __fpurge(stdin);
    fgets(inicio->nome, 50, stdin);
    
    
    

}

int main(void)
{
    aluno *aux;
    
    aux = (aluno *)malloc(sizeof (aluno));
    
    cadastroAluno(aux);
    
    return 0;
}
