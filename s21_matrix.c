#include "s21_matrix.h"

#include <stdio.h>

int main() {
  matrix_t test_mtrx;

  s21_create_matrix(2, 2, &test_mtrx);
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  double mass_mtrx[rows][columns];

  matrix_t result = {mass_mtrx, rows, columns};
}