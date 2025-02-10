#include <iostream>
#include <cstdlib>
#include <locale.h>
using namespace std;

void han(int size, int start, int point)
{
	setlocale(LC_ALL, "rus");
	if (size == 1)
	{
		cout << " Блок номер " << 1 << " Перенос " << start << " на " << point << endl;
	}
	else
	{
		int tmp = 6 - start - point;
		han(size - 1, start, tmp);
		cout << " Блок номер " << size << " Перенос " << start << " на " << point << endl;
		han(size - 1, tmp, point);
	}
	return;
}

int main()
{
	han(3, 1, 3);
	return 0;
}