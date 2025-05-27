#include <iostream>
#include "Vector.h"
#include "Time1.h"
using namespace std;

int main()
{
    Time t;
    cin >> t;
    cout << t;
    Vector <Time> A(5,t);
    cin >> A;
    cout << A << endl;
    Vector <Time>B(10,t);
    cout << B << endl;
    B = A;
    cout << B<< endl;
    cout << A[2] << endl;
    cout << "size="<<A() << endl;
    B = A + t;
    cout << B << endl;
    int k; 
    cout << "k?";
    cin >> k;
    //Time p;
    //p = k+p;
   // cout << p;
   

}