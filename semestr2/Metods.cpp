#include <iostream>
#include <locale.h>
#include <cstdlib>
using namespace std;
int main()
{
	setlocale(LC_ALL, " rus");
	int tmp, range_min, range_max;
	int* arr;
	range_min = 2;
	range_max = 1000;
	int n = 30;
	arr = new int[n + 1];
	for (int i = 0; i < n;i++)
	{
		arr[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
		cout << arr[i] << " ";
	}
	cout << endl;
	//Метод пузырька
	for (int i = 0;i < n - 1;i++)
	{
		for (int j = 0; j < n - 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}

		}
	}
	cout << endl;
	cout << "метод пузырька:";

	for (int i = 0; i < n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	//Метод выбора
	int min_index;// индекс наименьшего по значению элемента
	for (int i = 0;i < n - 1;i++)
	{
		min_index = i;
		for (int j = i + 1;j < n;j++)
		{
			if (arr[j] < arr[min_index])
			{
				min_index = j;
			}
		}
		tmp = arr[min_index];
		arr[min_index] = arr[i];
		arr[i] = tmp;
	}
	cout << endl;
	cout << "Метод выбора :";
	for (int i = 0; i < n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	
	//Метод вставками

	int key;
	for (int i = 0;i < n;i++)
	{
		key = arr[i];
		int j = i - 1;
		//Если условие выполняется,нам нужно обьенять элементы 
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	cout << endl;
	cout << "Метод вставки:";
	for (int i = 0; i < n;i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
