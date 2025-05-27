#pragma once
#include <iostream>
#include <clocale>
#include "Vector.h"
using namespace std;

class Time
{
public:
	Time(void);
	Time(int, int);
	Time(const 	Time& );
	Time&operator=(const Time&);
	Time operator +( Time k);
	//глобальные функции ввода-вывода
friend istream& operator>>(istream& in, Time& );
friend ostream& operator<<(ostream& in, const Time& );
public:
	virtual ~Time(void) {};

private:
	int min, sec;
};
