#include <iostream>
#include <clocale>
#include <stdio.h>

using namespace std;

class product
{
public:
	double first;
	unsigned int second;
	double cost()
	{
		return second * first;
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	product a;
	cout << "������� ���� ������: ";
	cin >> a.first;
	cout << "������� ���������� ������:";
	cin >> a.second;
	cout<<"����� ��������: "<<a.cost();
	return 0;

}