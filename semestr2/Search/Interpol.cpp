#include <iostream>
#include <clocale>

using namespace std;

// »теративный вариант
int interpolationSearch(int arr[], int low, int high, int x)
{
	while (low <= high && x >= arr[low] && x <= arr[high])
	{
		if (low == high)
		{
			if (arr[low] == x) return low;
			return -1;
		}

		int pos = low + (((x - arr[low]) * (high - low)) / (arr[high]- arr[low]));
		if (arr[pos] == x) return pos;
		if (arr[pos] < x) low = pos + 1;
		else high = pos - 1;
	}
	return -1;
}
// –екурсивный вариант
int interpolationSearchRec(int arr[], int low, int high, int x)
{
	if (high >= low && x >= arr[low] && x <= arr[high])
	{
		int pos = low + (((x - arr[low]) * (high - low)) / (arr[high]- arr[low]));
		if (arr[pos] == x) return pos;
		if (arr[pos] > x) return interpolationSearchRec(arr, low, pos-1, x);
		if (arr[pos] < x) return interpolationSearchRec(arr, pos + 1,high, x);
	}
	return -1;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int arr[10] = { 2, 2, 6, 7, 13, 18, 21, 54, 68, 77 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 54;
	int res = interpolationSearch(arr, 0, n - 1, x);
	if (res == -1) cout << "Ёлемент " << x << " не найден" << endl;
	else cout << "Ёлемент " << x << " найден по индексу " << res <<endl;

	int resRec = interpolationSearchRec(arr, 0, n - 1, x);
	if (resRec == -1) cout << "Ёлемент " << x << " не найден" << endl;
	else cout << "Ёлемент " << x << " найден по индексу " << resRec <<endl;
	return 0;
}