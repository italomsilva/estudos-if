#include "matriz.h"
#include <stdlib.h>

Matriz *mat_cria(int m, int n)
{
    Matriz *stmat = (Matriz *)malloc(sizeof(Matriz));
    float **matriz = (float **)malloc(m * sizeof(float *));
    for (int i = 0; i < m; i++)
        matriz[i] = (float *)malloc(n * sizeof(float));
    if (stmat != NULL || stmat != NULL)
    {
        stmat->linhas = m;
        stmat->colunas = n;
        stmat->valores = matriz;
    }
    return stmat;
}
void mat_libera(Matriz *m){
    for (int i = 0; i < m->linhas; i++)
    {
        free(m->valores[i]);
    }
    free(m->valores);
    free(m);
}
float mat_acessa(Matriz *mat, int i, int j){
    return mat->valores[i][j];
}
void mat_atribui(Matriz *mat, int i, int j, float v){
    mat->valores[i][j] = v;
}
int mat_linhas(Matriz *mat){
    return mat->linhas;
}
int mat_colunas(Matriz *mat){
    return mat->colunas;
}
