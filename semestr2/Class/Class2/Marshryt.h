#include <iostream>
#include <string>
#include <clocale>
using namespace std;


class Marshryt
{

	string otpravlenie;
	string naznachenie;
	float timeinpath;
public:

	Marshryt();
	Marshryt(string, string, float);
	Marshryt(const Marshryt&);
	~Marshryt();
	string get_otpravlenie();
	void set_otpravlenie(string);
	string get_naznachenie();
	void set_naznachenie(string);
	float get_timeinpath();
	void set_timeinpath(float);
	void show();
};