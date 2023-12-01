#include "pilhaenc.c"

void enter() {
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n'); // Limpa o buffer de entrada.
    getchar(); // Aguarda a entrada do usuário.
}

int menu(PilhaEnc pilha[], int *pilhaEscolhida){
    int opcao;
    PilhaEnc *p = &pilha[*pilhaEscolhida];

    printf("\nEditor de Pilha v1.0");
    printf("\n====================");
    printf("\n1- Inicializar");
    printf("\n2- Empilhar");
    printf("\n3- Desempilhar");
    printf("\n4- Elemento do topo");
    printf("\n5- Imprimir pilha");
    printf("\n6- Inverter elementos da pilha");
    printf("\n7- Esvaziar a pilha");
    printf("\nPilha atual: %d",*pilhaEscolhida);
    //printf("\n8- Mudar de pilha");
    printf("\n\nDigite sua opção: ");

    scanf("%d",&opcao);

    if(opcao==1){
        criarPilha(p);
        printf("\nPilha iniciada com sucesso!");
    }

    if(opcao==2){
        int dado;
        printf("\nDigite o dado a ser adicionado: ");
        scanf("%d",&dado);
        if(empilhar(&p[*pilhaEscolhida],dado)==1){
            printf("\nDado empilhado com sucesso!");
        }
        else{
            printf("\nErro ao empilhar dado.");
        }
    }

    if(opcao==3){
        int desempilhado;
        if(desempilhar(&p[*pilhaEscolhida], &desempilhado)==1){
            printf("\nDado removido: %d",desempilhado);
        }
        else{
            printf("\nNão há dados para desempilhar!");
        }
    }
    
    if(opcao==4){
        int t;
        if(topo(p[*pilhaEscolhida], &t)==1){
            printf("\nElemento no topo da pilha: %d",t);
        }
        else{
            printf("\nA pilha está vazia!");
        }
    }

    if(opcao==5){
        if(exibir(p[*pilhaEscolhida])==0){
            printf("\nA pilha está vazia!");
        }
    }

    if(opcao==6){
        if(invertePilha(&p[*pilhaEscolhida])==1){
            printf("\nPilha invertida com sucesso!");
        }
        else{
            printf("\nA pilha está vazia!");
        }
    }

    if(opcao==7){
        int confirma;
        printf("\nTens certeza de que deseja esvaziar a pilha? Digite 1 para sim, 0 para não");
        scanf("%d",&confirma);

        if(confirma==1){
            if(esvaziar(&p[*pilhaEscolhida])==1){
                printf("\nPilha esvaziada com sucesso!");
            }
            else{
                printf("\nA pilha já está vazia!");
            }
        }
        else if(confirma !=0){
            printf("\nOpção inválida!");
        }
    }

    if(opcao==8){
        if(mudaPilha(pilhaEscolhida)==1){
            printf("\nPilha trocada com sucesso!");
        }
        else{
            printf("\nOpção inválida!");
        }
    }

    if(opcao==0){
        return 0;
    }

    if(opcao > 8 || opcao < 0){
        printf("\nDigite uma opção válida!");
    }
    enter();
    return 1;
}

int main(){

    PilhaEnc vetorP[3];
    int pE = 0;

    int i = menu(vetorP, &pE);
    while(i == 1){
        i = menu(vetorP, &pE);
    }

    return 0;


}