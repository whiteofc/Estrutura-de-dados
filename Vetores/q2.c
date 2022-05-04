#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int x, v[10], contador = 0;

    for (int i = 0 ; i < 10; i++){
        scanf("%d", &v[i]);
    }
    scanf("%d", &x);

    for (int i = 0 ; i < 10; i++){
        if(x == v[i]){
            contador++;
        }

    }
    printf("%d Apareceu = %d vezes\n",x,  contador);
  
    return 0;
}