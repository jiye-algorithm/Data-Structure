/*
	2014年4月23日 17:35:37
	吉页
	功能： 程序的每次迭代都会提示用户输入一个非负的十进制数和一个相应的基数，
	程序使用 mulibaseOutput（） ，程序以相应的基数表示数字，
	当用户输入数字 0 和 基数 0 时，循环结束
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string multibaseOutput(int number, int base);

int main()
{
		// 保存用户输入
	int number, base;

		// 提示用户输入一个数字和一个基数
	do
	{
		cout << "请输入一个数字和对应的基数";
		cin >> number >> base;

		if (number < 0 || base < 0)
		{
			cout << "输入值应均为大于0的整数： " << endl;
			continue;
		}

		cout << "用户输入数字为： " << number << "（" << 10 << "）= " << multibaseOutput(number, base) 
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