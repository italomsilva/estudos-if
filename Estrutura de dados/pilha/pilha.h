#ifndef pilha_h
#define pilha_h
typedef struct prato
{
    char url[100];
    struct prato *prox;
} Prato;

typedef struct pilha
{
    struct prato *topo;
} Pilha;

Pilha *p_cria();
void p_push(Pilha* p,char *val, int tam);
char *p_pop(Pilha *p);
void p_free(Pilha* p);
int p_vazia(Pilha* p);

#include "pilha.c"
#endif