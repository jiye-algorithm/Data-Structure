/*
	2014��4��13�� 09:52:02
	��ҳ
	���ܣ� ����쳲������㷨�ĵ����͵ݹ��Ч��
*/

#include <iostream>

#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_timer.h"

using namespace std;

// 쳲������ĵݹ�汾
int fab(int n);

//쳲������ĵ����汾
int fabIter(int n);

int main()
{
	timer t;	// �Ƚ������汾��Ч��
	int fab_45;

	cout << "�ݹ�汾����ʾ��" << endl;
	t.start();
	cout << "fab(45) = " << fab(45);
	t.stop();
	cout << "  \t����ʱ��Ϊ�� " << t.time() << endl << endl;


	cout << "�����汾����ʾ��" << endl;
	t.start();
	cout << "fabIter(45) = " << fabIter(45);
	t.stop();
	cout << "  \t����ʱ��Ϊ�� " << t.time() << endl << endl;

	system("pause");

	return 0;
}

int fab(int n)
{
	if (0 == n || 1 == n)
		return n;
	else
		return fab(n - 2) + fab(n - 1);
}

int fabIter(int n)
{
	// �洢��ǰ��������ֵ
	int oneBack = 1,
		twoBack = 0,
		current = 0;

	if (0 == n || 1 == n)
		return n;
	else
	for (int i = 2; i <= n; i++)
	{
		// ������ɺ������ƶ�һ��
		current = oneBack + twoBack;
		twoBack = oneBack;
		oneBack = current;
	}

	return current;
}