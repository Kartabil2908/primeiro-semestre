#include <stdio.h>
#include <stdlib.h>

void preencherVetor(int*, int*);

int main(){

    int numero;
    int *ptr;
    int *ptr2;
    scanf("%d", &numero);

    ptr = malloc(numero * sizeof(int));




    return 0;
}


void preencherVetor(int *ptr, int *ptr2){



    for(ptr2 = *ptr; ptr2 < ptr; ptr2++){


     scanf("%d", *ptr2);

    }



}
