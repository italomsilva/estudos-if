#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

Pilha *p_cria(){
   Pilha* p = (Pilha*)malloc(sizeof(Pilha));
   p->topo=NULL;
   return p;
}
void p_push(Pilha* p,char *val, int tam){
    Prato* novoPrato = (Prato*)malloc(sizeof(Prato));
    for (int i = 0; i < tam; i++)
    {
        novoPrato->url[i]=val[i];
    }
    novoPrato->prox=p->topo;
    p->topo=novoPrato;
}
char *p_pop(Pilha *p){
    Prato* temp;
    char* result;
    if(p->topo==NULL) printf("Pilha vazia");
    temp=p->topo;
    result=temp->url;
    p->topo= temp->prox;
    free(temp);
    return result;
}
void p_free(Pilha* p){
    Prato* prato=p->topo;
    while (prato!=NULL)
    {
        Prato* prox = prato->prox;
        free(prato);
        prato=prox;
    }
    free(p);
}
int p_vazia(Pilha* p){
    return (p->topo==NULL);
}
