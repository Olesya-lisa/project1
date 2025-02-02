#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int k, range_min, range_max;
	int *arr;
	range_min =2;
	range_max = 1000;
	int n = 50;
	arr = new int[n+1];
	for (int i = 0; i < n;i++)
	{
		arr[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
		cout << arr[i] << " ";
	}
	cout << endl;
	int i = 0;
	while (i<n)
	{
		if (arr[i] == 0)
		{
			for (int j=i;j<n;j++)
			{
				arr[j] = arr[j + 1];
			}
			i--;
			n--;
		}
		i++;
	}
	//написать цикл, когда после четного значения добавляется другой элемент массива
	//int t = 0;
	for (int i = 0; i < n;i++)
	{
		if (arr[i] % 2 == 0)
		{

			k = arr[i - 1] + 2;
			for (int j = i+1;j < n;j++)
			{
				arr[n-(j-(i+1))] = arr[n - (j-i)];
				///arr[n - t] = arr[n - t - 1];
				//t++;
			}
			arr[i + 1] = k;
			n++;
			break;
		}

	}
	cout << endl;
	for (int i = 0; i < n;i++)
	{
		cout << arr[i] << " ";
	}
}
