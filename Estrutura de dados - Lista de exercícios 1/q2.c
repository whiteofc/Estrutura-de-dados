 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

int multi_matriz(int *linha, int *coluna, int qtd_lin, int qtd_col){

    int matriz_final[qtd_lin][qtd_col];

    for(int i = 0; i < qtd_lin; i++){
        for(int j = 0; j < qtd_col; j++){
            matriz_final[j][i] = linha[i] * coluna[j];
        }
    }

    printf("Resultado da Matriz multiplicada: \n");
    for(int i = 0; i < qtd_lin; i++){
        for(int j = 0; j < qtd_col; j++){
            if(j + 1 == qtd_col){
                printf("%d|", matriz_final[i][j]);
                break;
            }
            printf("|%d ", matriz_final[i][j]);
        }
        printf("\n");
    }
}

int preenche_matriz(int *linha, int *coluna, int qtd_lin, int qtd_col){

    printf("Preencha a linha da matriz: \n");
    for(int i = 0; i < qtd_lin; i++){
        scanf("%d", &linha[i]);
    }

    printf("Preencha a coluna da matriz: \n");
    
    for(int i = 0; i < qtd_col; i++){
        scanf("%d", &coluna[i]);
    }

    multi_matriz(linha, coluna, qtd_lin, qtd_col);
}

int main(void) {

    srand (time(NULL));

    int *n, *p;
    int qtd, qtd2;

    while(1){
        printf("Insira o tamanho da Linha da Matriz, OBS Limite MIN 1 e MAX 30: ");
        scanf("%d", &qtd);
        if(qtd > 30 || qtd < 1){
            printf("Insira um tamanho entre 1 e 30 apenas! \n");
        }
        else
            break;
    }

    n = (int *) calloc (qtd, sizeof(int));

    while(1){
        printf("Insira o tamanho da Coluna da Matriz, OBS Limite MIN 1 e MAX 30: ");
        scanf("%d", &qtd2);
        if(qtd2 > 30 || qtd2 < 1){
            printf("Insira um tamanho entre 1 e 30 apenas! \n");
        }
        else
            break;
    }

    p = (int *) calloc (qtd2, sizeof(int));

    int matriz_final[qtd][qtd2];

    preenche_matriz(n, p, qtd, qtd2);

    free(n);
    free(p);
    return 0;
}   