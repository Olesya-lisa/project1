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
	cout << "����������� ��� ���������� ��� ������� " << this << endl;
}
Marshryt::Marshryt(string O, string N, float T)
{
	setlocale(LC_ALL, "rus");
	otpravlenie =  O;
	naznachenie = N;
	timeinpath = T;
	cout << "����������� S  ����������� ��� �������" << this << endl;
}
Marshryt::Marshryt(const Marshryt& t)
{
	setlocale(LC_ALL, "rus");
	otpravlenie = t.otpravlenie;
	naznachenie = t.naznachenie;
	timeinpath = t.timeinpath;
	cout << "����������� ����������� ��� �������" << this << endl;
}
Marshryt::~Marshryt()
{
	setlocale(LC_ALL, "rus");
	cout << "���������� ��� �������" << this << endl;
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
	cout << "����� �����������: " << otpravlenie;
	cout << endl;
	cout << "����� ����������: " << naznachenie;
	cout << endl;
	cout << "����� � ����: " << timeinpath;
	cout << endl;
}
