#include <stdio.h>

#include <stdio.h>

void reset (int *n){
  *n = 0;
}

int main() {
  int n = 5;
  reset(&n);
  printf("%d\n", n);
  return 0;
}



