#include <check.h>
// #include <limits.h>
// #include <math.h>
#include <stdio.h>
// #include <time.h>

#include "s21_matrix.h"

#define ARRAY_DOUBLE                                                           \
  (double[]) {                                                                 \
    4.12512, 1.32345, 5.3434, 9.123, 3.423, -7, -2342.2, 6, 1, 0.4157, 0.5006, \
        0.1884, 0.2344, 0.8225, 0.4371, 0.0808, 0.013, 0.8204, 0.5015, 0.7873, \
        0.1538, 0.9806, 0.9468, 0.078, 0.4977, 0.743, -0.0434, 0.9209, 0.749,  \
        0.6829, 0.739, 0.1384, 0.8109, 0.5913, 0.6107, 0.2687, -0.3779,        \
        0.7682, 0.2943, 0.8724, 0.3116, 0.1198, 0.2749, 0.0641, 0.5021,        \
        -0.8657, 0.4406, 0.6234, 0.171, 0.0579, 0.086, 0.55, 0.8024, 0.5736,   \
        -0.1404, 0.1462, 0.6172, 0.4292, 0.058, 0.2317, 0.5967, 0.4873,        \
        0.1726, -0.5706, 0.6767, 0.3622, 0.3775, 0.643, 0.2117, 0.1683, 0.703, \
        0.2448, -0.5261, 0.6291, 0.4757, 0.0339, 0.7057, 0.8827, 0.5759,       \
        0.6319, 0.3025, -0.42, 0.7499, 0.6911, 0.5967, 0.1891, 0.336, 0.2373,  \
        0.4509, 0.4646, -0.6515, 0.9486, 0.7103, 0.0626, 0.2757, 0.8244,       \
        0.9472, 0.7044, -0.3874, 0.1399, 0.4882, 0.7975, 0.4117, 0.0027,       \
        0.3549, 0.8414, 0.0239, -0.1733, 0.098, 0.1065, 0.4405, 0.7345,        \
        0.8534, 0.426, 0.9292, 0.1767, -0.7374, 0.4815, 0.9739, 0.4876,        \
        0.0262, 0.1403, 0.1921, 0.7472, -0.5169, 0.7543, 0.5345, 0.4635,       \
        0.3534, 0.6513, 0.0867, 0.0013, 0.4953, -0.4359, 0.1437, 0.5049,       \
        0.0084, 0.7472, 0.3362, 0.7553, 0.1652, 0.1627, -0.1393, 0.3445,       \
        0.024, 0.9169, 0.0952, 0.2843, 0.1334, 0.099, 0.087, -0.4658, 0.7305,  \
        0.8998, 0.1138, 0.3479, 0.6054, 0.6645, 0.4858, -0.6006, 0.3069,       \
        0.5604, 0.8199, 0.4466, 0.0198, 0.4392, 0.2393, 0.4175, -0.2823,       \
        0.4243, 0.1683, 0.9902, 0.1453, 0.2186, 0.3224, 0.8634, 0.001,         \
        -0.8476, 0.7231, 0.5999, 0.6591, 0.2503, 0.3301, 0.2544, 0.5644,       \
        0.6209, 0.2708, 0.5955, 0.3221, 0.7958, 0.8995, 0.3439, 0.2614,        \
        0.7356, 0.4484, -0.6048, 0.3428, 0.6927, 0.3247, 0.5848, 0.6776,       \
        0.6777, 0.002, 0.7091, 0.9307, -0.0968, 0.3205, 0.5119, 0.5774,        \
        124234.4353, 2342424.6435, -235234.6433, 7654, 124, 1, 0.0, -0.0,      \
        2341.314                                                               \
  }

