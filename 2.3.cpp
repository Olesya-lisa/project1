#include <iostream>
using namespace std;
int main()
{
	int n; 
	int b, sum = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		b = 1;
		for (int j = i;j <= 2 * i; j++)
		{
			b *= j;
		}
		sum += b;
	}
	cout << sum << endl;
}