#include <iostream>
#include <clocale>

using namespace std;
// »теративный вариант
int binarySearch(int arr[], int low, int high, int x)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == x) return mid;
		if (arr[mid] < x) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}
// –екурсивный вариант
int binarySearchRec(int arr[], int low, int high, int x)
{
	if (high >= low)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == x) return mid;
		// если середина больше ключа, ищем в левой (меньшей) стороне массива
		if (arr[mid] > x) return binarySearchRec(arr, low, mid - 1, x);
		// если середина меньше ключа, ищем ключ в правой (большей стороне массива)
		return binarySearchRec(arr, mid + 1, high, x);
	}
	return -1;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int arr[10] = { 2, 2, 6, 7, 13, 18, 21, 54, 68, 77 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 18;
	int res = binarySearch(arr, 0, n - 1, x);
	if (res == -1) cout << "Ёлемент " << x << " не найден" << endl;
	else cout << "Ёлемент " << x << " найден по индексу " << res <<endl;

	int resRec = binarySearchRec(arr, 0, n - 1, x);
	if (resRec == -1) cout << "Ёлемент " << x << " не найден" << endl;
	else cout << "Ёлемент " << x << " найден по индексу " << resRec <<endl;
	return 0;
}