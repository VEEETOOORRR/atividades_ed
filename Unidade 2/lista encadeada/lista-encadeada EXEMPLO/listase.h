typedef struct no{
  int dado;
  struct no *prox;
}No;

typedef struct lista{
  No *inicio;
}Lista;

void cria(Lista *l);
int vazia(Lista *l);
int tamanho(Lista *l);
int busca(Lista *l, int dado);
int inserir(Lista *l, int dado);
int remover(Lista *l, int dado);
void exibir(Lista *l);




