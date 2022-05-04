#include <stdio.h>
#include <stdlib.h>

int main(void){

  int matriz[3][3];

  printf("Preenchendo Matriz: \n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
    scanf("%d", &matriz[i][j]);
    }
  }

  printf("Matriz\n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      printf("%d ", matriz[i][j]);
    }
    printf(" \n");
  }

  printf("Matriz Transposta: \n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      printf("%d ", matriz[j][i]);
    }
    printf(" \n");
  }
  return 0;
}