#ifndef SRC_S21_MATRIX_TEST_H_
#define SRC_S21_MATRIX_TEST_H_

#include <check.h>

#include "../s21_matrix.h"

Suite *suite_calc(void);
Suite *suite_cr_rm(void);
Suite *suite_det(void);
Suite *suite_eq(void);
Suite *suite_inverse(void);
Suite *suite_muit_mat(void);
Suite *suite_mult_num(void);
Suite *suite_sub(void);
Suite *suite_sum(void);
Suite *suite_transport(void);

void run_test(void);
void run_testcase(Suite *testcase);
double get_rand(double min_val, double max_val);

#endif  //  SRC_S21_MATRIX_TEST_H_