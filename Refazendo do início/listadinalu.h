#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    int matricula;
    char nome[30];
    int nota1, nota2;
} Aluno;

typedef struct no{
    Aluno dado;
    struct no *prox;
} No;

typedef struct lista{
    No *inicio;
} ListaAluno;

void cria(ListaAluno *la);
int tamanho(ListaAluno *la);
int vazia(ListaAluno *la);
int buscaPosMat(ListaAluno *la, int mat);
int buscaAlunoPos(ListaAluno *la, int pos, Aluno *al);
int insereFinal(ListaAluno *la, Aluno al);
int removeAlunoMat(ListaAluno *la, int mat);
void exibirAlunos(ListaAluno *la);
