#include "circle.h"
#include "../tad_ponto/ponto.h"
#include <stdlib.h>

Circle *circ_cria(float x, float y, float r)
{
    Circle *c = (Circle *)malloc(sizeof(Circle));
    Ponto *p = pto_cria(x, y);
    if (c != NULL && p != NULL)
    {
        c->raio = r;
        c->centro = p;
    };
}
void circ_libera(Circle *c)
{
    free(c->centro);
    free(c);
}
float circ_area(Circle *c)
{
    float rquad = (c->raio) * (c->raio);
    return 3.1415 * rquad;
}
float circ_interior(Circle *c, Ponto *p)
{
    float dist = pto_distancia(c->centro, p);
    return (dist <= c->raio ? 1 : 0);
}
