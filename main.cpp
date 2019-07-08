#include <iostream>
#include <cstring>
using namespace std;

void Func()
{
    static int n=65;
    cout<<n<<endl;
    n++;
}
void Func1()
{
    int n=65;
    cout<<n<<endl;
    n++;
}

char* MyStrtok(char * p, char * sep)
{
    static char * start;//start position this time.
    if(p) start=p;
    for(;*start&&strchr(sep,*start);++start);//skip sep
    if(*start==0) return NULL;
    char * q = start;
    for(;*start&&!strchr(sep, *start);++start);//skin non sep
    if(*start){//if not 0, it is a sep, set to 0;
        *start=0;
        ++start;//next start position.
    }
    return q;
}
main()
{
    Func();
    Func();
    Func();
    Func1();
    Func1();
    Func1();

    char str1[200]="--MyStrtok--works,well,as yours";

    char *p = MyStrtok(str1, "-, ");
    while (p)
    {
        cout<<p<<endl;
        p = MyStrtok(NULL, "-, ");
    }
    

}

