#include <iostream>
#include <queue>
#include <clocale>
#include <stdio.h>
#include <random>
#include <ctime>
#include <stack>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
struct Stack
{
	Node* top;
	int size;

	void init()
	{
		top = NULL;
		size = 0;
	}
	void push(int data)
	{
	 	Node* cur = new Node;
		cur->data = data;
		cur->next = top;
		top = cur;
		size++;
	}
	int pop()
	{
		int value = top->data;
		Node* tmp = top;
		top = top->next;
		size--;
		delete tmp;
		return value;
	}

	Node* Top() 
	{ 
		return top;
	}
};
Stack createStack(int size)
{
	Stack stack{};
	stack.init();
	int data;
	//cout << "ВВедите количество чисел в стеке :";
	for (int i = 0; i < size; i++)
	{
		cin >> data;
		stack.push(data);
	}
	return stack;
};
void Show(Stack stack)
{
	Node* tmp = stack.top;

	while (tmp != NULL)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	return;
}
/*void f_print(Stack stack)
{
	Node* p = top;
	while (p)
	{
		printf("%i", p->data);
		p = p->next;
	}
}*/

Stack Del_ind(Stack stack, int ind)
{
	Stack tmp_stack;
	tmp_stack.init();
	Node* top;
	for (int i = 0; i< ind; i++)
	{
		top = stack.top;
		tmp_stack.push(top->data);
		stack.pop();
	}
	stack.pop();
	while (tmp_stack.size>0)
	{
		top = tmp_stack.top;
		stack.push(top->data);
		tmp_stack.pop();
	}
	return stack;
}
Stack open(Stack stack, int ind)
{
	int n;
	cout << " Введите число: ";
	cin >> n;
	Stack tmp_stack;
	tmp_stack.init();
	Node* top;
	for (int i = 0; i < ind; i++)
	{
		top = stack.top;
		tmp_stack.push(top->data);
		stack.pop();
	}
	stack.push(n);
	while (tmp_stack.size > 0)
	{
		top = tmp_stack.top;
		stack.push(top->data);
		tmp_stack.pop();
	}
	return stack;
}

int main(void)
{
	Stack stack;
	setlocale(LC_ALL, "rus");
	//Node* top = NULL;
	int n;
	cin >> n;
	stack=createStack(n);
	Show(stack);
	int m;
	cout << endl;
	cout << " Введите индекс числа, которое хотите удалить: ";
	cin >> m;
	stack=Del_ind(stack, m);
	cout << endl;
	Show(stack);
	int j;
	cout << " Введите индекс числа: ";
	cin >> j;
	stack = open(stack, j);
	Show(stack);
	return 0;
}

