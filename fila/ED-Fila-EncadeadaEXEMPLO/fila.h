typedef struct no {
  int dado;
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
int entrar(Fila *f, int elem);
int primeiro(Fila *f);
int ultimo(Fila *f);
int sair(Fila *f);
void exibir(Fila *f);