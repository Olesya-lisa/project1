#include <iostream>
using namespace std;
int main()
{
	int a, dar, max;
	cout << "Введите длину последовательгости:" << endl;
	cin >> a;
	cout << "ВВедите первое число:" <<endl;
	cin >> max;
	for (int i = 2; i <= a; i++)
	{
		cout << "ВВедите второе число" << endl;
		cin >> dar;
		if (dar > max) { max = dar; }
	}
	cout << "Максимальный эллемент :" << max << endl;
}