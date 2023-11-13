#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

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

int primeiro(Fila *f){
  if (!vazia(f))
    return f->inicio->pac;
  return -1;
}

Paciente ultimo(Fila *f){
  if (!vazia(f))
    return f->fim->pac;
  return -1;
}

int entrar(Fila *f, int elem){
  No* novo = (No*) malloc(sizeof(No));

  if (novo == NULL)
    return 0;
  
  novo->dado = elem;
  novo->prox = NULL;

  //1o caso: Fila vazia
  if(vazia(f)){
    f->inicio = f->fim = novo;
    f->tamanho++;
    return 1;
  }

  //2o caso: Fila nao vazia
  f->fim->prox = novo;
  f->fim = novo;
  f->tamanho++;
  return 1;
  
}

int sair(Fila *f){
  if(vazia(f))
    return 0;

  No* temp = f->inicio;
  int retorno = f->inicio->dado;
  f->inicio = f->inicio->prox;
  free(temp);
  f->tamanho--;
  return retorno;
  
}

void exibir(Fila *f) {
  No *aux;
  printf("[ ");
  for (aux = f->inicio; aux != NULL; aux = aux->prox) {
    printf("%d ", aux->dado);
  }
  printf("]");

}