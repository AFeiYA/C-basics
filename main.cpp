#include <iostream>
#include <cstring>
using namespace std;
/* Enumerative Algorithm.
 枚举法：假币问题
 有12 枚硬币。其中有 11 枚真币和 1 枚假币。
 假币和真币重量不同，但不知道假币比真币轻还是重。
 现在，用一架天平称了这些币三次，告诉你称的结果，
 请你找出假币并且确定假币是轻是重（数据保证一定能找出来）。

 输入
 第一行是测试数据组数。
 每组数据有三行，每行表示一次称量的结果。银币标号为
 A-L 。每次称量的结果用三个以空格隔开的字符串表示：
 天平左边放置的硬币 天平右边放置的硬币 平衡状态。其
 中平衡状态用 ``up'', ``down'', 或 `even` 表示 , 分别为右
 端高、右端低和平衡。天平左右的硬币数总是相等的。

 输出
 输出哪一个标号的银币是假币，并说明它比真币轻还是重。

 输入样例
 1
 ABCD EFGH even
 ABCI EFJK up
 ABIJ EFGH even
 输出样例
 K is the counterfeit coin and it is light.
思路：假设x是假币， 如果三次称量结果都成立，那么x就是假币，否则x是真的。
称量最大范围一边六个。： abcdef  ghijkl
*/

char Left[3][7], Right[3][7], Result[3][7];
bool IsFake(char x, bool isLight);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> Left[i] >> Right[i] >> Result[i];
        }
        for (char x = 'A'; x < 'M'; ++x)
        {
            if (IsFake(x, true))
            {
                cout << x << " is the counterfeit coin and it is light." << endl;
                break;
            }
            else if (IsFake(x, false))
            {
                cout << x << " is the counterfeit coin and it is heavy." << endl;
                break;
            }
        }
    }

    return 0;
}

bool IsFake(char x, bool isLight)
{
    for (int i = 0; i < 3; ++i)
    {
        char *pLeftCoins, *pRightCoins; //天平座 左右两边；
        if (isLight)
        { //第一种：假设假币isLight, 那么可以进入switch分情况讨论。
            pLeftCoins = Left[i];
            pRightCoins = Right[i];
        }
        else
        { //第二种:如果假币!isLight，将左右对调，对调完毕后，switch的讨论依然有效。
            pLeftCoins = Right[i];
            pRightCoins = Left[i];
        }
        switch (Result[i][0])
        {
        case 'e':
            //如果天平平衡，那么天平左右两边应该都没有假币，如果假设的x能在左边或者右边找到，那么假设是错误的。
            if (strchr(pLeftCoins, x) || (strchr(pRightCoins, x)))
                return false;
            break;

        case 'u':
            //如果天平右端向上，而假币是light的，那么假币应该在右边，如果右边找不到，那么假设是错误的。
            if (strchr(pRightCoins, x) == NULL)
                return false;
            break;

        case 'd':
            //如果天平有端向下，而假币不是light的，那么假币应该在左边，如果左边找不到，那么假设是错误的。
            if (strchr(pLeftCoins, x) == NULL)
                return false;
            break;
        default:
            break;
        }
    }
    //如果循环结束，说明假设成立。
    return true;
}