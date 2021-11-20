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


//Busca em Users um usuário identificado pelo apelido 
User* Busca(Users *, char []); 

//Veririca se um usuário está na lista de parceiro do outro
int Busca_parceiros(Users *,char [], char []);


void Criar_Users(Users *);

// a) Cadastro de usuários                       
void Cadastro(Users *, char [], char [], int *);


// b) Lista usuários e informações               
void Imprime(Users *);


// c) Pedir para ser um parceiro                 
void Convidar(Users *, char [], char [], int *);


// d) Avaliar sua lista de pedidos               
void Avaliar_pedidos(Users *, char [], int *);


// e) Enviar mensagem para o parceiro         Falta: Ler mensagens com espaço    
void Enviar_mensagem(Users *, char [], char [], char [], int *);


// f) Ver mensagens recebidas                     
void Ver_mensagens(Users *, char [], int *);


// g) Sugerir novas parcerias                       :D
void Sugestao_parceiros(Users *L, int *);



// h) Reinicializar o sistema
void Libera(Users *);

