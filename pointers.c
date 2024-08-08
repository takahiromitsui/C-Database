#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_EMPLOYEES 1000

struct employee_t {
  int id;
  float income;
  bool ismanager;
};

int initialize_employee(struct employee_t *e) {
  static int numEmployees = 0;
  numEmployees++;
  e->id = numEmployees;
  e-> income = 0;
  e->ismanager = false;
  return numEmployees;
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

  for (int i= 0; i<n; i++) {
    int id = initialize_employee(&employees[i]);
    printf("New Employee, ID is %d\n", id);
  };

  initialize_employee(&employees[0]);

  printf("%f\n", employees[0].income);
  free(employees);
  employees = NULL;
  return 0;
}