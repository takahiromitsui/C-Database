#include <stdio.h>
#include <stdbool.h>

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
  struct employee_t Ralph;

  initialize_employee(&Ralph);

  printf("%f\n", Ralph.income);

  return 0;
}