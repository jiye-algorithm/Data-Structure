/*
	2014年4月27日 10:03:50
	吉页
	功能： 秘书输入面试时间， 用对列操作后得到每个面试这可以面试的时间，
	直到达到最后一位面试着或者下午17：00 下班时间为止
*/

#include <iostream>
#include <queue>

#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_time24.h"

using namespace std;

int main()
{
		// 面试时间
	time24 interviewTime;

		// 面试截至时间
	time24 STOP_INTERVIEW = time24(17, 0);

		// 今天每位面试着的面试时间队列
	queue<time24> time24Queue;

	cout << "请输入面试时间：";
	cin >> interviewTime;
	cout << endl;

		// 得到每位面试者的面试时间
	while (interviewTime < STOP_INTERVIEW)
	{
		time24Queue.push(interviewTime);

		cout << "请输入下一个面试时间：";
		cin >> interviewTime;
		cout << endl;
	}
		
	cout << "面试开始时间\t	可用的面试时间" << endl;
		// 计算显示每位面试者可以用的最多时间
	while (!time24Queue.empty())
	{
		interviewTime = time24Queue.front();
		time24Queue.pop();

		if (time24Queue.empty())
			cout << interviewTime << setw(20) << " "<< STOP_INTERVIEW - interviewTime << endl;
		else
			cout << interviewTime << setw(20) << " " << time24Queue.front() - interviewTime << endl;
	}

	system("pause");
	return 0;
}