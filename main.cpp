#include <iostream>
#include <cstdlib>
using namespace std;
/*
Algorithm
递归
逆波兰表达式
算式：（5+3-2）*8的逆波兰表达式为
* - + 5 3 2 8
 */
//

double exp()
{
    char s[20];
    cin>>s;
    switch(s[0])
    {
        case '+' :return exp()+exp();
        case '-' :return exp()-exp();
        case '*' :return exp()*exp();
        case '/' :return exp()/exp();
        default: return atof(s);
        break;
    }
}



int main()
{
    cout<<exp();
    return 0;
}
