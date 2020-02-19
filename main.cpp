#include <iostream>
#include "header/complex.h"
using namespace std;



int main()
{
    complex<int> c1(2,1);
    cout<<c1.real()<<c1.imag();
    return 0;
}