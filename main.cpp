#include <iostream>
#include <cstring>
#include "math.h"
using namespace std;

float DistanceBetweenToPoints(float x1,float y1,float x2,float y2)
{
    float Distance = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return Distance;
}



main()
{
    char ch1 = 'a';
    char *p1 = &ch1;

    cout<<"original ch1 : "<<ch1<<endl;
   
    *p1='m';
    cout<<"modified ch1 : "<<ch1<<endl;
    cout<<"p1's address : "<<&p1<<endl;
    cout<<"the value of *p1 : "<<*p1<<endl;
}

