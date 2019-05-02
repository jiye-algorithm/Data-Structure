/*
	2014年4月9日 18:35:26
	吉页
	功能： 程序说明 time24 对象的 I/O 以及运算符+和+=。
	在循环中，用户输入3个约会起始时间和分钟表示的每个约会的长度，输出显示每个约会的起始和结束时间
	在循环中，程序使用+= 运算符累计约会需要的总时间
*/

#include <iostream>

#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_time24.h"

using namespace std;

int main()
{
	time24 apptTime, totalApptTime;
	int apptLength; 

	for (size_t i = 0; i < 3; i++)
	{
		cout << "请输入约会的时间和持续的时间: ";
		cin >> apptTime >> apptLength;

		cout << "Appointment " << i << ": start: " << apptTime
			<< "Stop: " << (apptTime + apptLength) << endl;

		totalApptTime += apptLength;
	}

	// output the total time spent with appointments
	cout << "Total appointment time: " << totalApptTime << endl;

	system("pause");

	return 0;

}