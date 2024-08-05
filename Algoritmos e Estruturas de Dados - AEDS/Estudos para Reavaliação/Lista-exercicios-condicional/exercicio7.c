#include <stdio.h>

float mediaPonderada(float [], int[], int);


int main(){

    float notas[3];
    int pesos[3];
    float media;
    for(int i = 0; i < 3; i++){

     scanf("%f", &notas[i]);

    }

    for(int i = 0; i < 3; i++){

        scanf("%d", &pesos[i]);

    }

    media = mediaPonderada(notas, pesos, 3);

    if( media < 4){

     puts("Reprovado");


    }


    if( media >=4 && media < 7){

        puts("Exame Especial");

    }

    if ( media >= 7 && media<=10){

        puts("Aprovado");


    }

return 0;
}

float mediaPonderada( float notas[], int pesos[], int tamanho){

    float mediaP;

    mediaP = (notas[0]*pesos[0] + notas[1]*pesos[1] + notas[2]*pesos[2])/(pesos[0] + pesos[1] + pesos[2]);

    return mediaP;

}
