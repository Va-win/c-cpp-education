#include <iostream>

#include "arrays.h"

void print_array(const int a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << a[i];
    }
    std::cout << '\n';
}

void copy_array(const int src[], int dst[], int n) {
    for (int i = 0; i < n; ++i) {
        dst[i] = src[i];
    }
}

int main() {
    const int capacity = 8;
    int a[capacity];
    int b[capacity];
    int n = 0;
    if (!(std::cin >> n) || n < 1 || n > capacity) {
        std::cerr << "ошибка ввода\n";
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        if (!(std::cin >> a[i])) {
            std::cerr << "ошибка ввода\n";
            return 1;
        }
    }
    int k = 0;
    if (!(std::cin >> k) || k < 0) {
        std::cerr << "ошибка ввода\n";
        return 1;
    }
    int m = 0;
    if (!(std::cin >> m) || m < 0 || m > capacity) {
        std::cerr << "ошибка ввода\n";
        return 1;
    }
    for (int i = 0; i < m; ++i) {
        if (!(std::cin >> b[i])) {
            std::cerr << "ошибка ввода\n";
            return 1;
        }
    }

    int lo = 0;
    int hi = 0;
    if (!min_max(a, n, &lo, &hi)) {
        std::cout << "минимум: операция невозможна\n";
    } else {
        std::cout << "минимум: " << lo << '\n';
        std::cout << "максимум: " << hi << '\n';
    }

    int work[capacity];
    copy_array(a, work, n);
    reverse(work, n);
    std::cout << "реверс: ";
    print_array(work, n);

    copy_array(a, work, n);
    rotate_right(work, n, k);
    std::cout << "сдвиг: ";
    print_array(work, n);

    copy_array(a, work, n);
    int nu = unique_sorted(work, n);
    std::cout << "без повторов: ";
    print_array(work, nu);

    int out[capacity];
    int nm = merge_sorted(a, n, b, m, out, capacity);
    if (nm < 0) {
        std::cout << "слияние: операция невозможна\n";
    } else {
        std::cout << "слияние: ";
        print_array(out, nm);
    }
    return 0;
}
