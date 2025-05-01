#pragma once
#pragma once
#include "pip.h"
#include <iostream>
#include <string>

using namespace std;
class Vector
{
public:
	Vector(void);
	Vector(int);
public:
	~Vector(void);
	void Add(pip*);
	friend ostream& operator<<(ostream& out, const Vector&);
private:
	pip** beg;//указатель на первый элемента вектора
	int size;//размер
	int cur;//текущая позиция 
};
