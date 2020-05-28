
#include <iostream>
#include "header/complex.h"
#include "header/fegetground.h" 
using namespace std;


int main()
{
    fegetgroundtest();
    printf("rint(2.6)=%.1f\n", rint(2.6));
    printf("rint(2.2)=%.1f\n", rint(2.2));
    printf("rint(3.5)=%.1f\n", rint(3.5));
    printf("rint(3.6)=%.1f\n", rint(3.6));
	return 0;
}