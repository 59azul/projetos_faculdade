  # ifndef MATRIZ_H_
  # define MATRIZ_H_
  
  
// Augusto Scarelli Silva 				RA: 15049711
// Daniel Augusto Silveira Ramos 		RA: 15589500
// Danilo Luís Lopes Raymundo Paixão	RA: 15051659
// Júlio Ferro Neto						RA: 15265135

 /* TAD : Ponto (x,y) */

 /* Tipo exportado */
 typedef struct lista_matriz Matriz;
 
void criaVazia(Matriz **pLista);

void criaMatriz(Matriz **pLista, char nome[], int linhas, int colunas);

void destroiMatriz(Matriz **pLista, char nome[]);

void imprimeMatriz(Matriz *matriz, char nome[]);

void atribuirElemento(Matriz **pLista, char nome[], int linhas, int colunas, float valor);

void atribuirLinha(Matriz **pLista, char nome[], int linha);
 
void atribuirColuna(Matriz **pLista, char nome[], int coluna);

void transporMatriz(Matriz **pLista, char nome[]);

void somarMatriz(Matriz *pLista, char nome[], char nome2[], char nome3[]);

void dividirMatriz(Matriz *pLista, char nome[], char nome2[], char nome3[]);

void multiplicarMatriz(Matriz *pLista, char nome[], char nome2[], char nome3[]);

void multiplicarElementosMatriz(Matriz *pLista, char nome[], char nome2[], char nome3[]);

 # endif /* MATRIZ_H_ */