#include "Fila.h"
#include <string.h>
//novo
void Cria_F(Fila *L){
    L->init=NULL;
    L->fim=NULL;
}

void Entra(Fila *L, elem x[], int *erro){
    no_F *p;
    p = (no_F*) malloc(sizeof(no_F));
    if (p==NULL) *erro = 1; // Erro ao criar espaço na memória
    else{
        *erro = 0;
        strcpy(p->info, x);
        p->prox = NULL;
        if (L->init==NULL) L->init=p; //Se fila vazia, init aponta para o adicionado (primeiro)
        else L->fim->prox=p;
        L->fim=p;
    }
}

void Finaliza_F(Fila *L){
    no_F *p;
    p = L->init;
    while(p!=NULL){
        L->init=p->prox;
        free(p);
        p = L->init;
    }
    return;
}



void Sai(Fila *L, elem x[], int *erro){
    no_F *p=L->init;
    if (p!=NULL){
        *erro=0;
        strcpy(x,p->info);
        L->init=p->prox;
        free(p);
    }
    else *erro=1; //Erro caso a fila esteja vazia
    return;
}

int Busca_F(Fila *F, elem x[]){
    no_F *p=F->init;
    while (p!=NULL && strcmp(p->info,x)){
        p = p->prox;
    }
    if (p==NULL) return(0); // Retorna 0 se chegou no final e não entrou
    else return(1);
}