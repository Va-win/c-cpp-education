#include <iomanip>
#include <iostream>

#include "matrix.h"

#ifdef _WIN32
#include <windows.h>
#endif

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

void print_addresses(int a[][COLS]) {
    std::cout << "&a[0][0] = " << &a[0][0] << '\n';
    std::cout << "a[0] + 1 = " << a[0] + 1 << '\n';
    std::cout << "a + 1    = " << a + 1 << '\n';
    std::cout << "&a[1][2] = " << &a[1][2] << '\n';
    std::cout << "&a[1][2] - &a[0][0] = " << (&a[1][2] - &a[0][0]) << '\n';
    std::cout << "sizeof(a[0]) = " << sizeof(a[0]) << '\n';
}

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif
    int a[ROWS][COLS] = {};
    int rows = 0;
    int cols = 0;
    if (!read_matrix(a, &rows, &cols)) {
        std::cerr << "ошибка ввода\n";
        return 1;
    }

    std::cout << "матрица:\n";
    print_matrix(a, rows, cols);
    print_addresses(a);

    std::cout << "сумма: " << sum_flat(&a[0][0], rows, cols) << '\n';
    std::cout << "суммы строк:";
    for (int i = 0; i < rows; ++i) {
        std::cout << ' ' << row_sum(a, cols, i);
    }
    std::cout << '\n';
    std::cout << "суммы столбцов:";
    for (int j = 0; j < cols; ++j) {
        std::cout << ' ' << col_sum(a, rows, j);
    }
    std::cout << '\n';

    if (rows == cols) {
        std::cout << "главная диагональ: " << main_diag_sum(a, rows) << '\n';
    } else {
        std::cout << "главная диагональ: операция невозможна\n";
    }

    int t[ROWS][COLS] = {};
    if (transpose(a, rows, cols, t)) {
        std::cout << "транспонированная:\n";
        print_matrix(t, cols, rows);
    } else {
        std::cout << "транспонирование: операция невозможна\n";
    }
    return 0;
}
