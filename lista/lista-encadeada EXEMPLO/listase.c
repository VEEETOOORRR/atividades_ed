#include <stdio.h>
#include <stdlib.h>
#include "listase.h"

void cria(Lista *l){
  l->inicio = NULL;
}

int vazia(Lista *l){
  if (l->inicio == NULL)
    return 1;
  return 0;
}

int tamanho(Lista *l){
  int tam = 0;
  No *aux = l->inicio;
  while (aux!=NULL){
    tam++;
    aux=aux->prox;
  }
  return tam;
}

int busca(Lista *l, int dado){
  int pos = 0;
  No *aux = l->inicio;
  while (aux!=NULL){
    if (aux->dado == dado){
      return pos;
    }
    pos++;
    aux=aux->prox;
  }
  return -1;
}



int inserir(Lista *l, int dado){
  No *novo = (No*) malloc(sizeof(No));
  if (novo == NULL){
    return 0;
  }
  //1o caso
  if (vazia(l)){
      novo->dado = dado;
      novo->prox = NULL;
      l->inicio = novo;
  }
  //2o caso
  No* aux=l->inicio;
  while(aux->prox!=NULL){
    aux = aux->prox;
  }
  aux->prox = novo;
  novo->dado = dado;
  novo->prox = NULL;
  return 1;
  
}

int remover(Lista *l, int dado){
  if (vazia(l))
    return 0;

  int pos=busca(l,dado);
  if (pos == -1)
    return 0;

  if (pos == 0){
    No *temp = l->inicio;
    l->inicio = l->inicio->prox;
    free(temp);
    return 1;
  }

  No *aux = l->inicio;
  for (int i=0; i<pos-1; i++){
    aux = aux->prox;
  }
  No *temp = aux->prox;
  aux->prox = aux->prox->prox;
  free(temp);
  return 1;
    
}

void exibir(Lista *l){
  printf("\n");
  for (No *aux=l->inicio; aux!=NULL; aux=aux->prox){
    printf("%d ", aux->dado);
  }
  
}