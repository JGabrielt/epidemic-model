#include <stdio.h>
#include <stdlib.h>

#ifndef PROCESSOR_H
#define PROCESSOR_H

    //typedef declaration
    typedef struct{
        double *S, *I, *R, *tempo;
    } Dados;

    Dados* inicializarDados(int duracao, double h); //Aloca o espaço para o dados

    void SIR(Dados* d); //Calcula e guarda os dados nos vetores

    double* entradaParametros(); //Recebe os parametros de um arquivo .csv

    void escreverDados(Dados* d, int duracao); //Escreve os dados num arquivo .csv


#endif //PROCESSOR_H_INCLUDED