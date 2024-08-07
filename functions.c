#include <stdio.h>

int add(int x, int y) {
  int z = x+y;
  return z;
}

int main() {
  int other_int = add(10, 20);
  printf("%d\n", other_int);
  return 0;
}