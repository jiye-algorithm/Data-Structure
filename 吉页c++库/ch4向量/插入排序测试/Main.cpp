/*
	2014年4月13日 18:50:09
	吉页
	功能： 程序产生12个随机整数，范围【100，999】， 设定三个向量存储一定范围的值
	vSmall [100, 400)
	vMedium [400, 700)
	vLarge  [700, 1000)
	利用插入排序每个向量， 然后利用join()将 vSmall + vMedium + vLarge组合起来， 
	利用writeVector（）输出每个向量
*/

#include <iostream>
#include <vector>

#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_util.h"
#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_random.h"
#include "E:\学习\数据结构\数据结构STL\DataStruct_CppSTL\include/d_sort.h"

using namespace std;

// 将向量 cSrc 加入到vDest的尾部
template <typename T>
void join(vector<T>& vDest, const vector<T>& vSrc);

int main()
{
	// 产生随机数
	randomNumber rnd;
	vector<int> vSmall, vMedium, vLarge;

	int value;

	for (size_t i = 0; i < 12; i++)
	{
		value = rnd.random(900) + 100;
		
		if (value < 400)
			vSmall.push_back(value);
		else if (value < 700)
			vMedium.push_back(value);
		else
			vLarge.push_back(value);

	}

	// 利用插入排序法，对三个向量进行排序
	insertionSort(vSmall);
	insertionSort(vMedium);
	insertionSort(vLarge);


	// 输出没有合并时的向量
	cout << endl <<  "合并前 vSmall: ";
	writeVector(vSmall);
	cout << endl <<  "合并前 vMedium: ";
	writeVector(vMedium);
	cout << endl << "合并前 vLarge: ";
	writeVector(vLarge);

	// 合并向量到 vSmall
	join(vSmall, vMedium);
	join(vSmall, vLarge);

	// 输出合并后的最终向量
	cout << endl << "合并前 vSmall: ";
	writeVector(vSmall);

	system("pause");

	return 0;

}

// 将向量 cSrc 加入到vDest的尾部
template <typename T>
void join(vector<T>& vDest, const vector<T>& vSrc)
{
	vector<T>::size_t size = vSrc.size();

	for (size_t i = 0; i < size; i++)
	{
		vDest.push_back(vSrc[i]);
	}
}