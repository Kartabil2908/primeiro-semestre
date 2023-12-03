#ifndef CADASTRAR_PASSAGEM_H
#define CADASTRAR_PASSAGEM_H


#include <stdbool.h>
#include <stdio.h>
#include "Passagem.h"
#include "validacoes.h"

void cadastrarPassagem(){
    FILE *arquivo;
    Passagem pass;
    int IDtotal = 0, auxID = 0;
    pass.ID = 0;


    arquivo = fopen("Passagens.txt", "a+");

    if (arquivo == NULL) {
        puts("Erro ao abrir o arquivo,programa encerrado.");
        exit(2);
    }

    // Solicitação do código de aeroporto de origem com validação e correção para letras maiúscula //
    do {
        printf("Digite o codigo do aeroporto de origem (3 letras maiúsculas):\n");
        scanf(" %[^\n]", pass.aeroportoOrigem);
        fflush(stdin);

        // Corrigir código para letras maiúsculas //

        corrigirCodigoAeroporto(pass.aeroportoOrigem);

        if (!validarCodigoAeroporto(pass.aeroportoOrigem)) {
            printf("Código de aeroporto inválido. Por favor, insira um código válido.\n");
        }

    } while (!validarCodigoAeroporto(pass.aeroportoOrigem));

    // Solicitação do código de aeroporto de destino com validação e correção
    do {
        printf("Digite o codigo do aeroporto de destino (3 letras maiúsculas):\n");
        scanf(" %[^\n]", pass.aeroportoDestino);
        fflush(stdin);

        corrigirCodigoAeroporto(pass.aeroportoDestino);

        if (!validarCodigoAeroporto(pass.aeroportoDestino)) {
            printf("Código de aeroporto inválido. Por favor, insira um código válido.\n");
        }

    } while (!validarCodigoAeroporto(pass.aeroportoDestino));

    printf("Digite a cidade de origem:\n");
    scanf(" %[^\n]", pass.cidadeOrigem);
    fflush(stdin);
    printf("Digite a cidade de destino:\n");
    scanf(" %[^\n]", pass.cidadeDestino);
    fflush(stdin);

    // Solicitação da data com validação
  do {
    printf("Digite o dia do seu voo:\n");
    scanf(" %d", &pass.data.dia);
    fflush(stdin);
    printf("Digite o mes do seu voo:\n");
    scanf("%d", &pass.data.mes);
    fflush(stdin);
    printf("Digite o ano do seu voo (4 dígitos):\n");
    scanf("%d", &pass.data.ano);
    fflush(stdin);

    if (!validarData(pass.data.dia, pass.data.mes, pass.data.ano)) {
        printf("Data inválida. Por favor, insira uma data válida.\n");
    }

} while (!validarData(pass.data.dia, pass.data.mes, pass.data.ano) || pass.data.ano < 1000 || pass.data.ano > 9999);


    // Solicitação do horário de saída com validação
    do {
        printf("Digite o hora de saida do seu voo:\n");
        scanf("%d", &pass.horarioSaida.horas);
        fflush(stdin);
        printf("Digite o minuto de saida do seu voo:\n");
        scanf("%d", &pass.horarioSaida.minutos);
        fflush(stdin);

        if (!validarHorario(pass.horarioSaida.horas, pass.horarioSaida.minutos)) {
            printf("Horário de saída inválido. Por favor, insira um horário válido.\n");
        }

    } while (!validarHorario(pass.horarioSaida.horas, pass.horarioSaida.minutos));

    // Solicitação do horário de chegada com validação
    do {
        printf("Digite o hora de chegada do seu voo:\n");
        scanf("%d", &pass.horarioChegada.horas);
        fflush(stdin);
        printf("Digite o minuto de chegada do seu voo:\n");
        scanf("%d", &pass.horarioChegada.minutos);
        fflush(stdin);

        if (!validarHorario(pass.horarioChegada.horas, pass.horarioChegada.minutos)) {
            printf("Horário de chegada inválido. Por favor, insira um horário válido.\n");
        }

    } while (!validarHorario(pass.horarioChegada.horas, pass.horarioChegada.minutos));



    printf("Digite o preco da sua passagem:\n");
    scanf("%f", &pass.preco);
    fflush(stdin);

    IDtotal++;
    fseek(arquivo, 0, SEEK_SET); // Move o indicador de posição para o início do arquivo.
    fprintf(arquivo, "%d", IDtotal); // Atualiza o número total de passagens.

    fseek(arquivo, 0, SEEK_END); // Move o indicador de posição para o final do arquivo.
    pass.ID++;
    pass.ID = pass.ID + auxID;
    auxID = pass.ID;




    fprintf(arquivo,"%d;", auxID);
    fprintf(arquivo,"%s;", pass.aeroportoOrigem);
    fprintf(arquivo, "%s;", pass.aeroportoDestino);
    fprintf(arquivo, "%s;", pass.cidadeOrigem);
    fprintf(arquivo, "%s;", pass.cidadeDestino);
    fprintf(arquivo, "%02d/%02d/%04d;", pass.data.dia, pass.data.mes, pass.data.ano);
    fprintf(arquivo, "%02d:%02d;", pass.horarioSaida.horas, pass.horarioSaida.minutos);
    fprintf(arquivo, "%02d:%02d;", pass.horarioChegada.horas, pass.horarioChegada.minutos);
    fprintf(arquivo, "%.2f\n", pass.preco);

    fclose(arquivo);

}

#endif // CADASTRAR_PASSAGEM_H
