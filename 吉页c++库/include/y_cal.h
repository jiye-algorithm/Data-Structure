#ifndef CALENDAR_CLASS
#define CALENDAR_CLASS

#include <iostream>
#include "y_date.h"
#include "y_except.h"

using namespace std;

class calendar
{
public:
	// 初始化日历的年月，默认为1900年1月
	//前置条件：    0 < mm < 13 ,  yyyy > 1900
	calendar(int mm=1, int yyyy = 1900);

	// 显示当前年月的日历, 格式： 表单的形式
	void displayCalendar();

	/////////////////// get and set
	int getMonth() const;

	//   0 < mm < 13
	void setMonth(int mm);

	int getYear() const;

	//   yyyy > 1900
	void setYear(int yyyy);



private:
	date d;

	// 当月的第一天
	int firstDay() const;

	// 打印当前月份和年份
	void displayTitle() const;

	 // 打印当前日历月份的具体天数信息， 
	void displayDates() const;

};

// 初始化日历的年月，默认为1900年1月
//前置条件：    0 < mm < 13 ,  yyyy > 1900
calendar::calendar(int mm, int yyyy) 
{
	if (mm < 1 || mm > 12)
		throw dateError("constructor 参数", mm, "不是有效的");

	if (yyyy < 1900)
		throw dateError("constructor 参数", yyyy, "不是有效的");

	d = date(mm, 1, yyyy);
}

// 显示当前年月的日历, 格式： 表单的形式
void calendar::displayCalendar()
{
	displayTitle();
	displayDates();
}

/////////////////// get and set
int calendar::getMonth() const
{
	return d.getMonth();
}

//   0 < mm < 13
void calendar::setMonth(int mm)
{
	if (mm < 1 || mm > 12)
		throw dateError("setMonth 参数", mm, "invalid");

	d.setMonth(mm);
}

int calendar::getYear() const
{
	return d.getYear();
}

//   yyyy > 1900
void calendar::setYear(int yyyy)
{
	if (yyyy < 1900)
		throw dateError("setYear 参数", yyyy, "invalid");

	d.setYear(yyyy);
}



// 当月的第一天
int calendar::firstDay() const
{
	// 记录当前年份， 和从1900年1月1日到现在的天数
	int year = getYear();
	int day = 1;
	date tmpDate = date();

	for (int i = 1900; i < year; i++)
	{
		tmpDate.setYear(i);
		if (tmpDate.isLeapYear())
			day += 366;
		else
			day += 365;
	}

	day += d.numberOfDays() - 1;

	// 返回第一天的星期
	return day % 7;
}

	// 打印当前月份和年份
void calendar::displayTitle() const
{
	string monthNames[13] = { "", "January", "February", "March", "April", "May",
		"June", "July", "August", "September", "October",
		"November", "December" };

	//输出当前的年和月
	cout << setw(29) << monthNames[d.getMonth()]
		<< setw(5) << getYear() << endl;

	// 星期
	cout << "   Sun    Mon    Tue    Wed    Thu    Fri    Sat"
		<< endl;


}

	// 打印当前日历月份的具体天数信息， 
void calendar::displayDates() const
{
	int monthLength = d.daysInMonth();	// 该月的天数
	int day = 0;	// 作为循环的记录
	int dayValue = 1;	// 当前天的号数
	int firstDay = (*this).firstDay();

	while (day < firstDay)
	{
		cout << setw(7) << " ";
		day++;
	}

	while (dayValue <= monthLength)
	{
		cout << setw(7) << dayValue;

		dayValue++;

		if (day == 6)
			cout << endl;
		day = (day + 1) % 7;
	}

	// 跳过日期末尾没有的数据
	if (day != 0)
		cout << endl;
	
}

#endif // !CALENDAR_CLASS
