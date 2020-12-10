#include <stdio.h>
#include <stdlib.h>
#include "processor.h"
 
typedef struct
{
    double S, I, R, tempo, b, h, k;
} Dado;
 
int main(void) {
    Dado* d = criarDado(0);
 
    double N_b, T_b, S_b, I_b, m_k, n_k, T_k;
    int dias;
    FILE* input_data = fopen("entrada.csv", "r");
    //scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d", &d->S, &d->I, &d->R, &d->h, &N_b, &T_b, &S_b, &I_b, &m_k, &n_k, &T_k, &dias); Entrada de dados separados por virgula pelo terminal
    fscanf(input_data,"%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d", &d->S, &d->I, &d->R, &d->h, &N_b, &T_b, &S_b, &I_b, &m_k, &n_k, &T_k, &dias); //Entrada de dados num arquivo csv, separadas por virgula
    fclose(input_data);
    int duracao = dias * 24;
 
    d->b = facilidadeDeContagio(N_b, T_b, S_b, I_b);
    d->k = probabilidadeDeCura(m_k, n_k, T_k);
 
    FILE* saida = fopen("saida.csv", "w");
    while(d->tempo <= duracao)
    {
        printf("%lf, %lf, %lf, %lf\n", d->S, d->I, d->R, d->tempo); //Saida no terminal
        fprintf(saida, "%lf, %lf, %lf, %lf\n", d->S, d->I, d->R, d->tempo); //Escrita no arquivo saida.csv 
        calcDado(d);
    }
    printf("%lf, %lf, %lf, %lf\n", d->S, d->I, d->R, d->tempo); 
    fprintf(saida, "%lf, %lf, %lf, %lf\n", d->S, d->I, d->R, d->tempo); //Ultimo valor não estava sendo impresso
 
    return 0;
}