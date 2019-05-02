/*
	2014��4��12�� 08:42:43
	��ҳ
	���ܣ� �������� ARRAY_SIZE = 100 000 ����������list1�� list2�� �÷�Χ 0~999	999 �ڵ���ͬ�������ʼ����
	���������Χ�ڵ�������и� TARGET_SIZE = 50 000 ������targetList��ֵ�� ��Ϊ���ֲ��ҵ������� ��list2
	Ӧ��ѡ�����򣬲�ʹ�ü�ʱ������t����������Ҫ��ʱ�䣬ͨ����ʾÿ�ֲ��ҵ�ִ��ʱ�䣬˵���㷨�����Ч��
*/
#include <iostream>

#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_search.h"
#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_random.h"
#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_timer.h"

#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\DataStruct_CppSTL\include/d_sort.h"


using namespace std;

int main()
{
	const int ARRAY_SIZE = 100000, TARGET_SIZE = 50000;

	// ��������
	int list1[ARRAY_SIZE], list2[ARRAY_SIZE], targetList[TARGET_SIZE];

	// t ���ڼ�ʱ�����㷨
	timer t;
	// �������
	randomNumber rnd;

	// ������ͬ  0~ 999 999 �����ڵ��������ʼ�� list1 , list2
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		list1[i] = list2[2] = rnd.random(1000000);
	}

	// ������ͬ��Χ���������targetList ��ֵ
	for (int i = 0; i < TARGET_SIZE; i++)
	{
		targetList[i] = rnd.random(1000000);
	}

	// ���ܣ� ���� list1 �� ����ѡ�������ʱ��
	t.start();		// ��������
	selectionSort(list1, ARRAY_SIZE);
	t.stop();	// ֹͣ��ʱ
	cout << "ѡ�������ʱ��Ϊ�� " << t.time() << endl << endl;

	// ���ܣ� ����targetList�� ʹ��˳������� list2�в���targetList��ÿһ��Ԫ��
	t.start();// ������ʱ
	for (int i = 0; i < TARGET_SIZE; i++)
	{
		seqSearch(list2, 0, ARRAY_SIZE, targetList[i]);
	}
	t.stop();	// ֹͣ��ʱ
	cout << "����Ŀ�����飬 ʹ��˳�������list2�в���Ŀ�������ÿ��Ԫ�أ� ����ʱ��Ϊ�� " 
		 << t.time() << endl << endl;

	// ���ܣ� ����targetList�� ʹ�ö��ֲ����� list2�в���targetList��ÿһ��Ԫ��
	t.start();// ������ʱ
	for (int i = 0; i < TARGET_SIZE; i++)
	{
		binSearch(list1, 0, ARRAY_SIZE, targetList[i]);
	}
	t.stop();	// ֹͣ��ʱ
	cout << "����Ŀ�����飬 ʹ�ö��ֲ�����list2�в���Ŀ�������ÿ��Ԫ�أ� ����ʱ��Ϊ�� "
		<< t.time() << endl << endl;

	system("pause");

	return 0;
}