#define ARRAY_DOUBLE2                                                          \
  (double[]) {                                                                 \
    0.4157, 0.5006, 0.1884, 0.2344, 0.8225, 0.4371, 0.0808, 0.013, 0.8204,     \
        0.5015, 0.7873, 0.1538, 0.9806, 0.9468, 0.078, 0.4977, 0.743, -0.0434, \
        0.9209, 0.749, 0.6829, 0.739, 0.1384, 0.8109, 0.5913, 0.6107, 0.2687,  \
        -0.3779, 0.7682, 0.2943, 0.8724, 0.3116, 0.1198, 0.2749, 0.0641,       \
        0.5021, -0.8657, 0.4406, 0.6234, 0.171, 0.0579, 0.086, 0.55, 0.8024,   \
        0.5736, -0.1404, 0.1462, 0.6172, 0.4292, 0.058, 0.2317, 0.5967,        \
        0.4873, 0.1726, -0.5706, 0.6767, 0.3622, 0.3775, 0.643, 0.2117,        \
        0.1683, 0.703, 0.2448, -0.5261, 0.6291, 0.4757, 0.0339, 0.7057,        \
        0.8827, 0.5759, 0.6319, 0.3025, -0.42, 0.7499, 0.6911, 0.5967, 0.1891, \
        0.336, 0.2373, 0.4509, 0.4646, -0.6515, 0.9486, 0.7103, 0.0626,        \
        0.2757, 0.8244, 0.9472, 0.7044, -0.3874, 0.1399, 0.4882, 0.7975,       \
        0.4117, 0.0027, 0.3549, 0.8414, 0.0239, -0.1733, 0.098, 0.1065,        \
        0.4405, 0.7345, 0.8534, 0.426, 0.9292, 0.1767, -0.7374, 0.4815,        \
        0.9739, 0.4876, 0.0262, 0.1403, 0.1921, 0.7472, -0.5169, 0.7543,       \
        0.5345, 0.4635, 0.3534, 0.6513, 0.0867, 0.0013, 0.4953, -0.4359,       \
        0.1437, 0.5049, 0.0084, 0.7472, 0.3362, 0.7553, 0.1652, 0.1627,        \
        -0.1393, 0.3445, 0.024, 0.9169, 0.0952, 0.2843, 0.1334, 0.099, 0.087,  \
        -0.4658, 0.7305, 0.8998, 0.1138, 0.3479, 0.6054, 0.6645, 0.4858,       \
        -0.6006, 0.3069, 0.5604, 0.8199, 0.4466, 0.0198, 0.4392, 0.2393,       \
        0.4175, -0.2823, 0.4243, 0.1683, 0.9902, 0.1453, 0.2186, 0.3224,       \
        0.8634, 0.001, -0.8476, 0.7231, 0.5999, 0.6591, 0.2503, 0.3301,        \
        0.2544, 0.5644, 0.6209, 0.2708, 0.5955, 0.3221, 0.7958, 0.8995,        \
        0.3439, 0.2614, 0.7356, 0.4484, -0.6048, 0.3428, 0.6927, 0.3247,       \
        0.5848, 0.6776, 0.6777, 0.002, 0.7091, 0.9307, -0.0968, 0.3205,        \
        0.5119, 0.5774, 124234.4353, 2342424.6435, -235234.6433, 7654, 124, 1, \
        0.0, -0.0, 2341.314                                                    \
  }

matrix_t fill_matrix(matrix_t *A) {
  double a = 1.0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = a++;
    }
  }
  return *A;
}

void fill_matrix_static(matrix_t *A, double *array) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = array[i * A->rows + j];
    }
  }
}

// int print_matrix(matrix_t *A) {
//   if (check_matrix(A) == SUCCESS) {
//     printf("M:\n");
//     for (int i = 0; i < A->rows; i++) {
//       for (int j = 0; j < A->columns; j++) {
//         printf("%lf\t", A->matrix[i][j]);
//       }
//       printf("\n");
//     }
//   } else {
//     printf("INCORRECT\n");
//   }
//   return 0;
// }

// Start tests
// TEst s21_create_matrix(int rows, int columns, matrix_t *result);

int test_s21_create(int rows, int columns) {
  matrix_t matr;
  matr.matrix = NULL;
  int result = s21_create_matrix(rows, columns, &matr);
  s21_remove_matrix(&matr);
  return result;
}

START_TEST(test_s21_create1) {
  for (int i = 1; i <= 2; i++) {
    int result = test_s21_create(i, i + 4);
    ck_assert_int_eq(result, OK);
  }
}
END_TEST

