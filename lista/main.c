#include "listadinalu.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    ListaAluno testeLa;
    Aluno teste;
    teste.matricula = 12345;
    teste.nota1 = 10;
    teste.nota2 = 7;

    printf("Digite o nome do aluno: ");
    fgets(teste.nome, sizeof(teste.nome), stdin);
    teste.nome[strcspn(teste.nome, "\n")] = '\0'; // Remove o caractere de nova linha

    cria(&testeLa);
    insereFinal(&testeLa, teste);
    exibirALunos(&testeLa);

    No *atual = testeLa.inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}
