#include <iostream>
using namespace std;
/*
Algorithm
递归
 */

//求阶乘
int Factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * Factorial(n - 1);
}
//汉诺塔
void Hanoi(int n, char src, char temp, char dst)
{
    if (n == 1)
    {
        cout << "move " << n << " to " << dst << endl;
        return;
    }
    else
    {
        Hanoi(n - 1, src, dst, temp);
        cout <<"move "<<n<<" to " << dst << endl;
        Hanoi(n - 1, temp, src, dst);
        return;
    }
}

int main()
{
    cout << Factorial(5) << endl;
    Hanoi(3, 'S', 'T', 'D');
    return 0;
}
