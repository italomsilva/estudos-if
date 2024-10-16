#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "arvores_avl.h"

int main(){
  setlocale (LC_ALL, "portuguese");

  int opc;
  char val;
  Arv*a=NULL;
  while (1) {
    printf ("Linguagem de Programação I (Exemplos).\n");
    printf ("Árvore Binária de Busca.\n");
    printf ("No exemplo a informação é apenas um caractere.\n");
    printf ("(1)inserir (2)remover (3)imprimir (0) sair --> ");
    scanf("%d",&opc );
    switch (opc) {
      case 0:
        break;
      case 1:
        printf("Caractere: ");
        scanf(" %c",&val);
        a=ins_abb(val,a);
        break;
      case 2:
        printf("Caractere: ");
        scanf(" %c",&val);
        a=remover(val,a);
        break;
      case 3:
        printf("\npre: "); impr_pre(a);
        printf("\nord: "); impr_ord(a);
        printf("\npos: "); impr_pos(a);
        printf ("\n");
        break;
      default:
        printf("Opção inválida\n");
        break;
      }
    if(opc==0) break;
  }

  return 0;
}