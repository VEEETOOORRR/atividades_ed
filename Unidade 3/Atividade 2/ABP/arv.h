typedef struct noarv {
  struct noarv *esq;
  struct noarv *dir;
  int dado;
} NoArv;

typedef struct arvore {
  NoArv *raiz;
} Arvore;

void criar(Arvore *a);
void exibir(NoArv *raiz, int n);
// void exibir2(NoArv *r);
int inserir(Arvore *a, int valor);
NoArv *inserir_rec(NoArv *raiz, int dado);
void insere(Arvore *a, int dado);
int busca(NoArv *raiz, int valor);
NoArv *sucessor(NoArv *atual);
int remover(Arvore *a, int valor);