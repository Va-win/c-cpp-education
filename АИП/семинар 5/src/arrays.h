#pragma once

// Пишет в *lo наименьшее значение, в *hi – наибольшее.
// При n < 1 возвращает false и не меняет *lo и *hi.
bool min_max(const int a[], int n, int* lo, int* hi);

// Меняет порядок элементов на обратный.
void reverse(int a[], int n);

// Циклический сдвиг вправо на k позиций, k >= 0.
// При n < 2 и при k % n == 0 массив не меняется.
void rotate_right(int a[], int n, int k);

// Удаляет соседние повторы в упорядоченном по неубыванию массиве.
// Возвращает новую длину. При n < 1 возвращает 0.
int unique_sorted(int a[], int n);

// Сливает два упорядоченных массива в out.
// Возвращает na + nb или -1, если na + nb > capacity.
// При -1 массив out не меняется.
// Из двух равных элементов первым берется элемент массива a.
int merge_sorted(const int a[], int na, const int b[], int nb, int out[], int capacity);
