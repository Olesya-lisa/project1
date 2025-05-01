#include <iostream>
#include <string>
#include <clocale>
#include "Pair.h"

using namespace std;
Pair::Pair(void)
{
	first = 0;
	second = 0;

}
//деструктор
Pair::~Pair(void)
{
}
//конструктор с параметрами
Pair::Pair(int F, int S)
{
	first = F;
	second = S;
}
//конструктор копирования
Pair::Pair(const Pair& pair)
{
	first = pair.first;
	second = pair.second;
}
//модификаторы
void Pair::Set_first(int F)
{
	first = F;
}
void Pair::Set_second(int S)
{
	second = S;
}
//перегрузка операции присваивания
Pair& Pair::operator=(const Pair& p)
{
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	return *this;
}
//глобальные функции для ввода
istream& operator>>(istream& in, Pair& p)
{

	cout << "\nFirst:";
	in >> p.first;
	cout << "\nSecond:";
	in >> p.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& p)
{
	out << "\nFIRST: " << p.first;
	out << "\nSECOND: " << p.second;
	out << "\nPRO: " << p.second * p.first;
	out << "\n";
	return out;
}
void Pair::Shoow()
{

	cout << "\nFirst:"<<first;
	cout << "\nSecond:"<<second;
	cout<<"\n";
}

