#include<iostream>
using namespace std;
int main()
{
	int n, еm,max, min;
	cout << "ВВедите длину последовательности" << endl;
	cin >> n;
	cout << "ВВедите первое число" << endl;
	cin >> еm;
	max = еm;
	min = еm;
	for (int i = 2; i <= n;i++)
	{
		cout << "ВВедите второе число" << endl;
		cin >> еm;
		if (еm > max)
		{
			max = еm;
		}
		else if (еm < min)
		{
			min = em;
		}
	}
	cout << "Сумма максимального и минимального чисел" <<(max+min)<< endl;
}