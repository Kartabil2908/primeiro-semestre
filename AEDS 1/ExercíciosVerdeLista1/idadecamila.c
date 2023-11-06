/* Cibele, Camila e Celeste são três irmãs inseparáveis. Estão sempre juntas e
adoram fazer esportes, ler, cozinhar, jogar no computador... Agora estão
aprendendo a programar computadores para desenvolverem seus próprios jogos.

Mas nada disso interessa para esta tarefa: estamos interessados apenas nas suas
idades. Sabemos que Cibele nasceu antes de Camila e Celeste nasceu depois de
Camila.

Dados três números inteiros indicando as idades das irmãs, escreva um programa
para determinar a idade de Camila.

Entrada A entrada é composta por três linhas, cada linha contendo um número
inteiro N, a idade de uma das irmãs.

Saída Seu programa deve produzir uma única linha, contendo um único número
inteiro, a idade de Camila.

Restrições 5 ≤ N ≤ 100 */

#include <stdio.h>

// Camila é a irmã do meio

int main(void) {

  int idade1, idade2, idade3;

  scanf("%d", &idade1);
  scanf("%d", &idade2);
  scanf("%d", &idade3);

  // se a idade2 for camila

  if (idade2 > idade3 && idade2 < idade1 ||
      idade2 > idade1 && idade2 < idade3) {

    printf("%d", idade2);
  }

  // se a idade1 for camila

  if (idade1 > idade2 && idade1 < idade3 ||
      idade1 > idade3 && idade1 < idade2) {

    printf("%d", idade1);
  }

  // se a idade3 for camila

  if (idade3 > idade1 && idade3 < idade2 ||
      idade3 > idade2 && idade3 < idade1) {

    printf("%d", idade3);
  }

  return 0;
}