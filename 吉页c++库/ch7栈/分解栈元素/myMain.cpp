/*
	2014年4月23日 18:23:21
	吉页
	功能： 程序说明函数 uncouple（） ，开始时有个intStack， 程序使用数组
	初始化栈， 使用writeArray 输出栈的内容， 两次调用uncouple 从栈中删除14和11，
	之后用循环使每项出栈，并输出。
*/

#include <stack>
#include <iostream>

//#include "E:\学习\数据结构\数据结构STL\吉页c++库\include\y_util.h";

using namespace std;

template <typename T>
bool uncouple(stack<T>& tStack, const T& target);

int main()
{
	int intArr[] = { 19, 14, 37, 43, 11, 12 };
	int arrSize = sizeof(intArr) / sizeof(int);

	stack<int> intStack;

	for (int i = arrSize - 1; i > -1; --i)
	{
		intStack.push(intArr[i]);
	}
	cout << endl;

	if (uncouple(intStack, 11))
		cout << "成功移除11" << endl;
	else
		cout << "移除11失败" << endl;

	if (uncouple(intStack, 14))
		cout << "成功移除14" << endl;
	else
		cout << "移除14失败" << endl;

	while (!intStack.empty())
	{
		cout << intStack.top() << " ";
		intStack.pop();
	}
	cout << endl;

	system("pause");
	return 0;
}

template <typename T>
bool uncouple(stack<T>& tStack, const T& target)
{
	stack<T> tmpStack;
	bool foundTarget = true;

	while (!tStack.empty() && tStack.top() != target)
	{
		tmpStack.push(tStack.top());
		tStack.pop();
	}

	if (!tStack.empty())
		tStack.pop();
	else
		foundTarget = false;

	while (!tmpStack.empty())
	{
		tStack.push(tmpStack.top());
		tmpStack.pop();
	}

	return foundTarget;
}