/*
	2014��4��9�� 18:35:26
	��ҳ
	���ܣ� ����˵�� time24 ����� I/O �Լ������+��+=��
	��ѭ���У��û�����3��Լ����ʼʱ��ͷ��ӱ�ʾ��ÿ��Լ��ĳ��ȣ������ʾÿ��Լ�����ʼ�ͽ���ʱ��
	��ѭ���У�����ʹ��+= ������ۼ�Լ����Ҫ����ʱ��
*/

#include <iostream>

#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_time24.h"

using namespace std;

int main()
{
	time24 apptTime, totalApptTime;
	int apptLength; 

	for (size_t i = 0; i < 3; i++)
	{
		cout << "������Լ���ʱ��ͳ�����ʱ��: ";
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