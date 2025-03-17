#include <iostream>
#include <stdarg.h>
#include <clocale>
#include <stdio.h>
using namespace std;
int sum(int cout, ...)
{
	va_list arg;
	va_start(arg, cout);
	int s = 0;

	for (int i = 0; i < cout;++i)
	{
		s += va_arg(arg, int);
	}
	va_end(arg);
	return s;
}

int main(void)
{
	setlocale(LC_ALL, "Russian");
	//setlocale(0, " ");
	//int res = sum(3, 5, 10, 12);
	cout << "\nÑóììà(5, 10, 12) =" << sum(3, 5, 10, 12);
	return 0;
	
}