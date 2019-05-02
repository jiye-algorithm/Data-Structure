#ifndef CALENDAR_CLASS
#define CALENDAR_CLASS

#include <iostream>
#include "y_date.h"
#include "y_except.h"

using namespace std;

class calendar
{
public:
	// ��ʼ�����������£�Ĭ��Ϊ1900��1��
	//ǰ��������    0 < mm < 13 ,  yyyy > 1900
	calendar(int mm=1, int yyyy = 1900);

	// ��ʾ��ǰ���µ�����, ��ʽ�� ������ʽ
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

	// ���µĵ�һ��
	int firstDay() const;

	// ��ӡ��ǰ�·ݺ����
	void displayTitle() const;

	 // ��ӡ��ǰ�����·ݵľ���������Ϣ�� 
	void displayDates() const;

};

// ��ʼ�����������£�Ĭ��Ϊ1900��1��
//ǰ��������    0 < mm < 13 ,  yyyy > 1900
calendar::calendar(int mm, int yyyy) 
{
	if (mm < 1 || mm > 12)
		throw dateError("constructor ����", mm, "������Ч��");

	if (yyyy < 1900)
		throw dateError("constructor ����", yyyy, "������Ч��");

	d = date(mm, 1, yyyy);
}

// ��ʾ��ǰ���µ�����, ��ʽ�� ������ʽ
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
		throw dateError("setMonth ����", mm, "invalid");

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
		throw dateError("setYear ����", yyyy, "invalid");

	d.setYear(yyyy);
}



// ���µĵ�һ��
int calendar::firstDay() const
{
	// ��¼��ǰ��ݣ� �ʹ�1900��1��1�յ����ڵ�����
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

	// ���ص�һ�������
	return day % 7;
}

	// ��ӡ��ǰ�·ݺ����
void calendar::displayTitle() const
{
	string monthNames[13] = { "", "January", "February", "March", "April", "May",
		"June", "July", "August", "September", "October",
		"November", "December" };

	//�����ǰ�������
	cout << setw(29) << monthNames[d.getMonth()]
		<< setw(5) << getYear() << endl;

	// ����
	cout << "   Sun    Mon    Tue    Wed    Thu    Fri    Sat"
		<< endl;


}

	// ��ӡ��ǰ�����·ݵľ���������Ϣ�� 
void calendar::displayDates() const
{
	int monthLength = d.daysInMonth();	// ���µ�����
	int day = 0;	// ��Ϊѭ���ļ�¼
	int dayValue = 1;	// ��ǰ��ĺ���
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

	// ��������ĩβû�е�����
	if (day != 0)
		cout << endl;
	
}

#endif // !CALENDAR_CLASS
