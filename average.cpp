#include "average.h"



int calculateAverage(int* arr, int size) {
	int average;
	for (int i = 0; i < size; i++) {
		average += arr[i];
		Sleep(12);
	}
	cout << average << endl;
	return (average / size);
}