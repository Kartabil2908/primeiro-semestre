/* Um número primo é divisível somente por 1 e por ele mesmo. Faça um algoritmo
para identificar se um determinado número fornecido pelo usuário é primo ou não.
Exemplos de números primos: 2, 5, 7, 11, 13.

Entrada
Um número

Saída
1 Se o número for primo, 0 caso contrário */

#include <stdio.h>

int main(void) {

  int numero;

  scanf("%d", &numero);

  if (numero / 1 == numero && numero / numero == 1 && numero % 2 == 0 ||
      numero % 3 == 0) {

    printf("0");

  } else if (numero / 1 == numero && numero / numero == 1) {

    printf("1");
  }

  if (numero > 7 && numero % 5 == 0 || numero % 7 == 0) {

    printf("1");
  }

  return 0;
}
