/*
	2014��4��20�� 10:23:01
	��ҳ
	���ܣ� ����ʹ�ú��� isPalindrome() ���ж��ַ����Ƿ�Ϊ���ģ�
	������ʾ�û�����һ���ַ��������԰����ո����ɨ���ַ����е�ÿ���ַ��������зǿ���ĸ���Ƶ�charList���У�ʹ��copyList��Ϊ��������
	���� isPalindrome() ȷ���Ƿ�Ϊ����
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
		//�û�������Ҫ�����ַ���
	string astring;
	list<char> charList;

		// ��ʾ�û�����һ���ַ���
	cout << "������һ���ַ����� ";
	getline(cin, astring, '\n');

		// ���û�������ַ������д��� ȡ�����еĿո񣬷��ţ�
	for (size_t i = 0; i < astring.size(); i++)
	{
		char ch;
		ch = astring[i];
			// ���ַ�, ��������Сд����ʽ����������ַ�����
		if (isalnum(tolower(ch)))
			charList.push_back(ch);
	}

		// �Դ������ַ���Ϊ���������ú���isPalindrom�����ж��û������ַ��Ƿ�Ϊ����
		// ���ؽ��Ϊtrue��ʾ�ַ����ǻ��ģ�false��ʾ���ǻ���
	if (true == isPalindrome(charList))
		cout << "�û������ַ� " << astring << " ������ �ǻ��ġ�";
	else
		cout << "�û������ַ� " << astring << " ������ ���ǻ��ġ�";

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
		// �õ�Դ���һ���������������ɾ������
	list<T> copyList = alist;

		// �������Ƚ�����ͷ��β��Ԫ�أ���������� < 1�� ����ͷ��βԪ�ض���ȣ���Ϊ������
	while (copyList.size() > 1)
	{		
			// �Ƚϱ����βԪ��
		if (copyList.front() != copyList.back())
			break;

			// ɾ����βԪ�أ������´αȽ�
		copyList.pop_back();
		copyList.pop_front();
	}

	return (copyList.size() < 2) ? true
								 : false;
}