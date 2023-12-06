#ifndef EDITARPASSAGEM_H
#define EDITARPASSAGEM_H

#include <stdio.h>
#include <stdlib.h>

void NovaPassagem(FILE*, int);

void editarPassagem(){
FILE *arquivo, *novoArquivo;
char linha[80];
int IdUser, IdLinha, qtd, lastId, cont = 0;



printf("Digite o id da passagem: "); // Pedindo o id que o usuário quer editar
scanf("%d", &IdUser);

arquivo = fopen("Passagens.txt", "r"); // abrindo arquivo original para leitura
novoArquivo = fopen("Temporario.txt", "w");// abrindo arquivo temporário para escrita


//---- PRINTANDO A PRIMEIRA E SEGUNDA LINHA NO ARQUIVO TEMPORÁRIO ----------- //

fscanf(arquivo,"%d", &qtd);
fprintf(novoArquivo,"%d\n", qtd);
fscanf(arquivo,"%d", &lastId);
fprintf(novoArquivo,"%d\n", lastId);

//----- PRINTANDO A PRIMEIRA E SEGUNDA LINHA NO ARQUIVO TEMPORÁRIO --------- //




//-------------------------------------- EDITANDO PASSAGEM -------------------------------------------- //


// Loop para percorrer o arquivo original e editar a passagem desejada
while(fscanf(arquivo, " %[^\n]", linha) != EOF){
    sscanf(linha ,"%d", &IdLinha);

    if(IdLinha == IdUser ){
        NovaPassagem(novoArquivo, IdLinha); // Chama a função NovaPassagem para editar os detalhes da passagem no arquivo temporário
    }
    else{
        fprintf(novoArquivo, "%s\n", linha); // Se não for a passagem desejada, copia a linha para o arquivo temporário
    }


    cont++;
}

fclose(arquivo);
fclose(novoArquivo);


// Reabre os arquivos para copiar o conteúdo do temporário de volta para o original

arquivo = fopen("Passagens.txt", "w");
novoArquivo = fopen("Temporario.txt", "r");

// Copia o conteúdo do arquivo temporário de volta para o arquivo original

while(fscanf(novoArquivo, " %[^\n]", linha) != EOF){
    fprintf(arquivo,"%s\n", linha);

}

fclose(arquivo);
fclose(novoArquivo);
}

//-------------------------------------- EDITANDO PASSAGEM -------------------------------------------- //

