#include<iostream>
#include<cmath>
using namespace std;
const signed char epsilon = 2;
static signed char f  ( char x)
{
	return 3 * sin(pow(x, 1.2)) + 0.35 * x - 3.8;
}
int main()
{
	char a, b, c;
	a = 2;
	b = 3;
	while (b - a > epsilon) 
	{
		c = (a + b) / 2;
		if (f(b) * f(c) > 0)
			c = b;
		else
			c = a;
	}
	cout << (a + b) / 2 << endl;
	return 0;
}

