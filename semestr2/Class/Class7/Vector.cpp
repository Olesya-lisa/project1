#include <iostream>
#include "Vector.h"
#include <math.h>
#include <string>
using namespace std;

template <class T>
//����������� � ����������� 
Vector<T>::Vector(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}
//����������� �����������
template <class T>
Vector<T>::Vector(const Vector& a)
{
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}
//����������
template <class T>
Vector<T>::~Vector()
{
	delete[]data;
	data = 0;
}
//�������� ������������
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a)
{
	if (this == &a) return *this;
	size = a.size;
	if (data != 0) delete[] data;
	data = new T[size];
	for (int i = 0; i < size;i++)
		data[i] = a.data[i];
	return *this;

}
//�������� ������� �� �������
template <class T>
T& Vector<T>::operator[] (int index)
{
	int l;
	if (index < size) return data[index];
	else
	{
		cout << "\n Error! Index>size";
		return l;
	}
}
//�������� ��� ���������� ���������
template <class T>
Vector<T> Vector<T> ::operator +(const T k)//+k
{
	Vector<T> temp(size,k);
	for (int i = 0; i < size;++i)
		temp.data[i] += data[i] + k;
	return temp;
}
template <class T>
int Vector<T>::len()
{
	return size;
}
//�������� ��� ��������� ����� ������� 
/*int Vector ::operator () ()
{
	return len();
}*/
//�������� ��� �����-������
template <class T>
ostream& operator <<(ostream& out, Vector<T>& a)

{
	for (int i = 0; i < a.len();++i)
		out << a.data[i] << " ";
	return out;
}
template <class T>
istream& operator >>(istream& in, Vector<T>& a)
{
	for (int i = 0; i < a.len();++i)
		in >> a.data[i];
	return in;
}
