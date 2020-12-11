#include "processor.h"
 
int main(void) {
    Dados* d;
    int cenario;
    printf("Entre numero do cenario desejado: \n");
    scanf("%d", &cenario);
    simulacaoSIR(d, cenario);
 
    return 0;
}