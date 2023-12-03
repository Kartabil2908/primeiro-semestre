#ifndef CRIARID_H_INCLUDED
#define CRIARID_H_INCLUDED

#include<stdio.h>

int criarId(){

  FILE *arq;
  int qtdPassagens;
  int lastId, contador = 0;
  char linha[100];

//------------------------- ABRINDO O ARQUIVO ---------------------------------- //

  arq = fopen("Passagens.txt", "r");

//------------------------- ABRINDO O ARQUIVO ---------------------------------- //

//------------------------- CRIANDO O ID ---------------------------------- //

  fscanf(arq, "%d", &qtdPassagens);

  while(fscanf(arq, " %[^\n]", linha) != EOF){

    sscanf(linha,"%d", &lastId);
    contador++;
  }

  if(contador == 0){
    qtdPassagens = 0;
    lastId = 0;
  }

  qtdPassagens++;
  lastId++;

fclose(arq);

//------------------------- FECHANDO O ARQUIVO ---------------------------------- //

//------------------------- PRINTANDO OS IDS ---------------------------------- //

arq = fopen("Passagens.txt", "r+");

fprintf(arq,"%d\n", qtdPassagens);
fprintf(arq, "%d\n", lastId);


fclose(arq);

//------------------------- PRINTANDO OS IDS ---------------------------------- //

return lastId;

}

#endif // CRIARID_H_INCLUDED
