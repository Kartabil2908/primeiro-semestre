// Unidade 4 - Execícios Modularização

// Questão 1 //

/* Faça um procedimento que recebe 3 valores inteiros e os exibe em ordem
crescente. Crie um programa que lê 3 valores e aciona o procedimento.

#include <stdio.h>

void ordemCrescente(int num1, int num2, int num3){

  if (num1 < num2 && num2 < num3){

    printf("%d %d %d", num1, num2, num3);
  }


  if (num1 < num2 && num2 > num3 && num3 < num1){

    printf("%d %d %d", num3, num1, num2);
  }

  if (num2 < num1 && num1 < num3){

    printf("%d %d %d", num2, num1, num3);

  }



  if (num3 < num2 && num2 < num1){

    printf("%d %d %d", num3, num2, num1);

  }





}

int main (){

  int num1, num2, num3;

  scanf("%d",&num1);
  scanf("%d",&num2);
  scanf("%d",&num3);
  ordemCrescente(num1,num2,num3);

return 0;
} */

//----------------------------------------------------------------------------------------------//

// Questão 2 //

/* 2. Faça uma função que recebe um valor inteiro e retorna -1 caso o valor seja
negativo, 1 caso seja positivo e 0 caso seja nulo. Crie um programa para testar
sua função.

#include <stdio.h>

int VerificarValor(int numero) {

  if (numero < 0) {

    return -1;
  }

  if (numero > 0) {

    return 1;
  }

  if (numero == 0){

    return 0;
  }
}

int main() {
  int x, resposta;

  scanf("%d", &x);

  resposta = VerificarValor(x);
  printf("%d", resposta);
  return 0;
} */

//----------------------------------------------------------------------------------------------//

// Questão 5 //

/* 5. Escreva uma função que recebe um número inteiro e retorna o fatorial deste
número. Crie um programa paratestar sua função.

#include <stdio.h>

int Fatorial(int numero) {
  if (numero == 0 || numero == 1) {
    return 1; // Caso base: o fatorial de 0 e 1 é 1
  } else {
    return numero * Fatorial(numero - 1);
  }
}

int main() {

  int x, resposta;

  scanf("%d", &x);

  resposta = Fatorial(x);

  printf("%d", resposta);

  return 0;
} */

//--------------------------------------------------------------------------------------------------//

// Questão 6 //

/* 6. Escreva uma função que recebe um valor inteiro e positivo N e retorna o
valor de S, sendo S calculado segundo a fórmula abaixo. Crie um programa que lê
N e imprime o valor retornado pela função.

S = 1 + 1/1! + 1/2! + 1/3! + ...+1 /N!

#include <stdio.h>

float Fatorial(int numero){

  int fatorial;

  if (numero == 1 || numero == 0){

    return 1;

  } else{

  fatorial = numero * Fatorial(numero-1);

  return fatorial;

  }
}

float CalcularExpressao(int numero){

  float S = 1;

  for(int i = 1; i<= numero; i++){

    S = S + 1/Fatorial(i);

  }

  return S;
}


int main(){

  int x;
  float resposta;

  scanf("%d", &x);

  resposta = CalcularExpressao(x);
  printf("%f", resposta);

  return 0;
} */

// ------------------------------------------------------------------------------------------------------------//

// Questão 7//

/* 7. Escreva uma função que recebe por parâmetro um valor inteiro e positivo N
e retorna o valor de S, calculando-o segundo a fórmula abaixo. S = 2/4 + 5/5 +
10/6 + 17/7 + 26/8 + ... +(n2+1)/(n+3)

 #include <stdio.h>

float CalcularExpressao(int numero) {

  float S = (numero) / (numero);

  S = S + CalcularExpressao((numero + 1) / (numero + 3));

  return S;
}

int main() {

  int N;
  float resposta;

  scanf("%d", &N);

  resposta = CalcularExpressao(N);
  printf("%f", resposta);

  return 0;
} */

// EXERCÍCIOS VERDE //

//--------------------------------------------------------------------------------------------//

//  Lista Funções Ex. 3 //

/* Escreva um procedimento que recebe 3 valores reais X, Y e Z correspondentes
ao lado de um triângulo e exibe qual o tipo de triângulo (equilátero, isósceles,
escaleno), caso o triângulo seja válido.

Para que X, Y e Z formem um triângulo, é necessário que cada lado do triângulo
seja menor do que a soma dos outros dois lados. Caso o triângulo seja inválido,
o procedimento deve imprimir “Triangulo invalido”.

Faça um programa que lê triângulos (isto é, os lados do triângulo) e, para cada
triângulo, aciona o procedimento. A entrada de dados é finalizada quando
informado o valor -1.

Formato da entrada: conjunto de linhas, onde cada linha traz os lados de um
triângulo separados por espaço, sendo a última linha com -1.



Formato da saída: conjunto de linhas, cada linha com a classificação do
triângulo correspondente: “equilátero”, “isósceles” ou “escaleno”.

 #include <stdio.h>
#include <stdlib.h>
void FormarTriangulo(float lado1, float lado2,float lado3) {

  if (lado1 >= lado2 + lado3 || lado2 >= lado1 + lado3 ||
      lado3 >= lado1 + lado2) {

    printf("Triangulo invalido\n");

  } else {

    if (lado1 == lado2 && lado1 == lado3 && lado2 == lado3) {

      printf("equilatero\n");
    }

    if (lado1 == lado2 && lado3 != lado1 || lado2 == lado3 && lado2 != lado1 ||
        lado3 == lado1 && lado3 != lado2) {

      printf("isoceles\n");
    }

    if (lado1 != lado2 && lado1 != lado3 && lado2 != lado3) {

      printf("escaleno\n");
    }
  }
}

int main() {

  float x, y, z, aux = 1;

  while (aux != -1) {
    scanf("%f", &x);
    if (x == -1) {
      exit(0);
    } else {
      scanf("%f", &y);
      scanf("%f", &z);
      FormarTriangulo(x, y, z);
    }
  }
} */

