// OS_Laboratory_Work_2.cpp: определяет точку входа для приложения.
//

#include "main.h"
#include "average.h"
#include "min_max.h"

using namespace std;

int main()
{
	int size;
	cout << "Введите размерность массива: ";
	cin >> size;
	int* arr = new int[size];
	cout << "Введите элементы массива: ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	return 0;
}