START_TEST(test_s21_create2) {
  for (int i = 0; i >= -2; i--) {
    int result = test_s21_create(i, i + 7);
    ck_assert_int_eq(result, INCORRECT_MATRIX);
  }
}
END_TEST

START_TEST(test_s21_create3) {
  for (int i = 0; i >= -2; i--) {
    int result = test_s21_create(i / 0.0, i / (1.0 / 0.0));
    ck_assert_int_eq(result, INCORRECT_MATRIX);
  }
}
END_TEST
// Start test s21_eq

int test_s21_eq_success(int rows, int columns) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  fill_matrix_static(&A, ARRAY_DOUBLE);
  fill_matrix_static(&B, ARRAY_DOUBLE);
  int result3 = s21_eq_matrix(&A, &B);
  // printf("\nequal\n");
  // print_matrix(&A);
  // print_matrix(&B);
  // printf("result = %d\n", result3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  return result3;
}

int beat_matrix_eq(int rows, int columns) {
  matrix_t A;
  A.rows = rows;
  A.columns = columns;
  A.matrix = NULL;
  matrix_t B;
  B.rows = rows;
  B.columns = columns;
  B.matrix = NULL;
  int result = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  return result;
}

int test_s21_eq_failed(int rows, int columns) {
  matrix_t A;
  matrix_t B;
  B.matrix = NULL;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  fill_matrix_static(&A, ARRAY_DOUBLE);
  fill_matrix_static(&B, ARRAY_DOUBLE2);
  int result3 = s21_eq_matrix(&A, &B);
//   printf("\nequal\n");
//   print_matrix(&A);
//   print_matrix(&B);
//   printf("result = %d\n", result3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  return result3;
}

START_TEST(test_s21_eq_1) {
  for (int i = 1; i < 15; i++) {
    int result = test_s21_eq_success(i, i);
    ck_assert_int_eq(result, SUCCESS);
  }
}
END_TEST

START_TEST(test_s21_eq_2) {
  for (int i = 1; i < 15; i++) {
    int result = test_s21_eq_failed(i, i);
    ck_assert_int_eq(result, FAILURE);
  }
}
END_TEST

START_TEST(test_s21_eq_3) {
  for (int i = -15; i <= 0; i++) {
    int result = test_s21_eq_success(i, i);
    ck_assert_int_eq(result, FAILURE);
  }
}
END_TEST

START_TEST(test_s21_eq_beat_matr) {
  for (int i = 0; i <= 15; i++) {
    int result = beat_matrix_eq(i, i);
    ck_assert_int_eq(result, FAILURE);
  }
}
END_TEST

// Start test s21_sum()

int test_s21_sum(int rows, int columns) {
  matrix_t matr;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  fill_matrix_static(&A, ARRAY_DOUBLE);
  fill_matrix_static(&B, ARRAY_DOUBLE);
  int result3 = s21_sum_matrix(&A, &B, &matr);
  // printf("\nSUM\n");
  // print_matrix(&A);
  // print_matrix(&B);
  // printf("result = %d\n", result3);
  s21_remove_matrix(&matr);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&B);
  s21_remove_matrix(NULL);
  return result3;
}

int test_s21_sum_error_compute(int rows, int columns) {
  matrix_t matr;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(columns + 1, columns, &A);
  s21_create_matrix(rows, columns, &B);
  fill_matrix_static(&A, ARRAY_DOUBLE);
  fill_matrix_static(&B, ARRAY_DOUBLE);
  int result3 = s21_sum_matrix(&A, &B, &matr);
  s21_remove_matrix(&matr);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  return result3;
}

int beat_matrix_sum(int rows, int columns) {
  matrix_t matr;
  matr.rows = rows;
  matr.columns = columns;
  matr.matrix = NULL;
  matrix_t A;
  A.rows = rows;
  A.columns = columns;
  A.matrix = NULL;
  matrix_t B;
  B.rows = rows;
  B.columns = columns;
  B.matrix = NULL;
  int result = s21_sum_matrix(&A, &B, &matr);
  s21_remove_matrix(&matr);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  return result;
}

START_TEST(test_s21_sum1) {
  for (int i = 1; i < 20; i++) {
    int result3 = test_s21_sum(i, i);
    ck_assert_int_eq(result3, OK);
  }
}
END_TEST

