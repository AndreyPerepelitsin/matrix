#include "test.h"

// Минор матрицы и матрица алгебраических дополнений

START_TEST(compliment_test_1) {
  matrix_t A, B, R;
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &A);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 4;
  B.matrix[1][2] = 2;
  B.matrix[2][0] = 5;
  B.matrix[2][1] = 2;
  B.matrix[2][2] = 1;

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 10;
  A.matrix[0][2] = -20;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = -14;
  A.matrix[1][2] = 8;
  A.matrix[2][0] = -8;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = 4;

  int code = s21_calc_complements(&B, &R);
  ck_assert_int_eq(code, OK);
  ck_assert_int_eq(s21_eq_matrix(&R, &A), SUCCESS);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(compliment_test_2) {
  matrix_t A, B, R;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 5;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 3;

  s21_calc_complements(&A, &R);

  B.matrix[0][0] = 9;
  B.matrix[0][1] = -2;
  B.matrix[0][2] = -3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 14;
  B.matrix[1][2] = -1;
  B.matrix[2][0] = -7;
  B.matrix[2][1] = -18;
  B.matrix[2][2] = 17;

  ck_assert_int_eq(s21_eq_matrix(&R, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(compliment_test_not_square) {
  matrix_t B, R;
  s21_create_matrix(2, 3, &B);

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 4;
  B.matrix[1][2] = 2;

  int code = s21_calc_complements(&B, &R);

  ck_assert_int_eq(code, ERROR_CALC);
  s21_remove_matrix(&B);
  // s21_remove_matrix(&R);
}
END_TEST

START_TEST(compliment_test_1x1) {
  matrix_t A, B, R;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 5;

  s21_calc_complements(&A, &R);

  B.matrix[0][0] = 1;

  ck_assert_int_eq(s21_eq_matrix(&R, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(null_compliments) {
  matrix_t *B = NULL;
  matrix_t *R = NULL;
  int res = s21_calc_complements(B, R);
  ck_assert_int_eq(res, NOTCORRECT);
}
END_TEST

START_TEST(s21_calc_compl_1) {
  matrix_t A, B, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 4.0;
  A.matrix[1][2] = 2.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 2.0;
  A.matrix[2][2] = 1.0;
  s21_calc_complements(&A, &B);
  C.matrix[0][0] = 0.0;
  C.matrix[0][1] = 10.0;
  C.matrix[0][2] = -20.0;
  C.matrix[1][0] = 4.0;
  C.matrix[1][1] = -14.0;
  C.matrix[1][2] = 8.0;
  C.matrix[2][0] = -8.0;
  C.matrix[2][1] = -2.0;
  C.matrix[2][2] = 4.0;
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_compl_2) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  matrix_t res = {0};
  s21_create_matrix(3, 3, &res);
  matrix_t m;
  res.matrix[0][0] = 0;
  res.matrix[0][1] = 10;
  res.matrix[0][2] = -20;
  res.matrix[1][0] = 4;
  res.matrix[1][1] = -14;
  res.matrix[1][2] = 8;
  res.matrix[2][0] = -8;
  res.matrix[2][1] = -2;
  res.matrix[2][2] = 4;

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 4;
  a.matrix[1][2] = 2;
  a.matrix[2][0] = 5;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 1;
  s21_calc_complements(&a, &m);
  ck_assert_int_eq(s21_eq_matrix(&res, &m), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(empty) {
  matrix_t a = {0};
  matrix_t b = {0};
  ck_assert_int_eq(s21_calc_complements(&a, &b), NOTCORRECT);
}
END_TEST

START_TEST(size_mismatch) {
  matrix_t a = {0};
  matrix_t b = {0};
  s21_create_matrix(1, 2, &a);
  ck_assert_int_eq(s21_calc_complements(&a, &b), ERROR_CALC);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(complements) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 2;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = 2;
  m.matrix[2][2] = 1;

  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][1] = 10;
  expected.matrix[0][2] = -20;
  expected.matrix[1][0] = 4;
  expected.matrix[1][1] = -14;
  expected.matrix[1][2] = 8;
  expected.matrix[2][0] = -8;
  expected.matrix[2][1] = -2;
  expected.matrix[2][2] = 4;

  matrix_t res = {0};
  s21_calc_complements(&m, &res);

  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *suite_calc(void) {
  Suite *s = suite_create("\033[45ms21_calc_complements\033[0m");
  TCase *tc = tcase_create("sqrt_tc");

  // Минор матрицы и матрица алгебраических дополнений

  tcase_add_test(tc, compliment_test_1);
  tcase_add_test(tc, compliment_test_2);
  tcase_add_test(tc, compliment_test_not_square);
  tcase_add_test(tc, compliment_test_1x1);
  tcase_add_test(tc, null_compliments);
  tcase_add_test(tc, s21_calc_compl_2);
  tcase_add_test(tc, s21_calc_compl_1);
  tcase_add_test(tc, complements);
  tcase_add_test(tc, empty);
  tcase_add_test(tc, size_mismatch);

  suite_add_tcase(s, tc);
  return s;
}
