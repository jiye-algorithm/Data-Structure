/*
	2014��4��7�� 10:51:00
	��ҳ
	���ܣ���������ʾ������ݺ��·ݲ���ʾ������
	����setYear��setMonth���ĵ��÷��롡�������������У���Ϊ�·ݺ���ݿ��ܻ��д�
*/

#include <iostream>
#include <cstdlib>

#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_cal.h"

using namespace std;

int main()
{
	// �û�������·ݺ����
	int month, year;

	// Ĭ����1900.1.1
	calendar cal;

	cout << "Enter the month ande year: ";
	cin >> month >> year;
	cout << endl;

	 //setYear��setMonth���׳��쳣
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

	// ��ʾ����
	cal.displayCalendar();

	cout << setprecision(3) << 222223.1234567 << endl;

	system("pause");

	return 0;
}