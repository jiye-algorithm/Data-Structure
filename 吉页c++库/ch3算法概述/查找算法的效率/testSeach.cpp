/*
	2014年4月12日 08:42:43
	吉页
	功能： 程序声明 ARRAY_SIZE = 100 000 的整数数组list1， list2， 用范围 0~999	999 内的相同随机数初始化，
	还用这个范围内的随机序列该 TARGET_SIZE = 50 000 的数组targetList赋值， 作为二分查找的条件， 对list2
	应用选择排序，并使用计时器对像t来计算所需要的时间，通过显示每种查找的执行时间，说明算法的相对效率
*/
#include <iostream>

#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_search.h"
#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_random.h"
#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_timer.h"

#include "E:\学习\数据结构\数据结构STL\DataStruct_CppSTL\include/d_sort.h"


using namespace std;

int main()
{
	const int ARRAY_SIZE = 100000, TARGET_SIZE = 50000;

	// 查找数组
	int list1[ARRAY_SIZE], list2[ARRAY_SIZE], targetList[TARGET_SIZE];

	// t 用于记时查找算法
	timer t;
	// 随机对象
	randomNumber rnd;

	// 利用相同  0~ 999 999 返回内的随机数初始化 list1 , list2
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		list1[i] = list2[2] = rnd.random(1000000);
	}

	// 利用相同范围的随机数给targetList 赋值
	for (int i = 0; i < TARGET_SIZE; i++)
	{
		targetList[i] = rnd.random(1000000);
	}

	// 功能： 排序 list1 ， 计算选择排序的时间
	t.start();		// 启动计算
	selectionSort(list1, ARRAY_SIZE);
	t.stop();	// 停止计时
	cout << "选择排序的时间为： " << t.time() << endl << endl;

	// 功能： 遍历targetList， 使用顺序查找在 list2中查找targetList的每一个元素
	t.start();// 启动计时
	for (int i = 0; i < TARGET_SIZE; i++)
	{
		seqSearch(list2, 0, ARRAY_SIZE, targetList[i]);
	}
	t.stop();	// 停止计时
	cout << "遍历目标数组， 使用顺序查找在list2中查找目标数组的每个元素， 所用时间为： " 
		 << t.time() << endl << endl;

	// 功能： 遍历targetList， 使用二分查找在 list2中查找targetList的每一个元素
	t.start();// 启动计时
	for (int i = 0; i < TARGET_SIZE; i++)
	{
		binSearch(list1, 0, ARRAY_SIZE, targetList[i]);
	}
	t.stop();	// 停止计时
	cout << "遍历目标数组， 使用二分查找在list2中查找目标数组的每个元素， 所用时间为： "
		<< t.time() << endl << endl;

	system("pause");

	return 0;
}