#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;
/* Enumerative Algorithm.
课程题目（熄灯问题）：
– 有一个由按钮组成的矩阵 , 其中每行有 6 个按钮 , 共 5 行
– 每个按钮的位置上有一盏灯
– 当按下一个按钮后 , 该按钮以及周围位置 上边 , 下边 , 左边 , 右边 的灯都会改变状态
– 如果灯原来是点亮的 , 就会被熄灭
– 如果灯原来是熄灭的 , 则会被点亮
	•在矩阵 角上 的按钮改变 3 盏灯 的状态
	•在矩阵 边上 的按钮改变 4 盏灯 的状态
	•其他的按钮 改变 5 盏灯
	•与一盏灯毗邻的多个按钮被按下时 一个操作会抵消另一次操作的结果
	•给定矩阵中每盏灯的初始状态，求一种按按钮方案，使得所有的灯都熄灭

输入
– 第一行是一个正整数 N, 表示需要解决的案例数
– 每个案例由 5 行组成 , 每一行包括 6 个数字
– 这些数字以空格隔开 , 可以是 0 或 1
– 0 表示灯的初始状态是 熄灭 的
– 1 表示灯的初始状态是 点亮 的

输出
– 对每个案例 , 首先输出一行 ,输出字符串“PUZZLE #m”, 其中 m 是该案例的序号
– 接着按照该案例的输入格式输出 5 行
	•1 表示需要把对应的按钮 按下
	•0 表示 不需要按 对应的按钮
	•每个数字以一个空格隔开

样例输入
1
0 1 1 0 1 0
1 0 0 1 1 1
0 0 1 0 0 1
1 0 0 1 0 1
0 1 1 1 0 0

样例输出
PUZZLE #1
1 0 1 0 0 1
1 1 0 1 0 1
0 0 1 0 1 1
1 0 0 1 0 0
0 1 0 0 0 0
解题思路：在第一行的开关全部按过一遍之后，需要通过第二行的开关熄灭第一行还亮着的灯。
而且，第一行第i个位置亮着的灯只能通过第二行第i个位置的灯去熄灭，因此，第二列的开关只有一种按法。
同理，要使用第二行的开关状态确定完毕后，需要使用第三行的开关，去熄灭第二行还亮着的灯，因此，第三列的开关也只有一种按法。
所以，只需要枚举第一列开关的所有情况（2^6, 最多64四种情况），
如果存在一种情况，使得所有的灯都熄灭，那么，该解决方案就是问题的一个解。
*/
//
char oriLights[7];
char lights[7];
char result[7];

int GetBit(char c, int i)
{
	return (c >> i) & 1;
}
void SetBit(char &c, int i, int v)
{
	if (v)
		c |= (1 << i); //将c的第i位变成1
	else
		c &= ~(1 << i); //将c的第i位变成0
}
void FlipBit(char &c, int i)
{
	c ^= i << 1;
}
void OutputResults(int t, char results[], string name)
{
	cout << name << " #" << t << endl;
	for (int i = 1; i < 6; ++i)
	{
		for (int j = 1; j < 7; ++j)
			cout << GetBit(results[i], j) << " ";
		cout << endl;
	}
}
void Ouput8BitChar(const char &c)
{        
    for(int i=0; i<8; ++i)
    {
        cout<<GetBit(c, i);
    }
    cout<<endl;
}


/*

*/
int main()
{
	int T, t = 1;
	cin >> T;
	while (t <= T)
	{
		memset(oriLights,0,sizeof(oriLights));
		for (int i = 1; i < 6; ++i)
		{
			for (int j = 1; j < 7; ++j)
			{
				int s;
				cin >> s;
				SetBit(oriLights[i], j, s);
			}
		}
		OutputResults(t, oriLights, "originalLights");

      

		for (int n = 0; n < 64; ++n)//第一行开关的64中情况。
		{
			int switches = (n << 1);//将n左移一位，第1行开关状态。1-6为每个开关的下标。
            //Ouput8BitChar(switches);
			memcpy(lights, oriLights, sizeof(oriLights));//灯的初始状态。
			for (int i = 1; i < 6; ++i)
			{
				result[i] = switches;//第i行开关的状态；
                cout<<i<<endl;
				for (int j = 1; j < 7; ++j)//遍历第i行开关状态。
				{//i=1时 switches[1:6] = 000001,
					if (GetBit(switches, j))//如果第i行的的第j个按下，反转周围灯的效果。
					{
						FlipBit(lights[i], j);
						FlipBit(lights[i], j - 1);
						FlipBit(lights[i], j + 1);
						FlipBit(lights[i - 1], j);
						FlipBit(lights[i + 1], j);
					}
                    //cout<<j<<" : ";
                    //Ouput8BitChar(lights[5]);
				}

             
				switches = lights[i];// 本行的亮灯状态，应该位下一行开关需要按下的结果。	
			}
			if(lights[5]&126==0) //与01111110进行位运算，如果结果位0，说明第5列灯都是灭掉的。
			    OutputResults(n, lights, "Result");
		}


		t++;
	}
	return 0;
}
