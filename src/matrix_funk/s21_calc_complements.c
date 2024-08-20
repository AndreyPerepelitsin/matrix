#include "../s21_matrix.h"

// Матрица алгебраических дополнений (calc_complements)
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = 0;  // Переменная для хранения статуса создания матрицы (0 -
                   // успешно, 1 - некорректная матрица, 2 - ошибка вычисления)
  if (!A || !result) {
    status = 1;  // Проверка на нулевые указатели на матрицы
  } else if (A->rows != A->columns) {
    status = 2;  // Проверка на неправильные размеры матрицы
  } else if (s21_create_matrix(A->rows, A->columns,
                               result)) {  // Создание результирующей матрицы
    status = 1;  // Ошибка при создании результирующей матрицы
  } else {
    // Вычисление дополнений
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double minor;
        status = s21_minor(
            A, i, j, &minor);  // Вычисление минора для каждого элемента матрицы
        if (status) break;  // Если произошла ошибка, прерываем цикл
        result->matrix[i][j] =
            (i + j) % 2
                ? -minor
                : minor;  // Знак дополнения зависит от суммы индексов элемента
      }
      if (status) break;  // Если произошла ошибка, прерываем цикл
    }
  }
  return status;  // Возвращаем статус вычисления матрицы алгебраических
                  // дополнений
}