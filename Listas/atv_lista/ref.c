typedef struct Temp
  {
    int matricula;
    char nome[50];
    char curso[50];
    char datnasc[30];
    struct Temp *prox;
  }lista;
  // cria o inicio da lista
  lista *inicio;
//--------------------------------------------------------

// Funcao que define a lista como vazia.
void criaLista()
{
  inicio = NULL;
}

int cadastro()
{
  lista *ponteiro;
  ponteiro =  (lista *) malloc(sizeof(lista));
    if (ponteiro==NULL)
    {
      printf("Erro de alocacao\n");
      return 0;
    }
  printf("Digite a matricula:");
  scanf("%d",&ponteiro->matricula);
  printf("Digite o nome:");
  scanf(" %[^\n]",ponteiro->nome);
  printf("Digite o curso:");
  scanf(" %[^\n]",ponteiro->curso);
  printf("Digite a data de nascimento:");
  scanf(" %[^\n]",ponteiro->datnasc);
  ponteiro->prox = NULL;
    if (inicio==NULL)
      {
        inicio = ponteiro;
      }
    else
      {
     ponteiro->prox = inicio;
     inicio  = ponteiro;
     }
   return 1;
}

void imprime()
{
  lista *ponteirolista;
  if (inicio == NULL) // Caso a lista nao esteja vazia
  {
    printf("funcao-impressao>>lista-null--\n\n");
    return;
  }
  ponteirolista = inicio;
  while (ponteirolista !=NULL) {
    printf("Matricula = %d\n",ponteirolista->matricula);
    printf("Nome = %s\n",ponteirolista->nome);
    printf("Curso = %s\n",ponteirolista->curso);
    printf("Data de Nascimento = %s\n",ponteirolista->datnasc);
    ponteirolista = ponteirolista->prox;
    getchar();
    getchar();
  }
  printf("funcao-impressao>>fim-da-lista ---\n\n");
}

void imprimeponterio(lista *ponteirolista)///para imprimir resultado da função busca
{
   
  if (ponteirolista == NULL) // Caso a função busca restorne null
  {
    printf("Não achou!!");
    return;
  }
    printf("funcao-impressao--ponteiro ---\n\n");
    printf("Matricula = %d\n",ponteirolista->matricula);
    printf("Nome = %s\n",ponteirolista->nome);
    printf("Curso = %s\n",ponteirolista->curso);
    printf("Data de Nascimento = %s\n",ponteirolista->datnasc);
    getchar();
    getchar();
}

///-------------------------------------------------pesquisa
///pesquisa por matricula
lista *pesquisamatricula()
{
   int dado;
   printf("Digite a matricula:");
   scanf("%d",&dado);
  lista *ponteiro;
  if (inicio == NULL)
  {
    return NULL;  // Lista Vazia
  }
  // Caso a lista nao esteja vazia
  ponteiro = inicio;
  while (ponteiro != NULL) {
     printf("procurando %d==%d\n",dado,ponteiro->matricula);///comentar parar para de mostra lixo na tela
     getchar();///comentar ai ñ pede enter
    if (ponteiro->matricula == dado)  // achou !!
    {
       printf("\nACHOU %d==%d!!!\n",ponteiro->matricula,dado);
      
   return (ponteiro);        // retorna um ponteiro para função imprimir ponteiro
                           
                   }
    else
    {
      
        ponteiro = ponteiro->prox;
       
     }
  }
  return NULL;
}
lista *pesquisanome()
{
   char pesq[50];
   printf("Digite o nome:");
   scanf(" %[^\n]",pesq);
  lista *ponteiro;
  if (inicio == NULL)
  {
    return NULL;  // Lista Vazia
  }
  // Caso a lista nao esteja vazia
  ponteiro = inicio;
  while (ponteiro !=NULL) {
     printf("procurando %s==%s\n",pesq,ponteiro->nome);///comentar parar para de mostra lixo na tela
     getchar();///comentar ai ñ pede enter
    if (strcmp (ponteiro->nome,pesq)== 0 )  // achou !!
    {
            printf("\nACHOU %s==%s!!!\n",ponteiro->nome,pesq);      
         return (ponteiro);        // retorna um ponteiro para função imprimr
                           
                   }
    else
    {
      
        ponteiro = ponteiro->prox;
       
     }
  }
  return NULL;
}

///esvazia a fila
void  libera (lista* l)
{
   printf("\nFuncao liberar\n");
  lista* ponteiro = l;
  while (ponteiro != NULL)
      {
        lista* t = ponteiro->prox;
        free(ponteiro);
        ponteiro = t;
      }
     
}

///remove elemento
int removedado(int dado)
{
  lista *ptr, *antes;
  if (inicio==NULL)
  {
      return 0;  // Lista vazia !!!
  }
  else
  {  // Caso a lista nao esteja vazia
      ptr = inicio;
      antes = inicio;
      while (ptr !=NULL)
      {
    if (ptr->matricula == dado) // achou !!
    {
      if (ptr == inicio) // se esta removendo o primeiro da lista
      {
        inicio = inicio->prox;
        free(ptr);
        return 1; // removeu !!
      }
      else  // esta removendo do meio da lista
      {
        antes->prox = ptr->prox;  // Refaz o encadeamento
        free(ptr);                // Libera a area do nodo
        return 1;  // removeu !!
      }
    }
    else  // continua procurando no prox. nodo
    {
      antes = ptr;
      ptr = ptr->prox;
    }
      }
      return 0; // Nao achou !!!
  }
}

int main()
{
  criaLista();///iniciar a lista
  int op=1;
  for(;;) //loop infinito ate condicao de parada 'break'
    {
    cadastro();
    printf("Menu cadastro:\n1_Novo\t0_Sair:");
    scanf("%d",&op);
      if(op==0)//caso 0 sair do loop
      {
        break;
      }
    }
    printf(">>Dados cadastrados<<\n");
  imprime();///imprimir os dados cadastrados
  //-------------
  voltamenu :
  printf("Menu:\n1_Pesquisa por Matricula\n2_Pesquisa por Nome\n3_Remover\n4_Imprimi\n0_Sair:\n:");
  scanf("%d",&op);
  switch (op)
            {
              case 1:
                    {
                      imprimeponterio(pesquisamatricula());///pesquisa a matricula e retorna para funcao o ponterio para imprimir
                      break;
                    }
 
              case 2:
                    {
                      imprimeponterio(pesquisanome());
                      break;
                    }
              case 3:
                {
                   imprime();
                   removedado(pesquisamatricula()->matricula);///a pesquisa retorna um ponteiro para a funcao remover
                   printf("Removido... imprimindo lista \n");
                   imprime();
                   break;
                }           
              case 4:
                    {
                      imprime();
                      break;
                    }
              case 0:
                    {
                 libera (inicio);
                      return 0;
                      break;
                    }
            }
 
 
  goto voltamenu; //simplesmente volta ao menu
  return 0;
}