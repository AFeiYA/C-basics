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

    char ch1[20] = "abcde";// 等价于char *ch1 = "abcde";
    //等价于 *ch1="abcde"
    //数组的名字就是一个指针常量：可以赋值给一个指针；
    char *pc1 = ch1;

    cout<<"ch1 started address : "<<&ch1<<endl;
    cout<<"pc1's address       : "<<&pc1<<endl;


    ++pc1;
    cout<<"next value of pc1   : "<<pc1<<endl;
    cout<<"pc1's address       : "<<&pc1<<endl;
    cout<<"ch1's address       : "<<&ch1<<endl;

    ++pc1;
    cout<<"next value of pc1   : "<<pc1<<endl;
    cout<<"pc1's address       : "<<&pc1<<endl;
    cout<<"ch1's address       : "<<&ch1<<endl;

    cout<<"next value of ch1   : "<<ch1<<endl;
    cout<<"next value of pc1   : "<<pc1<<endl;

    cout<<"original ch1 of ch1 : "<<ch1<<endl;

    *pc1='m';
    
    cout<<"modified ch1 of ch1 : "<<ch1<<endl;
    cout<<"the value of pc1    : "<<pc1<<endl;

    cout<<"the size of pc1     : "<<sizeof(ch1)<<endl;
    cout<<"the size of pc1     : "<<sizeof(pc1)<<endl;

    for(int i=0; ch1[i]; i++)
    {
        cout<<ch1[i]<<endl;
    }


}

