#include <gtest/gtest.h>

#include "arrays.h"

void ExpectPrefix(const int a[], const int expect[], int n) {
    for (int i = 0; i < n; ++i) {
        EXPECT_EQ(a[i], expect[i]) << "i = " << i;
    }
}

TEST(MinMax, TooShort) {
    const int a[] = {4, 1, 9};
    int lo = 7;
    int hi = 9;
    EXPECT_FALSE(min_max(a, 0, &lo, &hi));
    EXPECT_EQ(lo, 7);
    EXPECT_EQ(hi, 9);
    EXPECT_FALSE(min_max(a, -1, &lo, &hi));
    EXPECT_EQ(lo, 7);
    EXPECT_EQ(hi, 9);
}

TEST(MinMax, Single) {
    const int a[] = {5};
    int lo = 0;
    int hi = 0;
    EXPECT_TRUE(min_max(a, 1, &lo, &hi));
    EXPECT_EQ(lo, 5);
    EXPECT_EQ(hi, 5);
}

TEST(MinMax, Values) {
    const int a[] = {4, -2, 9, 1, 9};
    int lo = 0;
    int hi = 0;
    EXPECT_TRUE(min_max(a, 5, &lo, &hi));
    EXPECT_EQ(lo, -2);
    EXPECT_EQ(hi, 9);
}

TEST(Reverse, Five) {
    int a[] = {1, 2, 3, 4, 5};
    reverse(a, 5);
    const int expect[] = {5, 4, 3, 2, 1};
    ExpectPrefix(a, expect, 5);
}

TEST(Reverse, Single) {
    int a[] = {7};
    reverse(a, 1);
    EXPECT_EQ(a[0], 7);
}

TEST(RotateRight, ByTwo) {
    int a[] = {1, 2, 3, 4, 5};
    rotate_right(a, 5, 2);
    const int expect[] = {4, 5, 1, 2, 3};
    ExpectPrefix(a, expect, 5);
}

TEST(RotateRight, ZeroAndLength) {
    int zero[] = {1, 2, 3, 4, 5};
    int full[] = {1, 2, 3, 4, 5};
    rotate_right(zero, 5, 0);
    rotate_right(full, 5, 5);
    const int expect[] = {1, 2, 3, 4, 5};
    ExpectPrefix(zero, expect, 5);
    ExpectPrefix(full, expect, 5);
}

TEST(RotateRight, BySeven) {
    int a[] = {1, 2, 3, 4, 5};
    rotate_right(a, 5, 7);
    const int expect[] = {4, 5, 1, 2, 3};
    ExpectPrefix(a, expect, 5);
}

TEST(RotateRight, Single) {
    int a[] = {7};
    rotate_right(a, 1, 3);
    EXPECT_EQ(a[0], 7);
}

TEST(UniqueSorted, Runs) {
    int a[] = {1, 1, 2, 2, 2, 3};
    EXPECT_EQ(unique_sorted(a, 6), 3);
    const int expect[] = {1, 2, 3};
    ExpectPrefix(a, expect, 3);
}

TEST(UniqueSorted, AllEqual) {
    int a[] = {2, 2, 2};
    EXPECT_EQ(unique_sorted(a, 3), 1);
    EXPECT_EQ(a[0], 2);
}

TEST(UniqueSorted, Single) {
    int a[] = {4};
    EXPECT_EQ(unique_sorted(a, 1), 1);
    EXPECT_EQ(a[0], 4);
}

TEST(MergeSorted, Example) {
    const int a[] = {1, 4, 9};
    const int b[] = {2, 4, 10, 11};
    int out[7] = {};
    EXPECT_EQ(merge_sorted(a, 3, b, 4, out, 7), 7);
    const int expect[] = {1, 2, 4, 4, 9, 10, 11};
    ExpectPrefix(out, expect, 7);
}

TEST(MergeSorted, EmptySide) {
    const int a[] = {1, 4, 9};
    const int b[] = {2, 4, 10, 11};
    int out[3] = {0, 0, 0};
    EXPECT_EQ(merge_sorted(a, 3, b, 0, out, 3), 3);
    const int expect[] = {1, 4, 9};
    ExpectPrefix(out, expect, 3);
    EXPECT_EQ(merge_sorted(b, 0, a, 3, out, 3), 3);
    ExpectPrefix(out, expect, 3);
}

// Свой тест допишите здесь: результат слияния не помещается в out.
// Образцы – TEST(MergeSorted, Example) и TEST(MinMax, TooShort), слайд «Свой тест».
