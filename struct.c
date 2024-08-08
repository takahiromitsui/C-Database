#include <stdio.h>
#include <stdbool.h>


#define MAX_IDS 32
# define MAX_EMPLOYEES 1000

struct employee_t {
  int id;
  char firstname[64];
  char lastname[64];
  float income;
  bool ismanager;
};

union myuion_u{
  int x;
  char c;
  short s;
};

int main () {
  struct employee_t employees[MAX_EMPLOYEES];
  int i = 0;
  for (i=0; i<MAX_EMPLOYEES; i++) {
    employees[i].income = 0;
    employees[i].ismanager = false;
  };
  printf("%f\n", employees[10].income);

  union myuion_u u;
  u.x = 0x41424344;
  printf("%hx %hhx", u.s, u.x);
  return 0;

}