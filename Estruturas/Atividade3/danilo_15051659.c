#include <stdio.h>
#include <stdlib.h>

typedef struct taluno aluno;
struct taluno{
    int ra;
    char nome[50];
    struct taluno *prox;
};

// para remover guardar o anterior

void cadastroAluno(aluno *inicio)
{
    int ra;
    
    printf("Digite o ra do aluno a ser cadastrado: ");
    scanf("%d", &ra);
    
    inicio->ra = ra;
    
    printf("Digite o nome do aluno: ");
    __fpurge(stdin);
    fgets(inicio->nome, 50, stdin);
    
    inicio->prox=NULL;
}

void procuraCadastroAluno(aluno *inicio) // Função procura o último elemento da lista alunos
{
    aluno *aux;
    aux=inicio->prox;
    if(aux)
    {
        while(aux)
        {
            aux = aux->prox;
        }
        
    }
    aux->prox = (aluno *)malloc(sizeof (aluno));
    
    cadastroAluno(aux->prox);
}

int main(void)
{
    aluno *aux;
    
    aux = (aluno *)malloc(sizeof (aluno));
    
    cadastroAluno(aux);
    
    
    
    
    return 0;
}
