#include "matrix.h"

int* element_ptr(int a[][COLS], int i, int j) {
    return &a[0][0] + i * COLS + j;
}

int sum_flat(const int* p, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += p[i * COLS + j];
        }
    }
    return sum;
}

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

int main_diag_sum(const int a[][COLS], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i][i];
    }
    return sum;
}

bool transpose(const int a[][COLS], int rows, int cols, int out[][COLS]) {
    if (cols > ROWS || rows > COLS) {
        return false;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            out[j][i] = a[i][j];
        }
    }
    return true;
}