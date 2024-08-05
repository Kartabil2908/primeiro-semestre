#include <stdio.h>

int main(){

    float S = 0;
    int N;

    scanf("%d", &N);


    for(int i = 0; i< N; i++){

        S = i/(N-i+1) + S;

    }


    printf("%f", S);

    return 0;
}
