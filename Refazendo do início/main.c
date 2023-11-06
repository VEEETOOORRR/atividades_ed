#include "listadinalu.c"

Aluno *cadastra(){
    Aluno *novo = (Aluno*) malloc(sizeof(Aluno));
    if (novo == NULL){
        return 0;
    }
    printf("\nDigite a matrícula: ");
    scanf("%d",&novo->matricula);

    getchar();

    printf("\nDigite o nome: ");
    fgets(novo->nome, sizeof(novo->nome), stdin);
    novo->nome[strcspn(novo->nome, "\n")] = 0;

    printf("\nDigite a primeira nota: ");
    scanf("%d",&novo->nota1);

    printf("\nDigite a segunda nota: ");
    scanf("%d",&novo->nota2);

    return novo;
}

int prompt(ListaAluno *la){
    printf("\nSeja bem vindo ao prompt de matrículas");
    printf("\nInsira a opção desejada:");
    printf("\n1- Verificar tamanho da lista");
    printf("\n2- Verificar se a lista está vazia");
    printf("\n3- Buscar posição na lista pela matrícula");
    printf("\n4- Buscar dados de um aluno pela sua posição");
    printf("\n5- Inserir aluno no final da lista");
    printf("\n6- Remover aluno da lista pela sua matrícula");
    printf("\n7- Exibir alunos cadastrados na lista");
    printf("\nOpção escolhida: ");
    int opcao;

    scanf("%d",&opcao);

    if(opcao == 1){

        printf("\nA lista possui %d elementos",tamanho(la));
        printf("\n Pressione ENTER para voltar ");

        char enter = 0;
        while (enter != '\r' && enter != '\n') { enter = getchar(); }
        return 1;

    return 0;
}
}

int main(){
    ListaAluno listaa;
    cria(&listaa);

    int i = prompt(&listaa);
    while(i == 1){
        i = prompt(&listaa);
    }

    return 0;
}