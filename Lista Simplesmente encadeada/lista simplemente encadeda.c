#include <stdio.h>
#include <stdlib.h>

struct sNode {
  int dado;
  struct sNode *prox;
};

struct sNode *ini = NULL, *fim = NULL;

void inserir (int dado){
  struct sNode *novo = (struct sNode*) malloc(sizeof(struct sNode));]
  novo->dado = dado;
  novo->prox = NULL;

  if (ini == NULL)
    novo=ini=fim;
  else{
    fim->prox = novo;
    fim = novo;
  }
}

void remover (int dado){
  struct sNode *aux = ini, *ant = NULL;

  while(aux){
    if(aux->dado == dado){
      if (ini == aux){
        ini = aux->prox;
      }
      else if (fim == aux){
        ant->prox = NULL;
        fim = ant;
    }
      else{
        ant->prox = aux->prox;
      }
      free(aux);
    }
    ant = aux;
    aux = aux-> prox;
  }

  
}

struct sNode *buscar (int dado){
  struct sNode *aux = ini;

  while(aux){
    if (aux->dado == dado){
      return aux;
    aux = aux->prox;
    }
      
  }
}

int tamanho (){
  struct sNode *aux = ini;

  int tam = 0; 
  while(aux){
    tam++;
  aux = aux->prox;
  }
}

int obter (struct sNode * node){
  if (!node){
    printf("Erro ao obter dado. Ponteiro invalido");
    exit(0);
  }
  return node->dado;
}


void imprimir(){
  struct sNode *aux = ini;

  printf("[ ");
  while(aux){
    printf("%d", aux->dado);
    aux = aux->prox;
  }
  printf("]\n");
}

void apagar(){
  struct sNode *aux = ini, *ant = NULL;

  while(aux){
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  ini = fim = NULL;
}

void inserir_ord(int elemento);

int main(void) {
  printf("Hello World\n");
  return 0;
}