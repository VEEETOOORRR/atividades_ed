

































































































typedef struct aluno{
    int matricula;
    char nome[30];
    float nota1, nota2;
} Aluno;

typedef struct no{
    Aluno dado;
    struct no *prox;
} No;

typedef struct lista{
    No *inicio;
}ListaAluno;

//operações básicas:

void cria(ListaAluno *la);
int tamanho(ListaAluno *la);
int vazia(ListaAluno *la);
int buscaPosMat(ListaAluno *la, int mat);
int buscaAlunoPos(ListaAluno *la, int pos);
int insereFinal(ListaAluno *la, Aluno al);
int removeAlunoMat(ListaAluno *la, int mat);
void exibirALunos(ListaAluno *la);