
#include <iostream>

#define MAX 29

int Cube(int n){return n*n*n;}


// 枚举算法 enumerative algorithm
// 1. 完美立方
void PerfectCube(int n)
{
    for(int i=1; i<n+1;++i)
    {
        for(int j=1; j<i; ++j)
        {
            for(int k=1; k<j; ++k)
            {
                for(int m=1; m<k; ++m)
                {     
                    if(Cube(i) == Cube(j)+ Cube(k)+ Cube(m))
                        printf("Cube=%d\t, Triple=(%d,%d,%d)\n",i,m,k,j);
                }  
            }
        }
    }
}
int main()
{
    PerfectCube(MAX);  
 	return 0;
}
