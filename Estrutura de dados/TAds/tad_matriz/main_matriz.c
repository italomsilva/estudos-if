#include <stdio.h>
#include "matriz.h"

int main()
{
    Matriz *mat = mat_cria(3, 3);

    for (int i = 0; i < mat_linhas(mat); i++)
    {
        for (int j = 0; j < mat_colunas(mat); j++)
        {
            mat_atribui(mat, i, j, i*5.0+j*2);
        }
        printf("\n");
    }

    for (int i = 0; i < mat_linhas(mat); i++)
    {
        for (int j = 0; j < mat_colunas(mat); j++)
        {
            printf("%.2f ", mat_acessa(mat, i, j));
        }
        printf("\n");
    }

    mat_libera(mat);

    return 0;
}
