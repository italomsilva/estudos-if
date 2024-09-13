#include <stdio.h>
#include <stdlib.h>

int main() {
    int base;
    printf("digite o tamanho da base");
    scanf("%d",&base);
    int** mat = (int**)malloc(base*sizeof(int*));
    for (int m = 0; m < base; m++)
    {
        mat[m]= (int*)malloc(base*sizeof(int));
    }
    
    for (int i = 0; i < base; i++)
    {
        for (int j = 0; j < base; j++)
        {
            if (j<=i)
            {
                printf("*\t");
            }
        }
        printf("\n");
    }
    
    return 0;
}