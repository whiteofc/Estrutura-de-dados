#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int *V, int N, int elem){

    int inicio, meio, final;
    inicio = 0;
    final = N - 1;

    while(inicio <= final){
        meio = (inicio + final) / 2;
        if(elem < V[meio]){
            final = meio - 1; // busca na metade da esquerda
        }
        else{
            if(elem > V[meio]){
                inicio = meio + 1;
            }
            else
                return meio;
        }
    }
    return -1;
}