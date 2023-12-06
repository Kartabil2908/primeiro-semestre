
#ifndef CADASTRAR_PASSAGEM_H
#define CADASTRAR_PASSAGEM_H


#include <stdbool.h>
#include <stdio.h>
#include "Passagem.h"
#include "validacoes.h"
#include "criarID.h"

int criarId();




void cadastrarPassagem()
{
    FILE *arquivo;
    Passagem pass;


//------------------------- ABRINDO O ARQUIVO ---------------------------------- //
arquivo = fopen("Passagens.txt", "a+");

    if (arquivo == NULL)
    {
        puts("Erro ao abrir o arquivo,programa encerrado.");
        exit(2);
    }




//------------------------- ABRINDO O ARQUIVO ---------------------------------- //

//-------------------------------------- CÓDIGO DO AEROPORTO ORIGEM -------------------------------------------- //

    do
    {
        printf("Digite o codigo do aeroporto de origem (3 letras maiúsculas):\n");
        scanf(" %[^\n]", pass.aeroportoOrigem);
        fflush(stdin);

        corrigirCodigoAeroporto(pass.aeroportoOrigem); // Corrigir código para letras maiúsculas //

        if (!validarCodigoAeroporto(pass.aeroportoOrigem))
        {
            printf("Código de aeroporto inválido. Por favor, insira um código válido.\n");
        }



    }while (!validarCodigoAeroporto(pass.aeroportoOrigem));

//-------------------------------------- CÓDIGO DO AEROPORTO ORIGEM -------------------------------------------- //

//-------------------------------------- CÓDIGO DO AEROPORTO DESTINO -------------------------------------------- //

    do
    {
        printf("Digite o codigo do aeroporto de destino (3 letras maiúsculas):\n");
        scanf(" %[^\n]", pass.aeroportoDestino);
        fflush(stdin);

        corrigirCodigoAeroporto(pass.aeroportoDestino);

        if (!validarCodigoAeroporto(pass.aeroportoDestino))
        {
            printf("Código de aeroporto inválido. Por favor, insira um código válido.\n");
        }

    }
    while (!validarCodigoAeroporto(pass.aeroportoDestino));

//-------------------------------------- CÓDIGO DO AEROPORTO DESTINO -------------------------------------------- //

//-------------------------------------- CIDADE ORIGEM E DESTINO -------------------------------------------- //

    printf("Digite a cidade de origem:\n");
    scanf(" %[^\n]", pass.cidadeOrigem);
    fflush(stdin);
    printf("Digite a cidade de destino:\n");
    scanf(" %[^\n]", pass.cidadeDestino);
    fflush(stdin);

//-------------------------------------- CIDADE ORIGEM E DESTINO -------------------------------------------- //

//-------------------------------------------------------- DATA -------------------------------------------- //

    do
    {
        printf("Digite o dia do seu voo:\n");
        scanf(" %d", &pass.data.dia);
        fflush(stdin);
        printf("Digite o mes do seu voo:\n");
        scanf("%d", &pass.data.mes);
        fflush(stdin);
        printf("Digite o ano do seu voo (4 dígitos):\n");
        scanf("%d", &pass.data.ano);
        fflush(stdin);

        if (!validarData(pass.data.dia, pass.data.mes, pass.data.ano))
        {
            printf("Data inválida. Por favor, insira uma data válida.\n");
        }

    }
    while (!validarData(pass.data.dia, pass.data.mes, pass.data.ano) || pass.data.ano < 1000 || pass.data.ano > 9999);

//------------------------------------------------------- DATA -------------------------------------------- //


//----------------------------------------------- HORARIO SAÍDA -------------------------------------------- //

    do
    {
        printf("Digite o hora de saida do seu voo:\n");
        scanf("%d", &pass.horarioSaida.horas);
        fflush(stdin);
        printf("Digite o minuto de saida do seu voo:\n");
        scanf("%d", &pass.horarioSaida.minutos);
        fflush(stdin);

        if (!validarHorario(pass.horarioSaida.horas, pass.horarioSaida.minutos))
        {
            printf("Horário de saída inválido. Por favor, insira um horário válido.\n");
        }

    }
    while (!validarHorario(pass.horarioSaida.horas, pass.horarioSaida.minutos));

//----------------------------------------------- HORARIO SAÍDA -------------------------------------------- //

//----------------------------------------------- HORARIO CHEGADA -------------------------------------------- //

    do
    {
        printf("Digite o hora de chegada do seu voo:\n");
        scanf("%d", &pass.horarioChegada.horas);
        fflush(stdin);
        printf("Digite o minuto de chegada do seu voo:\n");
        scanf("%d", &pass.horarioChegada.minutos);
        fflush(stdin);

        if (!validarHorario(pass.horarioChegada.horas, pass.horarioChegada.minutos))
        {
            printf("Horário de chegada inválido. Por favor, insira um horário válido.\n");
        }

    }
    while (!validarHorario(pass.horarioChegada.horas, pass.horarioChegada.minutos));

//----------------------------------------------- HORARIO CHEGADA -------------------------------------------- //
    do{

    printf("Digite o preco da sua passagem:\n");
    scanf("%f", &pass.preco);
    fflush(stdin);


    }while(pass.preco <= 0);

//----------------------------------------------- PRINTANDO A PASSAGEM -------------------------------------------- //
     pass.ID = criarId();

    fprintf(arquivo,"%d;", pass.ID);
    fprintf(arquivo,"%s;", pass.aeroportoOrigem);
    fprintf(arquivo, "%s;", pass.aeroportoDestino);
    fprintf(arquivo, "%s;", pass.cidadeOrigem);
    fprintf(arquivo, "%s;", pass.cidadeDestino);
    fprintf(arquivo, "%02d/%02d/%04d;", pass.data.dia, pass.data.mes, pass.data.ano);
    fprintf(arquivo, "%02d:%02d;", pass.horarioSaida.horas, pass.horarioSaida.minutos);
    fprintf(arquivo, "%02d:%02d;", pass.horarioChegada.horas, pass.horarioChegada.minutos);
    fprintf(arquivo, "%.2f\n", pass.preco);

    fclose(arquivo);

//----------------------------------------------- PRINTANDO A PASSAGEM -------------------------------------------- //

}

#endif // CADASTRAR_PASSAGEM_H