START_TEST(test_s21_sum11) {
  for (int i = -150; i <= 0; i++) {
    int result3 = test_s21_sum(i, i);
    ck_assert_int_eq(result3, INCORRECT_MATRIX);
  }
}
END_TEST

START_TEST(test_s21_sum12) {
  for (int i = 1; i <= 20; i++) {
    int result3 = test_s21_sum_error_compute(i + 6, i);
    ck_assert_int_eq(result3, ERROR_COMPUTE);
  }
}
END_TEST

START_TEST(test_s21_sum_beat_matr) {
  for (int i = 1; i <= 20; i++) {
    int result3 = beat_matrix_sum(i, i);
    ck_assert_int_eq(result3, INCORRECT_MATRIX);
  }
}
END_TEST

// Start test s21_sub()

int test_s21_sub(int rows, int columns) {
  matrix_t matr;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  // s21_create_matrix(rows, columns, &matr);
  fill_matrix_static(&A, ARRAY_DOUBLE);
  fill_matrix_static(&B, ARRAY_DOUBLE);
  int result3 = s21_sub_matrix(&A, &B, &matr);
  s21_remove_matrix(&matr);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  return result3;
}

int test_s21_sub_error_compute(int rows, int columns) {
  matrix_t matr;
  matr.matrix = NULL;
  matrix_t A;
  A.matrix = NULL;
  matrix_t B;
  B.matrix = NULL;
  s21_create_matrix(columns + 1, columns, &A);
  s21_create_matrix(rows, columns, &B);
  // s21_create_matrix(rows, columns, &matr);
  fill_matrix_static(&A, ARRAY_DOUBLE);
  fill_matrix_static(&B, ARRAY_DOUBLE);
  int result3 = s21_sub_matrix(&A, &B, &matr);
  s21_remove_matrix(&matr);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  return result3;
}

START_TEST(test_s21_sub1) {
  for (int i = -150; i <= 0; i++) {
    int result3 = test_s21_sub(i, i);
    ck_assert_int_eq(result3, INCORRECT_MATRIX);
  }
}
END_TEST

START_TEST(test_s21_sub2) {
  for (int i = 1; i <= 20; i++) {
    int result3 = test_s21_sub_error_compute(i + 8 % 20, i);
    ck_assert_int_eq(result3, ERROR_COMPUTE);
  }
}
END_TEST

START_TEST(test_s21_sub3) {
  for (int i = 1; i <= 20; i++) {
    int result3 = test_s21_sub(i, i);
    ck_assert_int_eq(result3, OK);
  }
}
END_TEST

int test_s21_mult_number(int rows, int columns, double number) {
  matrix_t matr;
  matrix_t A;
  // s21_create_matrix(rows, columns, &matr);
  s21_create_matrix(rows, columns, &A);
  fill_matrix_static(&A, ARRAY_DOUBLE);
  int result3 = s21_mult_number(&A, number, &matr);
  s21_remove_matrix(&matr);
  s21_remove_matrix(&A);
  return result3;
}

START_TEST(test_s21_mul1) {
  double number = 123.65446443;
  for (int i = 1; i < 15; i++) {
    int result3 = test_s21_mult_number(i, i, number);
    ck_assert_int_eq(result3, OK);
  }
}
END_TEST

START_TEST(test_s21_mul2) {
  double number = 0.0 / 0.0;
  for (int i = -15; i < 0; i++) {
    int result3 = test_s21_mult_number(i, i, number);
    ck_assert_int_eq(result3, INCORRECT_MATRIX);
  }
}
END_TEST

int test_s21_mult_MxM(int rows, int columns) {
  matrix_t matr;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &B);
  fill_matrix_static(&A, ARRAY_DOUBLE);
  fill_matrix(&B);
  int result3 = s21_mult_matrix(&A, &B, &matr);
  // if (result3 != OK) {
  //   printf("MxM err\n");
  //   print_matrix(&A);
  //   print_matrix(&B);
  //   print_matrix(&matr);
  // }
  s21_remove_matrix(&matr);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  return result3;
}

