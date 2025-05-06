#pragma once
#include <iostream>
using namespace std;
class Iterator
{
	friend class Vector;//дружественный класс
public:
	Iterator() //конструктор без параметров
	{
		elem = 0;
	}
	Iterator(const Iterator& it) { elem = it.elem; }//конструктор копирования
	//перегруженные операции сравнения
	bool operator ==(const Iterator& it) { return elem == it.elem; }
	bool operator !=(const Iterator& it) { return elem != it.elem; }
	//перегруженная операция инкрeмент
	void operator ++() { ++elem; };
	//перегруженная операция декремент
	void operator--() { --elem; }
	// перегруженная операция разыменования
	int& operator*() const { return *elem; }
private:
	int* elem;//указатель на элемент типа int

};

class Vector
{
	int size;
	//int *len;
	int* data;
	Iterator beg;//указатель на первый элемент вектора
	Iterator end;//указатель на элемент следующий за последним
public:

	//конструктор с параметрами: выделяет память под s элементов и заполняет их значениями k
	Vector(int s, int k = 0);
	//конструктор с параметрами
	Vector(const Vector& a);
	//деструктор
	~Vector();
	//оператор присваивания
	Vector& operator =(const Vector& a);
	//операция доступ по индексу
	int& operator[] (int index);
	//операция для добавления константы
	Vector operator +(const int k);
	//операция, возвращая длину вектора
	//int  operator() ();
	int len();
	//void add();
	//перегруженные операции ввода-вывода
	friend ostream& operator <<(ostream& out, Vector& a);
	friend istream& operator >> (istream& in, Vector& a);
	Vector operator +(const Vector& v);
	Iterator first() { return beg; }//возвращает указатель на первый элемент
	Iterator last() { return end; }// возвращает указатель на элемент следующий за последним

};