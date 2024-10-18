#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos=0;

void inserir(int elemento){
 int v = 0;

  for (int i = 0 ; i <= pos ; i++){
    if (l[i] == elemento)
      v = 1;
    }

  if (pos < MAX){
    if (v != 1)
      l[pos++] = elemento; 
  }
  else
    printf("Lista cheia\n");
}

int main (){
  inserir(6);
  inserir(6);
  inserir(5);
  printf("%d", l[0]);
}
