/*
	2014��4��6�� 08:39:19
	��ҳ
	���ܣ������������������die������������Ϸ��ģ�⣬��������ʹ���Զ����ӣ�
	�� 1 + die��random(6)�� + (1 + die.random(6))
	��ֵ�� 2-12 ֮��������������Ϊ���ʽ�е�ÿ�ʹ 1-6 ֮������������
	��������㷨���ɳ�ʼͶ�������������ܵ�Ӯ�ң�����ѭ��ִ�з���Ͷע��֪��ƥ��Ŀ���
	����7
*/
#include <iostream>
#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��/include/y_random.h"
//#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\DataStruct_CppSTL/include/d_random.h"

using namespace std;

int main()
{
	randomNumber die;
	int initToss, nextToss;

	initToss = (1 + die.random(6)) + (1 + die.random(6));

	// ���˭Ӯ��2.3.12��ׯ��Ӯ
	//7��11�����Ӯ
	if (initToss == 2 || initToss == 3 || initToss == 12)
	{
		cout << "Initial toss is " << initToss << " House wins " << endl;
	}
	else if (initToss == 7 || initToss == 11)
	{
		cout << "Initial toss is " << initToss << " player wins " << endl;
	}
	else
		// ��ʼ��Ͷ��Ŀ�ꡣ����Ͷ��
		// ֪������Ŀ�꣨���Ӯ������� craps = 7��ׯ��Ӯ��
	{
		cout << "Target is " << initToss << "play on" << endl;

		do
		{
			nextToss = (1 + die.random(6)) + (1 + die.random(6));
			cout << "Next toss " << nextToss << endl;
		} while (nextToss != 7 && nextToss != initToss);
		if (nextToss == 7)
		{
			cout << " Craps - house wins" << endl;
		}
		else
			cout << " Match -player wins" << endl;
	}

	system("pause");
	return 0;
}