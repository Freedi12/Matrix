//#include "s21_matrix.h" 

#include <stdio.h>

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);

int main() {
  matrix_t test_mtrx;
  printf("test");
  int rows = 2;
  int columns = 2;

  s21_create_matrix(rows, columns, &test_mtrx);
  
  //test_mtrx = {{1,2,3,4},{rows},{columns}};
  test_mtrx.matrix[0][0] = 2;
  test_mtrx.matrix[0][1] = 2;
  test_mtrx.matrix[1][0] = 3;
  test_mtrx.matrix[1][1] = 4;

  printf("test%f", **test_mtrx.matrix);
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  printf("test");
  double mass_mtrx[rows][columns];

  //result = {mass_mtrx, rows, columns};
  *result->matrix = mass_mtrx;
  result->rows = rows;
  result->columns = columns;

  return 0;
}