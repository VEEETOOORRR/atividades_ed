#include "arv.h"
#include <stdio.h>
#include <stdlib.h>

void criar(Arvore *a) { a->raiz = NULL; }

// in-ordem
/*void exibir2(NoArv *r){
  if (r!=NULL){
    exibir2(r->esq);
    printf("%d ",r->dado);
    exibir2(r->dir);
  }
}*/

void exibir(NoArv *r, int n) {
  if (r != NULL) {
    char galho[] = "---";
    exibir(r->esq, n + 1);
    for (int i = 0; i < n; i++) {
      printf("%s", galho);
    }
    printf("%d\n", r->dado);
    exibir(r->dir, n + 1);
  }
}

NoArv *inserir_rec(NoArv *raiz, int dado) {
  if (raiz == NULL) {
    NoArv *novo = (NoArv *)malloc(sizeof(NoArv));
    novo->dado = dado;
    novo->esq = novo->dir = NULL;
    raiz = novo;
  } else {
    if (dado < raiz->dado) {
      raiz->esq = inserir_rec(raiz->esq, dado);
    } else {
      raiz->dir = inserir_rec(raiz->dir, dado);
    }
  }
  return raiz;
}

void insere(Arvore *a, int dado) { a->raiz = inserir_rec(a->raiz, dado); }

int inserir(Arvore *a, int valor) {
  NoArv *novo = malloc(sizeof(NoArv));
  // arvore vazia
  if (novo == NULL)
    return 0;
  novo->dado = valor;
  novo->esq = novo->dir = NULL;
  if (a->raiz == NULL) {
    a->raiz = novo;
    return 1;
  }
  // arvore com elementos
  NoArv *atual = a->raiz;
  NoArv *anterior = NULL;
  while (atual != NULL) {
    anterior = atual;
    if (valor == atual->dado)
      return 0;
    if (valor > atual->dado)
      atual = atual->dir;
    else
      atual = atual->esq;
  }
  // indicando a posicao do novo no
  if (valor > anterior->dado)
    anterior->dir = novo;
  else
    anterior->esq = novo;
  return 1;
}

int busca(NoArv *raiz, int valor) {
  NoArv *atual = raiz;
  while (atual != NULL) {
    if (atual->dado == valor)
      return 1;
    if (valor > atual->dado)
      atual = atual->dir;
    else
      atual = atual->esq;
  }
  return 0;
}

NoArv *sucessor(NoArv *atual) {
  NoArv *pai = atual;

  atual = atual->esq;
  if (atual->dir == NULL) {
    return atual;
  }

  while (atual->dir != NULL) {
    pai = atual;
    atual = atual->dir;
  }

  NoArv *aux = pai->dir;
  pai->dir = NULL;
  return aux;
}

int remover(Arvore *a, int valor) {
  if (busca(a->raiz, valor) == 0)
    return 0;

  // Procura o elemento a ser deletado
  NoArv *atual = a->raiz;
  NoArv *pai = atual;
  while (atual->dado != valor) {
    pai = atual;
    if (valor > atual->dado)
      atual = atual->dir;
    else
      atual = atual->esq;
  }

  // No folha
  if (atual->dir == NULL && atual->esq == NULL) {
    if (atual == a->raiz) {
      free(atual); // raiz
      a->raiz = NULL;
    } else {
      if (pai->dir->dado == valor) {
        free(pai->dir); // free(atual)
        pai->dir = NULL;
      } else {
        free(pai->esq); // free(atual)
        pai->esq = NULL;
      }
    }
    return 1;
  }

  // No so com filho da direita
  if (atual->dir != NULL && atual->esq == NULL) {
    if (atual == a->raiz) {
      a->raiz = atual->dir;
      free(atual);
    } else if (pai->dir->dado == valor) {
      NoArv *temp = pai->dir;
      pai->dir = atual->dir;
      free(temp);
    } else {
      NoArv *temp = pai->esq;
      pai->esq = atual->dir;
      free(temp);
    }
    return 1;
  }

  // No so com filho da esquerda
  if (atual->dir == NULL && atual->esq != NULL) {
    if (atual == a->raiz) {
      a->raiz = atual->esq;
      free(atual);
    } else if (pai->dir->dado == valor) {
      NoArv *temp = pai->dir;
      pai->dir = atual->esq;
      free(temp);
    } else {
      NoArv *temp = pai->dir;
      pai->esq = atual->esq;
      free(temp);
    }

    return 1;
  }

  // No com filho a direita e esquerda
  if (atual->dir != NULL && atual->esq != NULL) {
    NoArv *suc = sucessor(atual);
    if (atual == a->raiz)
      a->raiz = suc;
    else if (pai->dir->dado == valor)
      pai->dir = suc;
    else
      pai->esq = suc;
    suc->dir = atual->dir;
    if (atual->esq != suc)
      suc->esq = atual->esq;
    NoArv *temp = atual;
    free(temp);
  }
  return 1;
}
