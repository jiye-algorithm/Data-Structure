/*
	2014��4��17�� 17:01:42
	��ҳ
	���ܣ� �����������ĳ�����
*/

#include <iostream>

#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_dynam.h"

using namespace std;

//void destroyDemo(int m1, int m2);
//
//int main()
//{
//	// ���ɶ��� obj1 �� member1 = 1, memver2 = 100
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
		 /*	 objA��3��5�����ù��캯����member1= 3, *member2 = 5��
			 objB = objA �Ӷ���objA���ø��ƹ��캯����ʼ������objB��member1 = 3, *member2 = 5��
			 ����objC���ù��캯��(member1 = 0, *member2 = 5)
		*/
	dynamicClass<int> objA(3, 5), objB = objA, objC(0, 0);

		/* ���ú���demo���������ƹ��캯��ͨ�����ƶ���objA
			����ֵ����one��member1 = 3�� *member2 = 5��
			�ڶ�������two�����ô��ݣ����Բ����ø��ƹ��캯��
			�ڷ���ʱ�� �Ծֲ�����obj���ɸ������˸�����ֵ������objC
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