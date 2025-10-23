#include <gtest/gtest.h>
#include "min_max.h"
#include "structure.h"

TEST(MinMaxTest, FindsMinAndMax) {
    Structure data;
    int arr[] = { 5, 2, 8, 1, 9 };
    data.arrStruct = arr;
    data.sizeStruct = 5;

    MinMax(&data);
    EXPECT_EQ(data.minValue, 1);
    EXPECT_EQ(data.maxValue, 9);
}

TEST(MinMaxTest, SingleElement) {
    Structure data;
    int arr[] = { 7 };
    data.arrStruct = arr;
    data.sizeStruct = 1;

    MinMax(&data);
    EXPECT_EQ(data.minValue, 7);
    EXPECT_EQ(data.maxValue, 7);
}

TEST(MinMaxTest, AllSameElements) {
    Structure data;
    int arr[] = { 5, 5, 5, 5 };
    data.arrStruct = arr;
    data.sizeStruct = 4;

    MinMax(&data);
    EXPECT_EQ(data.minValue, 5);
    EXPECT_EQ(data.maxValue, 5);
}

TEST(MinMaxTest, HandlesNegativeNumbers) {
    Structure data;
    int arr[] = { -3, -1, -7, -2 };
    data.arrStruct = arr;
    data.sizeStruct = 4;

    MinMax(&data);
    EXPECT_EQ(data.minValue, -7);
    EXPECT_EQ(data.maxValue, -1);
}

TEST(MinMaxTest, MixedPositiveNegative) {
    Structure data;
    int arr[] = { -5, 10, -3, 7, 0 };
    data.arrStruct = arr;
    data.sizeStruct = 5;

    MinMax(&data);
    EXPECT_EQ(data.minValue, -5);
    EXPECT_EQ(data.maxValue, 10);
}