#include <iostream>
#include "Rightangled.h"
#include<cmath>
using namespace std;

Rightangled::Rightangled(void) :Pair()
{
	gip = 0;
}
//����������
Rightangled::~Rightangled(void)
{
}
//����������� � �����������
Rightangled::Rightangled ( int F, int S, float G):Pair( F,S)
{
	gip = G;
}
//����������� �����������
Rightangled::Rightangled(const Rightangled& R)
{
	first = R.first;
	second=R.second;
	gip=R.gip;
}
//�����������
void Rightangled::Set_gip(float G)
{
	gip = G;
}
//�������� ������������
Rightangled& Rightangled::operator=(const Rightangled& r)
{
	if (&r == this) return *this;
	first = r.first;
	second = r.second;
	gip = r.gip;
	return *this;
}
//�������� �����
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