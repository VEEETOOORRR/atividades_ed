#include "listadinalu.h"

void cria(ListaAluno *la){
    la->inicio = NULL;
}

int tamanho(ListaAluno *la){
    int tam = 0;
    No *aux = la->inicio;
    while (aux != NULL){
        tam++;
        aux = aux->prox;
    }
    return tam;
}

int vazia(ListaAluno *la){
    return (la->inicio == NULL) ? 1 : 0;
}

int buscaPosMat(ListaAluno *la, int mat){
    int pos = 0;
    No *aux = la->inicio;
    while (aux != NULL){
        if (aux->dado.matricula == mat){
            return pos;
        }
        pos++;
        aux = aux->prox;
    }
    return -1;
}

int buscaAlunoPos(ListaAluno *la, int pos, Aluno *al){
    No *aux = la->inicio;
    for(int i = 0; i < pos; i++){
        aux = aux->prox;
        if (aux == NULL){
            return -1;
        }
        strcpy(al->nome, aux->dado.nome);
        al->matricula = aux->dado.matricula;
        al->nota1 = aux->dado.nota1;
        al->nota2 = aux->dado.nota2;
    }
    return 1;
}

int insereFinal(ListaAluno *la, Aluno al){
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL){
        return 0;
    }

    if (vazia(la) == 1){
        novo->dado = al;
        novo->prox = NULL;
        la->inicio = novo;
    } 

    No *aux = la->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    novo->dado = al;
    novo->prox = NULL;
    return 1;
}

int removeAlunoMat(ListaAluno *la, int mat){
    if(vazia(la) == 1){
        return 0;
    }

    int posicao = buscaPosMat(la, mat);
    if (posicao == -1){
        return 0;
    }
    No *aux = la->inicio;
    for (int i = 0; i < posicao - 1; i++){
        aux = aux->prox;
    }
    No *temp = aux->prox;
    aux->prox = aux->prox->prox;
    free(temp);
    return 1;
}

void exibirAlunos(ListaAluno *la){
    No *aux = la->inicio;
    while (aux != NULL) {
        printf("Matrícula: %d\n", aux->dado.matricula);
        printf("Nome: %s\n", aux->dado.nome);
        printf("Nota 1: %d\n", aux->dado.nota1);
        printf("Nota 2: %d\n", aux->dado.nota2);
        printf("\n");
        aux = aux->prox;
    }
}

//FUNÇÕES EXTRAS:

int inserePos(ListaAluno *la, Aluno al, int pos){
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL){
        return 0;
    }

    novo->dado = al;

    if (pos == 0) { // Caso 1: Nó no início
        novo->prox = la->inicio;
        la->inicio = novo;
    } else { // Caso 2: Nó no meio
        No *anterior = la->inicio;
        for (int i = 0; i < pos - 1; i++) { // Encontre o nó anterior à posição desejada.
            anterior = anterior->prox;
            if (anterior == NULL) {
                free(novo);
                return 0; // A posição desejada não existe.
            }
        }
        novo->prox = anterior->prox; // Conecte o novo nó ao nó seguinte.
        anterior->prox = novo; // Conecte o nó anterior ao novo nó.
    }

    return 1;
}
