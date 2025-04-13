#include <iostream>
#include <clocale>

using namespace std;
int search(int arr[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x) return i;
	}
	return -1;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int arr[10] = { 2, 46, 7, 90, 87, 10, 52, 71, 27, 13 };
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	int x = 90;
	int res = search(arr, arrLength, x);
	if (res == -1) cout << "Ёлемент " << x << " не найден" << endl;
	else cout << "Ёлемент " << x << " найден по индексу " << res <<endl;
	return 0;
}