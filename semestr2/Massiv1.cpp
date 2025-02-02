#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int n, k;
	cin >> n;
	int arr[4]{2,3,4,5};
	for (int i = 0;i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n / 2;i++)
	{
		k = arr[i];
		arr[i] = arr[n - 1 - i];
		arr[n - 1 - i] = k;
	}
	for (int i = 0; i < n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}