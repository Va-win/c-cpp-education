#include <gtest/gtest.h>

#include "matrix.h"

// Занятая часть 3 x 4 в массиве 4 x 5. Незанятые ячейки равны 100.
void FillPartial(int a[][COLS]) {
    const int src[ROWS][COLS] = {
        {1, 2, 3, 4, 100},
        {5, 6, 7, 8, 100},
        {9, 10, 11, 12, 100},
        {100, 100, 100, 100, 100},
    };
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            a[i][j] = src[i][j];
        }
    }
}

TEST(ElementPtr, Corner) {
    int a[ROWS][COLS] = {};
    FillPartial(a);
    EXPECT_EQ(element_ptr(a, 0, 0), &a[0][0]);
}

TEST(ElementPtr, Middle) {
    int a[ROWS][COLS] = {};
    FillPartial(a);
    ASSERT_EQ(element_ptr(a, 1, 2), &a[1][2]);
    EXPECT_EQ(*element_ptr(a, 1, 2), 7);
}

TEST(ElementPtr, RowStart) {
    int a[ROWS][COLS] = {};
    FillPartial(a);
    ASSERT_EQ(element_ptr(a, 2, 0), &a[2][0]);
    EXPECT_EQ(*element_ptr(a, 2, 0), 9);
}

TEST(SumFlat, FullWidth) {
    int a[ROWS][COLS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {100, 100, 100, 100, 100},
        {100, 100, 100, 100, 100},
    };
    EXPECT_EQ(sum_flat(&a[0][0], 2, 5), 55);
}

TEST(SumFlat, Partial) {
    int a[ROWS][COLS] = {};
    FillPartial(a);
    EXPECT_EQ(sum_flat(&a[0][0], 3, 4), 78);
}

TEST(SumFlat, Single) {
    int a[ROWS][COLS] = {{-7, 100}, {100}};
    EXPECT_EQ(sum_flat(&a[0][0], 1, 1), -7);
}

TEST(RowSum, Values) {
    int a[ROWS][COLS] = {};
    FillPartial(a);
    EXPECT_EQ(row_sum(a, 4, 0), 10);
    EXPECT_EQ(row_sum(a, 4, 1), 26);
}

TEST(ColSum, Values) {
    int a[ROWS][COLS] = {};
    FillPartial(a);
    EXPECT_EQ(col_sum(a, 3, 0), 15);
    EXPECT_EQ(col_sum(a, 3, 2), 21);
}

TEST(MainDiag, ThreeByThree) {
    int a[ROWS][COLS] = {
        {1, 2, 3, 100},
        {4, 5, 6, 100},
        {7, 8, 0, 100},
        {100, 100, 100, 100},
    };
    EXPECT_EQ(main_diag_sum(a, 3), 6);
}

TEST(MainDiag, Single) {
    int a[ROWS][COLS] = {{5, 100}, {100, 100}};
    EXPECT_EQ(main_diag_sum(a, 1), 5);
}

TEST(Transpose, TwoByThree) {
    int a[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
    };
    int out[ROWS][COLS] = {};
    EXPECT_TRUE(transpose(a, 2, 3, out));
    const int expect[3][2] = {{1, 4}, {2, 5}, {3, 6}};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            EXPECT_EQ(out[i][j], expect[i][j]) << "i = " << i << ", j = " << j;
        }
    }
}

TEST(Transpose, Single) {
    int a[ROWS][COLS] = {{5}};
    int out[ROWS][COLS] = {};
    EXPECT_TRUE(transpose(a, 1, 1, out));
    EXPECT_EQ(out[0][0], 5);
}

TEST(Transpose, DoesNotFit) {
    int a[ROWS][COLS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
    };
    int out[ROWS][COLS] = {};
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            out[i][j] = 7;
        }
    }
    EXPECT_FALSE(transpose(a, 2, 5, out));
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            EXPECT_EQ(out[i][j], 7) << "i = " << i << ", j = " << j;
        }
    }
}

TEST(ElementPtr, LastOfPartial) {
    int a[ROWS][COLS] = {};
    FillPartial(a);
    ASSERT_EQ(element_ptr(a, 2, 3), &a[2][3]);
    ASSERT_EQ(element_ptr(a, 2, 3), &a[0][0] + 13);
    EXPECT_EQ(*element_ptr(a, 2, 3), 12);
}

// Свой тест допишите здесь: element_ptr для последнего элемента занятой части 3 x 4.
// Образцы: TEST(ElementPtr, Middle) и TEST(ElementPtr, RowStart), слайд «Свой тест».
