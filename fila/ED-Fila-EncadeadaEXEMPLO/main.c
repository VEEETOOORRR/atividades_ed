#include <stdio.h>
#include "fila.h"

int main(void) {
  Fila f;

  criar(&f);
  entrar(&f, 2);
  entrar(&f, 1);
  entrar(&f, 7);
  entrar(&f, 8);
  
  exibir(&f);
  return 0;
}