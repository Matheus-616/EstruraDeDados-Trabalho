#include "Fila.h"
#include <string.h>
//novo
void Cria_F(Fila *L){
    //Fila *Laux = (Fila*) malloc(sizeof(Fila));
    //if (Laux==NULL) return(NULL);
    //else{
    L->init=NULL;
    L->fim=NULL;
    //}
}

void Entra(Fila *L, elem x[], int *erro){
    no_F *p;
    p = (no_F*) malloc(sizeof(no_F));
    if (p==NULL) *erro = 1;
    else{
        *erro = 0;
        strcpy(p->info, x);
        //p->info = x;
        p->prox = NULL;
        if (L->init==NULL) L->init=p;
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
    //L->fim=NULL; Apagando tudo
    //free(L);
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
    else *erro=1;
    return;
}
