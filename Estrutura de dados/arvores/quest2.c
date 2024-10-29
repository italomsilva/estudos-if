#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arv
{
    char info;
    struct arv *esq;
    struct arv *dir;
} Arv;

int indice(char *in, int in_inicio, int in_fim, char c)
{
    for (int i = in_inicio; i <= in_fim; i++)
    {
        if (in[i] == c)
            return i;
    }
    return -1;
}

Arv *ins_arv(char* pre, char* in, int *pre_indice, int in_inicio, int in_fim)
{
    if (in_inicio > in_fim)
    {
        return NULL;
    }
    char info_raiz = pre[*pre_indice];
    (*pre_indice)++;

    Arv *raiz = (Arv *)malloc(sizeof(Arv));
    raiz->info = info_raiz;
    raiz->esq = raiz->dir = NULL;

    if (in_inicio == in_fim)
    {
        return raiz;
    }
    int in_indice = indice(in, in_inicio, in_fim, info_raiz);
    raiz->esq = ins_arv(pre, in, pre_indice, in_inicio, in_indice - 1);
    raiz->dir = ins_arv(pre, in, pre_indice, in_indice + 1, in_fim);
    return raiz;
}

void impr_pos(Arv *a)
{
    if (a != NULL)
    {
        impr_pos(a->esq);
        impr_pos(a->dir);
        printf("%c", a->info);
    }
}


int main()
{
    char pre[27], in[27];

    while (scanf("%s %s", pre, in) != EOF)
    {
        int pre_indice = 0;
        int len = strlen(in);

        Arv *raiz = ins_arv(pre, in, &pre_indice, 0, len - 1);

        impr_pos(raiz);
        printf("\n");


        for (int i = 0; i < len; i++)
        {
            pre[i] = '\0';
            in[i] = '\0';
        }     
    }

    return 0;
}
