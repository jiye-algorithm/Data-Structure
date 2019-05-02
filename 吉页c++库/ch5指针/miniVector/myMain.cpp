/*
	2014年4月19日 09:03:14
	吉页
	功能： 测试向量类
*/

#include <iostream>

#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_vector.h"

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

	//cout << "v的大小为：" << v.size() << endl;

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