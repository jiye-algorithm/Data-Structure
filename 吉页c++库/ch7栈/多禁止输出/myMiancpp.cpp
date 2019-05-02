/*
	2014��4��23�� 17:35:37
	��ҳ
	���ܣ� �����ÿ�ε���������ʾ�û�����һ���Ǹ���ʮ��������һ����Ӧ�Ļ�����
	����ʹ�� mulibaseOutput���� ����������Ӧ�Ļ�����ʾ���֣�
	���û��������� 0 �� ���� 0 ʱ��ѭ������
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string multibaseOutput(int number, int base);

int main()
{
		// �����û�����
	int number, base;

		// ��ʾ�û�����һ�����ֺ�һ������
	do
	{
		cout << "������һ�����ֺͶ�Ӧ�Ļ���";
		cin >> number >> base;

		if (number < 0 || base < 0)
		{
			cout << "����ֵӦ��Ϊ����0�������� " << endl;
			continue;
		}

		cout << "�û���������Ϊ�� " << number << "��" << 10 << "��= " << multibaseOutput(number, base) 
			 << "( " << base << ")"<< endl;

	} while (number != 0 && base != 0);


	system("pause");
	return 0;
}

string multibaseOutput(int number, int base)
{
	string outString = "";
	stack<char> intStack;
	string digitChat = "0123456789ABCDEF";

	while (number != 0)
	{
		
		intStack.push(digitChat[number % base]);
		number /= base;
	}

	while (!intStack.empty())
	{
		outString += intStack.top();
		intStack.pop();
	}

	return outString;
}