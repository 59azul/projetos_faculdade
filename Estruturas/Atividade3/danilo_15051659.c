#include <stdio.h>
#include <stdlib.h>

typedef struct taluno aluno;
struct taluno{
    int ra;
    char nome[50];
    struct taluno *prox;
};

// para remover guardar o anterior

int tamanhoLista(aluno *inicio)
{
    if(inicio->prox)
    {
        return tamanhoLista(inicio->prox)+1;
    }
    return 0;
}

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

void ordenarLista(aluno *inicio)
{
    aluno *aux;
    aluno *aux2;
    aux = inicio->prox;
    aux2= aux->prox;
    
    if(aux)
    {
        if(aux2)
        {
            while(aux2->prox)
            {
    
                if(aux->ra > aux2->ra)
                {
                    aux2->ra = aux->ra + aux2->ra;
                    aux->ra = aux2->ra - aux->ra;
                    aux2->ra = aux2->ra - aux->ra;
                }
                aux->prox= aux2->prox;
                aux2->prox = aux2->prox->prox;
                
                
            }
        }
    }
    
}

void procuraCadastroAluno(aluno *inicio) // Função procura o último elemento da lista alunos
{
    aluno *aux, *aux2;
    
    if(!inicio->prox)
    {
        inicio->prox = (aluno *)malloc(sizeof (aluno));
    }
    aux = inicio->prox;
    
    while(aux)
    {
        aux2 = aux;
        aux = aux->prox;
        
    }
    aux2->prox = (aluno *)malloc(sizeof (aluno));
    
    cadastroAluno(aux2->prox);
}

int main(void)
{
    aluno *inicio;
    int escolha = 0;
    
    printf("Deseja cadastrar um aluno? 1-sim, 0-nao");
    scanf("%d", &escolha);
    
    if(escolha)
    {
        inicio = (aluno *)malloc(sizeof (aluno));
        cadastroAluno(inicio);
        
        printf("Deseja cadastar mais um aluno?");
        scanf("%d", &escolha);
        
    }
    
    while(escolha)
    {
        procuraCadastroAluno(inicio);
        
        printf("Deseja cadastrar um aluno? 1-sim, 0-nao");
        scanf("%d", &escolha);
        
        ordenarLista(inicio);
        
    }
    
    
    return 0;
}
