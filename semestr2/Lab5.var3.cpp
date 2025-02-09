#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int tmp;
	const int n = 3;
	int arr3[n][n];
	int arr4[n][n];
	int arr1[n][n] = {
		{1,2,3},
		{4,5,6},
		{7,4,0}
	};
	int arr2[n][n] = {
		{1,2,3},
		{4,5,6},
		{7,4,0}
	};
	for (int i = 0;i < n; i++)
	{

		for (int j = 0;j < n; j++)
		{
			cout << arr1[i][j] << " ";
		}
		cout << endl;

	}
	cout << endl;
	
	for (int i = 0; i < n;i++)
	{
		for (int j = 0 ;j < n;j++)
		{
			//tmp = arr1[i][j];
			//arr1[i][j] = arr1[j][i];
			//arr1[j][i] = tmp;
			arr4[j][n-1-i] = arr1[i][j];
		}
	}
	for (int i = 0;i < n; i++)
	{

		for (int j = 0;j < n; j++)
		{
			cout << arr4[i][j] << " ";
			
		}
		cout<<endl;

	}
	cout <<endl;
	for (int i = 0; i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			arr3[i][j] = arr4[i][j] + arr2[i][j];
		}

	}
	for (int i = 0;i < n; i++)
	{

		for (int j = 0;j < n; j++)
		{
			cout << arr3[i][j] << " ";

		}
		cout << endl;
	}
	return 0;
}