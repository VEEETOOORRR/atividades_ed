typedef struct paciente {
  int cpf;
  char nome[30];
  int idade;
  int gestante;
} Paciente;

typedef struct no {
  Paciente pac;
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
int entrar(Fila *f, Paciente p);
int primeiro(Fila *f);
int ultimo(Fila *f);
int sair(Fila *f);
void exibir(Fila *f);