#include <iostream>
using namespace std;
int main()
{
	float n, m;
	int we;
	cout << "Вводим 1-сложение, 2-вычитание, 3-умножение, 4-деление" << endl;
	cin >> n >> m >> we;
	switch (we)
	{
	case 1: cout << n + m << endl;break;
	case 2: cout << n - m << endl;break;
	case 3: cout << n * m << endl;break;
	case 4:
	{
		if ((m != 0) && (n != 0))
		{
			cout << n / m << endl;
		}
		else
		{
			if (m == 0)
			{
				cout << "Нельзя делить на 0!" << endl;
			}
			else
			{
				cout << "0" << endl;
			}
		}
		break;
	}
	default: cout << "Значение не подходит" << endl;
	}
	return 0;

}