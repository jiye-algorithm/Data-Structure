/*
	2014��4��27�� 11:30:31
	��ҳ
	���ܣ� ���Ի��������㷨,
				���������㷨��5λ������ɵ����������������ȣ�ͨ��һ��ѭ������50��  0 ~ 99999֮��
				����������������Ǹ�����������������displayVector������ʾ����
*/

#include <iostream>
#include <iomanip>

#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_sort.h"
#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_random.h"


using namespace std;

template <typename T>
void displayVector(const vector<T>& v)
{
		// ѭ����ӡ����
	for (int i = 0; i < v.size(); i++)
	{
		cout << setw(10) << v[i];

		// ÿ�д�ӡ6��
		if ((i + 1) % 6 == 0)
			cout << endl;
	}
	cout << endl;
}

int main()
{
		// ��ӡ������
	vector<int> testVec;

		// ���������
	randomNumber rnd;

	for (int i = 0; i < 50; ++i)
		testVec.push_back(rnd.random(100000));

	radixSort<int>(testVec, 5);
	displayVector(testVec);

	system("pause");
	return 0;
}


