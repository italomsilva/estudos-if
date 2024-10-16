#include <stdlib.h>
#include <stdio.h>

typedef struct arv
{
    int info;
    struct arv *esq;
    struct arv *dir;
} Arv;

Arv *ins_abb(int c, Arv *raiz)
{
    if (raiz == NULL)
    {
        Arv *novo = (Arv *)malloc(sizeof(Arv));
        novo->info = c;
        novo->dir = novo->esq = NULL;
        return novo;
    }
    else if (c < raiz->info) // anda a esquerda
        raiz->esq = ins_abb(c, raiz->esq);
    else // anda a direita
        raiz->dir = ins_abb(c, raiz->dir);

    return raiz;
}

void pre(Arv *a)
{
    if (a != NULL)
    {
        printf("%d", a->info);
        if (a->esq != NULL || a->dir != NULL)
            printf(" ");
        pre(a->esq);
        if (a->esq != NULL && a->dir != NULL)
            printf(" ");
        pre(a->dir);
    }
}
void in(Arv *a)
{
    if (a != NULL)
    {
        in(a->esq);
        printf("%d", a->info);
        if (a->dir != NULL)
            printf(" ");
        in(a->dir);
    }
}
void pos(Arv *a)
{
    if (a != NULL)
    {
        pos(a->esq);
        pos(a->dir);
        printf("%d", a->info);
        // verifica se tem a esquerda ou a direita antes
        if (a->dir != NULL || a->esq != NULL)
            printf(" ");
    }
}

int main()
{
    int C, N;
    scanf("%d", &C);
    // verificando quantidade de arvores
    if (C > 1000)
        exit(1);

    // array de arvores
    Arv **floresta = (Arv **)malloc(C * sizeof(Arv *));
    for (int i = 0; i < C; i++)
    {
        floresta[i] = NULL;
    }

    for (int i = 0; i < C; i++)
    {
        printf("\n");
        N = 0;
        // garantindo q N não será negativo e será menor q quinhentos
        while (N < 1 || N > 500)
        {
            scanf("%d", &N);
        }
        int valores[N];
        for (int j = 0; j < N; j++)
        {
            valores[j] = -1;
            // garantindo q o valor lido nao será negativo
            while (valores[j] < 0)
            {
                scanf("%d", &valores[j]);
                // garantindo q o valor lido nao será repetido
                for (int k = 0; k < j; k++)
                {
                    if (valores[j] == valores[k])
                    {
                        valores[j] = -1;
                    } else {
                        break;
                    }
                }
            }
            // inserindo
            floresta[i] = ins_abb(valores[j], floresta[i]);
        }
        printf("Case %d:\n", i + 1);
        printf("Pre.: ");
        pre(floresta[i]);
        printf("\n");
        printf("In..: ");
        in(floresta[i]);
        printf("\n");
        printf("Post: ");
        pos(floresta[i]);
        printf("\n");
    }
}