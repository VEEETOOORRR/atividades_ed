#include <stdio.h>
#include "fila.c"

void enter() {
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n'); // Limpa o buffer de entrada.
    getchar(); // Aguarda a entrada do usuário.
}

int prompt(Fila *pe, Fila *pa, Fila *en){
  char opcao;
  printf("\nRESTAURANTE REI DO MOCOTÓ");
  printf("\na) Inserir na fila de pedido");
  printf("\nb) Remover da fila de pedido");
  printf("\nc) Remover da fila de pagamento");
  printf("\nd) Remover da fila de encomenda");
  printf("\nDigite sua opção: ");

  scanf("%c",&opcao);

  if(opcao == 'a'){
    char nome[30];
    printf("\nDigite o nome: ");
    scanf("%s",nome);
    if(entrar(pe, nome) == 1){
      printf("\nCliente adicionado com sucesso!");
    }

    else{
      printf("\nErro ao adicionar cliente.");
    }

  }

  if(opcao == 'b'){
    char temp[30];
    strcpy(temp,pe->inicio->cliente);
    if(remove(&pe)==1){

      if(entrar(pa,temp)==1){
        printf("\nCliente removido da Fila de Pedidos com sucesso!");
      }
      else{
        printf("\nErro ao remanejar cliente para a Fila de Pagamentos.");
      }
    }
    else{
      printf("\nErro ao remover cliente da Fila de Pedidos.");
    }

  }

  if(opcao == 'c'){
    char temp[30];
    strcpy(temp,pa->inicio->cliente);
    if(remove(&pa)==1){

      if(entrar(en,temp)==1){
        printf("\nCliente removido da Fila de Pedidos com sucesso!");
      }
      else{
        printf("\nErro ao remanejar cliente para a Fila de Pagamentos.");
      }
    }
    else{
      printf("\nErro ao remover cliente da Fila de Pedidos.");
    }

  }

  if(opcao == 'd'){
    char temp[30];
    strcpy(temp,pa->inicio->cliente);
    if(remove(&pa)==1){

      if(entrar(en,temp)==1){
        printf("\nCliente removido da Fila de Pedidos com sucesso!");
      }
      else{
        printf("\nErro ao remanejar cliente para a Fila de Pagamentos.");
      }
    }
    else{
      printf("\nErro ao remover cliente da Fila de Pedidos.");
    }

  }

  // OPÇÕES EXTRAS!!

  if(opcao == 'e'){
    printf("\n");
    exibir(pe);
    printf("\n");
    exibir(pa);
    printf("\n");
    exibir(en);
  }
  enter();
  return 1;
}

int main(){
  Fila pedido, pagamento, encomenda;

  criar(&pedido);
  criar(&pagamento);
  criar(&encomenda);

  int i = prompt(&pedido, &pagamento, &encomenda);
  while(i == 1){
    int i = prompt(&pedido, &pagamento, &encomenda);
  }

  return 0;
}