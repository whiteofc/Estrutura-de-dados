#include <stdio.h>
#include <stdlib.h>
#include <time.h>
	
int procura(int *a, int tam, int indice, int x){

  if(indice == tam){
   return -1;
  }
  if(a[indice] == x){
    return indice;
  }
  else 
    return procura(a, tam, indice + 1, x);
}

int main(){
  srand(time(NULL));
  
  int *vet, tam, ind = 0, valor, indice;

  printf("Qual tamanho do seu array?\n");
  scanf("%d", &tam);

  printf("QUal numero deseja buscar no array?\n");
  scanf("%d", &valor);
  
  vet = (int *) calloc (tam, sizeof(int));
  
    for(int i = 0; i < tam; i++){
      vet[i] = rand() % 10;
    }

    printf("Imprimindo valores: \n");
    for(int i = 0; i < tam; i++){
    printf("%d\n", vet[i]);
  }


  indice = procura(vet, tam, ind, valor);

  if(indice == -1){
    printf("O número que você está buscando não está contido nesse array.");
  }
  else
    printf("Posição desse valor está no indice %d",       indice);
	
	return 0;	
}
