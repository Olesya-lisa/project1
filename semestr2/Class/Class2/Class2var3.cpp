#include <iostream>
#include <string>
#include <clocale>
#include "Marshryt.h"
using namespace std;

Marshryt make_marshryt()
{
	setlocale(LC_ALL, "rus");

	string s;
	string i;
	float d;
	cout << "������� ����� �����������: ";
	cin >> s;
	cout << "������� ����� ����������: ";
	cin >> i;
	cout << "������� ����� � ����: ";
	cin >> d;
	Marshryt t(s, i, d);
	return t;
}
void print_marshryt(Marshryt t)
{
	
	t.show();
}
void main()
{
	setlocale(LC_ALL, "rus");
	Marshryt t1;
	t1.show();
	Marshryt t2("��������", "����������", 3.30);
	t2.show();
	Marshryt t3 = t2;
	t3.set_otpravlenie("�����");
	t3.set_naznachenie("����-�����");
	t3.set_timeinpath(45.0);
	print_marshryt(t3);
	t1 = make_marshryt();
	t1.show();
}