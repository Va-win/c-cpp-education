#include "matrix.h"

int* element_ptr(int a[][COLS], int i, int j) {
    // TODO: вернуть &a[0][0] + i * COLS + j
    (void)a;
    (void)i;
    (void)j;
    return nullptr;
}

int sum_flat(const int* p, int rows, int cols) {
    // TODO: сложить занятую часть, элемент a[i][j] лежит в p[i * COLS + j]
    (void)p;
    (void)rows;
    (void)cols;
    return 0;
}

int row_sum(const int a[][COLS], int cols, int i) {
    // TODO: сумма строки i
    (void)a;
    (void)cols;
    (void)i;
    return 0;
}

int col_sum(const int a[][COLS], int rows, int j) {
    // TODO: сумма столбца j
    (void)a;
    (void)rows;
    (void)j;
    return 0;
}

int main_diag_sum(const int a[][COLS], int n) {
    // TODO: сумма элементов с i == j, один цикл
    (void)a;
    (void)n;
    return 0;
}

bool transpose(const int a[][COLS], int rows, int cols, int out[][COLS]) {
    // TODO: при cols > ROWS вернуть false, не трогая out; иначе out[j][i] = a[i][j]
    (void)a;
    (void)rows;
    (void)cols;
    (void)out;
    return true;
}
