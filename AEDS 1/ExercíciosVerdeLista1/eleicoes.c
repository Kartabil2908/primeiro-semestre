/* Em uma eleição presidencial existem quatro candidatos. Os votos são
informados por meio de código. Os códigos utilizados são:

1,2,3,4 - Votos para os respectivos candidatos
5 - Voto nulo
6 - Voto em branco


Faça um programa que calcule e mostre:

o total de votos para cada candidato;
o total de votos nulos;
a porcentagem de votos em branco sobre o total de votos.

Para finalizar o conjunto de votos digitados, deve-se informar o código zero.

Entrada
Sequência de números inteiros até encontrar o número zero

Saída
A saída deve conter três linhas:
A primeira linha contendo o total de votos de cada candidato.
A segunda linha o total de votos nulos.
A terceira linha com o percentual de votos em brancos */

#include <stdio.h>

int main(void) {

  int qtd1 = 0, qtd2 = 0, qtd3 = 0, qtd4 = 0, nulo = 0, branco = 0, votos = 0,
      numero;

  float porcentagem;

  do {

    scanf("%d", &numero);

    if (numero == 1) {

      qtd1++;
      votos++;
    }

    if (numero == 2) {

      qtd2++;
      votos++;
    }

    if (numero == 3) {

      qtd3++;
      votos++;
    }

    if (numero == 4) {

      qtd4++;
      votos++;
    }

    if (numero == 5) {

      nulo++;
      votos++;
    }

    if (numero == 6) {

      branco++;
      votos++;
    }

  } while (numero > 0);
  porcentagem = (branco * 100) / votos;

  printf("%d %d %d %d \n %d", qtd1, qtd2, qtd3, qtd4, nulo);

  printf("%f", porcentagem);

  return 0;
}