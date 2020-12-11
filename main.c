#include "processor.h"
 
int main(void) {
    Dados *d1, *d2, *d3;
    printf("Hello, welcome, select a scenario to model:\n");
    printf("1° Scenario: Nothing is done\n");
    printf("2° Scenario: Distancing and wear masks\n");
    printf("3° Scenario: Improvement in service protocols\n");
    printf("4° Scenario: Distancing, wear masks and improvment in service protocols\n");
    simulacaoSIR(d1, d2, d3);
 
    return 0;
}