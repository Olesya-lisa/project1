#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	int n, s, o;
	bool flag = false;
	cin >> n >> s;
	while (n > 0 && !flag)
	{
		o = n % 10;
		if (o == s)
		{
			flag = true;
			cout<<"Öטפנא םאיהוםא!" << endl;
		}
		else
		{
			n /= 10;
		}
	}
	if (!flag)
	{
		cout << "Öטפנא םו םאיהוםא!" << endl;
	}


}