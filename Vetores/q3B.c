#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a[5], b[5], auxA[10], auxAll = 0;
  
  printf("Preenchendo VETOR A\n");
  for(int i = 0; i < 5; i++){
    scanf("%d", &a[i]);
  }

  printf("Preenchendo VETOR B\n");
  for(int i = 0; i < 5; i++){
    scanf("%d", &b[i]);
  }

  printf("Elementos que estão em A e B: \n");

  for(int i = 0; i < 5; i++){
    int flag = 0;
    for(int j = 0; j < 5; j++){
      
      if(a[i] == b[j]){
        auxA[auxAll] = a[i];
        auxAll++;
        break;
      }
    }
    flag = 0;
  }
  for(int i = 0; i < auxAll; i++){
      printf("%d\n", auxA[i]);
    }
  return 0;
}