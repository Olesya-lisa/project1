#include <iostream>
using namespace std;
int main()
{
	int n;
	float x, sum, fact;
	cin >> n>>x;
	sum = 1 + x;
	fact = 1;
	for (int i = 2; i <= n; i++)
	{
		fact += 1;
		sum += (pow(x,i) / fact);
	}
	cout << sum << endl;
}