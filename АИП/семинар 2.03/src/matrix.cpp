#include "matrix.h"

int row_sum(const int a[][COLS], int cols, int i) {
    int sum = 0;
    for (int j = 0; j < cols; ++j) {
        sum += a[i][j];
    }
    return sum;
}

int col_sum(const int a[][COLS], int rows, int j) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        sum += a[i][j];
    }
    return sum;
}

int remove_max_row_col(int a[][COLS], int rows, int cols) {
    // TODO: при rows < 1 или cols < 1 вернуть -1; найти первый максимум (сравнение >),
    // сдвигом удалить его строку, затем его столбец в оставшихся строках; вернуть rows - 1
    (void)a;
    (void)rows;
    (void)cols;
    return -1;
}

int write_spiral(const int a[][COLS], int rows, int cols, int out[]) {
    // TODO: границы top, bottom, left, right; пройдя сторону, сдвинуть ее границу внутрь;
    // перед нижней строкой и левым столбцом проверить, что клетки еще остались; вернуть rows * cols
    (void)a;
    (void)rows;
    (void)cols;
    (void)out;
    return 0;
}

bool clear_zero_rows_cols(int a[][COLS], int rows, int cols) {
    // TODO: первым двойным циклом заполнить bool zero_row[ROWS] и zero_col[COLS],
    // вторым обнулить a[i][j], если zero_row[i] или zero_col[j]; нулей нет – вернуть false
    (void)a;
    (void)rows;
    (void)cols;
    return false;
}
