#include <stdio.h>
#include "ponto.h"

int main() {
    Ponto* p1 = pto_cria(2.0, 3.0);
    Ponto* p2 = pto_cria(5.0, 7.0);

    float distancia = pto_distancia(p1, p2);
    printf("Distância entre os pontos: %.2f\n", distancia);

    pto_libera(p1);
    pto_libera(p2);

    return 0;
}
