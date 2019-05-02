/*
	2014年4月27日 11:30:31
	吉页
	功能： 测试基数排序算法,
				基数排序算法对5位整数组成的向量进行排序，首先，通过一个循环产生50个  0 ~ 99999之间
				的随机数，并把它们赋给向量，程序利用displayVector（）显示向量
*/

#include <iostream>
#include <iomanip>

#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_sort.h"
#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_random.h"


using namespace std;

template <typename T>
void displayVector(const vector<T>& v)
{
		// 循环打印向量
	for (int i = 0; i < v.size(); i++)
	{
		cout << setw(10) << v[i];

		// 每行打印6列
		if ((i + 1) % 6 == 0)
			cout << endl;
	}
	cout << endl;
}

int main()
{
		// 打印的向量
	vector<int> testVec;

		// 产生随机数
	randomNumber rnd;

	for (int i = 0; i < 50; ++i)
		testVec.push_back(rnd.random(100000));

	radixSort<int>(testVec, 5);
	displayVector(testVec);

	system("pause");
	return 0;
}


