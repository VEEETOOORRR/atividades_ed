
#include "fila.h"

Paciente erro = {-1,"",-1,-1};

void criar(Fila *f){
  f->inicio = f->fim = NULL;
  f->tamanho = 0;
}

int vazia(Fila *f){
  return (f->inicio == NULL && f->fim == NULL);
}

int tamanho(Fila *f){
   return f->tamanho;
}

Paciente primeiro(Fila *f){
  if (!vazia(f))
    return f->inicio->pac;
  return erro;
}

Paciente ultimo(Fila *f){
  if (!vazia(f))
    return f->fim->pac;
  return erro;
}

int entrar(Fila *f, Paciente elem) {
  No* novo = (No*) malloc(sizeof(No));

  if (novo == NULL)
    return 0;

  novo->pac = elem;
  novo->prox = NULL;

  // 1o caso: Fila vazia
  if(vazia(f)) {
    f->inicio = f->fim = novo;
    f->tamanho++;
    return 1;
  }

  // 2o caso: Fila não vazia e gestante
  if(novo->pac.gestante == 1) {
    novo->prox = f->inicio;
    f->inicio = novo;
    f->tamanho++;
    return 1;
  }

  // 3o caso: Fila não vazia e idoso
  if(novo->pac.idade >= 65) {
    No *aux = f->inicio;
    No *anterior = NULL;

    while (aux != NULL && aux->pac.gestante == 1) {
      anterior = aux;
      aux = aux->prox;
    }

    if (anterior == NULL) {
      novo->prox = f->inicio;
      f->inicio = novo;
    }
    else {
      anterior->prox = novo;
      novo->prox = aux;
    }

    if (aux == NULL) {
      f->fim = novo;
    }

    f->tamanho++;
    return 1;
  }

  // 4o caso: Fila não vazia, não gestante e não idoso
  f->fim->prox = novo;
  f->fim = novo;
  f->tamanho++;
  return 1;
}


Paciente sair(Fila *f){
  if(vazia(f))
    return erro;

  No* temp = f->inicio;
  Paciente retorno = f->inicio->pac;
  f->inicio = f->inicio->prox;
  free(temp);
  f->tamanho = f->tamanho-1;
  return retorno;
  
}

void exibir(Fila *f) {
  No *aux;
  printf("[ ");
  for (aux = f->inicio; aux != NULL; aux = aux->prox) {
    printf("\nCPF: %d", aux->pac.cpf);
    printf("\nNome: %s", aux->pac.nome);
    printf("\nIdade: %d", aux->pac.idade);
    printf("\nGestante: %d\n", aux->pac.gestante);
  }
  printf("\n]");

}