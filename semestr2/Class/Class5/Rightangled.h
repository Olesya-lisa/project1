#pragma once
#pragma once
#include "Pair.h"
#include <iostream>
#include <math.h>

using namespace std;
class Rightangled :
	public Pair
{
public:
	Rightangled(void); //конструктор бех параметров
public:
	~Rightangled(void);//деструктор
	void Shoow();
	Rightangled(int, int, float);//конструктор с параметрами
	Rightangled(const Rightangled&);//конструктор с параметрами
	int Get_gip() { return gip; }//молифмкатор
	void Set_gip(float); //селектор
	Rightangled& operator=(const Rightangled&);//операция присваивания
	friend istream& operator>>(istream& in, Rightangled& r);//ввод
	friend ostream& operator<<(ostream& out, const Rightangled& r);//вывод
protected:
	int gip;//атрибут гипотенуза

};


