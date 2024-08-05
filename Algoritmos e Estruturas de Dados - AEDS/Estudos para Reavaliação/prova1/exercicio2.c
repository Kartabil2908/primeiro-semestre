#include <stdio.h>
#include <math.h>
int main(){

    int numero;
    int resposta;
    scanf("%d", numero);

    if(numero > -3 && numero != -7){

        resposta = pow(numero,3);

    }

    if(numero == -3){

        resposta = -10;

    }

    if(numero <= -7 && numero != -3){

        resposta = 5 * numero + 20;

    }


    printf("%d", resposta);


    return 0;
}
