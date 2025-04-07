#include <iostream>
#include <stdlib.h>
#include <clocale>
#include <stdio.h>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;
struct Node
{
	int data;
	Node* next;
};
struct Queue
{
	int size;
	Node* head;
	Node* tail;

	void push(Queue& q, char data)
	{
		Node* newNode = new Node{ data,NULL };
		q.tail->next = newNode;
		q.tail = newNode;
		q.size++;
		return;
	}
	void pop(Queue& q)

	{
		if (q.head != NULL)
		{
			Node* tmp = q.head;
			q.head = q.head->next;
			delete tmp;
			q.size--;
		}
		return;
	}
	void remove(Queue& q, char key)
	{
		int size = q.size;
		for (int i = 1;i <= size;i++)
		{
			if (q.head->data == key)
			{
				pop(q);
			}
			else
			{
				push(q, q.head->data);
				pop(q);
			}
		}
		return;

	}
	void insert(Queue& q, int k, int m)
	{
		for (int i = 1; i < m;i++)
		{
			push(q, q.head->data);
			pop(q);
		}
		int value;
		for (int i = 1; i <= k;i++)
		{
			cout << "Введите элемент для вставки: ";
			cin >> value;
			push(q, value);
		}
		int size = q.size;
		for (int i = m;i <= size - k;i++)
		{
			push(q, q.head->data);
			pop(q);
		}
		return;
	}
	void initQueue(Queue& q, int value)
	{
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = NULL;
		q.head = newNode;
		q.tail = newNode;
		q.size = 1;
		return;

	}
	void print(Queue& q)
	{
		Node* tmp = q.head;
		if (tmp == NULL) return;
		while (tmp != NULL)
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		return;
	}
	void create_queue(Queue& q, int n)
	{
		int value;
		cout << "Введите элемент #1:";
		cin >> value;
		initQueue(q, value);
		for (int i = 2;i <= n;i++)
		{
			cout << "Введите элемент # " << i << ": ";
			cin >> value;
			push(q, value);
		}
		print(q);
		return;
	}

};

int main()

{
	setlocale(LC_ALL, "rus");
	Queue q;
	int n;
	cout << "Введите количество элементов в очереди: ";
	cin >> n;
	q.create_queue(q, n);
	cout << endl;
	int key;
	cout<<"Введите число, которое надо удалить: ";
	cin >> key;
	q.remove(q, key);
	q.print(q);
	cout << endl;
	int  t;
	//cin >> l;
	cout << "Введите индекс вставляемого числа: ";
	cin >> t;
	q.insert(q, 1, t);
	q.print(q);
	return 0;
}



