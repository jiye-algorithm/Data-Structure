#ifndef STORE_CLASS
#define STORE_CLASS

#include <iostream>

using namespace std;

template <typename T>
class store
{
public:
	// ���캯��
	store(const T& item = T());

	// get and set ������ ���ڷ�����
	void setValue(const T& item);
	 T getValue() const;

	// �����������أ� ���������������
	friend ostream& operator<< (ostream& ostr, const store<T>& obj)
	{
		ostr << "Value = " << obj.value;
		
		return ostr;
	}

private:
	T value;
};

// ���캯��
template <typename T>
store<T>::store(const T& item) :
value(item)
{}

// get and set ������ ���ڷ�����
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
