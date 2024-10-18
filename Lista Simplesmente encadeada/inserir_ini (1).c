#include <stdio.h>
#include <stdlib.h>

struct sNODE {
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir_ini(int dado);
void imprimir();

int main(void) {
  inserir_ini(7);
  inserir_ini(5);
  inserir_ini(8);
  inserir_ini(9);
  imprimir();

}

void inserir_ini(int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
  novo->dado = dado;
  novo->prox = NULL;

  if (!ini)
  ini = fim = novo;
  else {
  novo->prox = ini;
  ini = novo;
    }
}

void imprimir(){
  struct sNODE *aux = ini;

  printf("[ ");
  while (aux){
  printf("%d ", aux->dado);
  aux = aux->prox;
  }
  printf("]\n");
}

