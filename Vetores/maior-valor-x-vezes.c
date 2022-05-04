#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void count(int x[]){

  int aux, contador = 0, maiorV;

  int max = -1;
  
  for(int i = 0; i < 10; i++){
    if(max < x[i]){
        max = x[i];
    }
  }

    for (int i = 0 ; i < 10; i++){
        if(max == x[i]){
            contador++;
        }
    }
    printf("Maior valor = %d, apareceu %d",max, contador);
}

int main(void) {

  srand(time(NULL));

  int x[10];

  for(int i = 0; i < 10; i++){
    x[i] = rand() % 10;
    printf("%d\n", x[i]);
  }

  count(x);
  
  return 0;
}