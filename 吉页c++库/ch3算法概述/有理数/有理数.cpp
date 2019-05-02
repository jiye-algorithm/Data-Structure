/*
	2014��4��13�� 09:18:14
	��ҳ
	���ܣ� ���ù�Լ�����㲢��ʾ������
*/

#include <iostream>

using namespace std;

int gcd(int a, int b);

int main()
{
	int numerator, denominator, wholePart, remainder, divisor;
	char slash;

	cout << "Enter a rational number (numerator / denominator): ";
	cin >> numerator >> slash >> denominator;
	cout << endl;

	// �����̺�����
	wholePart = numerator / denominator;
	remainder = numerator % denominator;

	if (0 == remainder)
		cout << wholePart << endl;
	else
	{
		if (0 != wholePart)
			cout << wholePart << " ";

		divisor = gcd(remainder, denominator);

		cout << remainder / divisor << "/" << denominator / divisor << endl;
	}

	system("pause");

	return 0;
}

int gcd(int a, int b)
{
	if (0 == b)
		return a;
	else
	{
		return gcd(b, a % b);
	}
}