#pragma once
#include <iostream>
using namespace std;

template<class T>//T-параметр шаблона
class Vector
{

public:
	//конструктор с параметрами: выделяет память под s элементов и заполняет их значениями k
	Vector(int s,T k);
	//конструктор с параметрами
	Vector(const Vector<T>& a);
	//деструктор
	~Vector();
	//оператор присваивания
	Vector& operator =(const Vector<T>& a);
	//операция доступ по индексу
	T& operator[] (int index);
	//операция для добавления константы
	Vector operator +(const T k);
	//операция, возвращая длину вектора
	int  operator() ();
	int len();
	//перегруженные операции ввода-вывода
	friend ostream& operator<< (ostream& out, const Vector<T>& a);
	friend istream& operator>> (istream& in, Vector<T>& a);
	//Vector operator +(const Vector<T>& v);
	//Iterator first() { return beg; }//возвращает указатель на первый элемент
	//Iterator last() { return end; }// возвращает указатель на элемент следующий за последним
private:
	int size;
	T* data;
};
