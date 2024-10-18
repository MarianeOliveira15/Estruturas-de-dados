#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct aluno {
  char *nome;
  int nota21, nota10;
  int media;
};

struct sNODE {
  struct aluno dado;
  struct sNODE *prox;
};

struct sLISTA {
  struct sNODE *ini, *fim;
};
typedef struct sLISTA LISTA;
typedef struct sNODE NOV;

void inicializar(LISTA *lst);

struct sNODE *buscar(LISTA *lst, char dado){
  struct sNODE *aux = lst->ini;

  while (aux){
  if (dado == aux->dado)
        return aux;
  aux = aux->prox;
  }

  return NULL;
}

void inserir_ord(LISTA *lst, struct aluno al) {
  NOV *aux = lst->ini, *ant = NULL;
  NOV *novo = (NO*)malloc(sizeof(NO));
  novo->dado = al;

  novo->dado.nome=(char*)malloc(sizeof(char)*(strlen(al.nome)+1));
  strcpy(novo->dado.nome, al.nome);

  novo->prox = NULL;

}

int main(void) {
  printf("Hello World\n");
  return 0;
}