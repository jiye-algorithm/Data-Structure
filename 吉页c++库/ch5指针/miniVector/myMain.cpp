/*
	2014��4��19�� 09:03:14
	��ҳ
	���ܣ� ����������
*/

#include <iostream>

#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_vector.h"

using namespace std;

int main()
{
	//miniVector<int> v;

	//try
	//{
	//	v.pop_back();
	//}
	//catch (const underflowError& e)
	//{
	//	cout << e.what() << endl;
	//	v.push_back(99);
	//}

	//cout << "v�Ĵ�СΪ��" << v.size() << endl;

	//try
	//{
	//	cout << "v[0] = " << v[0] << endl;
	//	cout << "v[1] = " << v[1] << endl;
	//}
	//catch (const indexRangeError& e)
	//{
	//	cout << e.what() << endl;
	//}


	miniVector<char *> vstring;
	char buf[100];

	while (true)
	{
		cin >> buf;
		if (strcmp(buf, "end") == 0) break;
		vstring.push_back(buf);
	}

	cout << endl << endl << "-----------------------" << endl;

	while (!vstring.empty())
	{
		cout << vstring.back() << endl;
		vstring.pop_back();
	}


	system("pause");

	return 0;
}