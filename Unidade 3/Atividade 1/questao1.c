#include <stdio.h>

int buscaBinaria (int x, int n, int v[]) { 
   int e = -1;
   int d = n;
   while (e < d-1) {  
      int m = (e + d)/2;
      if (v[m] < x) e = m;
      else d = m; 
   }
   if(x == v[d]){
    return d;
   }
   else{
    return -1;
       }

}

int main(){
    int vetor[10] = {33, 40, 56, 58, 59, 72, 77, 92, 96, 99};
    int vetor2[15] = {9, 22, 37, 39, 52, 58, 61, 63, 66, 69, 76, 82, 88, 89};
    int vetor3[20] = {1, 2, 16, 17, 19, 20, 35, 42, 53, 57, 58, 59, 64, 67, 75, 82, 93, 94, 96, 99};
    int chave = 92;
    int chave2 = 9;
    int chave3 = 83;

    int resultado = buscaBinaria(chave, 10, vetor);
    if(resultado != -1){
        printf("\nPosição: %d\n", resultado);
    }

    else{
        printf("\nNúmero não encontrado");
    }

    int resultado2 = buscaBinaria(chave2, 15, vetor2);
    if(resultado != -1){
        printf("\nPosição: %d\n", resultado2);
    }

    else{
        printf("\nNúmero não encontrado");
    }

    int resultado3 = buscaBinaria(chave3, 20, vetor3);
    if(resultado != -1){
        printf("\nPosição: %d\n", resultado3);
    }

    else{
        printf("\nNúmero não encontrado");
    }
}