/*
	2014年4月6日 08:39:19
	吉页
	功能：程序利用随机数对象die进行掷骰子游戏的模拟，这个随机数使用自动种子，
	（ 1 + die。random(6)） + (1 + die.random(6))
	的值在 2-12 之间的随机整数，因为表达式中的每项都使 1-6 之间的随机整数，
	主程序的算法生成初始投掷，并决定可能的赢家，否则，循环执行反复投注，知道匹配目标或
	出现7
*/
#include <iostream>
#include "E:\学习\数据结构\数据结构STL\吉页c++库/include/y_random.h"
//#include "E:\学习\数据结构\数据结构STL\DataStruct_CppSTL/include/d_random.h"

using namespace std;

int main()
{
	randomNumber die;
	int initToss, nextToss;

	initToss = (1 + die.random(6)) + (1 + die.random(6));

	// 检查谁赢，2.3.12则庄家赢
	//7或11则玩家赢
	if (initToss == 2 || initToss == 3 || initToss == 12)
	{
		cout << "Initial toss is " << initToss << " House wins " << endl;
	}
	else if (initToss == 7 || initToss == 11)
	{
		cout << "Initial toss is " << initToss << " player wins " << endl;
	}
	else
		// 初始化投掷目标。继续投掷
		// 知道出现目标（玩家赢）或出现 craps = 7（庄家赢）
	{
		cout << "Target is " << initToss << "play on" << endl;

		do
		{
			nextToss = (1 + die.random(6)) + (1 + die.random(6));
			cout << "Next toss " << nextToss << endl;
		} while (nextToss != 7 && nextToss != initToss);
		if (nextToss == 7)
		{
			cout << " Craps - house wins" << endl;
		}
		else
			cout << " Match -player wins" << endl;
	}

	system("pause");
	return 0;
}