#include <stdio.h>
#include <stdlib.h>

int main(void){

  int matriz[3][3],store[3], soma;

  printf("Preenchendo Matriz: \n");
  for(int i = 0; i < 3; i++){
    soma = 0;
    for(int j = 0; j < 3; j++){
      scanf("%d", &matriz[i][j]);
      soma += matriz[i][j];
    }
    store[i] = soma;
  }
  printf("Matriz\n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      printf("%d ", matriz[i][j]);
    }
    printf(" \n");
  }
  for(int i = 0; i < 3; i++){
    soma = 0;
    for(int j = 0; j < 3; j++){
      soma += matriz[j][i];
    }
    store[i] = soma;
  }
  for(int i = 0; i < 3; i++){
      printf("Soma da [%d]° Coluna = %d ",i + 1,  store[i]);
      printf("\n");
  }
  return 0;
}