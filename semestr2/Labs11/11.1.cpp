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
Node* head = NULL;
Node* tail = NULL;
Node* first = NULL;


Node* make_point_new(int n)
{
	Node* first;
	Node* p;
	first = NULL;
	for (int i = n;i > 0;i--)
	{
		p = new(Node);
		p->data = i;
		p->next = first;
		first = p;
	}
	return first;
}
void make_point(Node** first)
{
	//*first = NULL;
	*first = new Node;
	(*first)->data = rand();
	(*first)->next = NULL;

	//Node* end = *first;
	tail = *first;
	for (int i(0); i < 100; i++)
	{
		tail->next = new Node;
		tail = tail->next;
		tail->data = rand();
		tail->next = NULL;
	}
	//tail = end;
}
Node* print_point(Node* first)
{
	if (first == NULL)return NULL;
	Node* p = first;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	return first;
}
void pop_front()
{

	if (head == NULL) return;
	if (head = tail)
	{
		delete tail;
		head = tail = NULL;
		return;
	}
	Node* node = head;
	head = node->next;
	delete node;
}


Node* getAt(int t)//
{
	if (t < 0) return 0 ;
	Node* node = first;
	int n = 1;
	while (node && n != t && node->next) {
		node = node->next;
		n++;
	}
	if (n == t) 
	return node;
	else return NULL;
};

void insert(int k, int data)
{
	if (k == 1) {
		Node* node=new Node;
		node->next = first;
		node->data = data;
		first = node;
		return;
	}
	Node* left = getAt(k-1);
	if (left == NULL) return;
	Node* right = left->next;
	Node* node = new Node;
	//node->addData(data);
	left->next = node;
	node->data = data;
	node->next = right;
	if (right == NULL) tail = node;
}

void erase(int k)
{
	if (k < 0) return;
	if (k == 0)
	{
		pop_front();
		return;
	}

	Node* left = getAt(k-1);
	if (left == NULL)return;
	Node* node = left->next;
	if (node == NULL) return;
	Node* right = node->next;
	left->next = right;
	if (node == tail) tail = left;
	delete node;
}

		
int main()

{
	setlocale(LC_ALL, "rus");
	//Node* current = first;
	//int n;
	//cin >> n;
	make_point(&first);
	//first = make_point_new(100);
	print_point(first);
	int n;
	cout << endl;
	cout << "¬ведите индекс числа, которое хотите удалить:";
	cin >> n;
	erase(n);
	print_point(first);
	//return 0;
	int u, y;
	cout << endl;
	cout << "¬ведите число" << endl;
	cin >> u;
	cout << endl;
	cout << "¬ведите индекс числа, перед которым оно будет сто€ть" << endl;
	cin >> y;
	insert(y, u);
	print_point(first);
	string path = "File1.txt";
	ofstream fs;
	fs.open("path");
	if (fs.is_open())
	{
		fs << "hvgu" << std::endl;
	}
	fs.close();
	return 0;
}



