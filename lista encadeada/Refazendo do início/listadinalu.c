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

    if(vazia(la)==1){
        return -1;
    }
    No *aux = la->inicio;
    for(int i = 0; i < pos; i++){
        aux = aux->prox;
        if (aux == NULL){
            return -1;
        }

    }
    strcpy(al->nome, aux->dado.nome);
    al->matricula = aux->dado.matricula;
    al->nota1 = aux->dado.nota1;
    al->nota2 = aux->dado.nota2;
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
    if (vazia(la) == 1) {
        return 0; // Lista está vazia, não há nada para remover.
    }

    int posicao = buscaPosMat(la, mat);
    if (posicao == -1) {
        return 0; // Matrícula não encontrada na lista.
    }

    if (posicao == 0) {
        // Remoção do primeiro elemento da lista
        No *temp = la->inicio;
        la->inicio = la->inicio->prox;
        free(temp);
    } else {
        No *aux = la->inicio;
        for (int i = 0; i < posicao - 1; i++) {
            aux = aux->prox;
        }
        No *temp = aux->prox;
        aux->prox = aux->prox->prox;
        free(temp);
    }

    return 1; // Remoção bem-sucedida.
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

int insereOrdemMat(ListaAluno *la, Aluno al){
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL){
        return 0;
    }

    novo->dado = al;
    int menorMat = 2147483000; // Inicialize com um valor grande.
    int matNovo = al.matricula;
    int pos = 0;
    int posMat = 0;
    No *aux = la->inicio;

    while (aux != NULL) {
        if (menorMat > aux->dado.matricula) {
            menorMat = aux->dado.matricula;
            posMat = pos;
        }

        if (matNovo == aux->dado.matricula) {
            free(novo); // Libere o novo nó em caso de matrícula duplicada.
            return -1;
        }
        aux = aux->prox;
        pos++;
    }

    if (menorMat > matNovo) {
        int j = inserePos(la, al, posMat);
        if (j == 1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        int j = inserePos(la, al, posMat - 1);
        if (j == 1) {
            return 1;
        } else {
            return 0;
        }
    }
}

int removeAlunoPos(ListaAluno *la, int pos){
    No *aux = la->inicio;
    int mat;
    for(int i=0;i<pos;i++){
        aux = aux->prox;
    }
    mat = aux->dado.matricula;
    int remocao = removeAlunoMat(la,mat);

    return remocao;

}

int pesquisarAlunoOuMat(ListaAluno *la){
    int opcao;
    int contador = 0;

    printf("\nDigite 1 para pesquisar pelo nome");
    printf("\nDigite 2 para pesquisar pela matrícula");
    printf("\nOpção escolhida: ");
    scanf("%d",&opcao);

    if(opcao == 1){
        char nomeP[30];
        printf("\nDigite o nome a ser pesquisado: ");
        scanf("%s",nomeP);
       

        No *aux = la->inicio;
        while(aux != NULL){
            if (strcmp(nomeP,aux->dado.nome) == 0){
                printf("\nMatrícula: %d",aux->dado.matricula);
                printf("\nNome: %s",aux->dado.nome);
                printf("\nNota 1: %d",aux->dado.nota1);
                printf("\nNota 2: %d",aux->dado.nota2);
                contador++;
            }
            aux = aux->prox;
        }

    }

    if(opcao == 2){
        int matricula;
        printf("Digite a matrícula a ser pesquisada: ");
        scanf("%d",&matricula);
        No *aux = la->inicio;
        while(aux != NULL){
            if (aux->dado.matricula == matricula){
                printf("\nMatrícula: %d",aux->dado.matricula);
                printf("\nNome: %s",aux->dado.nome);
                printf("\nNota 1: %d",aux->dado.nota1);
                printf("\nNota 2: %d",aux->dado.nota2);
                contador++;
            }
            aux = aux->prox;
        }


    }

    if(contador > 0){
        return 1;
    }

    else{
        return 0;
    }
}