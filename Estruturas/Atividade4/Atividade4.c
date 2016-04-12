/*
 * Estrutura e Recuperação de Dados A
 * Atividade 4 (Lista Ligada)
 * 
 * Para compilar com o DEBUG ativado:
 * $ gcc -DDEBUG -g Atividade4.c -o Atividade4
 * 
 * Danilo Luís Lopes Raymundo Paixão
 * RA: 15051659
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct no No;
struct no {
    int chave;
    No *prox;
};
 
// Questao 1
void insereInicio (No **pLista, int n) {
    No *aux;
    aux = (No *)malloc(sizeof (No));
    aux->chave = n;
    aux->prox = *pLista;
    *pLista = aux;
}

// Questao 2
void insereFim (No **pLista, int n) {
    No *aux;
    aux=*pLista;
    if(aux->prox){
        
        while(aux->prox){
            aux=aux->prox;
        }
        
    }
    aux->prox = (No *)malloc(sizeof (No));
    aux->prox->chave = n;
}

// Questao 3
void insereK (No **pLista, int n, int k) {
    No *aux;
    aux = *pLista;
    
    while(k){
        aux=aux->prox;
        k--;
    }
    
    No *aux2;
    aux2 = (No *)malloc(sizeof (No));
    aux2->chave = aux->chave;
    aux2->prox = aux->prox;
    aux->prox = aux2;
    aux->chave = n;
}

// Questao 4
void exibePrimeiro (No *Lista) {
    if(Lista){
        printf("%d", Lista->chave);
    }
    
}

// Questao 5
void exibeUltimo (No *Lista){
    No *aux;
    aux=Lista;
    
    if(Lista){
        if(aux->prox){
            
            while(aux->prox){
                aux=aux->prox;
            }
            
        }
        
        printf("%d", aux->chave);
    }
    
}

// Questao 6
void exibeK (No *Lista, int k) {
    No *aux;
    aux = Lista;
    
    if(Lista){
        while(k){
            aux=aux->prox;
            k--;
        }
        printf("%d", aux->chave);
    }
}

// Questao 7
int procuraN (No *Lista, int n) {
    No *aux;
    aux=Lista;
    if(Lista){
        if(Lista->chave == n){
            return 1;
        }
        while(aux->prox){
            aux=aux->prox;
            if(aux->chave==n){
                return 1;
            }
        }
        return 0;
    }
    return 0;
}

// Questao 8
int quantidade (No *Lista) {
    int contador=0;
    No *aux;
    aux = Lista;
    if(Lista){
        contador=1;
        if(aux->prox){
            while(aux->prox){
                aux=aux->prox;
                contador++;
            }
            return contador;
        }
        return 1;
    }
    return 0;
}

// Questao 9
int soma (No *Lista) {
    int contador=0;
    No *aux;
    aux = Lista;
    if(Lista){
        contador=aux->chave;
        if(aux->prox){
            while(aux->prox){
                aux=aux->prox;
                contador=contador + aux->chave;
            }
            return contador;
        }
        return aux->chave;
    }
    return 0;
}

// Questao 10
float media (No *Lista) {
    int contador=0, soma;
    No *aux;
    aux = Lista;
    if(Lista){
        contador=1;
        soma=aux->chave;
        if(aux->prox){
            while(aux->prox){
                aux=aux->prox;
                contador++;
                soma = soma + aux->chave;
            }
            return (soma/contador);
        }
        return soma/contador; 
    }
    return 0;
}

// Questao 11
void excluiPrimeiro (No **pLista) {
    No *aux;
    aux = *pLista;
    aux=aux->prox;
    free(*pLista);
    *pLista = aux;
}

// Questao 12
void excluiUltimo (No **pLista) {
    No *aux, *aux2;
    aux = *pLista;
    
    if(aux){
        aux2=aux->prox;
        while(aux2->prox){
            aux=aux2;
            aux2=aux->prox;
            
        }
        aux->prox = NULL;
        free(aux2);
    }
    
}

// Questao 13
void excluiK (No **pLista, int k) {
    No *aux, *aux2;
    aux = *pLista;
    aux2=aux->prox;
    
    if(*pLista){
        if(k>0){
            
            while(k-1){
                aux=aux->prox;
                aux2=aux2->prox;
                k--;
            }
            aux->prox=aux2->prox;
            free(aux2);
        }
    }
    
}

// Questao 14
void excluiN (No **pLista, int n) {
    No *aux, *aux2;
    aux = *pLista;
    aux2=aux->prox;
    
    if(aux->chave == n){
        aux=aux->prox;
        free(*pLista);
        *pLista = aux;
    }
    while(aux2){
        if(aux2->chave == n){
            aux->prox=aux2->prox;
            free(aux2);
        }
        aux=aux->prox;
        aux2=aux->prox;
    }
}

// Cria uma lista vazia
void criaVazia (No **pLista) {
  *pLista = NULL;
}

// DEBUG: Exibe todos os elementos de uma Lista
void exibe (No *Lista) {
    while (Lista!=NULL) {
      printf("%d ",Lista->chave);
      Lista = Lista->prox;
    }
}

int main() {
    int opcao = -1, n, k;
    No *Lista;
    criaVazia(&Lista);
    while (opcao != 0) {
        do {
	    printf("\n");
            printf("(0) Finalizar o programa\n");
            printf("(1) Inserir elemento no inicio da lista (Q-1)\n");
            printf("(2) Inserir elemento no final da lista (Q-2)\n");
            printf("(3) Inserir elemento na k-esima posicao da lista (Q-3)\n");
            printf("(4) Exibir o primeiro elemento da lista (Q-4)\n");
            printf("(5) Exibir o ultimo elemento da lista (Q-5)\n");
            printf("(6) Exibir o k-esimo elemento da lista (Q-6)\n");
            printf("(7) Procurar um elemento da lista (Q-7)\n");
            printf("(8) Exibir a quantidade de elementos da lista (Q-8)\n");
            printf("(9) Exibir a soma dos valores da lista (Q-9)\n");
            printf("(10) Exibir a media dos valores da lista (Q-10)\n");
            printf("(11) Excluir o primeiro elemento da lista (Q-11)\n");
            printf("(12) Excluir o ultimo elemento da lista (Q-12)\n");
            printf("(13) Excluir o k-esimo elemento da lista (Q-13)\n");
            printf("(14) Excluir um elemento procurado da lista (Q-14)\n");
	    printf("Opcao: ");
            scanf("%d", &opcao);
	    printf("\n");
            if ((opcao<0) || (opcao>14))
                printf("Opcao invalida!\n");
        } while ((opcao<0) || (opcao>14));
        switch (opcao) {
	    case 0:
		printf("Finalizando o programa.\n");
                return 0;
            case 1:
                // Insere um elemento no inicio da lista
                printf("Q-1 Insere um elemento no inicio\n");
		printf("Chave: ");
                __fpurge(stdin);
                scanf("%d",&n);
                insereInicio(&Lista,n);
                break;
            case 2:
                // Insere um elemento no fim da lista
                printf("Q-2 Insere um elemento no fim\n");
                printf("Chave: ");
                __fpurge(stdin);
                scanf("%d",&n);
                insereFim(&Lista,n);
                break;
            case 3:
                // Insere um elemento na k-esima posicao da lista
                printf("Q-3 Insere um elemento na k-esima posicao\n");
                printf("Chave: ");
                __fpurge(stdin);
                scanf("%d",&n);
                printf("k: ");
                __fpurge(stdin);
                scanf("%d",&k);
                insereK(&Lista,n,k);
                break;
            case 4:
		// Exibe o primeiro elemento da lista
                printf("Q-4 Exibe o primeiro elemento\n");
                printf("Chave: ");
		exibePrimeiro(Lista);
		printf("\n");
                break;
            case 5:
		// Exibe o ultimo elemento da lista
                printf("Q-5 Exibe o ultimo elemento\n");
                printf("Chave: ");
                exibeUltimo(Lista);
		printf("\n");
                break;
	    case 6:
		// Exibe o k-esimo elemento da lista
                printf("Q-6 Exibe o k-esimo elemento\n");
		printf("k: ");
                __fpurge(stdin);
                scanf("%d",&k);
                printf("Chave: ");
                exibeK(Lista,k);
		printf("\n");
		break;
	    case 7:
		// Procura por um elemento da lista
                printf("Q-7 Procura por um elemento\n");
                printf("Chave: ");
                __fpurge(stdin);
                scanf("%d",&n);
		if (procuraN(Lista,n))
		  printf("Elemento %d encontrado.\n", n);
		else
		  printf("Elemento %d não encontrado.\n", n);
		break;
	    case 8:
		// Exibe a quantidade de elementos da lista
                printf("Q-8 Exibe a quantidade de elementos\n");
		printf("Quantidade de elementos: %d\n", quantidade(Lista));
		break;
	    case 9:
		// Exibe a soma dos elementos da lista
                printf("Q-9 Exibe a soma dos elementos\n");
		printf("Soma: %d\n", soma(Lista));
		break;
	    case 10:
		// Exibe a media dos elementos da lista
                printf("Q-10 Exibe a media dos elementos\n");
		printf("Media: %f\n", media(Lista));
		break;
	    case 11:
		// Exclui o primeiro elemento da lista
                printf("Q-11 Exclui o primeiro elemento\n");
		excluiPrimeiro(&Lista);
		break;
	    case 12:
		// Exclui o ultimo elemento da lista
                printf("Q-12 Exclui o ultimo elemento\n");
		excluiUltimo(&Lista);
		break;
	    case 13:
		// Exclui o k-esimo elemento da lista
                printf("Q-13 Exclui o k-esimo elemento\n");	      
		printf("k: ");
                __fpurge(stdin);
                scanf("%d",&k);
                excluiK(&Lista,k);
		break;
	    case 14:
		// Exclui um elemento procurado da lista
                printf("Q-14 Exclui um elemento procurado\n");	      
		printf("Chave: ");
                __fpurge(stdin);
                scanf("%d",&n);
                excluiN(&Lista,n);
		break;            
	    default:
                break;
        }
#ifdef DEBUG
	printf("\n[DEBUG] Lista: ");
	exibe(Lista);
	printf("\n");
#endif
    }
}