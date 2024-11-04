#include <stdio.h>
#include <stdlib.h>

typedef struct arv
{
    int valor;
    struct arv *esq;
    struct arv *dir;
} Arv;

typedef struct noFila
{
    Arv *noArv;
    struct noFila *prox;
} NoFila;

typedef struct Fila
{
    NoFila *inicio;
    NoFila *fim;
} Fila;

Arv *criar_noArv(int valor)
{
    Arv *a = (Arv *)malloc(sizeof(Arv));
    a->valor = valor;
    a->esq = a->dir = NULL;
    return a;
}

Arv *ins(Arv *raiz, int valor)
{
    if (raiz == NULL)
        return criar_noArv(valor);
    if (valor < (raiz->valor))
        raiz->esq = ins(raiz->esq, valor);
    else
        raiz->dir = ins(raiz->dir, valor);
    return raiz;
}

Fila *criar_fila()
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = fila->fim = NULL;
    return fila;
}

int fila_vazia(Fila *fila)
{
    return fila->inicio == NULL;
}

void enfileirar(Fila *fila, Arv *no)
{
    NoFila *novoNoFila = (NoFila *)malloc(sizeof(NoFila));
    novoNoFila->noArv = no;
    novoNoFila->prox = NULL;

    if (fila->fim != NULL)
    {
        fila->fim->prox = novoNoFila;
    }
    else
    {
        fila->inicio = novoNoFila;
    }
    fila->fim = novoNoFila;
}

Arv *desenfileirar(Fila *fila)
{
    if (fila_vazia(fila))
        return NULL;

    NoFila *temp = fila->inicio;
    Arv *noArvore = temp->noArv;
    fila->inicio = temp->prox;

    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }

    free(temp);
    return noArvore;
}

void percurso_nivel(Arv *raiz)
{
    if (raiz != NULL)
    {
        Fila *fila = criar_fila();
        enfileirar(fila, raiz);

        while (!fila_vazia(fila))
        {
            Arv *atual = desenfileirar(fila);
            printf("%d", atual->valor);

            if (atual->esq != NULL)
                enfileirar(fila, atual->esq);
            if (atual->dir != NULL)
                enfileirar(fila, atual->dir);

            if (!fila_vazia(fila))
                printf(" ");
        }
    }
}

int main()
{
    int casos;
    scanf("%d", &casos);

    for (int i = 1; i <= casos; i++)
    {
        int quantidade;
        scanf("%d", &quantidade);

        Arv *raiz = NULL;

        for (int j = 0; j < quantidade; j++)
        {
            int valor;
            scanf("%d", &valor);
            raiz = ins(raiz, valor);
        }
        printf("Case %d:\n", i);
        percurso_nivel(raiz);
        printf("\n\n");
    }

    return 0;
}
