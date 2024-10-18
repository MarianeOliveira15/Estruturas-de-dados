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

int buscar(int elemento){
  for (int i = 0 ; i < pos ; i++){
  if (l[i] == elemento)
    return i;
  }
  return -1;
}

void remover(int elemento){
  int c = 0;
  int p = 0;
  
  for (int i = 0 ; i < pos -1; i++){
    p = buscar(elemento);
    if (l[p] == elemento)
      c++;
  }
  
  if (p == -1)
    return;
  
  while (c > 0){
    for (int i = p ; i < pos -1; i++)
    l[i] = l[i+1];
    pos--;
    c--;
  }

}

int main (){
  inserir(6);
  inserir(6);
  inserir(5);
  remover(6);
  printf("%d", l[0]);
}
