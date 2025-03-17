#include <iostream>
#include <string>
#include <clocale>
using namespace std;
int main()
{
	//setlocale(LC_ALL, "Russian");
	setlocale(0, " ");

	string str;
	getline(cin, str);
	//string st = "σεΰξύθÿώ"; 
	string st = "aeyuoi";

	for (int i = 0; i < str.length();i++)
	{
		if (st.find(str[i]) != string::npos)
		{
			str.erase(i, 1);
			i--;
		}
	}
	 
}