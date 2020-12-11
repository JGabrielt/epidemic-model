#include "processor.h"

Dados* inicializarDados(int duracao, double h)
{
    Dados* d = malloc(sizeof(Dados));
    d->S = malloc(sizeof(double) * (duracao / h));
    d->I = malloc(sizeof(double) * (duracao / h));
    d->R = malloc(sizeof(double) * (duracao / h));
    d->tempo = malloc(sizeof(double) * (duracao / h));
    d->mortes = malloc(sizeof(double) * (duracao / h));
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

void escreverDados(Dados* d, int duracao)
{
    int i = 0;
    FILE* saida = fopen("saida.csv", "w");
    while(d->tempo[i] <= duracao)
    {
        fprintf(saida, "%lf, %lf, %lf, %lf\n", d->S[i], d->I[i], d->R[i], d->tempo[i]);
        i++;
    }
    fclose(saida);
}

void simulacaoSIR(Dados* d, int cenario)
{
    int i = 0;
    double b, k, duracao;
    double* p = malloc(sizeof(double) * 12);
    p = entradaParametros();  
    duracao = p[11] * 24;
    
    d = inicializarDados(duracao, p[3]);
    d->S[i] = p[0];
    d->I[i] = p[1];
    d->R[i] = p[2];
    d->tempo[i] = 0.0;
    d->mortes[i] = 0.0;

    //Constantes: Facilidade de contagio == b e Probabilidade de cura == k
    b = (p[4] / ((double)(p[5] * p[6] * p[7])));
    k = (p[8] / ((double)(p[9] * p[10])));

    int t = 96 / p[3];
    while(d->tempo[i] <= duracao) // !!! Não imprime o ultimo instante !!!
    {
        i++;
        if(cenario == 2 && i == t) //Cenario 2: T_b(p[5]) aumenta após 4 dias, soma-se 24h ao tempo de contaminação T_b
        {
            b = (p[4] / ((double)((p[5] + 24) * p[6] * p[7]))); //Cenario 3: T_k(p[10]) diminui após 4 dias, redução de 12h ao tempo de recuperação T_k
        }
        else if(cenario == 3 && i == t)
        {
            k = (p[8] / ((double)(p[9] * (p[10] - 8))));
        }
        double oldS = d->S[i-1], oldI = d->I[i-1], oldR = d->R[i-1];
        d->S[i] = (oldS - (p[3] * b * oldS * oldI));
        d->I[i] = (oldI + (p[3] * ((b * oldS * oldI) - (k * oldI))));
        d->R[i] = (oldR + (p[3] * k * oldI));
        d->tempo[i] = d->tempo[i-1] + p[3];
        d->mortes[i] = 0.02 * d->R[i];
    }    
    escreverDados(d, duracao);
}
