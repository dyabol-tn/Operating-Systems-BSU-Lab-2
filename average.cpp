#include "average.h"
#include "structure.h"

const int twelveMilliseconds = 12;

DWORD WINAPI Average(LPVOID lpParameters) {
	Structure* data = (Structure*)lpParameters;
	int* arr = data->arrStruct;
	int size = data->sizeStruct;
	int average;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        Sleep(twelveMilliseconds);
    }
    data->averageValue = sum / size;
    cout << "AVERAGE: " << data->averageValue << endl;
    return 0;
}