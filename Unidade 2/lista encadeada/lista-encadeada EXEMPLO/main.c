#include <stdio.h>
#include "listase.h"

int main(void) {
  Lista l;

  cria(&l);
  inserir(&l, 20);
  inserir(&l, 12);
  inserir(&l, 11);
  inserir(&l, 21);
  inserir(&l, 30);

  exibir(&l);
  printf("\nTamanho:%d", tamanho(&l));
  printf("\nBusca (20):%d", busca(&l,20));
  printf("\nBusca (21):%d", busca(&l,21));
  printf("\nBusca (7):%d", busca(&l,7));

  printf("\nRemovendo 20...");
  remover(&l, 20);
  exibir(&l);

  printf("\nRemovendo 11...");
  remover(&l, 11);
  exibir(&l);

  printf("\nRemovendo 30...");
  remover(&l, 30);
  exibir(&l);

  printf("\nRemovendo 30...");
  remover(&l, 30);
  exibir(&l);  
  return 0;
}