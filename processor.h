#ifdef PROCESSOR_H_INCLUDED
#define PROCESSOR_H_INCLUDED

    Dado* criarDado(double tempo); //Cria o dado

    double facilidadeDeContagio(int N_b, int T_b, int S_b, int I_b); // calcula a facilidade de contágio

    void calcDado(Dado* d); // Calcula os dados de transmissão
    
    //typedef declaration
    typedef struct{
        double S, I, R, tempo, b, h, k;
    } dados;


#endif //PROCESSOR_H_INCLUDED