/*
	2014��4��5�� 16:44:03
	��ҳ
	���ܣ� �ĳ���ʹ��time24��������ڹ�������ͣ���ķ��ã�
	�ٶ�������ÿСʱ6��Ԫ��������ʾ�û���������ʱ�䣬�ֱ���Ϊ
	��Ӧ�Ľ�����뿪�����ʱ�䣬�����һ���վ�
	���а�������ʱ�䡣�뿪ʱ�䡢����ͣ��ʱ���Լ��ܷ���
*/

#include <iostream>
#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_time24.h"

int main()
{
	// ÿСʱ��ͣ������
	const double PERHOUR_PARKING = 6.00;

	// ����ָ��������ʱ���복�⣬��ʱ�뿪���⣬�Լ�ͣ������ʱ��
	time24 enterGarage, exitGarage, parkingTime;

	cout << "��������ͣ������ʱ�� ";
	cin >> enterGarage;
	cout << endl << "�����뿪ͣ������ʱ�� ";
	cin >> exitGarage;
	cout << endl;

	// ͣ����ʱ��
	parkingTime = exitGarage - enterGarage;

	// �ܵķ���
	double billingHours = parkingTime.getHour() + parkingTime.getMinute() * 60;

	// ���ͣ�����վݣ���������ʱ�䣬�뿪ʱ�䣬��ͣ��ʱ�䣬�ܵķ���
	cout << "�������� " << enterGarage << endl
		<< "�����뿪 " << exitGarage << endl
		<< "��ͣ�� " << parkingTime << endl
		<< "�ܷ��� " << billingHours * PERHOUR_PARKING << endl;

	system("pause");

	return 0;
}