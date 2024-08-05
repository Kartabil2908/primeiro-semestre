#include <stdio.h>


int funcao(int, int, int);

int main(){
    int soma = 0;
    int x, n;
    int resposta;

    scanf("%d %d", &x, &n);

    resposta = funcao(x,n,soma);

printf("%d", resposta);

    return 0;
}



int funcao(int x,int n,int soma){


    for(int i = 0; i < n; i++){

     soma = soma + funcao(n,0,0);

    }

    return soma;

}






