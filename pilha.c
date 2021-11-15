#include "pilha.h"
#include <string.h>
//novo
void Cria_P(Pilha *L){
    //Pilha *Laux = (Pilha*) malloc(sizeof(Pilha));
    //if (Laux==NULL) return(NULL);
    //else{
    L->init=NULL;
    //}
}

void Push(Pilha *L, elem x[140], int *erro){
    no_P *p;
    p = (no_P*) malloc(sizeof(no_P));
    if (p==NULL) *erro = 1;
    else{
        *erro = 0;
        strcpy(p->info, x); // atribui x a info.
        //p->info = x;
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
    //free(L);
    return;
}



void Pop(Pilha *L, elem x[], int *erro){
    no_P *p=L->init;
    if (p!=NULL){
        *erro=0;
        strcpy(x,p->info);
        L->init=p->prox;
        free(p);
    }
    else *erro=1;
    return;
}
