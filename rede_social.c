#include "rede_social.h"
#include <string.h>

void Criar_Users(Users *L){
    L->inicio=NULL;
    L->fim=NULL;
}

User* Busca(Users *L, char apelido[30]){
    User *aux=L->inicio;
    while(aux!=NULL && strcmp(aux->apelido, apelido)){
        aux=aux->prox;
    }
    return(aux);
}


int Busca_parceiros(Users *L, char eu[30], char possivel_parceiro[30]){
    User *eumesmo=Busca(L,eu);
    if (eumesmo==NULL) return(2); // Apelido não cadastrados 
    else{
        return(Busca_L(eumesmo->parceiros, possivel_parceiro));
    }
}


void Cadastro(Users *L, char nome[50], char apelido[30], int *erro){
    User *aux = (User*) malloc(sizeof(User));
    aux->parceiros=(Lista*) malloc(sizeof(Lista));
    aux->pedidos=(Fila*) malloc(sizeof(Fila));
    aux->mensagens=(Pilha*) malloc(sizeof(Pilha));
    if (aux==NULL || aux->parceiros==NULL || aux->pedidos==NULL || aux->mensagens==NULL){
        *erro=1; // Erro ao criar espaço na memória
    }
    else if (Busca(L, apelido)!=NULL) {
        *erro=2; // Erro pessoa já cadastrada
    } 
    else {
        *erro=0;
    
        //Caso lista vazia, inicio também aponta para o novo usuário
        if (L->inicio==NULL) L->inicio=aux;
        else L->fim->prox=aux;
        //Faz o "antigo último" e o fim apontar para o novo.
        L->fim=aux;
        L->fim->prox=NULL;
    
        strcpy(L->fim->nome, nome);
        strcpy(L->fim->apelido,apelido);
        
        //Inicializando a lista de parceiros, a fila de pedidos e a pilha de mensagens.
        Cria(L->fim->parceiros);
        Cria_F(L->fim->pedidos);
        Cria_P(L->fim->mensagens);
    }
    return;
}



void Imprime(Users *L){
    printf("\t Usuários, seus apelidos e seus parceiros de trabalho: \n");
    User *aux_user=L->inicio;
    no *aux_no;

    //Percorre os usuários e printa seus apelidos e parceiros
    while(aux_user!=NULL) {
        printf("\t %s, %s: ", aux_user->nome, aux_user->apelido);
        aux_no=aux_user->parceiros->init;

        //Percorre os parceiros
        while(aux_no!=NULL){
            printf("%s, ",aux_no->info);
            aux_no=aux_no->prox;
        }

        printf("\n");
        aux_user=aux_user->prox;
    }
}


void Convidar(Users *L, char meu_apelido[30], char apelido_convidado[30], int *erro){
    User *convidado=Busca(L,apelido_convidado); 

    //Confere se o convidado está cadastrado
    if (convidado==NULL){
        *erro=2; // Erro: Um dos apelido não cadastrados 
    }
    else { 

        //Quem recebe não cadastrado erro=2
        //Quem envia não cadastrado erro=2;
        //Parceria já existente erro=3;

        //Confere 
        *erro=Busca_parceiros(L, meu_apelido, apelido_convidado);
        if (*erro==0)
            Entra(convidado->pedidos, meu_apelido, erro);
        else if(*erro==1) *erro=3; // Erro de parceria já existente
    }
}


void Avaliar_pedidos(Users *L, char meu_apelido[30], int *erro){
    User *eu=Busca(L, meu_apelido);
    if (eu!=NULL){
        *erro=0;
        char apelido[30], sim[4];

        //Variável para verificar se está pilha já está vaiza
        //Erro se fila vazia usado para verificar
        int EstaVazia=0;
        Sai(eu->pedidos, apelido, &EstaVazia);
        while (!EstaVazia){
            printf("\t %s deseja ser parceire. Aceitas (sim/não)? ", apelido);
            scanf("%s", sim);
            if (!strcmp(sim,"sim")) {
                //Insere uma na lista de amizade do outro
                Insere(eu->parceiros, apelido, erro);
                Insere(Busca(L,apelido)->parceiros, eu->apelido, erro);
            }
            if (*erro==1) return; //Retorna se acaba espaço de memória
            Sai(eu->pedidos, apelido, &EstaVazia);
        }
    }
    else *erro=2;
}



void Enviar_mensagem(Users *L, char mensagem[140], char remetente[30], char destinatario[30], int *erro){
    User *dest=Busca(L,destinatario);
    int aux; // variável para analisar se são parceiros
    aux = Busca_parceiros(L, remetente, destinatario);
    if (dest!=NULL && aux!=2){
        if (aux==1){ //Verifica se são parceiros
            Push(dest->mensagens, mensagem, erro);
            Push(dest->mensagens, remetente, erro);
            *erro=0;
        }
        else if (aux==0) *erro=3; //Não são parceiros
    }
    
    else *erro=2; // Erro de usuário não cadastrado
    

}



void Ver_mensagens(Users *L, char meu_apelido[30], int *erro){
    User *eu=Busca(L,meu_apelido);

    if (eu!=NULL){
        *erro=0;

        printf("Suas mensagens são: \n");
        //Variável para verificar se está pilha já está vaiza
        //Erro de pilha vazia usado para verificar
        int EstaVazia=0; 
        char mensagem[140], apelido[30];
        Pop(eu->mensagens, apelido, &EstaVazia);
        Pop(eu->mensagens, mensagem, &EstaVazia);
    
        while(!EstaVazia){
            printf("\n (%s): %s \n", apelido, mensagem);
            Pop(eu->mensagens, apelido, &EstaVazia);
            Pop(eu->mensagens, mensagem, &EstaVazia);
        }
    }
    else *erro=2;
}




void Sugestao_parceiros(Users *L){

}




void Libera(Users *L){
    User *aux1_user=L->inicio, *aux2_user;

    while(aux1_user!=NULL) {
        //Finaliza as listas, filhas e pilhas de cada usuário
        Finaliza_L(aux1_user->parceiros); 
        Finaliza_F(aux1_user->pedidos);
        Finaliza_P(aux1_user->mensagens);
        free(aux1_user->parceiros);
        free(aux1_user->pedidos);
        free(aux1_user->mensagens);

        //Finaliza o User e passa para o próximo
        aux2_user=aux1_user;
        aux1_user=aux1_user->prox;
        free(aux2_user);
    }
}
