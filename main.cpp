#include <iostream>
#include <cstring>
using namespace std;
//选择排序
void SelectionSort(int a[], int size)
{


    for(int i=0; i<size-1; ++i)
    {
        int minElementIndex = i; 
        for(int j=i+1; j<size;++j)
        {
            if(a[minElementIndex]>a[j])
            {
                minElementIndex=j;
            }
        }
        int temp = a[i];
        a[i] = a[minElementIndex];
        a[minElementIndex] = temp;       
    }

}

//二分查找求方程f(x)=x^3-5x^2+10x-80 = 0的根m, |f(m)|<=10^-6 :f(x)单调递增。
double f(double x) {return x*x*x-5*x*x+10*x-80;}
double findRoot(double x1, double x2,  double EPS)
{
    double root, y;
    root = x1+(x2-x1)/2;
    int triedTimes=1;
    y=f(root);

    while (abs(y)>EPS)
    {
        if(y>0) x2=root;
        else x1=root;
        root = x1+(x2-x1)/2;
        y = f(root);
        triedTimes++;
    }  
    cout<<triedTimes<<endl;
    return root;
}


main()
{
    int a[]={1,2,5,8,6,7};
    SelectionSort(a, sizeof(a)/sizeof(*a));
    
    cout<<f(0)<<"____"<<f(10)<<endl;
    double EPS = 1e-7,x1 = 0, x2 = 10; 
    double root = findRoot(x1,x2,EPS);
    cout<<"f("<<root<<")="<<f(root)<<endl;

}