int test_s21_mult_MxM_error_compute(int rows, int columns) {
  matrix_t matr;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(rows, columns + 1, &A);
  s21_create_matrix(rows, columns + 10, &B);
  fill_matrix_static(&A, ARRAY_DOUBLE);
  fill_matrix(&B);
  int result3 = s21_mult_matrix(&A, &B, &matr);
  s21_remove_matrix(&matr);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  return result3;
}

START_TEST(test_s21_mulmul1) {
  for (int i = 1; i < 15; i++) {
    int result3 = test_s21_mult_MxM(i, i);
    ck_assert_int_eq(result3, OK);
  }
}
END_TEST

START_TEST(test_s21_mulmul2) {
  for (int i = -15; i < 1; i++) {
    int result3 = test_s21_mult_MxM(i, i);
    ck_assert_int_eq(result3, INCORRECT_MATRIX);
  }
}
END_TEST

START_TEST(test_s21_mulmul3) {
  for (int i = 1; i < 10; i++) {
    int result3 = test_s21_mult_MxM_error_compute(i, i);
    ck_assert_int_eq(result3, ERROR_COMPUTE);
  }
}
END_TEST

int test_s21_transpon(int rows, int columns) {
  matrix_t matr;
  matr.matrix = NULL;
  matrix_t A;
  A.matrix = NULL;
  // s21_create_matrix(rows, columns, &matr);
  s21_create_matrix(columns, rows, &A);
  fill_matrix_static(&A, ARRAY_DOUBLE);
  int result3 = s21_transpose(&A, &matr);
  // printf("\nSUM\n");
  // print_matrix(&A);
  // print_matrix(&matr);
  // printf("result = %d\n", result3);
  s21_remove_matrix(&matr);
  s21_remove_matrix(&A);
  return result3;
}

// int test_s21_transpon_error_compute(int rows, int columns) {
//   matrix_t matr;
//   matr.matrix = NULL;
//   matrix_t A;
//   A.matrix = NULL;
//   // s21_create_matrix(rows, rows, &matr);
//   s21_create_matrix(columns, rows, &A);
//   fill_matrix_static(&A, ARRAY_DOUBLE);
//   int result3 = s21_transpose(&A, &matr);
//   s21_remove_matrix(&matr);
//   s21_remove_matrix(&A);
//   return result3;
// }

START_TEST(test_s21_trans1) {
  for (int i = 1; i < 15; i++) {
    int result3 = test_s21_transpon(i, i);
    ck_assert_int_eq(result3, OK);
  }
}
END_TEST

START_TEST(test_s21_trans2) {
  for (int i = -15; i <= 0; i++) {
    int result3 = test_s21_transpon(i, i + 2);
    ck_assert_int_eq(result3, INCORRECT_MATRIX);
  }
}
END_TEST

// START_TEST(test_s21_trans3) {
//   for (int i = 1; i < 15; i++) {
//     int result3 = test_s21_transpon_error_compute(i, i + 1);
//     ck_assert_int_eq(result3, ERROR_COMPUTE);
//   }
// }
// END_TEST

int test_s21_calc_complements(int rows, int columns) {
  matrix_t matr;
  matr.matrix = NULL;
  matrix_t A;
  A.matrix = NULL;
  // s21_create_matrix(rows, columns, &matr);
  s21_create_matrix(rows, columns, &A);
  fill_matrix_static(&A, ARRAY_DOUBLE);
  int result3 = s21_calc_complements(&A, &matr);
  s21_remove_matrix(&matr);
  s21_remove_matrix(&A);
  return result3;
}

START_TEST(test_s21_calc_complements1) {
  for (int i = 1; i < 10; i++) {
    int result3 = test_s21_calc_complements(i, i);
    ck_assert_int_eq(result3, OK);
  }
}
END_TEST

START_TEST(test_s21_calc_complements2) {
  for (int i = -10; i < 1; i++) {
    int result3 = test_s21_calc_complements(i, i);
    ck_assert_int_eq(result3, INCORRECT_MATRIX);
  }
}
END_TEST

START_TEST(test_s21_calc_complements3) {
  for (int i = 1; i < 10; i++) {
    int result3 = test_s21_calc_complements(i, i + 1);
    ck_assert_int_eq(result3, ERROR_COMPUTE);
  }
}
END_TEST

