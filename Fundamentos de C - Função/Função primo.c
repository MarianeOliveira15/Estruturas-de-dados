#include <stdio.h>

int primo (int n){
  int v = 0, valor = 0;
  for (int c = 1; c <= n; c++){
    valor = n%c;
    if (valor == 0){
      v++;
    }
  }
  if (v <= 2){
     return 1;
   }
  return 0;
}


int main() {
  printf("%d" , primo(2));
  return 0;
}