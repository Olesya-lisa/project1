#include <iostream>
#include <string>
#include <clocale>
#include "Marshryt.h"
using namespace std;

Marshryt::Marshryt()
{
	setlocale(LC_ALL, "rus");
	otpravlenie = "";
	naznachenie = "";
	timeinpath = 0;
	cout << "Конструктор без параметров для объекта " << this << endl;
}
Marshryt::Marshryt(string O, string N, float T)
{
	setlocale(LC_ALL, "rus");
	otpravlenie =  O;
	naznachenie = N;
	timeinpath = T;
	cout << "Конструктор S  параметрами для объекта" << this << endl;
}
Marshryt::Marshryt(const Marshryt& t)
{
	setlocale(LC_ALL, "rus");
	otpravlenie = t.otpravlenie;
	naznachenie = t.naznachenie;
	timeinpath = t.timeinpath;
	cout << "Конструктор копирования для объекта" << this << endl;
}
Marshryt::~Marshryt()
{
	setlocale(LC_ALL, "rus");
	cout << "Деструктор для объекта" << this << endl;
}
string Marshryt::get_otpravlenie()
{
	return otpravlenie;
}
string Marshryt::get_naznachenie()
{
	return naznachenie;
}
float Marshryt::get_timeinpath()
{
	return timeinpath;

}
void Marshryt::set_otpravlenie(string O)
{
	otpravlenie = O;

}
void Marshryt::set_naznachenie(string N)
{
	naznachenie = N;
}
void Marshryt::set_timeinpath(float T)
{
	timeinpath = T;
}
void Marshryt::show()
{
	setlocale(LC_ALL, "rus");
	cout << "Пункт отправления: " << otpravlenie;
	cout << endl;
	cout << "Пункт назначения: " << naznachenie;
	cout << endl;
	cout << "Время в пути: " << timeinpath;
	cout << endl;
}
