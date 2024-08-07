#include <stdio.h>

#define MAX_IDS 32

int main() {
  int ids[MAX_IDS] = {0,1,2};
  printf("%d\n", ids[0]);
  char myStr[] = {'h', 'e', 'l','l','o', 0};
  printf("%s\n", myStr);
  return 0;
}