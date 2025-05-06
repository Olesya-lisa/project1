#pragma once
#include <iostream>
using namespace std;
class Iterator
{
	friend class Vector;//������������� �����
public:
	Iterator() //����������� ��� ����������
	{
		elem = 0;
	}
	Iterator(const Iterator& it) { elem = it.elem; }//����������� �����������
	//������������� �������� ���������
	bool operator ==(const Iterator& it) { return elem == it.elem; }
	bool operator !=(const Iterator& it) { return elem != it.elem; }
	//������������� �������� ����e����
	void operator ++() { ++elem; };
	//������������� �������� ���������
	void operator--() { --elem; }
	// ������������� �������� �������������
	int& operator*() const { return *elem; }
private:
	int* elem;//��������� �� ������� ���� int

};

class Vector
{
	int size;
	//int *len;
	int* data;
	Iterator beg;//��������� �� ������ ������� �������
	Iterator end;//��������� �� ������� ��������� �� ���������
public:

	//����������� � �����������: �������� ������ ��� s ��������� � ��������� �� ���������� k
	Vector(int s, int k = 0);
	//����������� � �����������
	Vector(const Vector& a);
	//����������
	~Vector();
	//�������� ������������
	Vector& operator =(const Vector& a);
	//�������� ������ �� �������
	int& operator[] (int index);
	//�������� ��� ���������� ���������
	Vector operator +(const int k);
	//��������, ��������� ����� �������
	//int  operator() ();
	int len();
	//void add();
	//������������� �������� �����-������
	friend ostream& operator <<(ostream& out, Vector& a);
	friend istream& operator >> (istream& in, Vector& a);
	Vector operator +(const Vector& v);
	Iterator first() { return beg; }//���������� ��������� �� ������ �������
	Iterator last() { return end; }// ���������� ��������� �� ������� ��������� �� ���������

};