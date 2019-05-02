#ifndef DYNAMIC_CLASS
#define DYNAMIC_CLASS

#include <iostream>

using namespace std;

template <typename T>
class dynamicClass
{
public:
		// ���캯��
	dynamicClass(const T& m1, const T&m2);
	dynamicClass(const dynamicClass<T>& obj);

		// ��������
	~dynamicClass();

		// ��ֵ���������
	dynamicClass<T>& operator= (const dynamicClass<T>& rhs);

private:
		// ��Ա����
	T member1;
	T* member2;

	// ���������� ����ʱʹ��
	static int count;
};

template <typename T>
int dynamicClass<T>::count = 0;

	// ���캯��
template <typename T>
dynamicClass<T>::dynamicClass(const T& m1, const T&m2) :
member1(m1)
{
	cout << "���캯��" << count++ << endl;
	member2 = new T(m2);
}

template <typename T>
dynamicClass<T>::dynamicClass(const dynamicClass<T>& obj) :
member1(obj.member1)
{
		// ע�⣬ �˴�֮�����ܷ���rhs��˽�г�Ա����Ϊ��Ƶ���Ҫ�� c++�ĸ�ֵ����������
	cout << "���ƹ��캯��" << count++ << endl << endl;
	member2 = new T(*obj.member2);
}

	// ��������
template <typename T>
dynamicClass<T>::~dynamicClass()
{
	cout << "��������" << --count << endl << endl;
	if (NULL != member2)
		delete member2;
}

	// ��ֵ���������
template <typename T>
dynamicClass<T>& dynamicClass<T>::operator = (const dynamicClass<T>& rhs)
{
	cout << "��ֵ����" << count << endl << endl;
	member1 = rhs.member1;
		// ע�⣬ �˴�֮�����ܷ���rhs��˽�г�Ա����Ϊ��Ƶ���Ҫ�� c++�ĸ�ֵ����������
	*member2 = *rhs.member2;

	return *this;

}

#endif // !DYNAMIC_CLASS
