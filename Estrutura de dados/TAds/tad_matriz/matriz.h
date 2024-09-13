#ifndef matriz_h
#define matriz_h

typedef struct matriz
{
    int linhas;
    int colunas;
    float** valores;
} Matriz;


Matriz* mat_cria(int m, int n);
void mat_libera(Matriz* m);
float mat_acessa(Matriz* mat, int i, int j);
void mat_atribui(Matriz* mat, int i, int j, float v);
int mat_linhas(Matriz* mat);
int mat_colunas(Matriz* mat);

#include "matriz.c"
#endif