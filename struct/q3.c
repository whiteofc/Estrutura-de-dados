#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct
{
    char nome[50];
    int idade;
    float notas[4];
    int matricula;

}alunos;

void imprimir(alunos *aluno1){
    printf("Nome do Aluno: %s \n", aluno1->nome);
    printf("Idade = %d\n", aluno1->idade);
    printf("Matricula do aluno: %d\n", aluno1->matricula);

    for(int i = 0; i < 4; i++){
        printf("Notas %d Bimestre = ", i);
        printf("%.2f\n", aluno1->notas[i]);
    }
    free(aluno1);
}

int main(){

    srand (time(NULL));
    alunos *aluno1;

    aluno1 = (struct alunos*) malloc (sizeof(alunos));

    printf("Insira seu nome\n");
    fgets(aluno1->nome, 50, stdin);
    printf("Insira sua idade\n");
    scanf("%d", &aluno1->idade);
    printf("Insira sua matricula\n");
    scanf("%d", &aluno1->matricula);


    for(int i = 0; i < 4; i++){
        printf("Insira sua nota do %d Bimestre\n", i + 1);
        scanf("%f", &aluno1->notas[i]);
    }

    imprimir(aluno1);
    return 0;
}
