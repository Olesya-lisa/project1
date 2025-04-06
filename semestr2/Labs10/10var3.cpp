#include <iostream>
#include <stdlib.h>
#include <clocale>
#include <stdio.h>
#include <random>
using namespace std;

int* append(int* arr, size_t* len, size_t* cap, int value)
{
	if (*len >= *cap)
	{
		(*cap) *= 2;
		int* mas = (int*)malloc(sizeof(int) * *cap);
		if (mas == NULL)
		{
			return arr;
		}
		else
		{
			for (int i = 0;i < *len;++i)
			{
				mas[i] = arr[i];
			}
		}
		free(arr);
		arr = mas;
	}
	arr[*len] = value;
	(*len)++;
	return arr;
}

int* my_delete(int* arr, size_t* len, int pos)
{
	int* mass = (int*)malloc(sizeof(int) * *len - 1);
	int k = 0;
	for (int i = 0; i < *len;i++)
	{
		if (i != pos)
		{
			mass[k] = arr[i];
			k++;
		}
	}
	free(arr);
	*len = *len - 1;
	arr = mass;
	return arr;

}

int main(void)
{
	setlocale(LC_ALL, "Russian");
	//setlocale(0, " ");
	size_t cap = 20;
	size_t len = 0;
	int* arr = (int*)malloc(sizeof(int) * cap);
	//*arr = (int*)malloc(sizeof(int) * cap);
	int n, k = 0;
	cout<< "¬ведите число, с которого будет происходит удаление ";
	cin >> n;
	cout<< "¬ведите количество удал€емых элементов";
	cin >> k;

	for (int i = 0; i < cap;i++)
	{
		arr[i] = rand();
	}
	for (int i = 0; i < cap;i++)
	{
		printf("%d ", arr[i]);
	}
	cout << "\n";
	for (int i = n; i < n + k;i++)
	{
		arr = my_delete(arr, &cap, n);
	}

	//for (int i = 0; i < 21;i++)
	//{
//		arr=append(arr, &len, &cap, her);
//	}
	//printf(*arr);
	for (int i = 0; i < cap;i++)
	{
		printf("%d ", arr[i]);
	}
	cout << "\n";
	int m;
	cout << "¬ведите число:";
	cin>>m;

	arr = append(arr, &len, &cap, m);

	for (int i = 0; i < cap;i++)
	{
		printf("%d ", arr[i]);
	}
	free(arr);
	return 0;


}