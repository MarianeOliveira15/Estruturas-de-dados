#include <stdio.h>
#include <stdlib.h>

struct LISTA {
  unsigned MAX;
  int *l, pos;
};

void criar(struct LISTA *lista, unsigned tam)
{
  lista->MAX = tam;
  lista->pos = 0;
  lista->l = malloc( sizeof(int) * tam );
}

int buscar(struct LISTA *lista,int elemento){
  for (int i = 0 ; i < lista->pos ; i++){
  if (lista->l[i] == elemento)
        return i;
  }
  return -1;
}

void imprimir(struct LISTA *lista) {
  printf("[");

  if (lista->pos > 0)
      
  for (int i = 0; i < lista->pos; i++)
    printf("%d ", lista->l[i]);
  printf("]\n");
}

void remover(struct LISTA *lista, int elemento) {
  int posicaoElemento = buscar(lista,elemento);
  if (posicaoElemento == -1)
    return;
  /*if (posicaoElemento == lista->pos - 1)
    lista->pos--;*/
  for (int i = posicaoElemento; i < lista->pos - 1; i++)
    lista->l[i] = lista->l[i + 1];
  lista->pos--;
}

void domingos_divertidos(struct LISTA *lista){
  int domingos[4] = {7,14,21,28};
  
  for (int u = 0; u < 4; u++){
      int f = domingos[u];
      remover(lista,f);
  };
}

void inserir_ord(struct LISTA *lista, int elemento) {
  if (lista->pos >= lista->MAX) // printf("Tá cheia!");
    return;
  int i;
  for (i = 0; i < lista->pos; i++)
    if (lista->l[i] > elemento) 
      break;
  for (int j = lista->pos; j > i; j--)
    lista->l[j] = lista->l[j-1];
  lista->l[i] = elemento;
  lista->pos++;
}

int main(void) {
  struct LISTA l1;
  criar(&l1,10);
  inserir_ord(&l1,7);
  inserir_ord(&l1,8);
  inserir_ord(&l1,9);
  inserir_ord(&l1,14);
  
  imprimir(&l1);
  
  domingos_divertidos(&l1);

  imprimir(&l1);
  
  return 0;
}