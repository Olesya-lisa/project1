#include "Vector.h"

#include <iostream>
#include <string>

using namespace std;
Vector::Vector(void)
{
	beg = 0;
	size = 0;
	cur = 0;
}
//деструктор
Vector::~Vector(void)
{
	if (beg != 0) delete[] beg;
	beg = 0;
}
//конструктор с параметрами
Vector::Vector(int n)
{
	beg = new pip * [n];
	cur = 0;
	size = n;
}
void Vector::Add(pip* p)
{
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}
//операция вывода
ostream& operator <<(ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Empty" << endl;
	pip** p = v.beg;
	for (int i = 0; i < v.cur;i++)
	{
		(*p)->Shoow();
		p++;

	}
	return out;
}