#ifndef STORE_CLASS
#define STORE_CLASS

#include <iostream>

using namespace std;

template <typename T>
class store
{
public:
	// 构造函数
	store(const T& item = T());

	// get and set 方法， 用于访问类
	void setValue(const T& item);
	 T getValue() const;

	// 输出运算符重载， 用于输出对象数据
	friend ostream& operator<< (ostream& ostr, const store<T>& obj)
	{
		ostr << "Value = " << obj.value;
		
		return ostr;
	}

private:
	T value;
};

// 构造函数
template <typename T>
store<T>::store(const T& item) :
value(item)
{}

// get and set 方法， 用于访问类
template <typename T>
void store<T>::setValue(const T& item)
{
	value = item;
}

template <typename T>
 T store<T>::getValue() const
{
	return value;
}

#endif // !STORE_CLASS
