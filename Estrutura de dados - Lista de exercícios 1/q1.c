#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *uniao(int *v1, int n1, int *v2, int n2){

    int *v3;
    int n3 = n1 + n2;
    int count = 0;

    v3 = (int *) calloc (n3, sizeof(int));

    for(int i = 0; i < n1; i++){
        v3[i] = v1[i];
    }
    for(int i = n1; i < n3; i++){
        v3[i] = v2[count];
        count++;
    }
    return v3;
}
int main(){

    srand (time(NULL));

    int *vet1;
    int *vet2;
    int *vet3;
    int x1,x2,x3;


    printf("Insira o tamanho do Vetor 1: ");
    scanf("%d", &x1);

    vet1 = (int *) calloc (x1, sizeof(int));

    printf("\nVETOR 1: {");
    for(int i = 0; i < x1; i++){
        vet1[i] = rand() % 100;
        if(i + 1 == x1){
            printf("%d}", vet1[i]);
            break;
        }
        printf("%d,", vet1[i]);
    }

    printf("\n\nInsira o tamanho do Vetor 2: ");
    scanf("%d", &x2);

    x3 = x1 + x2;

    vet2 = (int *) calloc (x2, sizeof(int));

    printf("\nVETOR 2: {");
    for(int i = 0; i < x2; i++){
        vet2[i] = rand() % 100;
        if(i + 1 == x2){
            printf("%d}", vet2[i]);
            break;
        }
        printf("%d,", vet2[i]);
    }

    vet3 = (int *) calloc ((x1 + x2), sizeof(int));

    vet3 = uniao(vet1, x1, vet2, x2);

    printf("\n\nVETOR 3 PREENCHIDO: {");

    for(int i = 0; i < x3; i++){
        if(i + 1 == x3){
            printf("%d}\n", vet3[i]);
            break;
        }
        printf("%d,", vet3[i]);
    }  
    free(vet1);
    free(vet2);
    free(vet3);
}