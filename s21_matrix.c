// #include "s21_matrix.h"

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define LEAK                                       \
  if (mem_leak != 0) {                             \
    printf("Забыл память очистить придурок сука"); \
  }

int mem_leak = 0;
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
// int s21_determinant(matrix_t *A, double *result);
// int s21_inverse_matrix(matrix_t *A, matrix_t *result);

void mem_free(matrix_t *matrix);
void print_mtrx(matrix_t *test_mtrx);

// =========================================

int main() {
  matrix_t test_mtrx = {NULL};
  matrix_t test_mtrx_2 = {NULL};
  matrix_t result = {NULL};
  int rows = 3;
  int columns = 5;
  // double number = 3.123;

  s21_create_matrix(rows, columns, &test_mtrx);
  s21_create_matrix(rows, columns, &test_mtrx_2);
  // s21_create_matrix(rows, columns, &result);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_mtrx.matrix[i][j] = j-7;
    }
  }

  print_mtrx(&test_mtrx);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_mtrx_2.matrix[i][j] = 1 + j;
    }
  }
  print_mtrx(&test_mtrx_2);
  // s21_sum_matrix(&test_mtrx, &test_mtrx_2, &result);
  // s21_sub_matrix(&test_mtrx, &test_mtrx_2, &result);
  // s21_mult_number(&test_mtrx ,number, &result);
  // if (s21_mult_matrix(&test_mtrx ,&test_mtrx_2, &result) ==0){
  // print_mtrx(&result);}
  // s21_transpose(&test_mtrx, &result);
  s21_calc_complements(&test_mtrx, &result);
  print_mtrx(&result);

  printf("eq== %d\n", s21_eq_matrix(&test_mtrx, &test_mtrx_2));

  s21_remove_matrix(&test_mtrx);
  printf("free: %f ", **test_mtrx.matrix);

  mem_free(&test_mtrx_2);
  mem_free(&result);

  LEAK;
  return 0;
}

//=================================

int s21_transpose(matrix_t *A, matrix_t *result){
int error = 0;
  s21_create_matrix(A->columns, A->rows, result);

  for (int i = 0; i <result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }
  
  // проработать возвращения ошибки
  return error;

}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  s21_create_matrix(A->rows, B->columns, result);

  if ((A->columns == B->rows)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k <result->columns;k++){

        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  } else {
    error = 2;
  }

  // проработать ошибки возвращения
  return error;

}

int s21_mult_number(matrix_t *A, double number, matrix_t *result){
  int error = 0;

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  

  // проработать ошибки возвращения
  return error;

}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;

  if ((A->rows == B->rows) && (A->columns == B->columns)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  } else {
    error = 2;
  }

  // проработать ошибки возвращения
  return error;
}
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;

  if ((A->rows == B->rows) && (A->columns == B->columns)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  } else {
    error = 2;
  }

  // проработать ошибки возвращения
  return error;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int rez = 0, D, E;

  if ((A->rows == B->rows) && (A->columns == B->columns)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        D = A->matrix[i][j] * 10000000;
        E = B->matrix[i][j] * 10000000;
        if (D == E) {
          rez = SUCCESS;
        } else {
          rez = FAILURE;
          i = A->rows;
          j = B->columns;
        }
      }
    }
  } else {
    rez = FAILURE;
  }

  return rez;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) A->matrix[i][j] = 0.0;
  }
  mem_free(A);
}

void mem_free(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    free(matrix->matrix[i]);
  }
  free(matrix->matrix);
  mem_leak -= 1;
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;  // OK

  if (!(result->matrix = (double **)malloc(rows * sizeof(double *)))) {
    error = 1;
  } else {
    for (int i = 0; i < rows; i++) {
      if (!(result->matrix[i] = (double *)malloc(columns * sizeof(double)))) {
        error = 1;
      }
    }
  }
  result->rows = rows;
  result->columns = columns;
  mem_leak += 1;  // сделать макрос!!!!!!!!!!
  return error;
}

void print_mtrx(matrix_t *test_mtrx) {
  for (int i = 0; i < test_mtrx->rows; i++) {
    for (int j = 0; j < test_mtrx->columns; j++) {
      printf("%.7f ", test_mtrx->matrix[i][j]);
    }
    printf("\n");
  }
}