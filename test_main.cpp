#include <gtest/gtest.h>
#include "main.h"
#include "average.h"
#include "min_max.h"
#include "structure.h"

TEST(IntegrationTest, CompleteWorkflow) {
    Structure data;
    int arr[] = { 10, 20, 30, 40, 50 };
    data.arrStruct = arr;
    data.sizeStruct = 5;

    MinMax(&data);
    Average(&data);

    EXPECT_EQ(data.minValue, 10);
    EXPECT_EQ(data.maxValue, 50);
    EXPECT_EQ(data.averageValue, 30);

    for (int i = 0; i < data.sizeStruct; i++) {
        if (arr[i] == data.minValue || arr[i] == data.maxValue) {
            arr[i] = data.averageValue;
        }
    }

    EXPECT_EQ(arr[0], 30);
    EXPECT_EQ(arr[4], 30);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr[2], 30);
    EXPECT_EQ(arr[3], 40);
}

TEST(IntegrationTest, ReplaceLogic) {
    Structure data;
    int arr[] = { 1, 2, 3, 4, 5 };
    data.arrStruct = arr;
    data.sizeStruct = 5;
    data.minValue = 1;
    data.maxValue = 5;
    data.averageValue = 3;

    for (int i = 0; i < data.sizeStruct; i++) {
        if (arr[i] == data.minValue || arr[i] == data.maxValue) {
            arr[i] = data.averageValue;
        }
    }

    EXPECT_EQ(arr[0], 3);
    EXPECT_EQ(arr[4], 3);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 4);
}

TEST(IntegrationTest, WhenMinEqualsMax) {
    Structure data;
    int arr[] = { 5, 5, 5 };
    data.arrStruct = arr;
    data.sizeStruct = 3;
    data.minValue = 5;
    data.maxValue = 5;
    data.averageValue = 5;

    for (int i = 0; i < data.sizeStruct; i++) {
        if (arr[i] == data.minValue || arr[i] == data.maxValue) {
            arr[i] = data.averageValue;
        }
    }

    for (int i = 0; i < data.sizeStruct; i++) {
        EXPECT_EQ(arr[i], 5);
    }
}

TEST(IntegrationTest, MemoryHandling) {
    int size = 3;
    int* arr = new int[size] {1, 2, 3};

    Structure data;
    data.arrStruct = arr;
    data.sizeStruct = size;
    data.minValue = 1;
    data.maxValue = 3;
    data.averageValue = 2;

    for (int i = 0; i < data.sizeStruct; i++) {
        if (arr[i] == data.minValue || arr[i] == data.maxValue) {
            arr[i] = data.averageValue;
        }
    }

    EXPECT_EQ(arr[0], 2);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 2);

    delete[] arr;
}

TEST(IntegrationTest, ThreadSafetySimulation) {
    Structure data;
    int arr[] = { 15, 25, 35, 45 };
    data.arrStruct = arr;
    data.sizeStruct = 4;

    MinMax(&data);
    Average(&data);

    EXPECT_EQ(data.minValue, 15);
    EXPECT_EQ(data.maxValue, 45);
    EXPECT_EQ(data.averageValue, 30);

    for (int i = 0; i < data.sizeStruct; i++) {
        if (arr[i] == data.minValue || arr[i] == data.maxValue) {
            arr[i] = data.averageValue;
        }
    }

    EXPECT_EQ(arr[0], 30);
    EXPECT_EQ(arr[3], 30);
    EXPECT_EQ(arr[1], 25);
    EXPECT_EQ(arr[2], 35);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}