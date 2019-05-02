/*
	2014��4��23�� 18:23:21
	��ҳ
	���ܣ� ����˵������ uncouple���� ����ʼʱ�и�intStack�� ����ʹ������
	��ʼ��ջ�� ʹ��writeArray ���ջ�����ݣ� ���ε���uncouple ��ջ��ɾ��14��11��
	֮����ѭ��ʹÿ���ջ���������
*/

#include <stack>
#include <iostream>

//#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include\y_util.h";

using namespace std;

template <typename T>
bool uncouple(stack<T>& tStack, const T& target);

int main()
{
	int intArr[] = { 19, 14, 37, 43, 11, 12 };
	int arrSize = sizeof(intArr) / sizeof(int);

	stack<int> intStack;

	for (int i = arrSize - 1; i > -1; --i)
	{
		intStack.push(intArr[i]);
	}
	cout << endl;

	if (uncouple(intStack, 11))
		cout << "�ɹ��Ƴ�11" << endl;
	else
		cout << "�Ƴ�11ʧ��" << endl;

	if (uncouple(intStack, 14))
		cout << "�ɹ��Ƴ�14" << endl;
	else
		cout << "�Ƴ�14ʧ��" << endl;

	while (!intStack.empty())
	{
		cout << intStack.top() << " ";
		intStack.pop();
	}
	cout << endl;

	system("pause");
	return 0;
}

template <typename T>
bool uncouple(stack<T>& tStack, const T& target)
{
	stack<T> tmpStack;
	bool foundTarget = true;

	while (!tStack.empty() && tStack.top() != target)
	{
		tmpStack.push(tStack.top());
		tStack.pop();
	}

	if (!tStack.empty())
		tStack.pop();
	else
		foundTarget = false;

	while (!tmpStack.empty())
	{
		tStack.push(tmpStack.top());
		tmpStack.pop();
	}

	return foundTarget;
}