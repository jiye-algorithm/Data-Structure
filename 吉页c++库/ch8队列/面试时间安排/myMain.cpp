/*
	2014��4��27�� 10:03:50
	��ҳ
	���ܣ� ������������ʱ�䣬 �ö��в�����õ�ÿ��������������Ե�ʱ�䣬
	ֱ���ﵽ���һλ�����Ż�������17��00 �°�ʱ��Ϊֹ
*/

#include <iostream>
#include <queue>

#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_time24.h"

using namespace std;

int main()
{
		// ����ʱ��
	time24 interviewTime;

		// ���Խ���ʱ��
	time24 STOP_INTERVIEW = time24(17, 0);

		// ����ÿλ�����ŵ�����ʱ�����
	queue<time24> time24Queue;

	cout << "����������ʱ�䣺";
	cin >> interviewTime;
	cout << endl;

		// �õ�ÿλ�����ߵ�����ʱ��
	while (interviewTime < STOP_INTERVIEW)
	{
		time24Queue.push(interviewTime);

		cout << "��������һ������ʱ�䣺";
		cin >> interviewTime;
		cout << endl;
	}
		
	cout << "���Կ�ʼʱ��\t	���õ�����ʱ��" << endl;
		// ������ʾÿλ�����߿����õ����ʱ��
	while (!time24Queue.empty())
	{
		interviewTime = time24Queue.front();
		time24Queue.pop();

		if (time24Queue.empty())
			cout << interviewTime << setw(20) << " "<< STOP_INTERVIEW - interviewTime << endl;
		else
			cout << interviewTime << setw(20) << " " << time24Queue.front() - interviewTime << endl;
	}

	system("pause");
	return 0;
}