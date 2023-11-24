#include "fila.c"


void enter() {
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n'); // Limpa o buffer de entrada.
    getchar(); // Aguarda a entrada do usuário.
}

Paciente *cadastra(){
    Paciente *novoPaciente = (Paciente*) malloc(sizeof(Paciente));
    if (novoPaciente == NULL){
        return NULL; // Retorna NULL em caso de erro na alocação.
    }
    printf("\nDigite o CPF: ");
    scanf("%d", &novoPaciente->cpf);

    while (getchar() != '\n'); // Limpa o buffer de entrada.

    printf("\nDigite o nome: ");
    fgets(novoPaciente->nome, sizeof(novoPaciente->nome), stdin);
    novoPaciente->nome[strcspn(novoPaciente->nome, "\n")] = 0;

    printf("\nDigite a idade: ");
    scanf("%d", &novoPaciente->idade);

    while (getchar() != '\n'); // Limpa o buffer de entrada.

    printf("\nÉ gestante? 1 para sim, 0 para não: ");
    scanf("%d", &novoPaciente->gestante);

    return novoPaciente;
}

int prompt(Fila *f){
  int opcao;
  printf("\nFILA DE PESSOAS");
  printf("\n---------------------");
  printf("\n1 - Exibir a Fila");
  printf("\n2 - Entrar na Fila");
  printf("\n3 - Sair da Fila");
  printf("\n4 - Primeiro da Fila");
  printf("\n5 - Quantidade de Pessoas na Fila");
  printf("\n6 - Sair");
  printf("\n\nDigite a opção: ");

  scanf("%d",&opcao);

  if(opcao == 1){
    exibir(f);
  }

  if(opcao == 2){
    if(entrar(f,*cadastra())==1){
      printf("\nPaciente inserido com sucesso!");
    }
    else{
      printf("\nErro ao inserir paciente.");
    }
  }

  if(opcao == 3){
    Paciente removido = sair(f);
    if(removido.cpf == -1){
      printf("\nNão há pacientes para remover.");
    }
    else{
      printf("\nPaciente removido:");
      printf("\nCPF: %d",removido.cpf);
      printf("\nNome: %s",removido.nome);
      printf("\nIdade: %d",removido.idade);
      printf("\nGestante: %d",removido.gestante);
    }
  }

  if(opcao == 4){
    Paciente p = primeiro(f);
    if(p.cpf == -1){
      printf("\nA fila está vazia!");
    }
    else{
      printf("\nPrimeiro paciente:");
      printf("\nCPF: %d",p.cpf);
      printf("\nNome: %s",p.nome);
      printf("\nIdade: %d",p.idade);
      printf("\nGestante: %d",p.gestante);
    }
  }

  if(opcao == 5){
    printf("\nA fila tem %d pacientes.",tamanho(f));
  }

  if(opcao == 6){
    return 0;
  }

  enter();
  return 1;

}
int main() {
  Fila fila;
  criar(&fila);
  int i = prompt(&fila);

  while(i==1){
    i = prompt(&fila);
  }
}