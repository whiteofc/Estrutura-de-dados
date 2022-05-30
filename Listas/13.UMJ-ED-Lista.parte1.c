#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int num;
	struct No *prox;
} No;


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
No* inserir(No *lista, int valor)
{
	No *novo = (No*) malloc(sizeof(No));
	novo->num = valor;
	novo->prox = lista;
	
	return novo; 
	
}

/* função imprime: imprime valores dos Nós */
void imprimir(No *lista)
{
	No *no = lista;
	
	printf("Lista: ");
	while(no != NULL)
	{
		printf("%d ", no->num);
		no = no->prox;
	}
	 
	if(estaVazia(lista)) printf("vazia");
}

int main()
{
	No *lista = criar(); // função de lista
	int n, valor;
	
	printf("Número de elementos: ");
	scanf("%d", &n);
	
	while(n > 0)
	{
		scanf("%d", &valor);
		lista = inserir(lista, valor); // função de lista
		n--;
	}
	
	imprimir(lista); // função de lista
}
