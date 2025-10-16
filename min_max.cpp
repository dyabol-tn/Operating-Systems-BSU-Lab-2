#include "min_max.h"
#include "structure.h"

const int sevenMilliseconds = 7;

DWORD WINAPI MinMax(LPVOID lpParameters) {
	Structure* data = (Structure*)lpParameters;
	int* arr = data->arrStruct;
	int size = data->sizeStruct;
	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		if (min > arr[i]) {
			Sleep(sevenMilliseconds);
			min = arr[i];
		}
		if (max < arr[i]) {
			Sleep(sevenMilliseconds);
			max = arr[i];
		}
	}
	data->minValue = min;
	data->maxValue = max;
	cout << "MIN: " << min << endl;
	cout << "MAX: " << max << endl;
	return 0;
}