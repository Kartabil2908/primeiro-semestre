#ifndef LISTARPASSAGENS_H_INCLUDED
#define LISTARPASSAGENS_H_INCLUDED

#include "Passagem.h"
#include <stdio.h>

void listarPassagens()
{
    FILE *arquivo;
    char str[50];

//------------------------- ABRINDO O ARQUIVO ---------------------------------- //

    arquivo = fopen("Passagens.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

//------------------------- ABRINDO O ARQUIVO ---------------------------------- //

//------------------------- LENDO O ARQUIVO ------------------------------------ //

    do
    {
        if (fgets(str, sizeof(str), arquivo) != NULL)
        {

            printf("%s", str);
        }
    }
    while (!feof(arquivo)); // verifica a veracidade do final do arquivo

//------------------------- LENDO O ARQUIVO ------------------------------------ //

//------------------------- FECHANDO O ARQUIVO ------------------------------------ //

    fclose(arquivo);
}

//------------------------- FECHANDO O ARQUIVO ------------------------------------ //

#endif // LISTARPASSAGENS_H_INCLUDED
