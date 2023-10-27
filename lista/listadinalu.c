#include <stdio.h>
#include "listadinalu.h"

void cria(ListaAluno *la){
  la->inicio = NULL;
} 

int tamanho(ListaAluno *la){
  int tam = 0;
  No *aux = la->inicio;
  while (aux!=NULL){
    tam++;
    aux=aux->prox;
  }
  return tam;
}

int vazia(ListaAluno *la){
    if(la->inicio == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int buscaPosMat(ListaAluno *la, int mat, int *pos){
  *pos = 0;
  No *aux = la->inicio;
  while (aux!=NULL){
    if (aux->dado.matricula == mat){
      return pos;
    }
    *pos++;
    aux=aux->prox;
  }
  return -1;
}

int buscaAlunoPos(ListaAluno *la, int pos, Aluno al){
  No *aux = la->inicio;
  int i = 0;
  while (aux!=NULL && i < pos){
    
  if(i == pos){
    return (aux->dado.nome);
  }
    i++;
    aux=aux->prox;
  }
  return -1;
}

int insereFinal(ListaAluno *la, Aluno al){
  No *novo = (No*) malloc(sizeof(No));
  if (novo == NULL){
    return 0;
  }
  //1o caso
  if (vazia(la)){
      novo->dado = al;
      novo->prox = NULL;
      la->inicio = novo;
  }
  //2o caso
  No* aux=la->inicio;
  while(aux->prox!=NULL){
    aux = aux->prox;
  }
  aux->prox = novo;
  novo->dado = al;
  novo->prox = NULL;
  return 1;
  }

int removeAlunoMat(ListaAluno *la, int mat){
  if (vazia(la)){
    return 0;
  }