int test_s21_determinant(int rows, int columns, double *determ) {
  matrix_t matr;
  matr.matrix = NULL;
  s21_create_matrix(rows, columns, &matr);
  fill_matrix_static(&matr, ARRAY_DOUBLE);
  int result3 = s21_determinant(&matr, determ);
  s21_remove_matrix(&matr);
  return result3;
}

START_TEST(test_s21_determ1) {
  for (int i = 1; i < 2; i++) {
    double determ = -1.0;
    int result3 = test_s21_determinant(i, i, &determ);
    ck_assert_int_eq(result3, OK);
  }
}
END_TEST

START_TEST(test_s21_determ2) {
  for (int i = -10; i < 1; i++) {
    double determ = -1.0;
    int result3 = test_s21_determinant(i, i, &determ);
    ck_assert_int_eq(result3, INCORRECT_MATRIX);
  }
}
END_TEST

START_TEST(test_s21_determ3) {
  for (int i = 1; i < 10; i++) {
    double determ = -1.0;
    int result3 = test_s21_determinant(i, i + 1, &determ);
    ck_assert_int_eq(result3, ERROR_COMPUTE);
  }
}
END_TEST

int test_s21_determinant_check_number(int rows, int columns, double *determ) {
  matrix_t matr;
  matr.matrix = NULL;
  s21_create_matrix(rows, columns, &matr);
  fill_matrix(&matr);
  int result3 = s21_determinant(&matr, determ);
  s21_remove_matrix(&matr);
  return result3;
}

START_TEST(test_s21_determ4) {
  for (int i = 3; i < 10; i++) {
    double determ = -1.0;
    test_s21_determinant_check_number(i, i, &determ);
    ck_assert_double_eq(determ, 0.0);
  }
}
END_TEST

int test_s21_inverse_matrix(int rows, int columns) {
  matrix_t matr;
  matr.matrix = NULL;
  matrix_t A;
  A.matrix = NULL;
  // s21_create_matrix(rows, columns, &matr);
  s21_create_matrix(rows, columns, &A);
  fill_matrix_static(&A, ARRAY_DOUBLE);
  int result3 = s21_inverse_matrix(&A, &matr);
  s21_remove_matrix(&matr);
  s21_remove_matrix(&A);
  return result3;
}

START_TEST(test_s21_inverse1) {
  for (int i = 1; i < 10; i++) {
    int result3 = test_s21_inverse_matrix(i, i);
    ck_assert_int_eq(result3, OK);
  }
}
END_TEST

START_TEST(test_s21_inverse2) {
  for (int i = -10; i < 1; i++) {
    int result3 = test_s21_inverse_matrix(i, i);
    ck_assert_int_eq(result3, INCORRECT_MATRIX);
  }
}
END_TEST

START_TEST(test_s21_inverse3) {
  for (int i = 1; i < 10; i++) {
    int result3 = test_s21_inverse_matrix(i, i + 1);
    ck_assert_int_eq(result3, ERROR_COMPUTE);
  }
}
END_TEST

// int identity_matrix(matrix_t *matrix) {
//   for (int i = 0; i < matrix->rows; i++) {
//     for (int j = 0; j < matrix->columns; j++) {
//       if (j == i)
//         matrix->matrix[i][j] = 1.0;
//       else
//         matrix->matrix[i][j] = 0.0;
//     }
//   }
//   return 0;
// }

// int test_s21_inverse_matrix_with_identity_matrix(int rows, int columns) {
//   matrix_t matr;
//   matrix_t A;
//   matrix_t ident;
//   matrix_t result;
//   s21_create_matrix(rows, columns, &matr);
//   s21_create_matrix(rows, columns, &A);
//   s21_create_matrix(rows, columns, &ident);
//   s21_create_matrix(rows, columns, &result);
//   fill_matrix_static(&A, ARRAY_DOUBLE);
//   identity_matrix(&ident);
//   s21_inverse_matrix(&A, &matr);
//   s21_mult_matrix(&matr, &A, &result);
//   int result3 = s21_eq_matrix(&ident, &result);
//   if (result3 != SUCCESS) {
//     printf("matrix\n");
//     print_matrix(&A);
//     printf("inverse\n");
//     print_matrix(&matr);
//     printf("mult\n");
//     print_matrix(&result);
//   }
//   s21_remove_matrix(&result);
//   s21_remove_matrix(&ident);
//   s21_remove_matrix(&matr);
//   s21_remove_matrix(&A);
//   return result3;
// }

