#include <stdio.h>
#include <math.h>

int main(){

    int vetor[100];


    for(int i = 0; i < 100; i++){

        vetor[i] = i++;


    }



    for(int i = 0;i < 100; i++){

        if (i%2 == 0){

            vetor[i] = pow(vetor[i],2);

        }

        if(i%2 != 0){

            vetor[i] = pow(vetor[i],3);

        }

    }

    for(int i = 0; i < 100; i++){

        printf("%d", vetor[i]);

    }

    return 0;
}
