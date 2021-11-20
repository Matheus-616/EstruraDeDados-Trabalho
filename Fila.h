#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char elem;

typedef struct block{ 
    struct block *prox;
    elem info[30];
} no_F;

typedef struct Fila{
    no_F *init, *fim;
} Fila;

void Cria_F(Fila *L);
void Entra(Fila *, elem *, int *);
void Finaliza_F(Fila *);
void Sai(Fila *, elem *, int *);
int Busca_F(Fila *, elem *);