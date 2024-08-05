#include <stdio.h>

void VerificarSitu(float);

int main(){

    float peso;

    float altura;

    scanf("%f", &peso);
    scanf("%f", &altura);

    float IMC = peso/(altura*altura);

    VerificarSitu(IMC);



    return 0;
}


