#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>  // Библиотека для математических функций
#include <stdbool.h>  // Библиотека для работы с логическими значениями
#include <stdio.h>  // Библиотека для стандартного ввода/вывода
#include <stdlib.h>  // Библиотека для работы с памятью

typedef struct matrix_struct {
  double **matrix;  // Матрица
  int rows;         // Количество строк
  int columns;      // Количество столбцов
} matrix_t;

#define OK 0  // Код успешного выполнения
#define ERROR_CALC 2  // Код ошибки при выполнении вычислений
#define NOTCORRECT 1  // Код ошибки для некорректных данных
#define SUCCESS 1  // Код успешного выполнения (в контексте логических операций)
#define FAILURE \
  0  // Код неуспешного выполнения (в контексте логических операций)
#define EPSILON \
  0.0000001  // Маленькая величина для сравнения чисел с плавающей запятой

// Создание матриц (create_matrix):
int s21_create_matrix(int rows, int columns, matrix_t *result);

// Очистка матриц (remove_matrix):
void s21_remove_matrix(matrix_t *A);

// Сравнение матриц (eq_matrix):
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// Сложение (sum_matrix) и вычитание матриц (sub_matrix):
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Умножение матрицы на число (mult_number):
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

// Умножение двух матриц (mult_matrix):
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Транспонирование матрицы (transpose):
int s21_transpose(matrix_t *A, matrix_t *result);

// Определитель матрицы (determinant):
int s21_determinant(matrix_t *A, double *result);

// Минор матрицы и матрица алгебраических дополнений (calc_complements):
int s21_minor(matrix_t *A, int row, int col, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);

// Обратная матрица (inverse_matrix):
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif  //  SRC_S21_MATRIX_H_