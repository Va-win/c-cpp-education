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
    if (rows < 1 || cols < 1) {
        return -1;
    }

    int max_r = 0;
    int max_c = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (a[i][j] > a[max_r][max_c]) {
                max_r = i;
                max_c = j;
            }
        }
    }

    for (int i = max_r; i < rows - 1; ++i) {
        for (int j = 0; j < cols; ++j) {
            a[i][j] = a[i + 1][j];
        }
    }

    int new_rows = rows - 1;
    for (int i = 0; i < new_rows; ++i) {
        for (int j = max_c; j < cols - 1; ++j) {
            a[i][j] = a[i][j + 1];
        }
    }

    return new_rows;
}

int write_spiral(const int a[][COLS], int rows, int cols, int out[]) {
    if (rows < 1 || cols < 1) {
        return 0;
    }

    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;
    int k = 0;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; ++j) {
            out[k++] = a[top][j];
        }
        ++top;

        for (int i = top; i <= bottom; ++i) {
            out[k++] = a[i][right];
        }
        --right;

        if (top <= bottom) {
            for (int j = right; j >= left; --j) {
                out[k++] = a[bottom][j];
            }
            --bottom;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                out[k++] = a[i][left];
            }
            ++left;
        }
    }

    return k;
}

// bool clear_zero_rows_cols(int a[][COLS], int rows, int cols) {
//     if (rows < 1 || cols < 1) {
//         return false;
//     }

//     bool has_zero = false;

//     for (int i = 0; i < rows; ++i) {
//         for (int j = 0; j < cols; ++j) {
//             if (a[i][j] == 0) {
//                 has_zero = true;
//                 for (int c = 0; c < cols; ++c) {
//                     a[i][c] = 0;
//                 }
//                 for (int r = 0; r < rows; ++r) {
//                     a[r][j] = 0;
//                 }
//             }
//         }
//     }

//     return has_zero;
// }

bool clear_zero_rows_cols(int a[][COLS], int rows, int cols) {
    if (rows < 1 || cols < 1) {
        return false;
    }

    bool zero_row[ROWS] = {};
    bool zero_col[COLS] = {};
    bool has_zero = false;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (a[i][j] == 0) {
                zero_row[i] = true;
                zero_col[j] = true;
                has_zero = true;
            }
        }
    }

    if (!has_zero) {
        return false;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (zero_row[i] || zero_col[j]) {
                a[i][j] = 0;
            }
        }
    }

    return true;
}