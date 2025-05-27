#pragma once
#include <iostream>
using namespace std;

template<class T>//T-�������� �������
class Vector
{

public:
	//����������� � �����������: �������� ������ ��� s ��������� � ��������� �� ���������� k
	Vector(int s,T k);
	//����������� � �����������
	Vector(const Vector<T>& a);
	//����������
	~Vector();
	//�������� ������������
	Vector& operator =(const Vector<T>& a);
	//�������� ������ �� �������
	T& operator[] (int index);
	//�������� ��� ���������� ���������
	Vector operator +(const T k);
	//��������, ��������� ����� �������
	int  operator() ();
	int len();
	//������������� �������� �����-������
	friend ostream& operator<< (ostream& out, const Vector<T>& a);
	friend istream& operator>> (istream& in, Vector<T>& a);
	//Vector operator +(const Vector<T>& v);
	//Iterator first() { return beg; }//���������� ��������� �� ������ �������
	//Iterator last() { return end; }// ���������� ��������� �� ������� ��������� �� ���������
private:
	int size;
	T* data;
};
