/*
	2014年4月13日 09:18:14
	吉页
	功能： 利用公约数计算并表示有理数
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

	// 计算商和余数
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