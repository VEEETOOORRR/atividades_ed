#include <stdio.h>

void ordena_bolha(int v[], int tam){
    int aux;
    int n = tam;
    for (int i=0; i<n; i++){
        for(int j=1; j<n-i; j++){ 
            if(v[j-1] >v[j]){ 
                aux = v[j];
                v[j] = v[j-1]; v[j-1] = aux;
            }
            printf("\n");
            for(int x = 0; x < tam; x++){
                printf("%d ",v[x]);
            }
        }
    }
}


void ordena_insercao(int v[], int tam){ 
    int atual, j;
    int n = tam;
    for(int i=1; i<n; i++){
        atual = v[i];
        j = i-1;
        while(j >= 0 && atual < v[j] ){
            v[j+1] = v[j];
            j = j-1;
            v[j+1] = atual;
        }
        printf("\n");
        for(int x = 0; x<tam; x++){
            printf("%d ", v[x]);

        }
    }
}

int main(){
    int vetor[8] = {13, 86, 37, 61, 82, 63, 77, 53};
    //ordena_insercao(vetor, 8);
    ordena_bolha(vetor, 8);
}