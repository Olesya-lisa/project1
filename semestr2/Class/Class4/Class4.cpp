#include <iostream>
#include "Pair.h"
#include "Rightangled.h"
using namespace std;

//функция возвращаемого объекта базового класса
Pair f2()
{
	Rightangled l( 3,4,5);
	return l;
}
void main()
{

	Pair a;
	cin >> a;
	cout << a;
	Pair b(23,45);
	cout << b;
	//a = b;
	//cout << a;
	Rightangled c;
	cin >> c;
	cout << c;
	a = f2();
	cout << a;

}