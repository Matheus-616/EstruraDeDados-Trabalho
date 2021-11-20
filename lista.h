#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char elem;

// A Lista possui dois ponteiro que apontam para seus nós
// Ela é formada encadeando de maneira dinâmica os nós

typedef struct bloco{
    struct bloco *prox;
    elem info[30];
} no;

typedef struct lista{
    no *init, *fim;
} Lista;

void Cria_L(Lista *L);
void Insere(Lista *, elem *, int *);
void Finaliza_L(Lista *);
int Busca_L(Lista *, elem *);
int Tamanho_L(Lista *);
void Elemina_elemento(Lista *, elem *, int *);
void Imprime_L(Lista *);
int Soma(Lista *, int *);
elem Busca_posicao(Lista *,int , int *);
void Inverte(Lista *);
