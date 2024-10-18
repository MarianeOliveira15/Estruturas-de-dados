#include <stdio.h>
#include <stdlib.h>.h>

struct aluno {
  char *nome;
  double nota1;
  double nota2;
  double media;
  struct aluno *prox;
};

typedef struct aluno Aluno;

struct sLISTA {
  Aluno *ini, *fim;
};

typedef struct sLISTA LISTA;

void inicializar(LISTA *lst);

void inicializar(LISTA *lst) {
  lst->ini = NULL;
  lst->fim = NULL;
};

void imprimir(LISTA *lst) {
  Aluno *aux = lst->ini;

  printf("[ ");
  while (aux) {
    printf("%s ", aux->nome);
    aux = aux->prox;
  }
  printf("]\n");
}

void inserir_aluno(LISTA *lst, char nome[100], double nota1, double nota2) {
  Aluno *aux = lst->ini, *ant = NULL;
  Aluno *novo = (Aluno *)malloc(sizeof(Aluno));

  for(int i = 0; i<100;i++)
    novo->nome[i] = nome[i];

  novo->nota1 = nota1;
  novo->nota1 = nota2;
  novo->media = (nota1 + nota2) / 2;  
  novo->prox = NULL;

  while (aux && novo->media < aux->media) {
    ant = aux;
    aux = aux->prox;
  }

  if (!lst->ini)
    lst->ini = lst->fim = novo;
  else if (aux == lst->ini) {
    novo->prox = lst->ini;
    lst->ini = novo;
  } else if (!aux) {
    lst->fim->prox = novo;
    lst->fim = novo;
  } else {
    ant->prox = novo;
    novo->prox = aux;
  }
}

int main(void) {

  LISTA lst;

  inserir_aluno(&lst, "Lucas", 8.3,8.2);
  inserir_aluno(&lst, "João", 7.3,7.2);
  inserir_aluno(&lst, "Maria", 9.3,9.2);

  imprimir(&lst);
  
  return 0;
}