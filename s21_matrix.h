#ifndef S21_MATRIX_H_
#define S21_MATRIX_H_

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERR_MTRX 1
#define ERR_MATCH 2

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);


#endif //S21_DECIMAL_H_