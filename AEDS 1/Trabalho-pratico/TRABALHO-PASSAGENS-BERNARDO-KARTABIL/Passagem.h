#ifndef PASSAGEM_H
#define PASSAGEM_H

typedef struct {
    int dia;
    int mes;
    int ano;
} DATE;

typedef struct {
    int horas;
    int minutos;
} TIME;

typedef struct Passagem {
    int ID;
    char aeroportoOrigem[4];  // 3 letras + \0
    char aeroportoDestino[4];
    char cidadeOrigem[20];
    char cidadeDestino[20];
    DATE data;
    TIME horarioSaida;
    TIME horarioChegada;
    float preco;
} Passagem;

#endif // PASSAGEM_H
