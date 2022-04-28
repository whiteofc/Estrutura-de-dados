#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int idade;
    float notas[4];
    int matricula;

}alunos;


void busca(alunos aluno1[6], int matricula, int index){
    
    for(int i = 0; i < 6; i++){
        if(aluno1[i].matricula == matricula){
            printf("A matricula está localizada no Index [%d]", i);
            index = i;
            imprimir(aluno1,index);
            break;
        }
        else if(i == 5){
            printf("Matricula Inexistente\n");
            break;
        }
    }
}

void imprimir(alunos aluno1[6], int index){

    printf("\n\nNome do Aluno %d: %s\n", index + 1, aluno1[index].nome);
    printf("Idade do aluno %d: %d\n", index + 1,aluno1[index].idade);
    printf("Matricula do aluno %d: %d\n\n", index + 1, aluno1[index].matricula);

    for(int i = 0; i < 4; i++){
        printf("nota do aluno [%d] = %.2f\n",index + 1, aluno1[index].notas[i]);
    }
}

int main(){


    srand (time(NULL));
    alunos aluno1[6];
    int i = 0, matricula;
    char *p;

    FILE *pont_alunos;
    FILE *pont_matriculas;
    

    pont_alunos = fopen("Alunos.txt","r");
    while(!feof(pont_alunos)){
        fgets(aluno1[i].nome,50,pont_alunos);
        p = strtok(aluno1[i].nome, ", ");
        while(p){
            aluno1[i].idade = atoi(p);
            p = strtok(NULL, ", ");
        }
        setbuf(stdin, NULL);
        i++;
    }

    fclose(pont_alunos);

    i = 0;

    pont_matriculas = fopen("Matriculas.txt","r");

    while(!feof(pont_matriculas)){
        fscanf(pont_matriculas,"%d", &aluno1[i].matricula);
        i++;
    }
    fclose(pont_alunos);

    for(i = 0; i < 6; i++){
        for(int k = 0; k < 4; k++){
        aluno1[i].notas[k] = rand () % 10;
        }
    }

    printf("Bem vindo a UMJ!\n");
    printf("Informe o número da matricula do aluno:");
    scanf("%d", &matricula);

    busca(aluno1, matricula, 0);
    return 0;
}
