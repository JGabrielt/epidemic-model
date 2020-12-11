#include <stdio.h>
#include <stdlib.h>

#ifndef PROCESSOR_H
#define PROCESSOR_H

    //typedef declaration
    typedef struct{
        double *S, *I, *R, *tempo, b, h, k;
    } Dados;

    Dados* inicializarDados(int duracao, double h); //Aloca o espaço para o dados

    void simulacaoSIR(Dados* d1, Dados* d2, Dados* d3); //Calcula e guarda os dados nos vetores em 3 cenarios diferentes, gerando 3 arquivos de saida .csv

    double* entradaParametros(); //Recebe os parametros de um arquivo .csv

    void escreverDados(Dados* d1, Dados* d2, Dados* d3, int duracao); //Escreve os dados das 3 simulações em 3 arquivos .csv


#endif //PROCESSOR_H_INCLUDED