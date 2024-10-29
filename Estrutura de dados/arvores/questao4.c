#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arv
{
    int info;
    struct arv *esq;
    struct arv *dir;
} Arv;

Arv *inserir(int c, Arv *a)
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
            printf(" %d", a->info);
        }
        else
        {
            printf("%d", a->info);
            *primeiro = 0;
        }
        in(a->dir, primeiro);
    }
}

void pre(Arv *a, int *primeiro)
{
    if (a != NULL)
    {
        if (*primeiro == 0)
        {
            printf(" %d", a->info);
        }
        else
        {
            printf("%d", a->info);
            *primeiro = 0;
        }
        pre(a->esq, primeiro);
        pre(a->dir, primeiro);
    }
}

void pos(Arv *a, int *primeiro)
{
    if (a != NULL)
    {
        pos(a->esq, primeiro);
        pos(a->dir, primeiro);
        if (*primeiro == 0)
        {
            printf(" %d", a->info);
        }
        else
        {
            printf("%d", a->info);
            *primeiro = 0;
        }
    }
}

int busca(Arv *a, int c)
{
    if (a != NULL)
    {
        if (a->info == c)
            return 1;
        else if (a->info > c)
            return busca(a->esq, c);
        else if (a->info < c)
            return busca(a->dir, c);
        else
            return 0;
    }
    else
        return 0;
}

Arv *remover(int c, Arv*raiz){
  if (raiz == NULL)
    return NULL;
  else
  if (raiz->info > c) //elemento está a esquerda
    raiz->esq = remover(c,raiz->esq);
  else
  if (raiz->info < c) //elemento está a direita
      raiz->dir = remover(c,raiz->dir);
  else{               //se chegou aqui, encontrou o elemento
  if (raiz->esq == NULL && raiz->dir == NULL) { //nó sem filhos
    free (raiz);
    raiz = NULL;
    }
  else
  if (raiz->esq == NULL) {//apenas filho a direita
    Arv*aux = raiz;
    raiz = raiz->dir;
    free (aux);
    }
  else
  if (raiz->dir == NULL) { //apenas filho a esquerda
    Arv*aux = raiz;
    raiz = raiz->esq;
    free (aux);
  }
  else{ //se chgou aqui, tem dois filhos
    Arv*aux = raiz->esq; //desce um nível a esquerda
    while (aux->dir != NULL) {  //busca último elemento a direita
      aux = aux->dir;
    }
    raiz->info = aux->info; //troca as informações
    aux->info = c;
    raiz->esq = remover(c,raiz->esq);//remove c, a partir da esquerda da raiz original
    }
  }
  return raiz;
}


int main()
{
    char comando[8];
    Arv *a = NULL;
    int primeiro, info;
    while (scanf("%s", comando) != EOF)
    {
        primeiro = 1;
        if (strcmp(comando, "I") == 0)
        {
            scanf(" %d", &info);
            a = inserir(info, a);
        }
        else if (strcmp(comando, "INFIXA") == 0)
        {
            in(a, &primeiro);
            printf("\n");
        }
        else if (strcmp(comando, "PREFIXA") == 0)
        {
            pre(a, &primeiro);
            printf("\n");
        }
        else if (strcmp(comando, "POSFIXA") == 0)
        {
            pos(a, &primeiro);
            printf("\n");
        }
        else if (strcmp(comando, "P") == 0)
        {
            scanf(" %d", &info);
            (busca(a, info) ? printf("%d existe\n", info) : printf("%d nao existe\n", info));
        }
        else if (strcmp(comando, "R") == 0)
        {
            scanf(" %d", &info);
            a=remover(info, a);
        }

        for (int i = 0; i < 8; i++)
        {
            comando[i] = '\0';
        }
    }

    return 0;
}
