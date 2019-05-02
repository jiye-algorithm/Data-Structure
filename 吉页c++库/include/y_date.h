#ifndef DATE_CLASS
#define DATE_CLASS

#include <iostream>
#include <iomanip>
#include <string>

#include "y_except.h"

using namespace std;

class date
{
public:

	/*��ʼ�������գ�Ĭ��Ϊ1900��1��1�գ� 
	ǰ�������� yyyy > 1899    0 < m < 13   0 < dd < 32*/
	date(int mm = 1, int dd = 1, int yyyy = 1900);

	// output : MM/DD/YYYY
	void writeShortDate() const;

	// output the date in the format "month day, year"
	void writeLongDate() const;

	// ���� ndays ��
	//ǰ��������  0 <= ndays <= 365
	void incrementDate(int ndays);

	// return the number of days into the year
	int numberOfDays() const;
	
	// return the month as integer value 1 to 12
	int getMonth() const;

	// return day of the month
	int getDay() const;

	// return the year
	int getYear() const;

	// �����·ݣ� 
	//ǰ�������� 0 < mm < 13
	void setMonth(int mm);

	//������
	//ǰ�������� 0 < dd < 32
	void setDay(int dd);

	// ������
	// ǰ�������� �����2��29�� �����������
	void setYear(int yyyy);

	//���µ�����
	int daysInMonth() const;

	// is the current year a leap year (true/false)
	bool isLeapYear() const;


private:
	// private type used by date
	enum monthName {
		Jan = 1, Feb, Mar, Apr, May, Jun,
		Jul, Aug, Sep, Oct, Nov, Dec
	};

	// private members that specify the date
	int month, day, year;
};



/*��ʼ�������գ�Ĭ��Ϊ1900��1��1�գ�
ǰ�������� yyyy > 1899    0 < m < 13   0 < dd < 32*/
date::date(int mm , int dd , int yyyy ) :
month(mm), day(dd),year(yyyy)
{
	if (month < 1 || month > 12)
		throw dateError(" date constructor ", month, "invalid month");

	if (year < 1900)
		throw dateError("date constructor ", year, "invalid year");

	if (day < 1 || day > daysInMonth())
		throw dateError("date constructor ", day, "invalid day");
}

// output : MM/DD/YYYY
void date::writeShortDate() const
{
	long currentFlags = cout.flags();
	char currentFill = cout.fill();

	cout.setf(ios::right, ios::adjustfield);

	// �Կո����ķ�ʽ����·�
	cout.fill(' ');
	cout << setw(2) << month;

	// ����죬��0���
	cout.fill('0');
	cout << "/" << setw(2) << day << "/" << year;

	// �ָ�����״̬
	cout.fill(currentFill);
	cout.setf(currentFlags);

}

// output the date in the format "month day, year"
void date::writeLongDate() const
{
	static string monthName[] = {
		"", "January", "February", "March", "April",
		"May", "June", "July", "August", "Sepetemeber",
		"October", "November", "December" };

		cout << monthName[month] << "," << day << "," << year;

}

// ���� ndays ��
//ǰ��������  0 <= ndays <= 365
void date::incrementDate(int ndays)
{
	int totalDays = 0,
		daysInYear = 365,
		addDay;

	if (isLeapYear())	
		addDay = 1;	
	else 
		addDay = 0;

	totalDays = numberOfDays() + ndays;
	daysInYear += addDay;
	if (totalDays / daysInYear == 1 && totalDays%daysInYear != 0)
	{
		year++;
		if (isLeapYear())
		{
			addDay = 1;
		}
		else
			addDay = 0;

		totalDays %= daysInYear;
	}

	if (totalDays <= 31)
	{
		month = 1;
		day = totalDays;
	}
	else if (totalDays <= 59 + addDay)
	{
		month = 2;
		day = totalDays - 31;
	}
	else if (totalDays <= 90 + addDay)
	{
		month = 3;
		day = totalDays - 59;
	}
	else if (totalDays <= 120 + addDay)
	{
		month = 4;
		day = totalDays - 90;
	}
	else if (totalDays <= 151 + addDay)
	{
		month = 5;
		day = totalDays - 120;
	}
	else if (totalDays <= 181 + addDay)
	{
		month = 6;
		day = totalDays - 151;
	}
	else if (totalDays <= 212 + addDay)
	{
		month = 7;
		day = totalDays - 181;
	}
	else if (totalDays <= 243 + addDay)
	{
		month = 8;
		day = totalDays - 181;
	}
	else if (totalDays <= 273 + addDay)
	{
		month = 9;
		day = totalDays - 243;
	}
	else if (totalDays <= 304 + addDay)
	{
		month = 10;
		day = totalDays - 273;
	}
	else if (totalDays <=  334 + addDay)
	{
		month =11;
		day = totalDays - 304;
	}
	else if (totalDays <= 365 + addDay)
	{
		month = 12;
		day = totalDays - 334;
	}
}

// return the number of days into the year
int date::numberOfDays() const
{
	// ����һ�����飬ͳһ��������·ݵ�����
	int monthLength[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int dayToDate = 0;

	// ֮ǰ�·ݵ�����
	for (int i = 1; i < month; ++i)
	{
		dayToDate += monthLength[i];
	}

	// �����·ݵĹ�ȥ���������������겢�ҵ�����2��֮�� ���һ��
	if (isLeapYear() && month > 2)
		dayToDate += day + 1;
	else
		dayToDate += day;

	return dayToDate;

}

// return the month as integer value 1 to 12
int date::getMonth() const
{
	return month;
}

// return day of the month
int date::getDay() const
{
	return day;
}

// return the year
int date::getYear() const
{
	return year;
}

// �����·ݣ� 
//ǰ�������� 0 < mm < 13
void date::setMonth(int mm)
{
	if (mm < 1 || mm > 12)
		throw dateError("setmonth ���� ", mm, "������Чֵ");

	month = mm;
}

//������
//ǰ�������� 0 < dd < 32
void date::setDay(int dd)
{
	if (dd < 1 || dd > daysInMonth())
		throw dateError("setDay ���� ", dd, "������Ч�Ĳ���");

	day = dd;
}

// ������
// ǰ�������� �����2��29�� �����������
void date::setYear(int yyyy)
{
	if (yyyy < 1900)
		throw dateError("setYear���� ", yyyy, "������Ч��");

	year = yyyy;
}

//���µ�����
int date::daysInMonth() const
{
	int monthLength;

	switch (monthName(month))
	{
	case Jan:
	case Mar:
	case May:
	case Jul:
	case Aug:
	case Oct:
	case Dec:   monthLength = 31;    // months with 31 days
		break;

	case Apr:
	case Jun:
	case Sep:
	case Nov:   monthLength = 30;    // months with 30 days
		break;

	case Feb:   if (isLeapYear())    // special case of Feb
		monthLength = 29;
				else
					monthLength = 28;
		break;
	}
	return monthLength;
}

// is the current year a leap year (true/false)
bool date::isLeapYear() const
{
	return ((year % 4 == 0) && (year % 100 != 0))
		|| (year % 400 == 0);

}

#endif   // DATE_CLASS