#include <stdio.h>
#include <stdlib.h>

typedef struct arv
{
    int info;
    struct arv *dir;
    struct arv *esq;
} Arv;
typedef Arv *Parv;
Parv ins(Parv a, int n)
{
    if (a == NULL)
    {
        Parv novo = (Parv)malloc(sizeof(Arv));
        novo->info = n;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (n < (a->info))
    {
        a->esq = ins(a->esq, n);
    }
    else
    {
        a->dir = ins(a->dir, n);
    }
    return a;
};

int main()
{
    int C;
    do
    {
        scanf("%d", &C);
    } while (C > 1000);

    for (int i = 1; i <= C; i++)
    {
        int N;
        do
        {
            scanf("%d", &N);
        } while (C<1 || C > 1000);

        printf("Case %d:\n", i);
        int vetor[N];
        for (int j = 0; j < N; j++)
        {
            vetor[j]=-1;
            while (vetor[j]<0)
            {
                scanf("%d", &vetor[j]);
                for (int k = 0; k < j; k++)
                {
                    if (vetor[j]==vetor[k])
                    {
                        vetor[j]=-1;
                    }
                    
                }
            }
            
            
        }
        
    }

    return 0;
}