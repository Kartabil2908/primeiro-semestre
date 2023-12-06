/* A Olimpíada Municipal de Programação vai distribuir camisetas para os
melhores colocados, e por isso solicitou que os premiados informassem o tamanho
preferido da camiseta, entre os tamanhos pequeno e médio.

A empresa que confeccionou as camisetas, por uma falha, pode ter se enganado na
quantidade de camisetas para cada tamanho. Foram produzidas camisetas em número
suficiente para todos os premiados, mas talvez não do tamanho preferido.

Dadas a lista com os tamanhos preferidos pelos premiados e a quantidade de
camisetas de cada tamanho produzidas pela empresa, escreva um programa para
determinar se todos os premiados receberão camisetas do tamanho escolhido.

Entrada

A primeira linha contém um inteiro N, o número de premiados. A segunda linha
contém N inteiros Ti, indicando os tamanhos solicitados pelos premiados, sendo
que Ti = 1 representa o tamanho pequeno e Ti = 2 representa o tamanho médio. A
terceira linha contém um inteiro P, o número de camisetas de tamanho pequeno
produzidas. A quarta e última contém um inteiro M, o número de camisetas de
tamanho médio produzidas.


Saída

Seu programa deve produzir uma única linha, contendo um único caractere, que
deve ser a letra maiúscula 'S' se todos os premiados serão atendidos com a
camiseta do tamanho que escolheram, ou a letra maiúscula 'N' caso contrário.

Restrições

1 ≤ N ≤ 1000 0 ≤ P ≤ 1000 0 ≤ M ≤ 1000 N ≤ P + M 1 ≤ Xi ≤ 2 para 1 ≤ i ≤ N */

#include <stdio.h>

int main(void) {

  int premiados, camisas, qtdP = 0, qtdM = 0, i;

  // número de premiados //

  scanf("%d", &premiados);

  // tipo de camisas

  for (i = 0; i < premiados; i++) {

    scanf("%d", &camisas);

    if (camisas == 1) {

      qtdP++;
    }

    if (camisas == 2) {

      qtdM++;
    }
  }

  scanf("%d", &qtdP);

  scanf("%d", &qtdM);

  if (qtdP + qtdM == premiados) {

    printf("S");
  }

  if (qtdP + qtdM != premiados) {

    printf("N");
  }

  return 0;
}