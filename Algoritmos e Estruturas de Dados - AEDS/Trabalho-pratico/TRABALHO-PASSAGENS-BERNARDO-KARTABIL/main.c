#include <stdio.h>
#include "cadastrarPassagem.h"
#include "listarPassagens.h"
#include <locale.h>
#include "pesquisarpassagem.h"
#include "excluirPassagem.h"
#include "editarPassagem.h"


int main() {

    setlocale(LC_ALL,"Portuguese_Brazil");


    int respostaRegistrada;

    puts("<------------------------------------------------------------------------------------------->");

    puts("Olá! Obrigado por escolher a Ultrafast Airlines! Por favor, escolha "
         "uma das opções abaixo:");

    while (respostaRegistrada != 6) {
        puts("1) Ver todas as passagens no sistema;");
        puts("2) Pesquisar uma passagem;");
        puts("3) Cadastrar uma passagem");
        puts("4) Editar uma passagem");
        puts("5) Excluir uma passagem");
        puts("6) Sair do programa");

    puts("<------------------------------------------------------------------------------------------->");

        scanf("%d", &respostaRegistrada);

        switch (respostaRegistrada) {

            case 1:

                listarPassagens();
                break;

            case 2:
               pesquisarPassagem();
                break;

            case 3:
                cadastrarPassagem();
                break;

            case 4:

                editarPassagem();
                break;


            case 5:

                excluirPassagem();
                break;


            case 6:
                exit(1);
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}







