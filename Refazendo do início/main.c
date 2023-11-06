#include "listadinalu.c"

void enter() {
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n'); // Limpa o buffer de entrada.
    getchar(); // Aguarda a entrada do usuário.
}

Aluno *cadastra(){
    Aluno *novoAluno = (Aluno*) malloc(sizeof(Aluno));
    if (novoAluno == NULL){
        return NULL; // Retorna NULL em caso de erro na alocação.
    }
    printf("\nDigite a matrícula: ");
    scanf("%d", &novoAluno->matricula);

    while (getchar() != '\n'); // Limpa o buffer de entrada.

    printf("\nDigite o nome: ");
    fgets(novoAluno->nome, sizeof(novoAluno->nome), stdin);
    novoAluno->nome[strcspn(novoAluno->nome, "\n")] = 0;

    printf("\nDigite a primeira nota: ");
    scanf("%d", &novoAluno->nota1);

    while (getchar() != '\n'); // Limpa o buffer de entrada.

    printf("\nDigite a segunda nota: ");
    scanf("%d", &novoAluno->nota2);

    return novoAluno;
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
    printf("\n8- Cadastrar aluno em ordem de matrícula");
    printf("\nOpção escolhida: ");
    int opcao;

    scanf("%d",&opcao);

    if(opcao == 1){

        printf("\nA lista possui %d elementos",tamanho(la));        
        enter();

        return 1;
}

    if(opcao == 2){
        int tavazia = vazia(la);
        if(tavazia == 1){
            printf("A lista está vazia");
        }
        else if(tavazia == 0){
            printf("A lista não está vazia");
        }
        enter();
        return 1;
    }
    
    if(opcao == 3){
        int matricula;
        printf("\nDigite a matrícula a ser procurada: ");
        scanf("%d",&matricula);

        int posi = buscaPosMat(la,matricula);
        
        if(posi == -1){
            printf("\nA matrícula %d não está cadastrada na lista.", matricula);
            enter();
        }
        else{
            printf("\n A matrícula %d está na posição %d.", matricula, posi);
            enter();
        }
    }

    if(opcao == 4){ //esse código abaixo é da ultima operação que falta ser programada..
        char nome[30];
        printf("\nDigite o nome a ser pesquisado: ");
        fgets(nome, sizeof(nome), stdin);
        buscapos = buscaAlunoPos(ListaAluno *la, int pos, Aluno *al);
    }

    if(opcao == 8){
        int i = insereOrdemMat(la,*cadastra());
        return i;
        enter();
    }
    return 0;
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