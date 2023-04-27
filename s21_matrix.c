#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int rez = INCORRECT_MATRIX;
  if (result != NULL) {
    if (check_matrix(A) == SUCCESS && result != NULL) {
      double determinant = 0.0;
      s21_determinant(A, &determinant);
      if (check_square_matrix(A) == SUCCESS && determinant != 0.0) {
        // s21_create_matrix(A->rows, A->columns, result);
        if (determinant != 0.0) {
          s21_calc_complements(A, result);
          matrix_t tmp;
          s21_transpose(result, &tmp);
          for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
              result->matrix[i][j] = 0.0;
              result->matrix[i][j] =
                  (double)tmp.matrix[i][j] / (double)determinant;
            }
          }
          s21_remove_matrix(&tmp);
          rez = OK;
        }
      } else {
        rez = ERROR_COMPUTE;
        zero_matrix_pole(result);
      }
    } else {
      zero_matrix_pole(result);
    }
  }
  return rez;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int exit = INCORRECT_MATRIX;
  if (result != NULL) {
    if (check_matrix(A) == SUCCESS && result != NULL) {
      if (check_square_matrix(A) == SUCCESS) {
        s21_create_matrix(A->rows, A->columns, result);
        if (A->rows == 1) {
          result->matrix[0][0] = 1;
        } else {
          for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
              matrix_t minor;
              s21_minor(i, j, A, &minor);
              double number = 0.0 / 0.0;
              s21_determinant(&minor, &number);
              result->matrix[i][j] = ((i + j) % 2 == 1 ? -1 : 1) * number;
              s21_remove_matrix(&minor);
            }
          }
        }
        exit = OK;
      } else {
        exit = ERROR_COMPUTE;
        zero_matrix_pole(result);
      }
    } else {
      zero_matrix_pole(result);
    }
  }
  return exit;
}

int s21_determinant(matrix_t *A, double *result) {
  int exit = INCORRECT_MATRIX;
  if (check_matrix(A)) {
    if (check_square_matrix(A) == SUCCESS && result != NULL) {
      int minus = -1;
      double determinant = 0.0;
      if (A->rows == 1) {
        determinant = A->matrix[0][0];
      } else if (A->rows == 2) {
        determinant += (A->matrix[0][0] * A->matrix[1][1] -
                        A->matrix[1][0] * A->matrix[0][1]);
      } else {
        for (int i = 0; i < A->rows; i++) {
          minus *= -1;
          matrix_t MINOR;
          s21_minor(i, 0, A, &MINOR);
          s21_determinant(&MINOR, result);
          determinant += (minus * A->matrix[i][0] * *result);
          s21_remove_matrix(&MINOR);
        }
      }
      *result = determinant;
      exit = OK;
    } else {
      exit = ERROR_COMPUTE;
    }
  }
  return exit;
}

int s21_minor(int rows, int columns, matrix_t *matrix, matrix_t *result) {
  int error = 0;  // OK
  if (check_square_matrix(matrix) == SUCCESS) {
    s21_create_matrix(matrix->rows - 1, matrix->columns - 1, result);
    int x = 0;
    for (int i = 0; i < matrix->rows; i++) {
      if (i != rows) {
        int y = 0;
        for (int j = 0; j < matrix->columns; j++) {
          if (j != columns) {
            result->matrix[x][y] = matrix->matrix[i][j];
            y++;
          }
        }
        x++;
      }
    }
  } else {
    error = 1;
  }
  return error;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = INCORRECT_MATRIX;

  if (result != NULL) {
    if (check_matrix(A) == SUCCESS) {
      s21_create_matrix(A->columns, A->rows, result);
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
      error = OK;
    } else {
      zero_matrix_pole(result);
    }
  }

  // проработать возвращения ошибки
  return error;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = INCORRECT_MATRIX;

  if (check_matrix(A) == SUCCESS && check_matrix(B) == SUCCESS &&
      result != NULL) {
    if ((check_size_matrix(A, B) == SUCCESS)) {
      if (A->columns == B->rows) {
        s21_create_matrix(A->rows, B->columns, result);
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            for (int k = 0; k < result->columns; k++) {
              result->matrix[i][j] = A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
        error = OK;
      }
    } else {
      zero_matrix_pole(result);
      error = ERROR_COMPUTE;
    }
  } else {
    zero_matrix_pole(result);
  }
  // проработать ошибки возвращения
  return error;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = INCORRECT_MATRIX;

  if (result != NULL) {
    if (check_matrix(A) == SUCCESS) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
      error = OK;
    } else {
      zero_matrix_pole(result);
    }
  }
  // проработать ошибки возвращения
  return error;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = INCORRECT_MATRIX;

  if (check_matrix(A) == SUCCESS && check_matrix(B) == SUCCESS &&
      result != NULL) {
    if ((check_size_matrix(A, B) == SUCCESS)) {
      s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
      error = OK;
    } else {
      zero_matrix_pole(result);
      error = ERROR_COMPUTE;
    }
  } else {
    zero_matrix_pole(result);
  }
  // проработать ошибки возвращения
  return error;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = INCORRECT_MATRIX;

  if (check_matrix(A) == SUCCESS && check_matrix(B) == SUCCESS &&
      result != NULL) {
    if ((check_size_matrix(A, B) == SUCCESS)) {
      s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
      error = OK;
    } else {
      zero_matrix_pole(result);
      error = ERROR_COMPUTE;
    }
  } else {
    zero_matrix_pole(result);
  }
  // проработать ошибки возвращения
  return error;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int rez = FAILURE;
  if (check_matrix(A) == SUCCESS && check_matrix(B) == SUCCESS) {
    if (check_size_matrix(A, B) == SUCCESS) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          if (A->matrix[i][j] * 10000000 == B->matrix[i][j] * 10000000) {
            rez = SUCCESS;
          } else {
            rez = FAILURE;
            i = A->rows;
            j = B->columns;
          }
        }
      }
    }
  }
  return rez;
}

