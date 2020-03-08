#include <iostream>
#include "header/complex.h"
using namespace std;


int main()
{
    complex c1(2,1);
    cout<<c1.real()<<endl<<c1.imag()<<endl;
    complex c2(2.0,1.5);
    cout<<c2.real()<<endl<<c2.imag()<<endl;
    cout<<c1<<endl;
    cout<<"HELLLO";
    return 0;
}