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

void imprimir(alunos aluno1[2]){
    for(int i = 0; i < 2; i++){
        printf("#####################");
        printf("\nNome do Aluno %d: %s", i + 1, aluno1[i].nome);
        printf("Idade do aluno %d: %d\n", i + 1,aluno1[i].idade);
        printf("Matricula do aluno %d: %d\n\n", i + 1, aluno1[i].matricula);
    for(int j = 0; j < 4; j++){
        printf("%dº nota do aluno [%d] = %.2f\n",j + 1 ,i + 1, aluno1[i].notas[j]);
        }
    }
}

int main(){


    srand (time(NULL));
    alunos aluno1[2];
    for(int i = 0; i < 2; i++){
        printf("Insira o nome do aluno [%d]\n", i + 1);
        fgets(aluno1[i].nome, 50, stdin);
        setbuf(stdin, NULL);

        printf("Insira a idade do aluno [%d]\n", i + 1);
        scanf("%d", &aluno1[i].idade);
        setbuf(stdin, NULL);

        printf("Insira a matricula do aluno [%d]\n", i + 1);
        scanf("%d", &aluno1[i].matricula);
        setbuf(stdin, NULL);

        for(int j = 0; j < 4; j++){
            printf("Insira a %dº nota do aluno [%d] \n",j + 1 ,i + 1);
            scanf("%f", &aluno1[i].notas[j]);
            //aluno1[i].notas[j] = rand() % 10;
        }
        setbuf(stdin, NULL);
    }
    imprimir(aluno1);
    return 0;
}
