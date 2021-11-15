#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char elem;

typedef struct bloco{
    struct bloco *prox;
    elem info[];
} no;

typedef struct lista{
    no *init, *fim;
} Lista;

void Cria(Lista *L);
void Insere(Lista *, elem *, int *);
void Finaliza(Lista *);
int Busca_L(Lista *, elem *);
int Tamanho_L(Lista *);
void Elemina_elemento(Lista *, elem *, int *);
//void Imprime(Lista *);
int Soma(Lista *, int *);
elem Busca_posicao(Lista *,int , int *);
void Inverte(Lista *);
