#include <stdio.h>
#include "fila.c"

void enter() {
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n'); // Limpa o buffer de entrada.
    getchar(); // Aguarda a entrada do usuário.
}

int prompt(Fila *f){
  int opcao;
  printf("\nFILA DE PESSOAS");
  printf("\n---------------------");
  printf("\n1 - Exibir a Fila");
  printf("\n2 - Entrar na Fila");
  printf("\n3 - Sair da Fila");
  printf("\n4 - Primeiro da Fila");
  printf("\n5 - Quantidade de Pessoas na Fila");
  printf("\n6 - Sair");
  printf("\n\nDigite a opção: ");

  scanf("%d",&opcao);

  if(opcao == 1){
    exibir(f);
  }

  if(opcao == 2){

  }

  if(opcao == 3){

  }

  if(opcao == 4){

  }

  if(opcao == 5){

  }

  if(opcao == 6){
    return 0;
  }

  enter();
  return 1;

}
int main() {
  Fila fila;
  criar(&fila);
  int i = prompt(&fila);

  while(i==1){
    int i = prompt(&fila);
  }
}