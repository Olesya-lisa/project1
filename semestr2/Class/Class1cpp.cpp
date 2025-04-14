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
	cout << "¬ведите цену товара: ";
	cin >> a.first;
	cout << "¬ведите количество товара:";
	cin >> a.second;
	cout<<"ќбща€ стоимось: "<<a.cost();
	return 0;

}