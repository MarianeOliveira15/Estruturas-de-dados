#include <stdio.h>

int max (int n1, int n2){
  if (n1 > n2){
    return n1;
  }
  else 
      return n2;
}

int main() {
printf("%d", max(10, 20));
  return 0;
}

