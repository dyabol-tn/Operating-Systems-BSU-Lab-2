#include "min_max.h"

void findMinMax(int* arr, int size) {
	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		if (min > arr[i]) {
			Sleep(7);
			min = arr[i];
		}
		if (max < arr[i]) {
			Sleep(7);
			max = arr[i];
		}
	}
}