#include <gtest/gtest.h>

#include "matrix.h"

// Все ячейки массива 4 x 5 равны 100. Занятую часть тест пишет поверх.
void FillHundred(int a[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            a[i][j] = 100;
        }
    }
}

TEST(RemoveMax, Example) {
    int a[ROWS][COLS] = {
        {1, 8, 3},
        {4, 5, 6},
    };
    EXPECT_EQ(remove_max_row_col(a, 2, 3), 1);
    EXPECT_EQ(a[0][0], 4);
    EXPECT_EQ(a[0][1], 6);
}

TEST(RemoveMax, Tie) {
    int a[ROWS][COLS] = {
        {5, 1},
        {5, 2},
    };
    EXPECT_EQ(remove_max_row_col(a, 2, 2), 1);
    EXPECT_EQ(a[0][0], 2);
}

TEST(RemoveMax, Single) {
    int a[ROWS][COLS] = {{7}};
    EXPECT_EQ(remove_max_row_col(a, 1, 1), 0);
}

TEST(RemoveMax, IgnoreTail) {
    int a[ROWS][COLS] = {};
    FillHundred(a);
    a[0][0] = 9;
    a[0][1] = 1;
    a[1][0] = 2;
    a[1][1] = 3;
    EXPECT_EQ(remove_max_row_col(a, 2, 2), 1);
    EXPECT_EQ(a[0][0], 3);
}

TEST(Spiral, TwoByThree) {
    int a[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
    };
    int out[ROWS * COLS] = {};
    EXPECT_EQ(write_spiral(a, 2, 3, out), 6);
    const int expect[6] = {1, 2, 3, 6, 5, 4};
    for (int k = 0; k < 6; ++k) {
        EXPECT_EQ(out[k], expect[k]) << "k = " << k;
    }
}

TEST(Spiral, Column) {
    int a[ROWS][COLS] = {{1}, {2}, {3}};
    int out[ROWS * COLS] = {};
    for (int k = 0; k < ROWS * COLS; ++k) {
        out[k] = -1;
    }
    EXPECT_EQ(write_spiral(a, 3, 1, out), 3);
    EXPECT_EQ(out[0], 1);
    EXPECT_EQ(out[1], 2);
    EXPECT_EQ(out[2], 3);
    EXPECT_EQ(out[3], -1) << "лишняя запись после последней клетки";
}

TEST(Spiral, Square) {
    int a[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int out[ROWS * COLS] = {};
    EXPECT_EQ(write_spiral(a, 3, 3, out), 9);
    const int expect[9] = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    for (int k = 0; k < 9; ++k) {
        EXPECT_EQ(out[k], expect[k]) << "k = " << k;
    }
}

TEST(Spiral, Partial) {
    int a[ROWS][COLS] = {};
    FillHundred(a);
    const int src[2][3] = {{1, 2, 3}, {4, 5, 6}};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            a[i][j] = src[i][j];
        }
    }
    int out[ROWS * COLS] = {};
    EXPECT_EQ(write_spiral(a, 2, 3, out), 6);
    const int expect[6] = {1, 2, 3, 6, 5, 4};
    for (int k = 0; k < 6; ++k) {
        EXPECT_EQ(out[k], expect[k]) << "k = " << k;
    }
}

TEST(ClearZero, Example) {
    int a[ROWS][COLS] = {
        {1, 2, 0},
        {4, 5, 6},
        {7, 0, 9},
    };
    EXPECT_TRUE(clear_zero_rows_cols(a, 3, 3));
    const int expect[3][3] = {{0, 0, 0}, {4, 0, 0}, {0, 0, 0}};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            EXPECT_EQ(a[i][j], expect[i][j]) << "i = " << i << ", j = " << j;
        }
    }
}

TEST(ClearZero, None) {
    int a[ROWS][COLS] = {{1, 2}, {3, 4}};
    EXPECT_FALSE(clear_zero_rows_cols(a, 2, 2));
    EXPECT_EQ(a[1][0], 3);
}

TEST(ClearZero, Tail) {
    int a[ROWS][COLS] = {};
    FillHundred(a);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    a[0][2] = 0;
    EXPECT_FALSE(clear_zero_rows_cols(a, 2, 2));
    EXPECT_EQ(a[0][0], 1);
    EXPECT_EQ(a[0][1], 2);
    EXPECT_EQ(a[1][0], 3);
    EXPECT_EQ(a[1][1], 4);
}

TEST(ClearZero, SameRow) {
    int a[ROWS][COLS] = {
        {0, 1, 0},
        {2, 3, 4}
    };
    EXPECT_TRUE(clear_zero_rows_cols(a, 2, 3));
    EXPECT_EQ(a[0][0], 0);
    EXPECT_EQ(a[0][1], 0);
    EXPECT_EQ(a[0][2], 0);
    EXPECT_EQ(a[1][0], 0);
    EXPECT_EQ(a[1][1], 3);
    EXPECT_EQ(a[1][2], 0);
}

// Свой тест допишите здесь: TEST(ClearZero, SameRow), матрица 2 x 3 из строк 0 1 0 и 2 3 4.
// Ожидание и образец: слайд «Два нуля в одной строке», TEST(ClearZero, Example).
