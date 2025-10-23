#include <gtest/gtest.h>
#include "average.h"
#include "structure.h"

TEST(AverageTest, CalculatesAverage) {
    Structure data;
    int arr[] = { 1, 2, 3, 4, 5 };
    data.arrStruct = arr;
    data.sizeStruct = 5;

    Average(&data);
    EXPECT_EQ(data.averageValue, 3);
}

TEST(AverageTest, HandlesSingleElement) {
    Structure data;
    int arr[] = { 42 };
    data.arrStruct = arr;
    data.sizeStruct = 1;

    Average(&data);
    EXPECT_EQ(data.averageValue, 42);
}

TEST(AverageTest, HandlesNegativeNumbers) {
    Structure data;
    int arr[] = { -1, -2, -3, -4, -5 };
    data.arrStruct = arr;
    data.sizeStruct = 5;

    Average(&data);
    EXPECT_EQ(data.averageValue, -3);
}

TEST(AverageTest, HandlesMixedNumbers) {
    Structure data;
    int arr[] = { -5, 0, 5, 10 };
    data.arrStruct = arr;
    data.sizeStruct = 4;

    Average(&data);
    EXPECT_EQ(data.averageValue, 2);
}

TEST(AverageTest, HandlesZero) {
    Structure data;
    int arr[] = { 0, 0, 0, 0 };
    data.arrStruct = arr;
    data.sizeStruct = 4;

    Average(&data);
    EXPECT_EQ(data.averageValue, 0);
}