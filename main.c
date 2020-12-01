#include <stdio.h>
#include <stdlib.h>
 
typedef struct
{
    double S, I, R, tempo, b, h, k;
} Dado;
 
Dado* criarDado(double tempo)
{
    Dado* dado = malloc(sizeof(Dado));
    dado->tempo = tempo; 
    return dado;
}
 
//Facilidade de contagio == b
double facilidadeDeContagio(int N_b, int T_b, int S_b, int I_b) 
{ 
    return (N_b / ((double)(T_b * S_b * I_b)));
} 
 
//Probabilidade de cura == k
double probabilidadeDeCura(int m_k, int n_k, int T_k) 
{ 
    return (m_k / ((double)(n_k * T_k)));
}
 
double calcSuscetivel(Dado* d)
{
    double oldS, oldI;
    oldS = d->S;
    oldI = d->I;
    return (oldS - (d->h * d->b * oldS * oldI));
}
 
double calcInfectado(Dado* d)
{
    double oldS, oldI;
    oldS = d->S;
    oldI = d->I;
    return (oldI + (d->h * ((d->b * oldS * oldI) - (d->k * oldI))));
}
 
double calcRemovido(Dado* d)
{
    double oldR, oldI;
    oldR = d->R;
    oldI = d->I;
    return (oldR + (d->h * d->k * oldI));
}
 
void calcDado(Dado* d)
{
    Dado* novoDado = criarDado(d->tempo + d->h);
    novoDado->S = calcSuscetivel(d);
    novoDado->I = calcInfectado(d);
    novoDado->R = calcRemovido(d);
    d->S = novoDado->S;
    d->I = novoDado->I;
    d->R = novoDado->R;
    d->tempo = novoDado->tempo; 
}
 
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