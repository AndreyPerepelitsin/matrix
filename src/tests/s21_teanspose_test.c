#include "test.h"

// Транспонирование матрицы

START_TEST(transpose_test_1) {
  matrix_t A, B, R;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 1.25;
  B.matrix[0][0] = 1.25;

  s21_transpose(&A, &R);
  ck_assert_int_eq(s21_eq_matrix(&R, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(transpose_test_2) {
  matrix_t A, B, R;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 4.25;
  A.matrix[1][2] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;

  s21_transpose(&A, &R);

  B.matrix[0][0] = 0.25;
  B.matrix[1][0] = 1.25;
  B.matrix[2][0] = 2.25;
  B.matrix[0][1] = 3.25;
  B.matrix[1][1] = 4.25;
  B.matrix[2][1] = 5.25;
  B.matrix[0][2] = 6.25;
  B.matrix[1][2] = 7.25;
  B.matrix[2][2] = 8.25;

  ck_assert_int_eq(s21_eq_matrix(&R, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(transpose_NOTCORRECT) {
  matrix_t A, B;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.columns = -1;

  int ret = s21_transpose(&A, &B);
  ck_assert_int_eq(ret, NOTCORRECT);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(s21_transpose(NULL, NULL), NOTCORRECT);
}
END_TEST

Suite *suite_transport(void) {
  Suite *s = suite_create("\033[45ms21_transpose\033[0m");
  TCase *tc = tcase_create("sqrt_tc");

  // Транспонирование матрицы

  tcase_add_test(tc, transpose_test_1);
  tcase_add_test(tc, transpose_test_2);
  tcase_add_test(tc, transpose_NOTCORRECT);

  suite_add_tcase(s, tc);
  return s;
}