// START_TEST(test_s21_inverse4) {
//   for (int i = 2; i < 10; i++) {
//     int result3 = test_s21_inverse_matrix_with_identity_matrix(i, i);
//   }
// }
// END_TEST

int test() {
  Suite *s = suite_create("All Part");
  TCase *tc1 = tcase_create("Test1");
  TCase *tc2 = tcase_create("Test2");
  TCase *tc3 = tcase_create("Test3");
  TCase *tc4 = tcase_create("Test4");
  TCase *tc5 = tcase_create("Test5");
  TCase *tc6 = tcase_create("Test6");
  TCase *tc7 = tcase_create("Test7");
  TCase *tc8 = tcase_create("Test8");
  TCase *tc9 = tcase_create("Test9");
  TCase *tc10 = tcase_create("Test10");
  SRunner *sr = srunner_create(s);
  suite_add_tcase(s, tc1);
  // // s21_create tests
  tcase_add_test(tc1, test_s21_create1);
  tcase_add_test(tc1, test_s21_create2);
  tcase_add_test(tc1, test_s21_create3);
  // // // s21_eq tests
  suite_add_tcase(s, tc2);
  tcase_add_test(tc2, test_s21_eq_1);
  tcase_add_test(tc2, test_s21_eq_2);
  tcase_add_test(tc2, test_s21_eq_3);
  tcase_add_test(tc2, test_s21_eq_beat_matr);
  // // // s21_sum tests
  suite_add_tcase(s, tc3);
  tcase_add_test(tc3, test_s21_sum1);
  tcase_add_test(tc3, test_s21_sum11);
  tcase_add_test(tc3, test_s21_sum12);
  tcase_add_test(tc3, test_s21_sum_beat_matr);
  // // // s21_sub tests
  suite_add_tcase(s, tc4);
  tcase_add_test(tc4, test_s21_sub1);
  tcase_add_test(tc4, test_s21_sub2);
  tcase_add_test(tc4, test_s21_sub3);
  // // // s21_mult_number tests
  suite_add_tcase(s, tc5);
  tcase_add_test(tc5, test_s21_mul1);
  tcase_add_test(tc5, test_s21_mul2);
  // // // s21_mult_matrix tests
  suite_add_tcase(s, tc6);
  tcase_add_test(tc6, test_s21_mulmul1);
  tcase_add_test(tc6, test_s21_mulmul2);
  tcase_add_test(tc6, test_s21_mulmul3);
  // // // s21_transpon tests
  suite_add_tcase(s, tc7);
  tcase_add_test(tc7, test_s21_trans1);
  tcase_add_test(tc7, test_s21_trans2);
  // tcase_add_test(tc7, test_s21_trans3);
  // // // s21_calc_complements tests
  suite_add_tcase(s, tc8);
  tcase_add_test(tc8, test_s21_calc_complements1);
  tcase_add_test(tc8, test_s21_calc_complements2);
  tcase_add_test(tc8, test_s21_calc_complements3);
  // // // s21_determinant tests
  suite_add_tcase(s, tc9);
  tcase_add_test(tc9, test_s21_determ1);
  tcase_add_test(tc9, test_s21_determ2);
  tcase_add_test(tc9, test_s21_determ3);
  tcase_add_test(tc9, test_s21_determ4);
  // // // s21_inverse_matrix tests
  suite_add_tcase(s, tc10);
  tcase_add_test(tc10, test_s21_inverse1);
  tcase_add_test(tc10, test_s21_inverse2);
  tcase_add_test(tc10, test_s21_inverse3);
  // tcase_add_test(tc10, test_s21_inverse4);

  srunner_run_all(sr, CK_ENV);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf;
}

int main(void) {
  int nf = 0;
  nf += test();
  return 0;
}