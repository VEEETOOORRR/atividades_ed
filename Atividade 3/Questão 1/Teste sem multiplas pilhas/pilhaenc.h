#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura pilha encadeada
typedef struct no {
	int dado;	// campo que guarda a informacao
	struct no *prox; // guarda o endereço para prox nó
}No;

typedef struct pilha {
	No *topo; // guarda o endereço para prox nó
}PilhaEnc;

//************** Interface de uso do TAD Pilha Encadeada **************//


/* Criar uma pilha vazia */
void criarPilha( PilhaEnc *p );

/* Verificar se a pilha está vazia ou não */
int pilhaVazia( PilhaEnc p );

/* Tamanho da pilha */
int tamanhoPilha( PilhaEnc p );

/* Empilhar um elemento */
int empilhar( PilhaEnc *p, int dado );

/* Desempilhar um elemento */
/* O elemento desempilhado deve ser retornado
na variavel dado*/
int desempilhar(PilhaEnc *p, int *dado );

/* Consultar o topo pilha */
/* O topo deve ser retornado na variavel dado*/
int topo( PilhaEnc p, int *dado );

/* Exibir todos os elementos da pilha */
int exibir ( PilhaEnc p );