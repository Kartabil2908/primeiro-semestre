#ifndef PESQUISAR_PASSAGEM_H
#define PESQUISAR_PASSAGEM_H

#include <stdio.h>
#include <stdlib.h>
#include "Passagem.h"
#include <stdbool.h>

void pesquisarPassagem()
{

    int opcao;

    puts("<-------------------------------------------------------->");
    puts("Selecione o parâmetro o qual deseja utilizar na busca:");
    puts("1. ID");
    puts("2. Aeroporto origem");
    puts("3. Aeroporto destino");
    puts("4. Cidade de origem");
    puts("5. Cidade de destino");
    puts("<-------------------------------------------------------->");
    scanf("%d", &opcao);

    switch (opcao)
    {

    case 1:
        pesquisarID();
        break;

    case 2:
        pesquisarAeroOrig();
        break;

    case 3:
        pesquisarAeroDest();
        break;

    case 4:
        pesquisarCidadeOrigem();
        break;

    case 5:
        pesquisarCidadeDestino();
        break;
    }

}

//---------------------------------------------------------------------------------------------- PESQUISA POR ID ----------------------------------------------------------------- //

void pesquisarID()
{
    FILE *arquivo;
    int IDpesquisa;
    char linha[100], linhaOriginal[100];
    char *token;
    int idAtual;

//------------------------- ABRINDO O ARQUIVO ---------------------------------- //

    arquivo = fopen("Passagens.txt", "r");

    if (arquivo == NULL)
    {
        puts("Erro ao abrir o arquivo, verifique se o arquivo existe");
        return;
    }

//------------------------- ABRINDO O ARQUIVO ---------------------------------- //

//------------------------- PESQUISA POR ID ---------------------------------- //

    puts("Digite o ID da passagem que deseja procurar:");

    scanf("%d", &IDpesquisa);

    while (fgets(linha, sizeof(linha), arquivo) != NULL)   // Vai varrendo todas as linhas até encontrar a linha certa
    {
        linhaOriginal[100];

        strcpy(linhaOriginal, linha); // copia o conteúdo de "linha" para "linhaOriginal" // se eu não copiasse para "LinhaOriginal", ele printaria só o ID, e não a linha toda //

        token = strtok(linha, ";"); // pegou o ID da linha e retornou como string //

        idAtual = atoi(token); // transforma a string em inteiro, mas só dá certo quando a string for um número

        if (idAtual == IDpesquisa)   // Se o ID encontrado for igual ao ID da pesquisa, printa a Linha toda"
        {
            puts("<-------------------------------------------------------->");
            printf("%s", linhaOriginal);
            puts("<-------------------------------------------------------->");
            fclose(arquivo);
            return;
        }
    } // termina o while

    printf("Nenhuma passagem encontrada com o ID %d.\n", IDpesquisa); // Nenhum foi encontrado

    fclose(arquivo);


}

//---------------------------------------------------------------------------------------------- PESQUISA POR ID ----------------------------------------------------------------- //


//---------------------------------------------------------------------------------------------- PESQUISA POR CÓDIGO DE ORIGEM ----------------------------------------------------------------- //


void pesquisarAeroOrig()
{
    FILE *arquivo;
    char *token;
    char linha[100];
    char linhaOriginal[100];
    char codigoAtual[4];
    int encontrou = 0;

    arquivo = fopen("Passagens.txt", "r");

    if (arquivo == NULL)
    {
        puts("Erro ao abrir o arquivo, verifique se o arquivo existe");
        return;
    }



    do
    {
        puts("Digite o código do aeroporto de origem (3 letras maiúsculas):");
        scanf(" %[^\n]", codigoAtual);
        fflush(stdin);

        corrigirCodigoAeroporto(codigoAtual); // Corrigir código para letras maiúsculas //

        if (!validarCodigoAeroporto(codigoAtual))
        {
            puts("Código de aeroporto inválido. Por favor, insira um código válido.");
        }

    }
    while (!validarCodigoAeroporto(codigoAtual));



    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {

        strcpy(linhaOriginal, linha); // copia o conteúdo de "linha" para "linhaOriginal" // se eu não copiasse para "LinhaOriginal", ele printaria só o ID, e não a linha toda //

        token = strtok(linha, ";"); // ID
        token = strtok(NULL, ";"); // Esse strtok continua do token anterior e termina até encontrar o próximo ";" //

        if (token != NULL && strcmp(token, codigoAtual) == 0)   // compara as strings
        {
            printf("%s", linhaOriginal);
            encontrou = 1;
        }
    }

    fclose(arquivo);

    if (!encontrou)
    {
        // Nenhuma passagem encontrada com o código do aeroporto de origem
        printf("Nenhuma passagem encontrada com o código do aeroporto de origem %s.\n", codigoAtual);
    }
}

//---------------------------------------------------------------------------------------------- PESQUISA POR CÓDIGO DE ORIGEM ----------------------------------------------------------------- //

//---------------------------------------------------------------------------------------------- PESQUISA POR CÓDIGO DE DESTINO ----------------------------------------------------------------- //

