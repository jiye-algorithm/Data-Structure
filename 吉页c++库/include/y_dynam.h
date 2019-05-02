#ifndef DYNAMIC_CLASS
#define DYNAMIC_CLASS

#include <iostream>

using namespace std;

template <typename T>
class dynamicClass
{
public:
		// 构造函数
	dynamicClass(const T& m1, const T&m2);
	dynamicClass(const dynamicClass<T>& obj);

		// 析构函数
	~dynamicClass();

		// 赋值运算符重载
	dynamicClass<T>& operator= (const dynamicClass<T>& rhs);

private:
		// 成员属性
	T member1;
	T* member2;

	// 用来计数， 测试时使用
	static int count;
};

template <typename T>
int dynamicClass<T>::count = 0;

	// 构造函数
template <typename T>
dynamicClass<T>::dynamicClass(const T& m1, const T&m2) :
member1(m1)
{
	cout << "构造函数" << count++ << endl;
	member2 = new T(m2);
}

template <typename T>
dynamicClass<T>::dynamicClass(const dynamicClass<T>& obj) :
member1(obj.member1)
{
		// 注解， 此处之所以能访问rhs的私有成员是因为设计的需要， c++的赋值操作能特殊
	cout << "复制构造函数" << count++ << endl << endl;
	member2 = new T(*obj.member2);
}

	// 析构函数
template <typename T>
dynamicClass<T>::~dynamicClass()
{
	cout << "析构函数" << --count << endl << endl;
	if (NULL != member2)
		delete member2;
}

	// 赋值运算符重载
template <typename T>
dynamicClass<T>& dynamicClass<T>::operator = (const dynamicClass<T>& rhs)
{
	cout << "赋值函数" << count << endl << endl;
	member1 = rhs.member1;
		// 注解， 此处之所以能访问rhs的私有成员是因为设计的需要， c++的赋值操作能特殊
	*member2 = *rhs.member2;

	return *this;

}

#endif // !DYNAMIC_CLASS
