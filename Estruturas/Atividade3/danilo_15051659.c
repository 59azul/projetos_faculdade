#include <stdio.h>
#include <stdlib.h>

typedef struct taluno aluno;
struct taluno{
    int ra;
    char nome[50];
    struct taluno *prox;
};

// para remover guardar o anterior

int tamanhoLista(aluno *inicio) // Função que mede o tamanho da lista
{
    if(inicio->prox)
    {
        return tamanhoLista(inicio->prox)+1;
    }
    return 0;
}

void cadastroAluno(aluno *no) // Função que cadastra o aluno no final da lista
{
    int ra;
    
    printf("Digite o ra do aluno a ser cadastrado: ");
    scanf("%d", &ra);
    
    no->ra = ra;
    
    printf("Digite o nome do aluno: ");
    __fpurge(stdin);
    fgets(no->nome, 50, stdin);
    
    no->prox=NULL; // 
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

void removerCadastro(aluno *inicio, int num)
{
    aluno *aux, *aux2;
    aux = inicio->prox;
    aux2 = aux->prox;
    
    while(aux2->ra != num && aux2)
    {
        aux=aux2;
        aux2=aux->prox;
    }
    
    aux->prox = aux2->prox;
    
    void free(void *aux2);
    
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
    
    ordenarLista(inicio);
}

void buscaRA(aluno *inicio, int ra)
{
    
}

void exibirLista(aluno *inicio)
{
    aluno *aux;
    aux=inicio;
    
    while(aux->prox)
    {
        printf("%d", aux->ra);
        printf("%s\n", aux->nome);
        aux = aux->prox;
    }
    
    
    
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
        
        //ordenarLista(inicio);
        
    }
    
    exibirLista(inicio);
    
    
    
    return 0;
}
