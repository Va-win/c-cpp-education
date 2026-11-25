#include <iomanip>
#include <iostream>

#include "matrix.h"

bool read_matrix(int a[][COLS], int* rows, int* cols) {
    if (!(std::cin >> *rows >> *cols)) {
        return false;
    }
    if (*rows < 1 || *rows > ROWS || *cols < 1 || *cols > COLS) {
        return false;
    }
    for (int i = 0; i < *rows; ++i) {
        for (int j = 0; j < *cols; ++j) {
            if (!(std::cin >> a[i][j])) {
                return false;
            }
        }
    }
    return true;
}

void print_matrix(const int a[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(4) << a[i][j];
        }
        std::cout << '\n';
    }
}

void copy_matrix(const int a[][COLS], int rows, int cols, int out[][COLS]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            out[i][j] = a[i][j];
        }
    }
}

int main() {
    int a[ROWS][COLS] = {};
    int rows = 0;
    int cols = 0;
    if (!read_matrix(a, &rows, &cols)) {
        std::cerr << "ошибка ввода\n";
        return 1;
    }

    std::cout << "матрица:\n";
    print_matrix(a, rows, cols);

    // Каждая функция получает исходную матрицу, а не результат предыдущей.
    int smaller[ROWS][COLS] = {};
    copy_matrix(a, rows, cols, smaller);
    int smaller_rows = remove_max_row_col(smaller, rows, cols);
    if (smaller_rows < 0) {
        std::cout << "без строки и столбца максимума: операция невозможна\n";
    } else if (smaller_rows == 0 || cols == 1) {
        std::cout << "без строки и столбца максимума: матрица пуста\n";
    } else {
        std::cout << "без строки и столбца максимума:\n";
        print_matrix(smaller, smaller_rows, cols - 1);
    }

    int out[ROWS * COLS] = {};
    int n = write_spiral(a, rows, cols, out);
    std::cout << "спираль:";
    for (int k = 0; k < n; ++k) {
        std::cout << ' ' << out[k];
    }
    std::cout << '\n';

    int cleared[ROWS][COLS] = {};
    copy_matrix(a, rows, cols, cleared);
    if (clear_zero_rows_cols(cleared, rows, cols)) {
        std::cout << "после обнуления:\n";
        print_matrix(cleared, rows, cols);
    } else {
        std::cout << "обнуление: нулей нет\n";
    }
    return 0;
}
