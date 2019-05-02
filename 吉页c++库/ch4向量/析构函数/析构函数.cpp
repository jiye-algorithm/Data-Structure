/*
	2014年4月17日 17:01:42
	吉页
	功能： 对析构函数的初体验
*/

#include <iostream>

#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_dynam.h"

using namespace std;

//void destroyDemo(int m1, int m2);
//
//int main()
//{
//	// 生成对象 obj1 ， member1 = 1, memver2 = 100
//	dynamicClass<int> obj1(1, 100);
//	dynamicClass<int> obj3(obj1);
//
//	dynamicClass<int> *ptrObj2;
//	ptrObj2 = new dynamicClass<int>(2, 200);
//
//	destroyDemo(3, 300);
//
//	delete ptrObj2;
//
//	system("pause");
//
//	return 0;
//}
//
//void destroyDemo(int m1, int m2)
//{
//	dynamicClass<int> obj(m1, m2);
//}

template<typename T> 
dynamicClass<T> demo(dynamicClass<T> one, dynamicClass<T>& two, const T& m);

int main()
{
		 /*	 objA（3，5）调用构造函数（member1= 3, *member2 = 5）
			 objB = objA 从对象objA调用复制构造函数初始化对象objB（member1 = 3, *member2 = 5）
			 对象objC调用构造函数(member1 = 0, *member2 = 5)
		*/
	dynamicClass<int> objA(3, 5), objB = objA, objC(0, 0);

		/* 调用函数demo（），复制构造函数通过复制对象objA
			产生值参数one（member1 = 3， *member2 = 5）
			第二个参数two按引用传递，所以不调用复制构造函数
			在返回时， 对局部对象obj生成副本，此副本赋值给对象objC
		*/
	objC = demo(objA, objB, 5);

	system("pause");

	return 0;
}


template<typename T>
dynamicClass<T> demo(dynamicClass<T> one, dynamicClass<T>& two, const T& m)
{
	dynamicClass<T> obj(m, m);

	return obj;
}