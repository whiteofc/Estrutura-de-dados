#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


int* buscaLinear(int *V, int N, int elem){

    int *posi, aux = 1;
    posi = (int *) calloc (aux, sizeof(int));
    aux = 0;
	for(int i = 0; i < N; i++){
		if(elem == V[i]){
        posi[aux] = i;
        aux++;
		posi = realloc(posi, aux * sizeof(int));
        }
	}
    aux++;
    
    posi[aux - 1] = -1;
    
    return posi;
}




int main(){
    srand (time(NULL));

    int *array,*posi, n, elem;

    printf("Informe o tamanho do seu array\n");
    scanf("%d", &n);

    array = (int *) calloc (n, sizeof(n));
    posi = (int *) calloc (n, sizeof(n));

    for(int i = 0; i < n; i++){
    array[i] =  rand () % 10;
    printf("Indice [%d] = %d\n", i, array[i]);
    }

    printf("Qual elemento você deseja buscar no array?\n");
    scanf("%d", &elem);

    posi = buscaLinear(array, n, elem);


    for(int i = 0; i < n; i++){
        if(posi[i] == -1){
            break;
        }
        printf("Seu elemento foi encontrado nas seguintes posições: %d\n", posi[i]);
    }

    return 0;
}