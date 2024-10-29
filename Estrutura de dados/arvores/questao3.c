#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arv
{
    char info;
    struct arv *esq;
    struct arv *dir;
} Arv;

Arv *inserir(char c, Arv *a)
{
    if (a == NULL)
    {
        Arv *novo = (Arv *)malloc(sizeof(Arv));
        novo->esq = novo->dir = NULL;
        novo->info = c;
        return novo;
    }

    if (c < (a->info))
    {
        a->esq = inserir(c, a->esq);
    }
    else
    {
        a->dir = inserir(c, a->dir);
    }

    return a;
}

void in(Arv *a, int *primeiro)
{
    if (a != NULL)
    {
        in(a->esq, primeiro);
        if (*primeiro == 0)
        {
            printf(" %c", a->info);
        }
        else
        {
            printf("%c", a->info);
            *primeiro = 0;
        }
        in(a->dir, primeiro);
    }
}

void pre(Arv* a, int* primeiro)
{
    if (a!=NULL)
    {
        if (*primeiro==0)
        {
            printf(" %c", a->info);
        } else {
            printf("%c", a->info);
            *primeiro=0;
        }
        pre(a->esq, primeiro);
        pre(a->dir, primeiro);  
    }
    
}

void pos(Arv* a, int* primeiro){
    if (a!=NULL)
    {
        pos(a->esq, primeiro);
        pos(a->dir, primeiro);
        if (*primeiro==0)
        {
            printf(" %c", a->info);
        } else {
            printf("%c", a->info);
            *primeiro=0;
        }
    }
    
}

int busca(Arv* a, char c){
    if (a!=NULL)
    {
        if (a->info==c) return 1;
        else if(a->info>c) return busca(a->esq, c);
        else if(a->info<c) return busca(a->dir, c);
        else return 0;      
    } else return 0;
    
}

int main()
{
    char comando[8], info;
    Arv *a = NULL;
    int primeiro;
    while (scanf("%s", comando) != EOF)
    {
        primeiro = 1;
        if (strcmp(comando, "I") == 0)
        {
            scanf(" %c", &info);
            a = inserir(info, a);
        }
        else if (strcmp(comando, "INFIXA") == 0)
        {
            in(a, &primeiro);
            printf("\n");
        }
        else if (strcmp(comando, "PREFIXA") == 0)
        {
            pre(a,&primeiro);
            printf("\n");
        }
        else if (strcmp(comando, "POSFIXA") == 0)
        {
            pos(a,&primeiro);
            printf("\n");
        }
        else if (strcmp(comando, "P") == 0)
        {
            scanf(" %c", &info);
            (busca(a, info)? printf("%c existe\n", info): printf("%c nao existe\n", info));

        }
        for (int i = 0; i < 8; i++)
        {
            comando[i] = '\0';
        }
        info = '\0';
    }

    return 0;
}