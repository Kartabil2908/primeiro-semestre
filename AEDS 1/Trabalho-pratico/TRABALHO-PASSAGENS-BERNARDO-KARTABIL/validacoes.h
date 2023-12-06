#ifndef VALIDACOES_H
#define VALIDACOES_H

#include <ctype.h>
#include "Passagem.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ---------------------- VALIDAR DATA ----------------------------------------- //

bool validarData(int dia, int mes, int ano)
{
    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
    {
        diasNoMes[2] = 29;  // Ano bissexto, fevereiro tem 29 dias
    }

    if (mes < 1 || mes > 12 || dia < 1 || dia > diasNoMes[mes])
    {
        return false;
    }

    return true;
}

// ---------------------- VALIDAR DATA ----------------------------------------- //

// ---------------------- VALIDAR HORÁRIO ----------------------------------------- //

bool validarHorario(int horas, int minutos)
{
    // Verifica se as horas e minutos estão dentro dos limites válidos
    if (horas < 0 || horas > 23 || minutos < 0 || minutos > 59)
    {
        return false;
    }

    return true;
}

// ---------------------- VALIDAR HORÁRIO ----------------------------------------- //

// ---------------------- VALIDAR CÓDIGO AEROPORTO ----------------------------------------- //

bool validarCodigoAeroporto(const char *codigo)
{
    // Verifica se o código tem exatamente 3 letras
    if (strlen(codigo) != 3)
    {
        return false;
    }
    else
    {

        return true;
    }
}

// ---------------------- VALIDAR CÓDIGO AEROPORTO ----------------------------------------- //

// ---------------------- CORRIGIR CÓDIGO AEROPORTO ----------------------------------------- //

void corrigirCodigoAeroporto(char *codigo)
{
    // Converte todas as letras do código para maiúsculas
    for (int i = 0; i < 3; ++i)
    {
        codigo[i] = toupper(codigo[i]);
    }
}

// ---------------------- CORRIGIR CÓDIGO AEROPORTO ----------------------------------------- //

#endif // VALIDACOES_H