void NovaPassagem(FILE *novoArquivo, int IdLinha){

    Passagem pass;

//-------------------------------------- CÓDIGO DO AEROPORTO ORIGEM -------------------------------------------- //

    do
    {
        printf("Digite o codigo do aeroporto de origem (3 letras maiúsculas):\n");
        scanf(" %[^\n]", pass.aeroportoOrigem);
        fflush(stdin);

        corrigirCodigoAeroporto(pass.aeroportoOrigem); // Corrigir código para letras maiúsculas //

        if (!validarCodigoAeroporto(pass.aeroportoOrigem))
        {
            printf("Código de aeroporto inválido. Por favor, insira um código válido.\n");
        }



    }while (!validarCodigoAeroporto(pass.aeroportoOrigem));

//-------------------------------------- CÓDIGO DO AEROPORTO ORIGEM -------------------------------------------- //

//-------------------------------------- CÓDIGO DO AEROPORTO DESTINO -------------------------------------------- //

    do
    {
        printf("Digite o codigo do aeroporto de destino (3 letras maiúsculas):\n");
        scanf(" %[^\n]", pass.aeroportoDestino);
        fflush(stdin);

        corrigirCodigoAeroporto(pass.aeroportoDestino);

        if (!validarCodigoAeroporto(pass.aeroportoDestino))
        {
            printf("Código de aeroporto inválido. Por favor, insira um código válido.\n");
        }

    }
    while (!validarCodigoAeroporto(pass.aeroportoDestino));

//-------------------------------------- CÓDIGO DO AEROPORTO DESTINO -------------------------------------------- //

//-------------------------------------- CIDADE ORIGEM E DESTINO -------------------------------------------- //

    printf("Digite a cidade de origem:\n");
    scanf(" %[^\n]", pass.cidadeOrigem);
    fflush(stdin);
    printf("Digite a cidade de destino:\n");
    scanf(" %[^\n]", pass.cidadeDestino);
    fflush(stdin);

//-------------------------------------- CIDADE ORIGEM E DESTINO -------------------------------------------- //

//-------------------------------------------------------- DATA -------------------------------------------- //

    do
    {
        printf("Digite o dia do seu voo:\n");
        scanf(" %d", &pass.data.dia);
        fflush(stdin);
        printf("Digite o mes do seu voo:\n");
        scanf("%d", &pass.data.mes);
        fflush(stdin);
        printf("Digite o ano do seu voo (4 dígitos):\n");
        scanf("%d", &pass.data.ano);
        fflush(stdin);

        if (!validarData(pass.data.dia, pass.data.mes, pass.data.ano))
        {
            printf("Data inválida. Por favor, insira uma data válida.\n");
        }

    }
    while (!validarData(pass.data.dia, pass.data.mes, pass.data.ano) || pass.data.ano < 1000 || pass.data.ano > 9999);

//------------------------------------------------------- DATA -------------------------------------------- //


//----------------------------------------------- HORARIO SAÍDA -------------------------------------------- //

    do
    {
        printf("Digite o hora de saida do seu voo:\n");
        scanf("%d", &pass.horarioSaida.horas);
        fflush(stdin);
        printf("Digite o minuto de saida do seu voo:\n");
        scanf("%d", &pass.horarioSaida.minutos);
        fflush(stdin);

        if (!validarHorario(pass.horarioSaida.horas, pass.horarioSaida.minutos))
        {
            printf("Horário de saída inválido. Por favor, insira um horário válido.\n");
        }

    }
    while (!validarHorario(pass.horarioSaida.horas, pass.horarioSaida.minutos));

//----------------------------------------------- HORARIO SAÍDA -------------------------------------------- //

//----------------------------------------------- HORARIO CHEGADA -------------------------------------------- //

    do
    {
        printf("Digite o hora de chegada do seu voo:\n");
        scanf("%d", &pass.horarioChegada.horas);
        fflush(stdin);
        printf("Digite o minuto de chegada do seu voo:\n");
        scanf("%d", &pass.horarioChegada.minutos);
        fflush(stdin);

        if (!validarHorario(pass.horarioChegada.horas, pass.horarioChegada.minutos))
        {
            printf("Horário de chegada inválido. Por favor, insira um horário válido.\n");
        }

    }
    while (!validarHorario(pass.horarioChegada.horas, pass.horarioChegada.minutos));

//----------------------------------------------- HORARIO CHEGADA -------------------------------------------- //

    do{

    printf("Digite o preco da sua passagem:\n");
    scanf("%f", &pass.preco);
    fflush(stdin);


    }while(pass.preco <= 0);

//----------------------------------------------- PRINTANDO A PASSAGEM -------------------------------------------- //




    fprintf(novoArquivo,"%d;", IdLinha);
    fprintf(novoArquivo,"%s;", pass.aeroportoOrigem);
    fprintf(novoArquivo, "%s;", pass.aeroportoDestino);
    fprintf(novoArquivo, "%s;", pass.cidadeOrigem);
    fprintf(novoArquivo, "%s;", pass.cidadeDestino);
    fprintf(novoArquivo, "%02d/%02d/%04d;", pass.data.dia, pass.data.mes, pass.data.ano);
    fprintf(novoArquivo, "%02d:%02d;", pass.horarioSaida.horas, pass.horarioSaida.minutos);
    fprintf(novoArquivo, "%02d:%02d;", pass.horarioChegada.horas, pass.horarioChegada.minutos);
    fprintf(novoArquivo, "%.2f\n", pass.preco);


}

#endif
