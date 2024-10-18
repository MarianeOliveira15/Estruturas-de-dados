#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos=0;

void inserir(int elemento){
  if (pos < MAX)
    l[pos++] = elemento;
  else
    printf("Lista cheia\n");
  return;
}

void inserir_ini (int elemento) {
  if (pos < MAX){
    for (int i = pos; i > 0; i--){
      l[i] = l[i-1];
    }
    l[0] = elemento;
  }
  else
    printf("Lista cheia\n");
  return;
}

int main (){
  inserir(6);
  inserir(8);
  inserir_ini(7);
  printf("%d", l[0]);
    return 0;
}