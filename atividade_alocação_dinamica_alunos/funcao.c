 #include <stdio.h>
 #include <stdlib.h>

float aumentar_alunos(float *p, int qtd, int qtd2, int qtd_total, float media){


    printf("\nAbrimos vagas para novos alunos, informe quantos deseja inserir: ");

    scanf("%d", &qtd2);

    qtd_total = qtd + qtd2;
    p = realloc (p, qtd2 * sizeof(float));

    printf("\nInsira a notas dos %d novos alunos: \n", qtd2);

    for(int i = qtd; i < qtd_total; i++){
        printf("Insira a nota do aluno %d: ", i + 1);
        scanf("%f", &p[i]);
        media += p[i];
    }

    printf("\n");

    for(int i = 0; i < qtd_total; i++){
        printf("Nota do aluno %d = %.2f\n", i + 1, p[i]);
    }

    printf("\nMedia da turma com os novos alunos: %.2f\n", (media / qtd_total));

}

float diminuir_alunos(float *p, int qtd, int qtd2, int qtd_total, float media){

    printf("\nRetirando os novos alunos que haviam entrado..\n");
    p = realloc(p, qtd * sizeof(float));

    /*aux = realloc(notas, qtd * sizeof(float));
    notas = aux;
    */

    setbuf(stdin,NULL);

    for(int i = 0; i < qtd; i++){
        printf("Nota do aluno %d = %.2f\n", i + 1, p[i]);
    }

    printf("\nMedia da turma sem os novos alunos: %.2f\n", (media / qtd));

    free(p);

}
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

    aumentar_alunos(notas, qtd, qtd2, qtd_total, media);
    diminuir_alunos(notas, qtd, qtd2, qtd_total, media);
    return 0;
}   