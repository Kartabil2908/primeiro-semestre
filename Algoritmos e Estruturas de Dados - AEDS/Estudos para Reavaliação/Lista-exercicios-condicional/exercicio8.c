#include <stdio.h>

float calcularAumento(float, float);

int main(){

    int opcao;
    float salario;
    float resposta;

    puts("Digite o c�digo do funcion�rio");
    scanf("%d", &opcao);

    puts("Digite o sal�rio do funcion�rio");
    scanf("%f", &salario);

    switch (opcao){

        case 1:
            resposta = calcularAumento(salario, 50);
            break;

        case 2:
            resposta = calcularAumento(salario,35);
            break;
        case 3:
            resposta = calcularAumento(salario,20);
            break;

        case 4:
            resposta = calcularAumento(salario,10);
            break;

        case 4:
            printf("O sal�rio de Diretor n�o teve aumento");
            break;

        default:
            puts("op��o inv�lida");

    }




    }



 float calcularAumento(float salario,float porcentagem){

  salario = salario + (salario * (porcentagem/100))


 }




