#include <stdio.h>
#include "Passagem.h"
#include "cadastrarPassagem.h"
#include "validacoes.h"

int main() {
    int respostaRegistrada;

    puts("Olá! Obrigado por escolher a Ultrafast Airlines! Por favor, escolha "
         "uma das opções abaixo:");

    while (respostaRegistrada != 6) {
        puts("1) Ver todas as passagens no sistema;");
        puts("2) Pesquisar uma passagem;");
        puts("3) Cadastrar uma passagem");
        puts("4) Editar uma passagem");
        puts("5) Excluir uma passagem");
        puts("6) Sair do programa");

        scanf("%d", &respostaRegistrada);

        switch (respostaRegistrada) {

            case 1:

                listarPassagens();
                break;

            case 3:
                cadastrarPassagem();
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







