#include <iostream>
#include <cstring>
using namespace std;

void Swap(char *s1, char *s2)
{
    char temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}


main()
{
    char s1='a';
    char s2='b';
    cout<<s1<<s2<<endl;
    Swap(&s1, &s2);
    cout<<s1<<s2<<endl;

    int **pp;
    int ***ppp;
    int *p;
    int n=123456;
    p = &n;
    pp = &p;
    ppp = &pp;

    cout<<"n's address:\t"<<p<<endl;
    cout<<"p's address:\t"<<pp<<endl;
    cout<<"pp's address:\t"<<ppp<<endl;
    cout<<"ppp's adress:\t"<<&ppp<<endl;

    cout<<"pp's address:\t"<<ppp<<endl;
    cout<<"p's address\t"<<*ppp<<endl;
    cout<<"n's address:\t"<<**ppp<<endl;
    cout<<"n's value:\t"<<***ppp<<endl;

    cout<<"n's value:\t"<<*p<<endl;
    cout<<"n's value:\t"<<**pp<<endl;
    cout<<"n's value:\t"<<***ppp<<endl;
}

