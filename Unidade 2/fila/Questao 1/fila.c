#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

char *primeiro(Fila *f){
  if (!vazia(f))
    return f->inicio->cliente;
  return NULL;
}

char *ultimo(Fila *f){
  if (!vazia(f))
    return f->fim->cliente;
  return NULL;
}

int entrar(Fila *f, char *nome){
  No* novo = (No*) malloc(sizeof(No));

  if (novo == NULL)
    return 0;
  
  strcpy(novo->cliente, nome);
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

char *sair(Fila *f){
  if(vazia(f))
    return NULL;

  No* temp = f->inicio;
  char *retorno = f->inicio->cliente;
  f->inicio = f->inicio->prox;
  free(temp);
  f->tamanho--;
  return retorno;
  
}

void exibir(Fila *f) {
  No *aux;
  printf("[ ");
  for (aux = f->inicio; aux != NULL; aux = aux->prox) {
    printf("%s ", aux->cliente);
  }
  printf("]");

}