#include <stdio.h>
#include "rede_social.h"

// PERGUNTAS PARA O THIAGO
// Que tipo de prints ou scans a gente tem que fazer nas funções e não aqui? .
// É muito desperdício de memória usar o método de print das mensagens que estamos usando?
// As mensagens podem ser apagadas depois de lidas?
// Perguntar se vale a pena fazer um ponteiro para void na info da lista de parceiros. (pq queremos um para User)
// Pode tirar as funções não utilizadas nos TAD's pilha, fila e lista?

int main(){
    Users L;
    int erro, opcao;
    Criar_usuarios(&L);
    char nome[50], meu_apelido[30], outro_apelido[30], mensagem[140];

    while (opcao!=8){
        opcao = 0;
        printf("Caro usuário, suas opções são: \n");
        printf("\t 1) Cadastrar um usuário.\n");
        printf("\t 2) Listas usuários cadastrados e suas informações.\n");
        printf("\t 3) Pedir para ser parceiro de um usuário.\n");
        printf("\t 4) Avaliar lista de pedidos de parceiros.\n");
        printf("\t 5) Enviar mensagem para um parceiro.\n");
        printf("\t 6) Ver mensagens recebidas.\n");
        printf("\t 7) Sugerir novas parcerias.\n");
        printf("\t 8) Renicializar o sistema.\n");
        printf("\n \t Opção: ");

        scanf("%d", &opcao);
        //printf("\n");

        if (opcao==1){ 
            
            printf("\tEntre com seu nome: ");
            scanf("%s", nome);
            printf("\tEntre com seu apelido: ");
            scanf("%s", meu_apelido);
            Cadastro(&L, nome, meu_apelido, &erro);
            if (erro==0) printf("Usuário cadastrado com sucesso\n");
            if (erro==2) printf("Indivíduo já cadastrado\n");
        }


        else if (opcao==2){
            Imprime(&L);
            printf("Listagem completa!\n");
        }


        else if (opcao==3){
            printf("\t Entre com seu apelido: ");
            scanf("%s", meu_apelido);
            printf("\t Entre com o apelido de quem quer ser parceiro: ");
            scanf("%s", outro_apelido);
            Convidar(&L, meu_apelido, outro_apelido, &erro);
            if (erro==0) printf("Pedido encaminhado com sucesso!\n");
            if (erro==2) printf("Você já é parceiro dessa pessoa\n");
            if (erro==3) printf("Erro ao digitar seu nome ou da pessoa convidada\n");
        }


        else if (opcao==4){
            printf("\t Entre com seu apelido: ");
            scanf("%s", meu_apelido);
            Avaliar_pedidos(&L, meu_apelido, &erro);
            if (erro==0) printf("Operação realizada com sucesso\n");
            if (erro==2) printf("Nome não cadastrado");
        }


        else if (opcao==5){
            printf("\t Entre com seu apelido: ");
            scanf("%s", meu_apelido);
            printf("\t Entre com o apelido de quem quer enviar mensagem: ");
            scanf("%s", outro_apelido);
            printf("Entre com a mensagem: ");
            scanf("%s", mensagem);
            Enviar_mensagem(&L, mensagem, meu_apelido, outro_apelido, &erro);
            if (erro==0) printf("Mensagem enviada com Sucesso\n");
            if (erro==2) printf("Rementente ou destinatário não encontrado\n");
        }

        else if (opcao==6){
            printf("Entre com seu apelido: ");
            scanf("%s", meu_apelido);
            printf("Suas mensagens são: \n");
            Ver_mensagens(&L, meu_apelido);
        }

        else if (opcao==7){}


        if (erro==1) printf("Erro ao criar espaço de memória.\n");
        //printf("\nAperte enter para voltar\n");
        printf("\n");



    }



    /*User *U;

    Criar_usuarios(&L);
    Cadastro(&L, "marvin", "marvex", &erro);
    if (erro==1){
        printf("erro no cadastro 1 \n");
    }
    Cadastro(&L, "Matheus", "Siqueira", &erro);
    if (erro==1){
        printf("erro no cadastro 2 \n");
    }
    Cadastro(&L, "Siqueira", "siqs", &erro);
    if (erro==1){
        printf("erro no cadastro 3\n");
    }


    Convidar(&L, "siqs","marvex", &erro);
    if (erro==1) printf("falta de memória no convite 1\n");
    else if(erro==2) printf("apelido não encontrado no convite 1\n");

    Convidar(&L, "Siqueira","marvex", &erro);
    if (erro==1) printf("falta de memória no convite 2\n");
    else if(erro==2) printf("apelido não encontrado no convite 2\n");


    Avaliar_pedidos(&L, "marvex", &erro);
    if (erro==1) printf("falta de memória na avaliação\n");
    else if(erro==2) printf("apelido não encontrado na avaliação\n");


    Enviar_mensagem(&L, "Eae, bora no podrão?", "siqs", "marvex", &erro);
    if (erro==1) printf("falta de memória no envio 1\n");
    else if(erro==2) printf("apelido não encontrado no envio de mensagem 1\n");

    Enviar_mensagem(&L, "Eae, bora no podrão hoje?", "Siqueira", "marvex", &erro);
    if (erro==1) printf("falta de memória no envio 2\n");
    else if(erro==2) printf("apelido não encontrado no envio de mensagem 2\n");


    Enviar_mensagem(&L, "Eae, bora no podrão amanhã?", "siqs", "marvex", &erro);
    if (erro==1) printf("falta de memória no envio 2\n");
    else if(erro==2) printf("apelido não encontrado no envio de mensagem 2\n");


    Ver_mensagens(&L, "marvex");



    Imprime(&L);*/
    Libera(&L);





    return(0);
}


