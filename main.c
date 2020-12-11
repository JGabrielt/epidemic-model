#include "processor.h"
 
int main(void) {
    Dados* d;
    int cenario;
    printf("Hello, welcome, select a scenario to model:\n");
    printf("1: Nothing is done\n");
    printf("2: Distancing and wear masks\n");
    printf("3: Improvement in service protocols\n");
    printf("input example: 1\n");
    scanf("%d", &cenario);
    simulacaoSIR(d, cenario);
 
    return 0;
}