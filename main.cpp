#include <iostream>
#include <string>
#include <bitset>

using namespace std;
/*
Algorithm
枚举
001:特殊密码锁

总时间限制: 1000ms 内存限制: 1024kB
描述
有一种特殊的二进制密码锁，由n个相连的按钮组成（n<30），按钮有凹/凸两种状态，用手按按钮会改变其状态。

然而让人头疼的是，当你按一个按钮时，跟它相邻的两个按钮状态也会反转。当然，如果你按的是最左或者最右边的按钮，该按钮只会影响到跟它相邻的一个按钮。

当前密码锁状态已知，需要解决的问题是，你至少需要按多少次按钮，才能将密码锁转变为所期望的目标状态。

输入
两行，给出两个由0、1组成的等长字符串，表示当前/目标密码锁状态，其中0代表凹，1代表凸。
输出
至少需要进行的按按钮操作次数，如果无法实现转变，则输出impossible。
样例输入
00111  a:001000 110000 000000
00000
111  //100 011 101
101
样例输出
3
 */
 //
#define N  30

int main()
{
	string inputString, targetString;


	cin >> inputString;
	cin >> targetString;
	bitset<N> checkResult;
	bitset<N> checkResult2;
	bitset<N> inputState(inputString);
	bitset<N> inputState2(inputString);
	bitset<N> targetState(targetString);
	int inputLength = inputString.size();

	int n = 1;
	//如果按下了第一个开关：
	inputState.flip(0);
	inputState.flip(1);
	for (int i = 0; i < inputLength-1; ++i)
	{
		if (inputState[i] != targetState[i])//如果i不满足，需要按下i后面的按钮i+1。
		{
			n++;
			if (i < inputLength - 2)//按下i+1个开关
			{
				inputState.flip(i);
				inputState.flip(i + 1);
				inputState.flip(i + 2);
			}
			else//按下最后一个开关。
			{
				inputState.flip(i);
				inputState.flip(i + 1);
			}
		}
	}
	checkResult = inputState ^ targetState;


	//如果没有按下第一个开关
	int m = 0;
	for (int i = 0; i < inputLength - 1; ++i)
	{
		if (inputState2[i] != targetState[i])//如果i不满足，需要按下i后面的按钮i+1。
		{
			m++;
			if (i < inputLength - 2)//按下i+1个开关
			{
				inputState2.flip(i);
				inputState2.flip(i + 1);
				inputState2.flip(i + 2);
			}
			else//按下最后一个开关。
			{
				inputState2.flip(i);
				inputState2.flip(i + 1);
			}
		}
	}
	checkResult2 = inputState2 ^ targetState;


	if (checkResult == 0 && checkResult2 != 0)
		cout << n << endl;
	if (checkResult != 0 && checkResult2==0)
		cout << m << endl;
	if (checkResult == 0 && checkResult2 == 0)
	{
		if (n < m)
			cout << n << endl;
		else
			cout<<m<<endl;
	}
	if (checkResult != 0 && checkResult2 != 0)
		cout << "impossible" << endl;
	return 0;
}
