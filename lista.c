#include "lista.h"

void Cria(Lista *L){
    //Lista *Laux = (Lista*) malloc(sizeof(Lista));
    //if (Laux==NULL) return(NULL);
    //else{
    L->init=NULL;
    L->fim=NULL;
    //}
}

void Insere(Lista *L, elem x[], int *erro){
    no *p;
    p = (no*) malloc(sizeof(no));
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

void Finaliza(Lista *L){
    no *p;
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

int Busca_L(Lista *L, elem x[]){
    int encontrou=0;
    no *p=L->init;
    while (p!=NULL && strcmp(p->info,x)){
        p = p->prox;
    }
    if (p==NULL) return(0);
    else return(1);
}


int Tamanho_L(Lista *L){
    no *p=L->init;
    int contador=0;
    while (p!=NULL) {
        ++contador;
        p=p->prox;
    }
    return(contador);   
}





void Elemina_elemento(Lista *L, elem x[], int *erro){
    no *p=L->init;
    no *anterior;
    while (p!=NULL && p->info!=x) {
        anterior=p;
        p = p->prox;
    }
    if (p==NULL) *erro=1;
    else {
        *erro = 0;
        if (p==L->init){
            L->init = L->init->prox;
        }

        else if(p==L->fim){
            L->fim = anterior;
            anterior->prox = NULL;

        }

        else {
            anterior->prox=p->prox;
        }
        free(p);

    }
    return;
}

void Aux_imprime(no *p){ 
    if (p!=NULL) {
        printf("%s, ", p->info);
        Aux_imprime(p->prox);
    }
    return;
}

/*void Imprime(Lista *L){
    Aux_imprime(L->init);
    printf("\n");
    return;
}*/


void Inverte(Lista *L){
    if (L->init==L->fim){
        return;
    }
    no *aux1, *aux2;
    L->fim=L->init;
    aux1=L->init; //Coloca aux1 no primeiro
    aux2=L->init->prox->prox; // Coloca o aux2 no terceiro
    L->init=aux1->prox;//Coloca o init no segundo
    aux1->prox = NULL;
    while(aux2!=NULL){
        L->init->prox=aux1;
        aux1=L->init;
        L->init=aux2;
        aux2=aux2->prox;
    }
    L->init->prox=aux1;

    return;
}