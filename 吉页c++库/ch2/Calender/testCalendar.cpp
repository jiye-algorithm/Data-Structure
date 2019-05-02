/*
	2014年4月7日 10:51:00
	吉页
	功能：　程序提示输入年份和月份并显示日历，
	程序将setYear和setMonth　的调用放入　ｔｒｙ　程序块中，因为月份和年份可能会有错
*/

#include <iostream>
#include <cstdlib>

#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_cal.h"

using namespace std;

int main()
{
	// 用户输入的月份和年份
	int month, year;

	// 默认是1900.1.1
	calendar cal;

	cout << "Enter the month ande year: ";
	cin >> month >> year;
	cout << endl;

	 //setYear和setMonth会抛出异常
	try
	{
		cal.setMonth(month);
		cal.setYear(year);
	}
	catch (const dateError& de)
	{
		cerr << de.what() << endl;
		system("pause");
		exit(1);
	}

	// 显示日历
	cal.displayCalendar();

	cout << setprecision(3) << 222223.1234567 << endl;

	system("pause");

	return 0;
}