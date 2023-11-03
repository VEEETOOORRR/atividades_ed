#include <stdio.h>
#include <stdlib.h>
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

int buscaPosMat(ListaAluno *la, int mat){
  int pos = 0;
  No *aux = la->inicio;
  while (aux!=NULL){
    if (aux->dado.matricula == mat){
      return pos;
    }
    pos++;
    aux=aux->prox;
  }
  return -1;
}

int buscaAlunoPos(ListaAluno *la, int pos){
  No *aux = la->inicio;
  int i = 0;
  while (aux!=NULL || i < pos){

    i++;
    aux=aux->prox;
  }
  if(i == pos){
    
    for(int j=0;aux->dado.nome[j] != '\0';j++){
    printf("%c",aux->dado.nome[j]);
  }
  return -1;
}
}

int insereFinal(ListaAluno *la, Aluno al){
  No *novo = (No*) malloc(sizeof(No));
  if (novo == NULL){
    return 0;
  }
  //1o caso: Lista vazia
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
  if (vazia(la))
    return 0;

  int pos=buscaPosMat(la, mat);
  if (pos == -1)
    return 0;

  if (pos == 0){
    No *temp = la->inicio;
    la->inicio = la->inicio->prox;
    free(temp);
    return 1;
  }

  No *aux = la->inicio;
  for (int i=0; i<pos-1; i++){
    aux = aux->prox;
  }
  No *temp = aux->prox;
  aux->prox = aux->prox->prox;
  free(temp);
  return 1;
    
}

int exibirAlunos(ListaAluno *la) {
    No *atual = la->inicio;
    while (atual != NULL) {
        printf("Matrícula: %d\n", atual->dado.matricula);
        printf("Nome: %s\n", atual->dado.nome);
        printf("Nota 1: %.2f\n", atual->dado.nota1);
        printf("Nota 2: %.2f\n", atual->dado.nota2);
        printf("\n");
        atual = atual->prox;
    }
}

