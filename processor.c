#include "processor.h"

Dados* inicializarDados(int duracao, double h)
{
    Dados* d = malloc(sizeof(Dados));
    d->S = malloc(sizeof(double) * (duracao / h));
    d->I = malloc(sizeof(double) * (duracao / h));
    d->R = malloc(sizeof(double) * (duracao / h));
    d->tempo = malloc(sizeof(double) * (duracao / h));
    return d;
}

/*
    Entrada dos parametros por um arquivo "entrada.csv" os parametros estarão dispostos num vetor do tipo double na seguinte ordem:
    [i] == parametro
    [0] == S0, [1] == I0, [2] == R0, [3] == h,
    [4] == N_b, [5] == T_b, [6] == S_b, [7] == I_b
    [8] == m_k, [9] == n_k, [10] == T_k, [11] == dias
*/
double* entradaParametros()
{
    FILE* entrada = fopen("entrada.csv", "r");
    if(entrada == NULL)
    {
        return NULL;
    }
    double* entradaDouble = malloc(sizeof(double) * 12);
    for(int i = 0; i < 12; i++)
    {
        fscanf(entrada, "%lf,", &entradaDouble[i]);
    }
    fclose(entrada);
    return entradaDouble;
}

void escreverDados(Dados* d1, Dados* d2, Dados* d3, int duracao)
{
    int i = 0;
    FILE *saida1 = fopen("saida1.csv", "w"), *saida2 = fopen("saida2.csv", "w"), *saida3 = fopen("saida3.csv", "w");
    while(d1->tempo[i] <= duracao)
    {
        fprintf(saida1, "%lf, %lf, %lf, %lf\n", d1->S[i], d1->I[i], d1->R[i], d1->tempo[i]);
        i++;
    }
    i = 0;
    while(d2->tempo[i] <= duracao)
    {
        fprintf(saida2, "%lf, %lf, %lf, %lf\n", d2->S[i], d2->I[i], d2->R[i], d2->tempo[i]);
        i++;
    }
    i = 0;
    while(d3->tempo[i] <= duracao)
    {
        fprintf(saida3, "%lf, %lf, %lf, %lf\n", d3->S[i], d3->I[i], d3->R[i], d3->tempo[i]);
        i++;
    }
    fclose(saida1);
    fclose(saida2);
    fclose(saida3);
}

void simulacaoSIR(Dados* d1, Dados* d2, Dados* d3)
{
    int i = 0;
    double b, k, duracao;
    double* p = malloc(sizeof(double) * 12);
    p = entradaParametros();  
    duracao = p[11] * 24;
    
    d1 = inicializarDados(duracao, p[3]);
    d2 = inicializarDados(duracao, p[3]);
    d3 = inicializarDados(duracao, p[3]);
    d1->S[i] = p[0];
    d1->I[i] = p[1];
    d1->R[i] = p[2];
    d1->tempo[i] = 0.0;
    d2->S[i] = p[0];
    d2->I[i] = p[1];
    d2->R[i] = p[2];
    d2->tempo[i] = 0.0;
    d3->S[i] = p[0];
    d3->I[i] = p[1];
    d3->R[i] = p[2];
    d3->tempo[i] = 0.0;

    //Constantes: Facilidade de contagio == b e Probabilidade de cura == k
    b = (p[4] / ((double)(p[5] * p[6] * p[7])));
    k = (p[8] / ((double)(p[9] * p[10])));

    //Cenario 1: b e k constantes
    while(d1->tempo[i] <= duracao) // !!! Não imprime o ultimo instante !!!
    {
        i++;
        double oldS = d1->S[i-1], oldI = d1->I[i-1], oldR = d1->R[i-1];
        d1->S[i] = (oldS - (p[3] * b * oldS * oldI));
        d1->I[i] = (oldI + (p[3] * ((b * oldS * oldI) - (k * oldI))));
        d1->R[i] = (oldR + (p[3] * k * oldI));
        d1->tempo[i] = d1->tempo[i-1] + p[3];
    }
    //Cenario 2: T_b(p[5]) aumenta após 5 dias, soma-se 12h ao tempo de contaminação T_b
    i = 0;
    while(d2->tempo[i] <= duracao)
    {
        i++;
        if(d2->tempo[i] == 120)
        {
            b = (p[4] / ((double)((p[5] + 12) * p[6] * p[7])));
        }
        double oldS = d2->S[i-1], oldI = d2->I[i-1], oldR = d2->R[i-1];
        d2->S[i] = (oldS - (p[3] * b * oldS * oldI));
        d2->I[i] = (oldI + (p[3] * ((b * oldS * oldI) - (k * oldI))));
        d2->R[i] = (oldR + (p[3] * k * oldI));
        d2->tempo[i] = d2->tempo[i-1] + p[3];
    }   
    //Cenario 3: T_k(p[10]) diminui após 5 dias, redução de 8h ao tempo de recuperação T_k
    i = 0;
    b = (p[4] / ((double)(p[5] * p[6] * p[7]))); //Valor de b de volta ao original
    while(d3->tempo[i] <= duracao)
    {
        i++;
        if(d3->tempo[i] == 120)
        {
            k = (p[8] / ((double)(p[9] * (p[10] - 8))));
        }
        double oldS = d3->S[i-1], oldI = d3->I[i-1], oldR = d3->R[i-1];
        d3->S[i] = (oldS - (p[3] * b * oldS * oldI));
        d3->I[i] = (oldI + (p[3] * ((b * oldS * oldI) - (k * oldI))));
        d3->R[i] = (oldR + (p[3] * k * oldI));
        d3->tempo[i] = d3->tempo[i-1] + p[3];
    }   

    escreverDados(d1, d2, d3, duracao);
}
