#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	int n, www;
	bool plusfirst = false;
	bool minusfirst = false;
	cout << "Ведите число последовательности:" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> www;
		if (!plusfirst && !minusfirst)
		{
			if (www > 0)
			{
				plusfirst = true;
			}
			else if (www < 0)
			{
				minusfirst = true;
			}
		}
	}

	if (plusfirst)
	{
		cout << "Вы ввели сначало положительное число" << endl;
	}
	else if (minusfirst)
	{
		cout << "Вы ввели сначала отрицательное число " << endl;
	}
	else
	{
		cout << " Все числа нулевые" << endl;
	}
	cout << endl;
}
