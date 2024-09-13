#include <stdio.h>
#include <stdlib.h>

void swap(float *a, float *b)
{
    float temp = *b;
    *b = *a;
    *a = temp;
}
void ordena_vetor(float *vetor, int n, char ordem)
{
    switch (ordem)
    {
    case 'c':
        // crescente
        for (int i = 1; i < n; i++)
        {
            if (vetor[i-1] > vetor[i])
            {
                swap(&vetor[i-1], &vetor[i]);
                i=0;
            }
        }
        break;
    case 'd':
        // decrescente
        for (int i = 1; i < n; i++)
        {
            if (vetor[i - 1] < vetor[i])
            {
                swap(&vetor[i-1], &vetor[i]);
                i=0;
            }
        }
        break;
    default:
        break;
    }
}

int main()
{
    float vetor[8] = {3.5, 7.2, 1.8, 9.6, 4.4, 2.3, 8.9, 6.1}; 
    ordena_vetor(vetor, 8, 'c');

    printf("Vetor:\n");
    for (int i = 0; i < 8; i++) {
        printf("%f\n", vetor[i]);
    }
    return 0;
}
