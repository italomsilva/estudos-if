#include <stdio.h>
#include "circle.h"
#include "../tad_ponto/ponto.h"

int main()
{
    Circle *c = circ_cria(0.0, 0.0, 5.0);
    Ponto *p1 = pto_cria(3.0, 1.0);

    if (circ_interior(c, p1)== 1)
    {
        printf("O ponto esta dentro do circulo.\n");
    }
    else
    {
        printf("O ponto esta fora do circulo.\n");
    }
    float area = circ_area(c);
    printf("area do circulo: %.2f\n", area);
    pto_libera(p1);
    circ_libera(c);
    return 0;
}
