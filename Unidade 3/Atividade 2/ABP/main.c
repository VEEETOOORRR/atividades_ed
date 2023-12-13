#include "arv.h"
#include <stdio.h>

int main(void) {
  Arvore arv;
  criar(&arv);
  Arvore arv2;
  criar(&arv2);
  /* inserir(&arv,9);
   inserir(&arv,5);
   inserir(&arv,14);
   inserir(&arv,2);
   inserir(&arv,6);
   inserir(&arv,12);
   inserir(&arv,18);
   inserir(&arv,1);

   inserir(&arv,3);
   inserir(&arv,7);
   inserir(&arv,17);*/

  insere(&arv, 9);
  insere(&arv, 5);
  insere(&arv, 14);
  insere(&arv, 2);
  insere(&arv, 6);
  insere(&arv, 12);
  insere(&arv, 18);
  insere(&arv, 1);

  insere(&arv, 3);
  insere(&arv, 7);
  insere(&arv, 17);

  printf("\nFormato de Arvore: \n");

  // printf("In-ordem: \n");
  exibir(arv.raiz, 0);
  /* printf("Apos remocao: \n");
   remover(&arv,9);
   exibir(arv.raiz, 0);*/

  /*printf("\nFormato de Arvore: \n");
  remover(&arv,9);
  exibir(arv.raiz,0);*/
  return 0;
}