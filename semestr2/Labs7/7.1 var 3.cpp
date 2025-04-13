#include <iostream>
#include <complex>
using namespace std;
double myltipy(double a, double b) {
	return a * b;
}
complex<double> myltipy(complex<double> a, complex<double> b) {
	return a * b;
}
int main() {
	auto da = 2.5;
	auto db = 3.5;
	auto dm = myltipy(da, db);
	cout << da << " * " << db << " = " << dm << '\n';
	complex<double> ca(3.0, 5.0);
	complex<double> cb(4.0, 6.0);
	auto cm = myltipy(ca, cb);
	cout << ca << " * " << cb << " = " << cm << '\n';
	return 0;
}