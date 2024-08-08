#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_EMPLOYEES 1000

struct employee_t {
  int id;
  float income;
  bool ismanager;
};

void initialize_employee(struct employee_t *e) {
  e->id = 0;
  e-> income = 0;
  e->ismanager = false;
  return;
};

int main() {
  // struct employee_t Ralph;

  // initialize_employee(&Ralph);

  // printf("%f\n", Ralph.income);
  int n = 4;
  struct employee_t *employees = malloc(sizeof(struct employee_t)*n);

  if (employees == NULL) {
    printf("The allocator failed\n");
    return -1;
  };
  initialize_employee(&employees[0]);

  printf("%f\n", employees[0].income);
  free(employees);
  employees = NULL;
  return 0;
}