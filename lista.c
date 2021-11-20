#include "lista.h"

void Cria_L(Lista *L){
    L->init=NULL;
    L->fim=NULL;
}

void Insere(Lista *L, elem x[], int *erro){
    no *p;
    p = (no*) malloc(sizeof(no));
    if (p==NULL) *erro = 1; // Erro ao criar espaço na memória
    else{
        *erro = 0;
        strcpy(p->info, x);
        p->prox = NULL;

        if (L->init==NULL) L->init=p; //Se lista vazia, init aponta para o adicionado (primeiro)
        else L->fim->prox=p;
        L->fim=p;
    }

}

void Finaliza_L(Lista *L){
    no *p;
    p = L->init;

    //Percorre todos os nós e da free neles
    while(p!=NULL){
        L->init=p->prox;
        free(p);
        p = L->init;
    }
    return;
}

int Busca_L(Lista *L, elem x[]){
    no *p=L->init;
    while (p!=NULL && strcmp(p->info,x)){
        p = p->prox;
    }
    if (p==NULL) return(0); // Retorna 0 se chegou no final e não entrou
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
    if (p==NULL) *erro=1; // erro = 1 se o elemento não foi encontrad
    else {

        //Avalisa os 3 casos possíveis de posição do elemento
        *erro = 0;

        //1) Elemento está no início
        if (p==L->init){
            L->init = L->init->prox;
        }


        //2) Elemento está no fim 
        else if(p==L->fim){
            L->fim = anterior;
            anterior->prox = NULL;

        }

        //3) Elemento está no meio
        else {
            anterior->prox=p->prox;
        }
        free(p);

    }
    return;
}

//Função recursiva para imprimir
void Aux_imprime(no *p){ 
    if (p!=NULL) {
        printf("%s, ", p->info);
        Aux_imprime(p->prox);
    }
    return;
}

//Função de imprimir recursivamente
//O usuário passa a lista e ela chama a função recursiva Aux_imprime
void Imprime_L(Lista *L){
    Aux_imprime(L->init);
    printf("\n");
    return;
}


void Inverte(Lista *L){
    if (L->init!=L->fim){ // Verifica se a lista não está vazia
        no *aux1, *aux2;
        L->fim=L->init; 

        //Bloco para ir invertendo a ordem elemento à elemento
        aux1=L->init; //Coloca aux1 no primeiro
        aux2=L->init->prox->prox; // Coloca o aux2 no terceiro
        L->init=aux1->prox;//Coloca o init no segundo
        aux1->prox = NULL;
        while(aux2!=NULL){ //Se aux2 chegar em NULL voltamos ao final (novo começo) da lista
            L->init->prox=aux1;
            aux1=L->init;
            L->init=aux2;
            aux2=aux2->prox;
        }
        L->init->prox=aux1;
    }
    return;
}