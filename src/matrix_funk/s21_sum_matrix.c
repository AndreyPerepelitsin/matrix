#include "../s21_matrix.h"

// Сложение матриц (sum_matrix)
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = 0;  // Переменная для хранения статуса создания матрицы (0 -
                   // успешно, 1 - некорректная матрица, 2 - ошибка вычисления)
  if (!A || !B || !result) {
    status = 1;  // Проверка на нулевые указатели на матрицы
  } else if (A->rows != B->rows || A->columns != B->columns) {
    status = 2;  // Проверка на различные размеры матриц
  } else {
    if (s21_create_matrix(A->rows, A->columns,
                          result)) {  // Создание результирующей матрицы
      status = 1;  // Ошибка при создании результирующей матрицы
    } else {
      // Цикл по индексу i для итерации по строкам матриц A и B
      for (int i = 0; i < A->rows; i++) {
        // Цикл по индексу j для итерации по столбцам матриц A и B
        for (int j = 0; j < A->columns; j++) {
          // Сложение соответствующих элементов матриц A и B и присваивание
          // результата в матрицу result
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  }
  return status;  // Возвращаем статус сложения матриц
}