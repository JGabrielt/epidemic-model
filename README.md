# epidemic-model
Final project of the discipline Introduction to Programming Techniques

## Struct
`` 
typedef struct
{
    double S, I, R, tempo, b, h, k;
} Dado;
``

## Alocação
Em cima dos números de dias será alocado o tamanho
``
Dado* criarDado(double tempo)
{
    Dado* dado = malloc(sizeof(Dado));
    dado->tempo = tempo; 
    return dado;
}
``

## Functions

### Facilidade de contágio
Inputs:
output:

`` 
double facilidadeDeContagio(int N_b, int T_b, int S_b, int I_b) 
{ 
    return (N_b / ((double)(T_b * S_b * I_b)));
} 
``

### Probabilidade de cura

``
double probabilidadeDeCura(int m_k, int n_k, int T_k) 
{ 
    return (m_k / ((double)(n_k * T_k)));
}
``
### Calculo de Suceptível

``
double calcSuscetivel(Dado* d)
{
    double oldS, oldI;
    oldS = d->S;
    oldI = d->I;
    return (oldS - (d->h * d->b * oldS * oldI));
}
``
### Infectado
``
double calcInfectado(Dado* d)
{
    double oldS, oldI;
    oldS = d->S;
    oldI = d->I;
    return (oldI + (d->h * ((d->b * oldS * oldI) - (d->k * oldI))));
}
``

## Crescimento

temos uma função onde aproveita os dados que vai crescendo

``
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
``