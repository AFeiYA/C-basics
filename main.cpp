#include <iostream>
using namespace std;
/*
Algorithm
递归
N皇后问题：
在NxN的棋盘上，
摆放n个皇后，
使得任意两个皇后
    不在同一行，
    不在同一列，
    不在正方形的对角线上。
 */
//

int N=10 ;//棋盘矩阵。

int queenPos[100];

void NQueen(int k)//假设k-1个皇后已经摆放完毕。继续摆放第k个皇后。
{
    int i;
    if(k==N)//如果k=n,那么N个皇后已经摆放完毕，输出结果。
    {
        for(i=0; i<N; i++)
            cout<<queenPos[i]+1<<" ";
        cout<<endl;
        return;
    }
    for(i=0; i<N; ++i)
    {//遍历第k个皇后所有可能的位置。
        int j;
        for(j=0; j<k;++j)
        {//和已经摆好的k个皇后的位置进行比较。
            if(queenPos[j]==i||abs(queenPos[j]-i)==abs(k-j))
            {
                break;//冲突， 测试下一个位置。
            }
        }
        if(j==k)
        {
            queenPos[k]=i;
            NQueen(k+1);
        }
    }

}

int main()
{
    cin>>N;
    NQueen(0);
    return 0;
}
