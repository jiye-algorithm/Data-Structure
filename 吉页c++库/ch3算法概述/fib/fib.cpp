/*
	2014年4月13日 09:52:02
	吉页
	功能： 评估斐波那契算法的迭代和递归的效率
*/

#include <iostream>

#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_timer.h"

using namespace std;

// 斐波那契的递归版本
int fab(int n);

//斐波那契的迭代版本
int fabIter(int n);

int main()
{
	timer t;	// 比较两个版本的效率
	int fab_45;

	cout << "递归版本的演示：" << endl;
	t.start();
	cout << "fab(45) = " << fab(45);
	t.stop();
	cout << "  \t所用时间为： " << t.time() << endl << endl;


	cout << "迭代版本的演示：" << endl;
	t.start();
	cout << "fabIter(45) = " << fabIter(45);
	t.stop();
	cout << "  \t所用时间为： " << t.time() << endl << endl;

	system("pause");

	return 0;
}

int fab(int n)
{
	if (0 == n || 1 == n)
		return n;
	else
		return fab(n - 2) + fab(n - 1);
}

int fabIter(int n)
{
	// 存储当前遍历到的值
	int oneBack = 1,
		twoBack = 0,
		current = 0;

	if (0 == n || 1 == n)
		return n;
	else
	for (int i = 2; i <= n; i++)
	{
		// 计算完成后均向后移动一项
		current = oneBack + twoBack;
		twoBack = oneBack;
		oneBack = current;
	}

	return current;
}