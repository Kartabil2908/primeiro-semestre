
/* Faça um algoritmo que imprima a série de Fibonacci até o valor N fornecido
pelo usuário. A série de Fibonacci é mostrada abaixo.


1,1,2,3,5,8,13,21,...,N

Entrada
N

Saída
Termos da série da Fibonacci menores que N */

#include <stdio.h>

int main(void) {

  int numero, valor1 = 0, valor2 = 1, valor = 1;

  scanf("%d", &numero);

  for (int i = 0; i < numero; i++) {

    printf("%d", valor);

    valor = valor1 + valor2;

    valor1 = valor2;
    valor2 = valor;

    if (valor > numero) {

      break;
    }
  }

  return 0;
}