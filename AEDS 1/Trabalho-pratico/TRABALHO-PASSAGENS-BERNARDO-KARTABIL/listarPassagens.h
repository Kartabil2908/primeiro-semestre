#ifndef LISTARPASSAGENS_H_INCLUDED
#define LISTARPASSAGENS_H_INCLUDED

#include "Passagem.h"
#include <stdio.h>

void listarPassagens()
{
    FILE *arquivo;
    char str[100];
    int contador = 0;

//------------------------- ABRINDO O ARQUIVO ---------------------------------- //

    arquivo = fopen("Passagens.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

//------------------------- ABRINDO O ARQUIVO ---------------------------------- //

//------------------------- LENDO O ARQUIVO ------------------------------------ //
    puts("<-------------------------------------------------------->");


  while(fscanf(arquivo, " %[^\n]", str) != EOF){ // lê o arquivo até achar um /n

    if(contador != 1){
        printf("%s\n", str);
    }
    contador++;
  }

//------------------------- LENDO O ARQUIVO ------------------------------------ //

//------------------------- FECHANDO O ARQUIVO ------------------------------------ //

    fclose(arquivo);
}

//------------------------- FECHANDO O ARQUIVO ------------------------------------ //

#endif // LISTARPASSAGENS_H_INCLUDED
