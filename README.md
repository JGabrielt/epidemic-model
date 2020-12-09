# Modelo epidemiológicos / Epidemic model
Projeto final da disciplina de Introdução as técnicas de programação. 

/ 

Final project of the discipline Introduction to Programming Techniques.

### Checkpoints
#### Checkpoint 1
- [x] Implementação do modelo com entrada e saída no terminal.
- [x] Formato de dados do arquivo csv de configuração e leitura do arquivo de configuração.
- [x] Saída de dados no arquivo de csv (+25% do checkpoint)

### Propósito / Purpose
São utilizados para a compreensão da dinâmica de uma epidemia ou afim, e são,portanto,ferramentas essenciais na determinação de políticas públicas para combate e prevenção de doenças 

/ 

They are used to understand the dynamics of an epidemic or the like, and are therefore essential tools in determining public policies for combating and preventing diseases

### Modo de Uso / Way of using
Primeiro de tudo, devemos compilar os arquivos que serão utilizados, para isso rode no terminal o comando.

/


First of all, we must compile the files that will be used, for that run the command in the terminal.

`` 
gcc main.c -o epidemic
``

O próximo passo é executar o binário fruto da compilação.

/ 


The next step is to run the compilation binary.

`` 
./epidemic
``



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