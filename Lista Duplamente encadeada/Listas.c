#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *ant;
  struct sNODE *prox;
};

struct sLISTA{
  struct sNODE *ini, *fim;
};

typedef struct sLISTA LISTA;

void inicializar(LISTA *lst);
void apagar(LISTA *lst);

void inserir_ord(LISTA *lst, int dado);
void remover(LISTA *lst, int dado);
struct sNODE *buscar(LISTA *lst, int dado);

int obter(struct sNODE *node);
int tamanho(LISTA *lst);

int main(void) {
  printf("Hello World\n");
  return 0;
}

void inicializar(LISTA *lst){
  lst->ini = NULL;
  lst->fim = NULL;
};

void apagar(LISTA *lst){
  struct sNODE *aux = lst->ini, *ant;
  while (aux){
    ant = aux;
    aux = aux->prox;
    free(aux);
  }
}

void inserir_ord(LISTA *lst, int dado){
   struct sNODE *aux = lst->ini;
    struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
    novo->dado = dado;
    novo->ant = NULL;
    novo->prox = NULL;

    while(aux && dado > aux->dado)
    aux = aux->prox;

    if (!lst->ini)
      lst->ini = lst->fim = novo;
    else if (aux == lst->ini){
    novo->prox = lst->ini;
    lst->ini->ant = novo;
    lst->ini = novo;
    } else if (!aux){
    lst->fim->prox = novo;
    novo->ant = lst->fim;
    lst->fim = novo;
    } else {
    aux->ant->prox = novo;
    novo->ant = aux->ant;
    novo->prox = aux;
    aux->ant = novo;
    }
};

void remover(LISTA *lst, int dado){
  struct sNODE *aux = buscar(lst,dado);
  if (!aux)
  return;

  if (!aux->ant && !aux->prox)
  lst->ini = lst->fim = NULL;
  else if (aux == lst->ini) {
  lst->ini = lst->ini->prox;
  lst->ini->ant = NULL;
  } else if (aux == lst->fim) {
  lst->fim = lst->fim->ant;
  lst->fim->prox = NULL;
  } else {
  aux->ant->prox = aux->prox;
  aux->prox->ant = aux->ant;
  }
  free(aux);  
};

struct sNODE *buscar(LISTA *lst, int dado){
  struct sNODE *aux = lst->ini;

  while (aux){
  if (dado == aux->dado)
        return aux;
  aux = aux->prox;
  }

  return NULL;
}

int obter(struct sNODE *node){
  if (!node){
  printf("Erro ao obter dado. Ponteiro invalido.");
  exit(0);
  }

  return node->dado;
}

int tamanho(LISTA *lst){
  struct sNODE *aux = lst->ini;
  int tam = 0;

  while (aux){
  tam++;
  aux = aux->prox;
  }

  return tam;
}