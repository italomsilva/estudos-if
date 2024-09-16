#include <stdio.h>
#include <stdlib.h>
typedef struct lista
{
    int data;
    struct lista *prox;
} Lista;

typedef struct lista *PLista;

// 1 - Implemente funções para inserir, remover e buscar elementos na lista.*/
PLista lista_insere(PLista lista, int info)
{
    PLista novoItem = (PLista)malloc(sizeof(Lista));
    novoItem->prox = lista;
    novoItem->data = info;
    return novoItem;
}

PLista lista_remove(PLista lista, int info)
{
    if (lista == NULL)
    {
        printf("Lista vazia");
        return lista;
    }
    PLista temp = lista;
    PLista anterior = NULL;
    while (temp != NULL && temp->data != info)
    {
        anterior = temp;
        temp = temp->prox;
    }
    if (temp == NULL)
    {
        printf("Não encontrado");
        return lista;
    }

    if (anterior == NULL)
    {
        lista = lista->prox;
    }
    else
    {
        anterior->prox = temp->prox;
    }
    free(temp);
    return lista;
}

PLista lista_busca(PLista lista, int info)
{
    if (lista == NULL)
    {
        printf("lista vazia.");
        return NULL;
    }
    PLista temp = lista;
    while (temp != NULL && temp->data != info)
    {
        temp = temp->prox;
    }
    return temp;
}

//  2 - Crie uma função que retorne o ponteiro para o último nó de uma lista encadeada.
PLista ultimo(PLista lista)
{
    if (lista == NULL)
    {
        printf("lista vazia.");
        return NULL;
    }

    PLista temp = lista;
    while (temp->prox != NULL)
    {
        temp = temp->prox;
    }
    return temp;
}

// 3 - Dadas duas listas encadeadas, crie uma função que una as duas em uma única lista.
PLista concatena (PLista lista1, PLista lista2){
    if (lista1==NULL)
    {
        return lista2;
    }
    if (lista2 == NULL)
    {
        return lista1;
    }
    PLista temp=lista1;
    while (temp->prox!=NULL)
    {
        temp=temp->prox;
    }
    temp->prox=lista2;
    return lista1;
}