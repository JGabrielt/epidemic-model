#include "processor.h"
 
int main(void) {
    Dados* d;
    int cenario;
    printf("Hello, welcome, select a scenario to model:\n");
    printf("1° Scenario: Nothing is done\n");
    printf("2° Scenario: Distancing and wear masks\n");
    printf("3° Scenario: Improvement in service protocols\n");
    scanf("%d", &cenario);
    simulacaoSIR(d, cenario);
 
    return 0;
}