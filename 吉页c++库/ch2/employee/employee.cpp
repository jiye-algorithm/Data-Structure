/*
	2014��4��9�� 15:04:51
	��ҳ
	���ܣ� �˳���ģ����ʱԱ���ϰ��5��00PM �°����뿪������
	������ʾ�û������ϰ��Сʱ�ͷ��������Լ���ᱣ�Ϻţ�
	��ʹ��timeCard��ȷ��Ա��һ��Ĺ��ʣ�
	����ʹ�������ģ���ķ�֮������Ա�Լ���
	����������£� ������û�д�ʱ timeCard ���׳���rangeError�쳣
	catch ��ģ�������ԱΪԱ����
*/

#include <iostream>

#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_random.h"
#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_tcard.h"

using namespace std;

int main()
{
	// ÿСʱ��нˮ
	const double PAYRATE = 12.5;

	// 5:00PM �°�
	const time24 CHECKOUT(17, 0);

	// ��������ģ��Ա�����°��Ǵ������ ����������� < 0.25 ˵��Ա��û���°��
	// �����ɹ���Ա��Ա����
	randomNumber rnd;

	// Ա����Ա���ź��ϰ�ʱ��
	string id;
	int hour, minute;

	cout << "������Ա���ţ� ";
	cin >> id;
	cout << endl;
	cout << "������Ա���ϰ��Сʱ�ͷ������� ";
	cin >> hour >> minute;
	cout << endl;

	timeCard employee(id, PAYRATE, hour, minute);

	if (rnd.frandom() > 0.25)
		employee.PunchOut(CHECKOUT);

	// ���Ա��û�д򿨣� ������Ա����
	try
	{
		employee.writeSalaryInfo();
	}
	catch (const rangeError& e)
	{
		// ���������Ϣ
		cerr << e.what() << endl;

		employee.PunchOut(CHECKOUT);
		employee.writeSalaryInfo();
	}

	return 0;

}