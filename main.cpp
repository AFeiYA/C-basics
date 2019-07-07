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
    char s1[7] = "Hello ";
    char s2[7] = "world!";
    strcat(s1, s2);
    cout<<s1<<endl;


    int n=strlen(s1);
    cout<<n<<endl;
   
    for(int i=0; s1[i]; i++)
    {
        s1[i]=s1[i]+1;
        cout<<s1[i];
    }
    cout<<endl<<s1;
}
