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
	Vector v(5);//вектор из 5 элементов
	Pair a;
	cin >> a;
	Rightangled b;
	cin >> b;
	//cout << a << endl;
	pip* p = &a;//указатель на объект
	v.Add(p);//добавляем объект в вектор 
	p = &b;//ставим указатель на объект класса Lorry
	v.Add(p);
	cout << v;
}