void pesquisarAeroDest()
{
    FILE *arquivo;
    char *token;
    char linha[100];
    char linhaOriginal[100];
    char codigoAtual[4];
    int encontrou = 0;

    arquivo = fopen("Passagens.txt", "r");

    if (arquivo == NULL)
    {
        puts("Erro ao abrir o arquivo, verifique se o arquivo existe");
        return;
    }



    do
    {
        puts("Digite o código do aeroporto de destino (3 letras maiúsculas):");
        scanf(" %[^\n]", codigoAtual);
        fflush(stdin);

        corrigirCodigoAeroporto(codigoAtual); // Corrigir código para letras maiúsculas //

        if (!validarCodigoAeroporto(codigoAtual))
        {
            puts("Código de aeroporto inválido. Por favor, insira um código válido.");
        }

    }
    while (!validarCodigoAeroporto(codigoAtual));



    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {

        strcpy(linhaOriginal, linha); // copia o conteúdo de "linha" para "linhaOriginal" // se eu não copiasse para "LinhaOriginal", ele printaria só o ID, e não a linha toda //

        token = strtok(linha, ";"); // ID
        token = strtok(NULL, ";"); // CODIGO DE ORIGEM //
        token = strtok(NULL, ";");  // Esse strtok continua do token anterior e termina até encontrar o próximo ";" //

        if (token != NULL && strcmp(token, codigoAtual) == 0)   // compara as strings
        {
            printf("%s", linhaOriginal);
            encontrou = 1;
        }
    }

    fclose(arquivo);

    if (!encontrou)
    {
        // Nenhuma passagem encontrada com o código do aeroporto de destino
        printf("Nenhuma passagem encontrada com o código do aeroporto de destino %s.\n", codigoAtual);
    }
}

//---------------------------------------------------------------------------------------------- PESQUISA POR CÓDIGO DE DESTINO ----------------------------------------------------------------- //


//---------------------------------------------------------------------------------------------- PESQUISA POR CIDADE DE ORIGEM ----------------------------------------------------------------- //


void pesquisarCidadeOrigem(){

  FILE *arquivo;
    char *token;
    char linha[100];
    char linhaOriginal[100];
    char cidadeAtual[20];
    int encontrou = 0;

    arquivo = fopen("Passagens.txt", "r");

    if (arquivo == NULL)
    {
        puts("Erro ao abrir o arquivo, verifique se o arquivo existe");
        return;
    }

        puts("Digite o nome da cidade de origem:");
        scanf(" %[^\n]", cidadeAtual);
        fflush(stdin);


    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {

        strcpy(linhaOriginal, linha); // copia o conteúdo de "linha" para "linhaOriginal" // se eu não copiasse para "LinhaOriginal", ele printaria só o ID, e não a linha toda //

        token = strtok(linha, ";"); // ID
        token = strtok(NULL, ";"); // CODIGO DE ORIGEM //
        token = strtok(NULL, ";"); // CODIGO DE DESTINO //
        token = strtok(NULL, ";");  // Esse strtok continua do token anterior e termina até encontrar o próximo ";" //

        if (token != NULL && strcmp(token, cidadeAtual) == 0)   // compara as strings
        {
            printf("%s", linhaOriginal);
            encontrou = 1;
        }
    }

    fclose(arquivo);

    if (!encontrou)
    {
        // Nenhuma passagem encontrada com o nome da cidade de origem
        printf("Nenhuma passagem encontrada cujo nome da cidade de origem    é %s.\n", cidadeAtual);
    }



}

//---------------------------------------------------------------------------------------------- PESQUISA POR CIDADE DE ORIGEM ----------------------------------------------------------------- //

//---------------------------------------------------------------------------------------------- PESQUISA POR CIDADE DE DESTINO ----------------------------------------------------------------- //

void pesquisarCidadeDestino(){

  FILE *arquivo;
    char *token;
    char linha[100];
    char linhaOriginal[100];
    char cidadeAtual[20];
    int encontrou = 0;

    arquivo = fopen("Passagens.txt", "r");

    if (arquivo == NULL)
    {
        puts("Erro ao abrir o arquivo, verifique se o arquivo existe");
        return;
    }

        puts("Digite o nome da cidade de destino:");
        scanf(" %[^\n]", cidadeAtual);
        fflush(stdin);


    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {

        strcpy(linhaOriginal, linha); // copia o conteúdo de "linha" para "linhaOriginal" // se eu não copiasse para "LinhaOriginal", ele printaria só o ID, e não a linha toda //

        token = strtok(linha, ";"); // ID
        token = strtok(NULL, ";"); // CODIGO DE ORIGEM //
        token = strtok(NULL, ";"); // CODIGO DE DESTINO //
        token = strtok(NULL, ";"); // CIDADE DE ORIGEM
        token = strtok(NULL, ";");  // Esse strtok continua do token anterior e termina até encontrar o próximo ";" //

        if (token != NULL && strcmp(token, cidadeAtual) == 0)   // compara as strings
        {
            printf("%s", linhaOriginal);
            encontrou = 1;
        }
    }

    fclose(arquivo);

    if (!encontrou)
    {
        // Nenhuma passagem encontrada com o nome da cidade de destino
        printf("Nenhuma passagem encontrada cujo nome da cidade de destino é %s.\n", cidadeAtual);
    }



}




#endif // PESQUISAR_PASSAGEM_H



