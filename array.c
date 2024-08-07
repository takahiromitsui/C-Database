#include <stdio.h>

#define MAX_IDS 32

int main() {
  int ids[MAX_IDS] = {0,1,2};
  printf("%d\n", ids[0]);
  char myStr[] = {'h', 'e', 'l','l','o', 0};
  printf("%s\n", myStr);
  int temp;
  printf("What temperature is it?\n");
  scanf("%d", &temp);
  if (temp > 25) {
    printf("It's too hot, innit?\n");
  } else if (temp >15) {
    printf("It's all right\n");
  } else {
    printf("It's cold\n");
  };
  return 0;
}