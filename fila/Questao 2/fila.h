#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct paciente {
  int cpf;
  char nome[30];
  int idade;
  int gestante;
} Paciente;

typedef struct no {
  Paciente pac;
  struct no *prox;
} No;

typedef struct fila {
  No *inicio;
  No *fim;
  int tamanho;
} Fila;

void criar(Fila *f);
int vazia(Fila *f);
int tamanho(Fila *f);
int entrar(Fila *f, Paciente p);
Paciente primeiro(Fila *f);
Paciente ultimo(Fila *f);
Paciente sair(Fila *f);
void exibir(Fila *f);

