#ifndef circle_h
#define circle_h
#include "../tad_ponto/ponto.h"
typedef struct circle
{
    float raio;
    Ponto* centro;
}Circle;

Circle* circ_cria(float x, float y, float r);
void circ_libera(Circle* c);
float circ_area(Circle* c);
float circ_interior(Circle* c, Ponto* p);


#include "circle.c"
#endif