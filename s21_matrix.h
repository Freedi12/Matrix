#ifndef S21_MATRIX_H_
#define S21_MATRIX_H_

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define INCORRECT_MATRIX 1
#define ERROR_COMPUTE 2


typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

// int mem_leak = 0;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

void mem_free(matrix_t *matrix);
void print_matrix(matrix_t *test_mtrx);
int s21_minor(int rows, int columns, matrix_t *matrix, matrix_t *result);
int check_matrix(matrix_t *matrix);
void zero_matrix_pole(matrix_t *result) ;
int check_square_matrix(matrix_t *matrix);
int check_size_matrix(matrix_t *A, matrix_t *B);


#endif //S21_DECIMAL_H_