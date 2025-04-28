#include <iostream>
#include "Rightangled.h"
#include<cmath>
using namespace std;

Rightangled::Rightangled(void) :Pair()
{
	gip = 0;
}
//деструктор
Rightangled::~Rightangled(void)
{
}
//конструктор с параметрами
Rightangled::Rightangled ( int F, int S, float G):Pair( F,S)
{
	gip = G;
}
//конструктор копирования
Rightangled::Rightangled(const Rightangled& R)
{
	first = R.first;
	second=R.second;
	gip=R.gip;
}
//модификатор
void Rightangled::Set_gip(float G)
{
	gip = G;
}
//операция присваивания
Rightangled& Rightangled::operator=(const Rightangled& r)
{
	if (&r == this) return *this;
	first = r.first;
	second = r.second;
	gip = r.gip;
	return *this;
}
//операция ввода
istream& operator>>(istream& in, Rightangled& r)
{
	cout << "\n First: ";
	in >> r.first;
	cout << "\n Second: ";
	in >> r.second;
	//cout << "\n Gipotenuza: ";
	//in >> r.gip;
	return in;
}
ostream& operator<<(ostream& out, const Rightangled& r)
{
	out << "\nFist: " << r.first;
	out << "\n Second: " <<r.second;
	out << "\n Gipotenuza: " << sqrt((r.first* r.first)+(r.second* r.second));
	out << "\n";
	return out;
}