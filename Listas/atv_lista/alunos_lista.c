#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int idade;
    float notas[4];
    int matricula;
	struct No *prox;
}No;

/* criação: retorna lista vazia */
No* criar()
{
	return NULL;
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int estaVazia(No *lista)
{
	return (lista == NULL);
}

/* Inserção no início: retorna lista atualizada. Deve-se atualizar 
 * a variável que representa a lista a cada inserção de um novo elemento. */
No* inserir(No *lista, char nome[50], int idade, float notas[4], int matricula)
{
	No *novo = (No*) malloc(sizeof(No));
	strcpy(novo->nome, nome);
	novo->idade = idade;
	novo->matricula = matricula;
	for(int i = 0; i < 4; i++){
		printf("Insira sua nota do %d Bimestre\n", i + 1);
		novo->notas[i] = notas[i];
	}
	
	novo->prox = lista;
	
	return novo; 
	
}

/* função imprime: imprime valores dos elementos */
void imprimir(No *lista)
{
	No *no = lista;
	
	printf("Lista: \n");
	while(no != NULL)
	{
        printf("Nome do Aluno: %s \n", no->nome);
		printf("Idade = %d\n", no->idade);
		printf("Matricula do aluno: %d\n", no->matricula);

		for(int i = 0; i < 4; i++){
			printf("Notas %d Bimestre = ", i);
			printf("%.2f\n", no->notas[i]);
		}
		printf("\n");
		no = no->prox;
	}
	
	if(estaVazia(lista)) printf("vazia");
}

/* função retira: retira elemento da lista. Retorna lista atualizada. Deve-se
 * atualizar a variável que representa a lista a cada remoção de um elemento. */
No* remover(No *lista, char nome[50], int idade, float notas[4], int matricula)
{
	No *anterior = NULL;
	No *no = lista;
	
	while(no != NULL && no->num != nome != idade != notas != matricula)
	{
		anterior = no;
		no = no->prox;
	}
	
	if(no == NULL) 
	{
		printf("Valor não encontrado!\n");
		return lista;
	}
		
	if(anterior == NULL)
	{
		lista = no->prox;
	}
	else
	{
		anterior->prox = no->prox;
	}
	
	free(no);
	return lista;
}

/* destrói a lista, liberando todos os elementos alocados */
void esvaziar(No *lista)
{
	No *no = lista;
	while(no != NULL)
	{
		No *temp = no->prox;
		free(no);
		no = temp;
	}
}

int main()
{
	No *lista = criar();
	int opc;

	char nome[50];
    int idade;
    float notas[4];
    int matricula;
	
	do
	{
		printf("\n\nEscolha uma opção:\n");
		printf("1 - Adicionar valor no início;\n");
		printf("2 - Remover valor;\n");
		printf("3 - Imprimir lista;\n");
		printf("4 - Esvaziar lista;\n");
		printf("0 - Sair.\n");
		scanf("%d", &opc);
		
		switch(opc)
		{
			case 1: 
				printf("\nDados do aluno: \n");
				printf("Insira seu nome\n");
				setbuf(stdin, NULL);
				fgets(nome, 50, stdin);
				printf("Insira sua idade\n");
				scanf("%d", &idade);
				printf("Insira sua matricula\n");
				scanf("%d", &matricula);


				for(int i = 0; i < 4; i++){
					printf("Insira sua nota do %d Bimestre\n", i + 1);
					scanf("%f", &notas[i]);
				}
				lista = inserir(lista,nome,idade,notas,matricula);
				break;
			// case 2:
			// 	printf("\nValor a ser removido: ");
			// 	scanf("%d", &valor);
			// 	lista = remover(lista, valor);
			// 	break;
			case 3:
				imprimir(lista);
				break;
			case 4:
			  esvaziar(lista);
			  lista = criar();
			  break;
		}
	} while(opc != 0);
}
