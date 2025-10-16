// OS_Laboratory_Work_2.cpp: определяет точку входа для приложения.
//

#include "main.h"
#include "average.h"
#include "min_max.h"
#include "structure.h"

using namespace std;

int main()
{
	int size;
	cout << "Array size: ";
	cin >> size;
	int* arr = new int[size];
	cout << "Array elements: ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	Structure data;
	data.arrStruct = arr;
	data.sizeStruct = size;

	HANDLE hMinMaxThread;
	DWORD IDMinMaxThread;
	hMinMaxThread = CreateThread(NULL, 0, MinMax, &data, 0, &IDMinMaxThread);
	WaitForSingleObject(hMinMaxThread, INFINITE);
	CloseHandle(hMinMaxThread);
	HANDLE hAverageThread;
	DWORD IDAverageThread;
	hAverageThread = CreateThread(NULL, 0, Average, &data, 0, &IDMinMaxThread);
	WaitForSingleObject(hAverageThread, INFINITE);
	CloseHandle(hAverageThread);
	for (int i = 0; i < size; i++) {
		if (arr[i] == data.minValue || arr[i] == data.maxValue) {
			arr[i] = data.averageValue;
		}
	}

	delete[] arr;

	return 0;
}
