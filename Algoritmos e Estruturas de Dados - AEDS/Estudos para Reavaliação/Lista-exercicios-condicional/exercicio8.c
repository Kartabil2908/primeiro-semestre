#include <stdio.h>

float calcularAumento(float, float);

int main(){

    int opcao;
    float salario;
    float resposta;

    puts("Digite o código do funcionário");
    scanf("%d", &opcao);

    puts("Digite o salário do funcionário");
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
            printf("O salário de Diretor não teve aumento");
            break;

        default:
            puts("opção inválida");

    }




    }



 float calcularAumento(float salario,float porcentagem){

  salario = salario + (salario * (porcentagem/100))


 }




