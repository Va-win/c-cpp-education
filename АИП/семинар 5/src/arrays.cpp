#include "arrays.h"

bool min_max(const int a[], int n, int* lo, int* hi) {
    // TODO: при n < 1 вернуть false, не трогая *lo и *hi
    (void)a;
    (void)n;
    *lo = 0;
    *hi = 0;
    return true;
}

void reverse(int a[], int n) {
    // TODO: обратить массив на месте
    if (n > 0) {
        a[0] = 0;
    }
}

void rotate_right(int a[], int n, int k) {
    // TODO: циклический сдвиг вправо на k
    (void)k;
    if (n > 0) {
        a[0] = 0;
    }
}

int unique_sorted(int a[], int n) {
    // TODO: убрать соседние повторы, вернуть новую длину
    (void)a;
    (void)n;
    return -1;
}

int merge_sorted(const int a[], int na, const int b[], int nb, int out[], int capacity) {
    // TODO: слить два упорядоченных массива или вернуть -1
    (void)a;
    (void)na;
    (void)b;
    (void)nb;
    (void)out;
    (void)capacity;
    return 0;
}
