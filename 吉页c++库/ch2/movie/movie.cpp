/*
	2014年4月9日 17:43:08
	吉页
	功能： 程序提示用户电影开始时间以及电影的长度， 使用time24 + 运算符确定电影的结束时间，
	公共汽车总是在22：45到达电影院，使用time24 运算符计算在公共汽车站等待的时间
	输出电影结束的时间以及等待时间
*/

#include <iostream>

#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_time24.h"

using namespace std;

int main()
{
	// 电影的开始时间，电影的长度，到达公共汽车站的时间
	time24 filmStart, movieLength, filmEnd;

	// 用户到达汽车站的时间(hour : minute)
	 const time24 busArrive(22, 45);

	cout << "电影开始的时间（hour：minute）： ";
	cin >> filmStart;
	cout << endl;

	cout << "电影的长度： ";
	cin >> movieLength;
	cout << endl;

	// 电影结束的时间
	filmEnd = filmStart + movieLength;

	cout << "电影结束的时间： " << filmEnd << endl;
	cout << "用户在汽车站等待时间： " << busArrive - filmEnd << endl;

	system("pause");

	return 0;
}

/*--------------------------------------------------------------------------
	运算符的重载使得类的使用跟自然， 能提高编程的效率， 简化代码， 
	使得再次阅读代码时，更高效符号毕竟比文字更具有象征意义

--------------------------------------------------------------------------
*/