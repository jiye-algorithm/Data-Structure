/*
	2014��4��12�� 13:46:20
	��ҳ
	���ܣ� ������ʾ������һ��������һ�������� ���õݹ麯������Ҫ��Ľ����������
*/

#include <iostream>
#include <string>

using namespace std;

void displayInBase(int number, int base);

int main()
{
	// ʮ����������Ҫ��ת���Ļ���
	int number, base;
	cout << "������һ��ʮ����������һ������ range 2 <= base <= 10 ��";
	cin >> number >> base;
	cout << endl;

	if (base < 2 || base > 10)
	{
		cout << "The base should at the range [2,10]" << endl;
	}
	else 
	{
		cout << "\t" << number << "(10) = ";
		displayInBase(number, base);
		cout << "(" << base << ")" << endl;
	}

	system("pause");

	return 0;
}

void displayInBase(int number, int base)
{

	if (number > 0)	
	{
		displayInBase(number / base, base);
		cout << number % base;
	}

	return ;
}