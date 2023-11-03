#include "listadinalu.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    ListaAluno testeLa;
    Aluno teste;
    teste.matricula = 12345;
    teste.nota1 = 10;
    teste.nota2 = 7;

    fgets(teste.nome, sizeof(teste.nome), stdin);

    cria(&testeLa);
    insereFinal(&testeLa, teste);
    exibirALunos(&testeLa);
}