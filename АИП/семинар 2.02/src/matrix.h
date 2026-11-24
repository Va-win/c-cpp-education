#pragma once

// Емкость матрицы. Занятая часть rows x cols хранится отдельно.
const int ROWS = 4;
const int COLS = 5;

// Адрес элемента a[i][j], посчитанный от &a[0][0] по формуле i * COLS + j.
// 0 <= i < ROWS, 0 <= j < COLS.
int* element_ptr(int a[][COLS], int i, int j);

// Сумма занятой части rows x cols. p указывает на a[0][0] матрицы емкостью ROWS x COLS.
// Ячейки за пределами rows x cols не читаются.
int sum_flat(const int* p, int rows, int cols);

// Сумма строки i: элементы a[i][0] … a[i][cols - 1].
int row_sum(const int a[][COLS], int cols, int i);

// Сумма столбца j: элементы a[0][j] … a[rows - 1][j].
int col_sum(const int a[][COLS], int rows, int j);

// Сумма главной диагонали квадратной матрицы n x n.
int main_diag_sum(const int a[][COLS], int n);

// Пишет в out транспонированную матрицу: cols строк и rows столбцов.
// Возвращает false, если cols > ROWS: результат не помещается, out не меняется.
bool transpose(const int a[][COLS], int rows, int cols, int out[][COLS]);
