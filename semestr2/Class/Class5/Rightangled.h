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
	Rightangled(void); //����������� ��� ����������
public:
	~Rightangled(void);//����������
	void Shoow();
	Rightangled(int, int, float);//����������� � �����������
	Rightangled(const Rightangled&);//����������� � �����������
	int Get_gip() { return gip; }//�����������
	void Set_gip(float); //��������
	Rightangled& operator=(const Rightangled&);//�������� ������������
	friend istream& operator>>(istream& in, Rightangled& r);//����
	friend ostream& operator<<(ostream& out, const Rightangled& r);//�����
protected:
	int gip;//������� ����������

};


