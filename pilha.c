#include "pilha.h"
#include <string.h>
void Cria_P(Pilha *L){
    L->init=NULL;
}

void Push(Pilha *L, elem x[140], int *erro){
    no_P *p;
    p = (no_P*) malloc(sizeof(no_P));
    if (p==NULL) *erro = 1; // Erro ao criar espaço na memória
    else{
        *erro = 0;
        strcpy(p->info, x); 
        p->prox = L->init;
        L->init=p;
    }
}


void Finaliza_P(Pilha *L){
    no_P *p;
    p = L->init;
    while(p!=NULL){
        L->init=p->prox;
        free(p);
        p = L->init;
    }
    return;
}



void Pop(Pilha *L, elem x[], int *erro){
    no_P *p=L->init;
    if (p==NULL) *erro=1; //Erro se pilha vazia
    else {
        *erro=0;
        strcpy(x,p->info);
        L->init=p->prox;
        free(p);
    }
    return;
}
