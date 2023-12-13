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
    printf("\n1- Verificar se a lista está vazia");
    printf("\n2- Obter tamanho da lista");
    printf("\n3- Obter dados de um aluno informando a posição");
    printf("\n4- Obter a posição do aluno quando a matrícula deste é informada");
    printf("\n5- Inserir aluno no final da lista");
    printf("\n6- Remover aluno informando sua matrícula");
    printf("\n7- Exibir alunos cadastrados na lista");
    printf("\n8- Inserir um novo aluno em determinada posição");
    printf("\n9- Cadastrar aluno em ordem de matrícula");
    printf("\n10- Remover aluno em uma determinada posição:");
    printf("\n11- Pesquisar um aluno pela sua matrícula ou pelo seu nome");
    printf("\n12- Sair");
    printf("\nOpção escolhida: ");
    int opcao;

    scanf("%d",&opcao);


    if(opcao == 1){
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

    if(opcao == 2){

        printf("\nA lista possui %d elementos",tamanho(la));        
        enter();

        return 1;
}

    if(opcao == 3){
        int posicao;
        Aluno auxiliar;
        printf("\nDigite a posição do aluno a ser pesquisado:");
        scanf("%d",&posicao);
        if(buscaAlunoPos(la, posicao, &auxiliar) == 1){
            printf("\nMatrícula: %d",auxiliar.matricula);
            printf("\nNome: %s",auxiliar.nome);
            printf("\nNota 1: %d",auxiliar.nota1);
            printf("\nNota 2: %d",auxiliar.nota2);
            enter();
            return 1;
        }
        else{
            printf("\nPosição não encontrada!");
            enter();
            return 1;
        }


    }

    if(opcao == 4){
        int matricula;
        printf("\nDigite a matrícula a ser procurada: ");
        scanf("%d",&matricula);

        int posi = buscaPosMat(la,matricula);
        
        if(posi == -1){
            printf("\nA matrícula %d não está cadastrada na lista.", matricula);
        }
        else{
            printf("\nA matrícula %d está na posição %d.", matricula, posi);
        }
        enter();
        return 1;
    }




    if(opcao == 5){
        int i = insereFinal(la,*cadastra());
        if(i==1){
            printf("\nAluno cadastrado com sucesso!");
        }

        else{
            printf("\nErro ao cadastrar aluno");
        }
        enter();
        return 1;

    }

    if(opcao == 6){
        int mat;
        printf("\nInsira a matrícula a ser removida: ");
        scanf("%d",&mat);
        int i = removeAlunoMat(la, mat);
        if(i==1){
            printf("\nMatrícula removida com sucesso!");

        }
        else{
            printf("\nMatrícula inexistente na lista!");
        }

        enter();
        return 1;
    }

    if(opcao == 7){
        exibirAlunos(la);
        enter();
        return 1;
    }

// OPÇÕES EXTRAS:

    if(opcao == 8){
        int posicao;
        printf("\nDigite a posição do novo aluno cadastrado: ");
        scanf("%d",&posicao);
        int i = inserePos(la, *cadastra(), posicao);

        if(i==1){
            printf("\nAluno cadastrado com sucesso!");
        }
        else{
            printf("\nA posição desejada não existe.");
        }
        enter();
        return 1;
    }

    if(opcao == 9){
        int i = insereOrdemMat(la,*cadastra());

        if(i==1){
            printf("\nAluno cadastrado com sucesso!");
        }
        else{
            printf("\nErro ao cadastrar aluno.");
        }
        enter();
        return 1;
    }

    if(opcao == 10){
        int posicao;
        printf("\nDigite a posição do aluno a ser removido: ");
        scanf("%d",&posicao);
        int i =removeAlunoPos(la, posicao);

        if(i==1){
            printf("\nAluno removido com sucesso!");
        }

        else{
            printf("\nFalha ao remover aluno.");
        }
        enter();
        return 1;
    }

    if(opcao == 11){
        int i = pesquisarAlunoOuMat(la);

        if(i!=1){
            printf("\nAluno inexistente");
        }
        enter();
        return 1;
    }

    if(opcao == 12){
        printf("Até logo!\n");
        return 0;
    }

    if(opcao >= 13 || opcao < 1){
        printf("\nOpção inválida");
        enter();
        return 1;
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