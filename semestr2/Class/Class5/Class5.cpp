#include "pip.h"
#include "Pair.h"
#include "Rightangled.h"
#include "Vector.h"
#include <iostream>
#include <string>
#include <clocale>
using namespace std;
void main()
{
	Vector v(5);//������ �� 5 ���������
	Pair a;
	cin >> a;
	Rightangled b;
	cin >> b;
	//cout << a << endl;
	pip* p = &a;//��������� �� ������
	v.Add(p);//��������� ������ � ������ 
	p = &b;//������ ��������� �� ������ ������ Lorry
	v.Add(p);
	cout << v;
}