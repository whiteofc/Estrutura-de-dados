#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a[5], b[5], auxA[5], auxB[5], auxAll = 0;
  
  printf("Preenchendo VETOR A\n");
  for(int i = 0; i < 5; i++){
    scanf("%d", &a[i]);
  }

  printf("Preenchendo VETOR B\n");
  for(int i = 0; i < 5; i++){
    scanf("%d", &b[i]);
  }
  
  for(int i = 0; i < 5; i++){
    int in = 0;
    for(int j = 0; j < 5; j++){
      if(b[i] == a[j]){
        in = 1;
        break;
      }
    }
    if(in == 0) {
      auxB[auxAll] = b[i];
      auxAll++;
    }
  }

  printf("Elementos que estão em A\n");
  for(int i = 0; i < 5; i++){
      printf("%d\n", a[i]);
    }
  printf("Elementos que estão em B que não estão em A\n");
  for(int i = 0; i < auxAll; i++){
      printf("%d\n", auxB[i]);
    }
  return 0;
}