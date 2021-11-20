#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char elem;

typedef struct Piece{ 
    struct Piece *prox;
    elem info[140];
} no_P;

typedef struct Pilha{
    no_P *init;
} Pilha;

void Cria_P(Pilha *L);
void Push(Pilha *, elem *, int *);
void Finaliza_P(Pilha *);
void Pop(Pilha *, elem *, int *);

