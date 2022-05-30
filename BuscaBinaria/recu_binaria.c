#include <stdio.h>
#include <stdlib.h>


int buscaBinaria(int *V, int inicio, int final, int elem){
    int meio;

        meio = (inicio + final) / 2;
        if(elem < V[meio]){
            final = meio - 1; 
            return buscaBinaria(*V, inicio, meio - 1,elem);
        }
        else{
            if(elem > V[meio]){
            return buscaBinaria(*V, inicio + 1,final, elem);
            }
            else
                return meio;
        }
    return -1;
}


int main(){

    int array[9] = {2,8,9,25,75,85,86,100,112};
    int inicio = 0, final = 8, elem = 5, valor;

    valor = buscaBinaria(array,inicio,final, elem);

    printf("Retorno da função %d", valor);

    return 0;
}