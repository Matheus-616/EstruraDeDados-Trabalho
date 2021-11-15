#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "pilha.h"
#include "Fila.h" 


typedef struct usuario{
    char nome[50];
    char apelido[30];
    struct  usuario *prox;
    
    Lista *parceiros; // Lista de parceiros
    Fila *pedidos; // Fila de pedidos
    Pilha *mensagens; // Pilha de mensagens 
} User;

typedef struct Lista_usuarios{
    User *inicio, *fim;
} Users;


User* Busca(Users *, char []);

int Busca_parceiros(Users *,char [], char []);


void Criar_usuarios(Users *);
//Users* Criar_usuarios(void);
// a) Cadastro de usuários                       :D
void Cadastro(Users *, char [], char [], int *);


// b) Lista usuários e informações               :D
void Imprime(Users *);


// c) Pedir para ser um parceiro                 :D
void Convidar(Users *, char [], char [], int *);


// d) Avaliar sua lista de pedidos               :D
void Avaliar_pedidos(Users *, char [], int *);


// e) Enviar mensagem para o parceiro             :D
void Enviar_mensagem(Users *, char [], char [], char [], int *);


// f) Ver mensagens recebidas                     :D
void Ver_mensagens(Users *, char []);


// g) Sugerir novas parcerias
void Sugestao_parceiros(Users *L);



// h) Reinicializar o sistema
void Libera(Users *);

