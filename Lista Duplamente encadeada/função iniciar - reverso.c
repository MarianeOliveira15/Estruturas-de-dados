#include <stdio.h>
#include <stdlib.h>

struct sNODE {
  int dado;
  struct sNODE *prox;
  struct sNODE *ant;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir_ini(int dado);
void remover(int dado);
struct sNODE *buscar (int dado);

int obter (struct sNODE *node);
int tamanho ();
void imprimir ();
void apagar ();


void inserir_ini(int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  struct sNODE *aux = ini;
  
  novo -> dado = dado;
  novo -> prox = NULL;
  novo -> ant = NULL;

  while (dado && aux->dado < dado){
    aux = aux->prox;
  };
  
  if (!ini){
    ini = fim =novo;
  }
  else {
   novo->prox = ini;
   ini->ant = novo;
   ini = novo;
  }
  
};



void imprimir_reverso(){
  struct sNODE *aux = fim;
  printf("[");
  while(aux){
    printf("%d", aux->dado);
    aux = aux->ant;
  }
  printf("]\n");
};

void remover(int dado);
struct sNODE *buscar (int dado);

int obter (struct sNODE *node);
int tamanho ();
void imprimir ();
void apagar ();

int main(void) {
  inserir_ini(7);
  inserir_ini(5);
  inserir_ini(8);
  inserir_ini(9);
  imprimir_reverso();
  return 0;
}