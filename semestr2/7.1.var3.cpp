#include <iostream>
#include <complex>

using namespace std;
int ym(int a, int b)
{
	return a * b;
}
double ym(double a, double b)
{
	return a * b;
}
int com(int a, int b, double i)
{
	return a + (b*i);
}
void main()
{
	cout << ym(4.5, 5.5) << endl;
	cout << com(4,5,1) << endl;

}