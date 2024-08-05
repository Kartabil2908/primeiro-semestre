#include <stdio.h>

float calcularMedia(float [], int);
void verificarSitu(float);

int main(void){

        float notas[3];
        float resposta;

        for(int i = 0; i < 3; i++)
        {
            scanf("%f", &notas[i]);
        }

        resposta = calcularMedia(notas, 3);

        verificarSitu(resposta);




return 0;
}

float calcularMedia(float notas[], int n){

 float resposta;

 resposta = (notas[0] + notas[1] + notas[2])/3;

    return resposta;
}

void verificarSitu(float media){

    if(media < 4){

        printf("Reprovado");

    }

    if ( media < 7 && media >= 4){

        printf("Exame especial");

    }

    if(media <=10 && media >= 7){

     printf("Aprovado");

    }





}
