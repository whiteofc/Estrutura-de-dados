#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int x[10],aux[10];
	
	srand(time(NULL));
		
	for(int i = 0; i < 10; i++){
		x[i] =  rand() % 100;
		aux[i] = x[i];
		if(x[i] % 2 ==0){
			x[i] = 1;
		}
		else
			x[i] = -1;
	}
	
	for(int i = 0; i < 10; i++){
		printf("Valor [%d] = %d\n",aux[i], x[i]);
	}
 return 0;
}