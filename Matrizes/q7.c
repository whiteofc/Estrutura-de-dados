#include <stdio.h>
#include <stdlib.h>

int main(void){

  srand (time(NULL));
  
  int matrizA[3][3],matrizB[3][3], matrizC[3][3],store[3];
  int soma, multi = 0;
  printf("Preenchendo Matriz A: \n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      matrizA[i][j] = rand() % 10;
    }
  }
  printf("Preenchendo Matriz B: \n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      matrizB[i][j] = rand() % 10;
    }
  }
  printf("\nMatriz A\n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      printf("%d ", matrizA[i][j]);
    }
    printf(" \n");
  }
  printf("\nMatriz B\n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      printf("%d ", matrizB[i][j]);
    }
    printf(" \n");
  }
  printf("\nGerando Matriz C..\n");
  sleep(2);
  
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++) {
				multi +=  matrizA[i][k] * matrizB[k][j];
			}
      matrizC[i][j] = multi;
      multi = 0;
    }
  }

  printf("\nMatriz C\n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      printf("%d ", matrizC[i][j]);
    }
    printf(" \n");
  }
  return 0;
}