//-----------------------------------------------------------------------------------------//

// Lista Funções. Ex4 //

/* Faça um procedimento que recebe a nota de um aluno, identifica e exibe o seu
conceito, conforme a tabela abaixo.

Faça um programa que lê a média de N alunos, acionando o procedimento para
cada um deles. N é fornecido pelo usuário.


Nota	Conceito
Até 39	F
40 a 59	E
60 a 69	D
70 a 79	C
80 a 89	B
a partir de 90	A


Formato da entrada: primeira linha contém N, próximas N linhas contendo a nota
de cada aluno.

Formato da saída: N linhas com o conceito de cada aluno

#include <stdio.h>

void verificarNota(int numAlunos) {

  float nota;

  // preenchendo as notas //

  for (int i = 0; i < numAlunos; i++) {

    scanf("%f", &nota);

    if (nota <= 39 && nota >= 0) {

      printf("F\n");
    }

    if (nota >= 40 && nota <= 59) {

      printf("E\n");
    }

    if (nota >= 60 && nota <= 69) {

      printf("D\n");
    }

    if (nota >= 70 && nota <= 79) {

      printf("C\n");
    }

    if (nota >= 80 && nota <= 89) {

      printf("B\n");
    }

    if (nota >= 90) {

      printf("A\n");
    }
  }
};

int main() {

  int alunos;

  scanf("%d", &alunos);
  verificarNota(alunos);

  return 0;
} */

// ---------------------------------------------------------------------------------------------
// //

// Lista de Funções Ex. 8 //

/* 8. [V] Faça uma função que calcula e retorna a nota final de um aluno. Para
isso, a função recebe as 3 notas do aluno e uma letra. Se a letra for ‘A’, a
nota final do aluno é calculada como a média aritmética das notas; se for ‘P’, a
nota final é a média ponderada das notas, considerando pesos iguais a 5, 3 e 2.
Faça um programa que lê as 3 notas de N alunos e o tipo de média a ser
utilizada. Armazene as notas em uma matriz. O programa deve imprimir as três
notas e a nota final de cada aluno. Para a nota final, o programa deve acionar a
função criada. N deve ser informado pelo usuário. Formato da entrada: primeira
linha contém N e o tipo de média, próximas N linhas contêm as 3 notas de cada
aluno por linha. Formato da saída: N linhas, cada linha contendo as três notas e
a nota final de um aluno. */

#include <stdio.h>
#include <stdlib.h>

float calcularMedia(float nota1, float nota2, float nota3, char tipo) {

  float media;

  if (tipo == 'A') {

    media = (double)(nota1 + nota2 + nota3) / 3;
    return media;
  }

  if (tipo == 'P') {

    media = (double)(nota1 * 5 + nota2 * 3 + nota3 * 2) / 10;

    return media;
  }

  return 0;
}

int main() {

  float nota1, nota2, nota3;
  int alunos;
  char tipo;

  scanf("%d %c", &alunos, &tipo);

  float matriz[alunos][4];

  for (int i = 0; i < alunos; i++) {

    scanf("%f %f %f", &nota1, &nota2, &nota3);

    for (int j = 0; j < 4; j++) {

      if (j == 0) {

        matriz[i][j] = nota1;
      }

      if (j == 1) {

        matriz[i][j] = nota2;
      }

      if (j == 2) {

        matriz[i][j] = nota3;
      }

      if (j == 3) {

        matriz[i][j] = calcularMedia(nota1, nota2, nota3, tipo);
      }
    }
  }

  for (int i = 0; i < alunos; i++) {

    for (int j = 0; j < 4; j++) {

      printf("%.2f ", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}

// -----------------------------------------------------------------------------------------------------//

// Lista de Funções Ex. 9 //

/* A prefeitura de uma cidade fez uma pesquisa entre os seus habitantes,
coletando dados sobre o salário e número de dependentes dos adultos. Crie uma
função que recebe o salário e a quantidade de dependentes de cada adulto da
cidade e retorna a renda per capita da população. Use o seguinte protótipo para
sua função:

double calcularRendaPerCapita(int n, double salarios[], int dependentes[]);

onde n é o total de adultos, salarios guarda os salarios de cada um dos adultos,
e dependentes guarda o número de dependentes de cada um dos adultos. Crie um
programa para ler os dados (total de adultos, salários e quantidades de
dependentes por adulto), chamar a função e imprimir a renda per capita.

Formato da entrada: primeira linha contém a quantidade de adultos n, próximas n
linhas contêm o salário de cada adulto, próximas n linhas contêm o número de
dependentes de cada adulto.

Formato da saída: única linha contendo a renda per capita da cidade com 2 casas
decimais. */
