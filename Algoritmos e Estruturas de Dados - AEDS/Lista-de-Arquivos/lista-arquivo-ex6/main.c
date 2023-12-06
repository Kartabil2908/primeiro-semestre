/* Faça um programa para inserir N letras informadas pelo usuário em um arquivo texto. Onde N é uma quantidade
de letras definida pelo usuário. Depois de inseridas as N letras, o programa deverá ler todas as N letras do
arquivo, calcular e mostrar a quantidade de vogais, ou seja, quantas letras a, e, i, o, u. */

#include <stdio.h>

int main(){

    int numero;
    FILE *arquivo;

        puts("Digite a quantidade de letras:");
        scanf("%d", &numero);

        char letras[numero];

        for(int i = 0; i < numero;i++){
            scanf(" %c", &letras[i]);

        }


       arquivo = fopen("arquivo1.txt", "w+");

        for(int i = 0; i < numero; i++){
            fputs(letras[i], arquivo);
        }


        fclose(arquivo);






return 0;
}
