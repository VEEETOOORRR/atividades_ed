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
  while (aux!=NULL){
    if (aux->dado.nome == mat){
      return pos;
    }
    *pos++;
    aux=aux->prox;
  }
  return -1;
}

// Consertar esse acima

