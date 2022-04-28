 #include <stdio.h>
 #include <stdlib.h>

int main(void) {

    float *notas,*aux, media = 0; 
    int qtd, qtd2, qtd_total;

    printf("Informe a quantidade de alunos: ");
    scanf("%d", &qtd);

    ///////////////////////* CRIANDO MEU VETOR DE PONTEIROS COM MALLOC *///////////////////////////
    notas = (float *) calloc (qtd, sizeof(qtd));

    for(int i = 0; i < qtd; i++){
        printf("Insira a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
        media += notas[i];
    }
     printf("\n***************************\n\n");

    for(int i = 0; i < qtd; i++){
        printf("Nota do aluno %d = %.2f\n", i + 1, notas[i]);
    }

    printf("\nMedia da turma: %.2f\n", (media / qtd));

    printf("\nAbrimos vagas para novos alunos, informe quantos deseja inserir: ");

    scanf("%d", &qtd2);
    qtd_total = qtd + qtd2;

   ///////////////////////* AUMENTANDO O TAMANHO DO MEU VETOR COM REALOC *///////////////////////////

    notas = realloc (notas, qtd2 * sizeof(float));

    //printf("\nInsira a notas dos %d novos alunos: \n", qtd2);

    for(int i = qtd; i < qtd_total; i++){
        printf("Insira a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
        media += notas[i];
    }

    printf("\n");

    for(int i = 0; i < qtd_total; i++){
        printf("Nota do aluno %d = %.2f\n", i + 1, notas[i]);
    }

    printf("\nMedia da turma com os novos alunos: %.2f\n", (media / qtd_total));

    ///////////////////////* DIMINUINDO O TAMANHO DO MEU VETOR COM REALLOC *///////////////////////////

    printf("\nRetirando os novos alunos que haviam entrado..\n");
    getchar();
    notas = realloc(notas, qtd * sizeof(float));

    /*aux = realloc(notas, qtd * sizeof(float));
    notas = aux;
    */

    //setbuf(stdin,NULL)

    for(int i = 0; i < qtd; i++){
        printf("Nota do aluno %d = %.2f\n", i + 1, notas[i]);
    }

    printf("\nMedia da turma sem os novos alunos: %.2f\n", (media / qtd));

    free(notas);

    return 0;
}   