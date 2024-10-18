#include <stdio.h>

int array_soma (int array[], int t, int n){
  int soma = 0;
  for (int i = 0; i < t; i++){
    soma += array[i] * n;
  }
  return soma;
}

int main() {
  int array[3] = {1,2,3};
  printf("%d\n", array_soma(array, 3, 2));
  return 0;
}