#include "pilhaenc.h"

void criarPilha( PilhaEnc *p ){
  p->topo = NULL;
}

int pilhaVazia( PilhaEnc p ){
    if(p.topo==NULL){
        return 1;
    }
    return 0;
}

int empilhar(PilhaEnc *p, int dado){
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL){
        return 0;
    }

    if (pilhaVazia(*p) == 1){
        novo->dado = dado;
        novo->prox = NULL;
        p->topo = novo;
        return 1;
    } 

    novo->prox = p->topo;
    p->topo = novo;
    return 1;
}

int desempilhar(PilhaEnc *p, int *dado){
    if(pilhaVazia(*p)==1){
        return -1;
    }
    *dado = p->topo->dado;
    p->topo = p->topo->prox;
    return 1;
}

int topo(PilhaEnc p, int *dado){ //REFAZER ESSA
    if(pilhaVazia(p)==1){
        return -1;
    }    
    *dado = p.topo->dado;
    return 1;
}

int exibir(PilhaEnc p){
    if(pilhaVazia(p)==1){
        return 0;
    }
    No *aux = p.topo;
    while(aux != NULL){
        printf("\n%d",aux->dado);
        aux = aux->prox;
    }
    return 1;
}

int invertePilha(PilhaEnc *p){
    if(pilhaVazia(*p)==1){
        return 0;
    }
    
    PilhaEnc inversora;
    criarPilha(&inversora);

    for(No *aux = p->topo;aux !=NULL;aux = aux->prox){
        empilhar(&inversora, aux->dado);
    }
    p = &inversora;
    return 1;

}

int esvaziar(PilhaEnc *p){
    if(pilhaVazia(*p)==1){
        return 0;
    }
    
    while(pilhaVazia(*p)!=1){
        int dado;
        desempilhar(p, &dado);
        printf("\nDado removido: %d", dado);
    }
    return 1;
}


int mudaPilha(PilhaEnc *p, PilhaEnc *p1, PilhaEnc *p2, PilhaEnc *p3){
    int opcao;
    printf("\nDigite qual das três pilhas queres manipular: ");
    scanf("%d", &opcao);

    if(opcao==1){
        p = p1;
    }
    
    else if(opcao==2){
        p = p2;
    }

    else if(opcao==3){
        p = p3;
    }

    else{
        return 0;
    }
    return 1;
}
