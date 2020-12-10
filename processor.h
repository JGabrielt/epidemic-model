#ifndef PROCESSOR_H
#define PROCESSOR_H

    //typedef declaration
    typedef struct{
        double S, I, R, tempo, b, h, k;
    } dados;

    dados* criarDado(double tempo); //Cria o dado

    double facilidadeDeContagio(int N_b, int T_b, int S_b, int I_b); // calcula a facilidade de contágio

    void calcDado(dados* d); // Calcula os dados de transmissão

    


#endif //PROCESSOR_H_INCLUDED