// Создание матриц
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = INCORRECT_MATRIX;  // OK

  if (result != NULL) {
    if (rows > 0 && columns > 0) {
      if (!(result->matrix = (double **)malloc(rows * sizeof(double *)))) {
        error = 1;
      } else {
        for (int i = 0; i < rows; i++) {
          if (!(result->matrix[i] =
                    (double *)malloc(columns * sizeof(double)))) {
            error = 1;
          }
        }
      }
      result->rows = rows;
      result->columns = columns;
      error = OK;
    } else {
      zero_matrix_pole(result);
    }
  }
  // mem_leak += 1;  // сделать макрос!!!!!!!!!!
  return error;
}

//===================================

// УДаление матриц
void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->rows > 0 && A->columns > 0 && A->matrix != NULL) {
      for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
      }
      free(A->matrix);
    } else {
      zero_matrix_pole(A);
    }
    A->rows = 0;
    A->columns = 0;
    A->matrix = NULL;
  }
}
// void s21_remove_matrix(matrix_t *A) {
//   for (int i = 0; i < A->rows; i++) {
//     for (int j = 0; j < A->columns; j++) {
//       A->matrix[i][j] = 0.0;
//     }
//   }
//   zero_matrix_pole(A);
//   mem_free(A);
// }

// void mem_free(matrix_t *matrix) {
//   for (int i = 0; i < matrix->rows; i++) {
//     free(matrix->matrix[i]);
//   }
//   free(matrix->matrix);
//   // mem_leak -= 1;  // сделать макрос!!!!!!!!!!
// }

// Зануление матриц
void zero_matrix_pole(matrix_t *result) {
  result->columns = 0;
  result->rows = 0;
  result->matrix = NULL;
}

// Проверка матриц
int check_matrix(matrix_t *matrix) {
  int result = FAILURE;
  if (matrix != NULL) {
    if (matrix->rows > 0 && matrix->columns > 0 && matrix->matrix != NULL) {
      result = SUCCESS;
    } else {
      matrix->rows = 0;
      matrix->columns = 0;
      matrix->matrix = NULL;
    }
  }
  return result;
}

// Проверка на квадратность
int check_square_matrix(matrix_t *matrix) {
  int result = FAILURE;
  if (matrix->rows == matrix->columns) result = SUCCESS;
  return result;
}

// ПРоверка на равенство размеров
int check_size_matrix(matrix_t *A, matrix_t *B) {
  int result = FAILURE;
  if (A->rows == B->rows && A->columns == B->columns) result = SUCCESS;
  return result;
}

// Печать матриц
void print_matrix(matrix_t *test_mtrx) {
  for (int i = 0; i < test_mtrx->rows; i++) {
    for (int j = 0; j < test_mtrx->columns; j++) {
      printf("%.7f ", test_mtrx->matrix[i][j]);
    }
    printf("\n");
  }
}