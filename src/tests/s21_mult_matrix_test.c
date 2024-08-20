#include "test.h"

// Умножение матрицы на матрицу
START_TEST(test_mult_null_A) {
  matrix_t *A = NULL, B, result;
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(A, &B, &result), 1);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_mult_null_B) {
  matrix_t A, *B = NULL, result;
  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(s21_mult_matrix(&A, B, &result), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_mult_invalid_A) {
  matrix_t A, B, result;
  A.rows = -1;
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_mult_invalid_B) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  B.columns = -5;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_mult_incompatible) {
  matrix_t A, B, result;
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(1, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_mult_null_result) {
  matrix_t A, B, *result = NULL;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, result), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test_1) {
  matrix_t A, B, R, R2;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &R2);

  A.matrix[0][0] = -1;
  B.matrix[0][0] = 2;

  R2.matrix[0][0] = -2;

  s21_mult_matrix(&A, &B, &R);

  ck_assert(fabs(R.matrix[0][0] - R2.matrix[0][0]) < 1e-7);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}
END_TEST

START_TEST(mult_matrix_test_2) {
  matrix_t A, B, R, R2;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &R2);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 6;
  A.matrix[2][1] = 7;

  B.matrix[0][0] = 9;
  B.matrix[0][1] = 8;
  B.matrix[0][2] = 7;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 4;

  R2.matrix[0][0] = 6;
  R2.matrix[0][1] = 5;
  R2.matrix[0][2] = 4;
  R2.matrix[1][0] = 51;
  R2.matrix[1][1] = 44;
  R2.matrix[1][2] = 37;
  R2.matrix[2][0] = 96;
  R2.matrix[2][1] = 83;
  R2.matrix[2][2] = 70;

  s21_mult_matrix(&A, &B, &R);

  ck_assert_int_eq(s21_eq_matrix(&R, &R2), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}
END_TEST

START_TEST(mult_matrix_test_null) {
  matrix_t *A = NULL, *B = NULL, *R = NULL;
  ck_assert_int_eq(s21_mult_matrix(A, B, R), NOTCORRECT);
}
END_TEST

Suite *suite_muit_mat(void) {
  Suite *s = suite_create("\033[45ms21_mult_matrix\033[0m");
  TCase *tc = tcase_create("sqrt_tc");

  // Умножение матрицы на матрицу
  tcase_add_test(tc, test_mult_null_A);
  tcase_add_test(tc, test_mult_null_B);
  tcase_add_test(tc, test_mult_null_result);
  tcase_add_test(tc, test_mult_incompatible);
  tcase_add_test(tc, test_mult_invalid_B);
  tcase_add_test(tc, test_mult_invalid_A);
  tcase_add_test(tc, mult_matrix_test_1);
  tcase_add_test(tc, mult_matrix_test_2);
  tcase_add_test(tc, mult_matrix_test_null);

  suite_add_tcase(s, tc);
  return s;
}