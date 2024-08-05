#include <stdio.h>




int main(){

    int maior = 0, N, posimaior = 0;

    scanf("%d", &N);

    int vetor[N];

    for(int i = 0; i < N; i++){

        scanf("%d", &vetor[i]);

        if(vetor[i] > maior){

            maior = vetor[i];
            posimaior = i;

        }

        if(vetor[i] == maior && i > posimaior){

            maior = vetor[i];
            posimaior = i;

        }

    }

    printf("%d %d", maior, posimaior);


return 0;
}


