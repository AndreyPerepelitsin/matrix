#include "test.h"

// Сравнение матриц

START_TEST(eq_matrix_identical) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_different) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 1.0;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_diff_sizes) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 2, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_near_equal) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 0.00000005;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_null_pointer) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  int code = s21_eq_matrix(&A, NULL);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(eq_matrix_identical_single_element) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_identical_one_column) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(2, 1, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_null_pointer_vs_matrix) {
  matrix_t B = {0};
  s21_create_matrix(1, 1, &B);
  int code = s21_eq_matrix(NULL, &B);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_different_same_size) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[1][1] = 2.0;
  B.matrix[1][1] = 3.0;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_zero_size_vs_normal) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(3, 3, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, cols, &mtx);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      double rand_val = get_rand(DBL_MIN, DBL_MAX);
      m.matrix[i][j] = rand_val;
      mtx.matrix[i][j] = rand_val;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&m, &mtx), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
}
END_TEST

START_TEST(not_eq_1) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, cols, &mtx);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX) + 1;
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&m, &mtx), FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
}
END_TEST

START_TEST(not_eq_2) {
  const int rows1 = rand() % 100 + 1;
  const int cols1 = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows1, cols1, &m);
  const int rows2 = rand() % 100 + 1;
  const int cols2 = rand() % 100 + 1;
  matrix_t mtx = {0};
  s21_create_matrix(rows2, cols2, &mtx);

  for (int i = 0; i < rows1; ++i) {
    for (int j = 0; j < cols1; ++j) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX) + 1;
    }
  }
  for (int i = 0; i < rows2; ++i) {
    for (int j = 0; j < cols2; ++j) {
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&m, &mtx), FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
}
END_TEST

Suite *suite_eq(void) {
  Suite *s = suite_create("\033[45ms21_eq_matrix\033[0m");
  TCase *tc = tcase_create("sqrt_tc");

  // Сравнение матриц
  tcase_add_test(tc, eq_matrix_identical);
  tcase_add_test(tc, eq_matrix_different);
  tcase_add_test(tc, eq_matrix_diff_sizes);
  tcase_add_test(tc, eq_matrix_near_equal);
  tcase_add_test(tc, eq_matrix_null_pointer);
  tcase_add_test(tc, eq_matrix_identical_single_element);
  tcase_add_test(tc, eq_matrix_identical_one_column);
  tcase_add_test(tc, eq_matrix_null_pointer_vs_matrix);
  tcase_add_test(tc, eq_matrix_different_same_size);
  tcase_add_test(tc, eq_matrix_zero_size_vs_normal);

  tcase_add_test(tc, eq_matrix);
  tcase_add_test(tc, not_eq_1);
  tcase_add_test(tc, not_eq_2);

  suite_add_tcase(s, tc);
  return s;
}