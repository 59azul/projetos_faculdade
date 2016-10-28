
enum Balance {E,C,D};

struct no {
        int chave;
        Balance bal;
        struct no *esq, *dir;
         };

int h=0; // A �rvore n�o mudou de altura. h deve valer 0 antes de cada inserção.


/* INSERCAO DE ELEMENTOS NA ARVORE BINARIA BALANCEADA */
void insere(no **raiz, int n, int *h)
{
     struct no *p1, *p2;

        if (*raiz == NULL) {
                   *raiz = (struct no *) malloc(sizeof(struct no));
                   *h=1;
                   (*raiz) -> chave = n;
                   (*raiz) -> esq = (*raiz) -> dir = NULL;
                   (*raiz) -> bal=C;
                   }
                   else
                   if (n < (*raiz)->chave) {
                      insere (&(*raiz)->esq,n,h);
                      if (*h) {
                             switch ((*raiz)->bal){
                                    case D:
                                         (*raiz)->bal = C;
                                         *h=0;
                                         break;
                                    case C:
                                         (*raiz)->bal = E;
                                         break;
                                    case E:
                                         p1= (*raiz) -> esq;
                                         if (p1->bal == E) { // rebalanceamento simples
                                            (*raiz) -> esq = p1->dir;
                                            p1->dir = (*raiz);
                                            (*raiz)->bal= C;
                                            (*raiz) = p1;
                                            }
                                         else { //rebalanceamento duplo
                                              p2 = p1->dir;
                                              p1->dir = p2->esq;
                                              p2->esq = p1;
                                              (*raiz)->esq=p2->dir;
                                              p2->dir=(*raiz);
                                              if (p2->bal==E) (*raiz)->bal = D;
                                                 else (*raiz)->bal = C;
                                              if (p2->bal==D) p1->bal = E;
                                                 else p1->bal = C;
                                              (*raiz) = p2;
                                              }
                                         (*raiz)->bal = C;
                                         *h=0;
                                         break;
                                    }
                      }
                      }
                      else
                       if (n > (*raiz)->chave) {
                        insere (&(*raiz)->dir,n,h);
                        if (*h) {
                             switch ((*raiz)->bal){
                                    case E:
                                         (*raiz)->bal = C;
                                         *h=0;
                                         break;
                                    case C:
                                         (*raiz)->bal = D;
                                         break;
                                    case D:
                                         p1= (*raiz) -> dir;
                                         if (p1->bal == D) { // rebalanceamento simples
                                            (*raiz) -> dir = p1->esq;
                                            p1->esq = (*raiz);
                                            (*raiz)->bal= C;
                                            (*raiz) = p1;
                                            }
                                         else { //rebalanceamento duplo
                                              p2 = p1->esq;
                                              p1->esq = p2->dir;
                                              p2->dir = p1;
                                              (*raiz)->dir=p2->esq;
                                              p2->esq=(*raiz);
                                              if (p2->bal==D) (*raiz)->bal = E;
                                                 else (*raiz)->bal = C;
                                              if (p2->bal==E) p1->bal = D;
                                                 else p1->bal = C;
                                              (*raiz) = p2;
                                              }
                                         (*raiz)->bal = C;
                                          *h=0;
                                         break;
                                    }
                      }
                      }
}
