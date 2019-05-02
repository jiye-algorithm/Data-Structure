/*
	2014年4月12日 13:46:20
	吉页
	功能： 程序提示用输入一个整数和一个基数， 利用递归函数按照要求的进制输出数字
*/

#include <iostream>
#include <string>

using namespace std;

void displayInBase(int number, int base);

int main()
{
	// 十进制整数和要求转换的基数
	int number, base;
	cout << "请输入一个十进制整数和一个基数 range 2 <= base <= 10 ：";
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