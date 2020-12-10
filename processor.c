#include "processor.h"

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