#include <iostream>
#include <cstdlib>
#include <locale.h>
using namespace std;

void han(int size, int start, int point)
{
	setlocale(LC_ALL, "rus");
	if (size == 1)
	{
		cout << " ���� ����� " << 1 << " ������� " << start << " �� " << point << endl;
	}
	else
	{
		int tmp = 6 - start - point;
		han(size - 1, start, tmp);
		cout << " ���� ����� " << size << " ������� " << start << " �� " << point << endl;
		han(size - 1, tmp, point);
	}
	return;
}

int main()
{
	han(3, 1, 3);
	return 0;
}