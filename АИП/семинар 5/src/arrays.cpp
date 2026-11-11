#include "arrays.h"

bool min_max(const int a[], int n, int* lo, int* hi) {
    if (n < 1 || lo == nullptr || hi == nullptr) {
        return false;
    }

    int min_val = a[0];
    int max_val = a[0];

    for (int i = 1; i < n; ++i) {
        if (a[i] < min_val) {
            min_val = a[i];
        }
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }

    *lo = min_val;
    *hi = max_val;
    return true;
}

void reverse(int a[], int n) {
    if (n <= 1 || a == nullptr) {
        return;
    }

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;

        ++left;
        --right;
    }
}

void rotate_right(int a[], int n, int k) {
    if (n <= 1 || a == nullptr) {
        return;
    }

    k = (k % n + n) % n;
    if (k == 0) {
        return;
    }

    reverse(a, n);
    reverse(a, k);
    reverse(a + k, n - k);
}

int unique_sorted(int a[], int n) {
    if (n <= 1 || a == nullptr) {
        return n < 0 ? 0 : n;
    }

    int write_idx = 1;
    for (int read_idx = 1; read_idx < n; ++read_idx) {
        if (a[read_idx] != a[write_idx - 1]) {
            a[write_idx] = a[read_idx];
            ++write_idx;
        }
    }
    return write_idx;
}

int merge_sorted(const int a[], int na, const int b[], int nb, int out[], int out_cap) {
    if (na + nb > out_cap) {
        return -1; 
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < na && j < nb) {
        if (a[i] <= b[j]) {
            out[k++] = a[i++];
        } else {
            out[k++] = b[j++];
        }
    }

    while (i < na) {
        out[k++] = a[i++];
    }

    while (j < nb) {
        out[k++] = b[j++];
    }

    return k;
}
