#include <stdio.h>
#include <stdlib.h>

float **criaMatriz(int linhas, int colunas)
{
    float **matriz = (float **)malloc(linhas * sizeof(float *));
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (float *)malloc(colunas * sizeof(float));
    }

    return matriz;
}

void preencheMatriz(float **mat, int l, int c, float n)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mat[i][j] = n * (i + 1) + j;
        }
    }
}

void mostraMatriz(float **mat, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%.2f\t", mat[i][j]);
        }
        printf("\n");
    }
}

void multMatriz(float **matA, int n, int m, float **matB, int o, int p)
{
    if (m != o)
    {
        printf("não pode mult");
    }

    float **matRes = criaMatriz(n, p);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < m; k++)
            {
                matRes[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
    mostraMatriz(matRes, n, p);
    for (int i = 0; i < 5; i++)
    {
        free(matRes[i]);
    }
}

int main()
{
    float **matA = criaMatriz(5, 4);
    float **matB = criaMatriz(4, 2);
    preencheMatriz(matA, 5, 4, 5.0);
    preencheMatriz(matB, 4, 2, 3.0);
    printf("Primeira matriz\n");
    mostraMatriz(matA, 5, 4);
    printf("\nSegunda matriz\n");
    mostraMatriz(matB, 4, 2);
    printf("\nMatriz Resutante\n");
    multMatriz(matA, 5, 4, matB, 4, 2);
    for (int i = 0; i < 5; i++)
    {
        free(matA[i]);
        free(matB[i]);
    }

    return 0;
}