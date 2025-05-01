#pragma once
#include <iostream>
#include "pip.h"
#include <string>
#include <clocale>
using namespace std;
class Pair :
	public pip
{
	//конструктор без параметров
public:
	Pair(void);
public:
	//деструктор
	virtual~Pair(void);
	void Shoow();
	//конструктор с параметрами
	Pair(int, int);
	//конструктор копирования
	Pair(const Pair&);
	//селекторы
	int Get_first() { return first; }
	int Get_second() { return second; }
	//модификаторы
	void Set_first(int);
	void Set_second(int);
	//перегрузка операции присваивания
	Pair& operator=(const Pair&);
	//глобальные операторы-функции ввода-вывода
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
	//атрибуты
protected:
	int first;
	int second;
};
