/*
	2014年4月20日 10:23:01
	吉页
	功能： 程序使用函数 isPalindrome() 来判断字符串是否为回文，
	程序提示用户输入一个字符串，可以包含空格程序扫描字符串中的每个字符，将所有非空字母复制到charList表中，使用copyList作为参数调用
	函数 isPalindrome() 确定是否为回文
*/

#include <iostream>
#include <list>
#include <string>
#include <ctype.h>

using namespace std;

template <typename T>
bool isPalindrome(const list<T>& alist);

int main() 
{
		//用户保存需要处理字符串
	string astring;
	list<char> charList;

		// 提示用户输入一个字符串
	cout << "请输入一个字符串： ";
	getline(cin, astring, '\n');

		// 对用户输入的字符串进行处理， 取出期中的空格，符号，
	for (size_t i = 0; i < astring.size(); i++)
	{
		char ch;
		ch = astring[i];
			// 将字符, 和数字以小写的形式加入待处理字符集中
		if (isalnum(tolower(ch)))
			charList.push_back(ch);
	}

		// 以待处理字符集为参数，调用函数isPalindrom（）判断用户输入字符是否为回文
		// 返回结果为true表示字符串是回文，false表示不是回文
	if (true == isPalindrome(charList))
		cout << "用户输入字符 " << astring << " 经处理， 是回文。";
	else
		cout << "用户输入字符 " << astring << " 经处理， 不是回文。";

	//list<char>::iterator first = charList.begin();
	//list<char>::iterator last = charList.end();
	//first--;
	//last++;
	//if (first == last)
	//	cout << endl << endl << endl << "first == last";
	//else
	//	cout << endl << endl << endl << "first != last";


	system("pause");

	return 0;
}

template <typename T>
bool isPalindrome(const list<T>& alist)
{
		// 得到源表的一个副本，方便进行删除操作
	list<T> copyList = alist;

		// 遍历表，比较链表头和尾部元素，如果链表长度 < 1， 并且头，尾元素都相等，则为回文数
	while (copyList.size() > 1)
	{		
			// 比较表的首尾元素
		if (copyList.front() != copyList.back())
			break;

			// 删除首尾元素，便于下次比较
		copyList.pop_back();
		copyList.pop_front();
	}

	return (copyList.size() < 2) ? true
								 : false;
}