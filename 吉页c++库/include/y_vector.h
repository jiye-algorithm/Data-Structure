#ifndef VECTOR
#define VECTOR

#include <exception>
Vector
using namespace std;

template <typename T>
class Vector
{
public:
		// 构造函数, 如果size > 0， 申请size大小的空间，使用T类型默认构造函数初始化空间
		// 后置条件： 向量的容量和大小都为 size
	Vector(int size = 0);

		// 复制构造函数， 
	Vector(const Vector<T>& obj);

		// 释放动态数组申请的空间
	~Vector();

		// 赋值函数， 将rhs拷贝到当前对象
	Vector<T>& operator= (const Vector<T>& rhs);
	
		// 访问向量末尾元素
		// 前置条件，如果向量为空， throw underflowError
	T& back();
	const T& back() const;

		// 重载下标访问运算符， 
		// 前置条件 ;如果 i<0 或者 i> vSize-1， throw underflowError
		// 后置条件： 返回向量 i 位置上的元素
	T& operator[](int i);
	const T& operator[](int i)const;

		// 前置条件： 如果当前向量已满，且容量不为0， 将向量容量加倍， 如果容量为0， 则置为1
		// 后置条件， 向量的大小增加1， 且末尾元素为item
	void push_back(const T& item);

		// 删除向量末尾元素， 
		// 前置条件： 如果向量为空， throw underflowError
		// 后置条件： 向量的 vSize - 1
	void pop_back();

		// 当前向量的大小
	int size() const;

		//	当前向量的容量
	int capacity() const;

		// 判断向量是否为空
	bool empty() const;

private:
	int vCapacity;	// 向量的容量
	int vSize;		//  向量当前存储的元素数目
	T* vArr;	// 存储向量元素的动态数组

		/* 功能： 改变向量的容量， 为向量重新分派n大小的空间并如果copy = true， 赋值原来向量元素到新的空间
			前置条件： 如果分派新的空间失， throw memoryAllocationError, 原来向量的状态不变
			后置条件： 向量的容量变为 n，
		*/
	void reserve(int n, bool copy);
};

/* 功能： 改变向量的容量， 为向量重新分派n大小的空间并如果copy = true， 赋值原来向量元素到新的空间
前置条件： 如果分派新的空间失， throw memoryAllocationError, 原来向量的状态不变
后置条件： 向量的容量变为 n，
*/
template <typename T>
void Vector<T>::reserve(int n, bool copy)
{
	T* newArr = new T[n];
	if (NULL == newArr)
		throw memoryAllocationError("reserve()申请内存空间失败");

	// 如果 copy == true， 复制当前元素
	if (true == copy)
	{
		for (int i = 0; i < vSize; i++)
		{
			newArr[i] = vArr[i];
		}
	}
		// 释放原来的空间
	if (NULL != vArr)
		delete[] vArr;

	vArr = newArr;
	vCapacity = n;
}

// 构造函数, 如果size > 0， 申请size大小的空间，使用T类型默认构造函数初始化空间
// 后置条件： 向量的容量和大小都为 size
template <typename T>
Vector<T>::Vector(int size) :
vSize(0), vCapacity(0), vArr(NULL)
{
	if (size == 0) return;		

		// 申请空间
	reserve(size, false);

	vSize = size;
		// 初始化空间元素
	for (int i = 0; i < vSize; i++)
		vArr[i] = T();
}

// 复制构造函数，
template <typename T>
Vector<T>::Vector(const Vector<T>& obj) :
vSize(0), vCapacity(0), vArr(NULL)
{
	if (obj.vSize == 0) return;

	// 申请空间
	reserve(obj.vSize, false);

	vSize = obj.vSize;
	// 初始化空间元素
	for (size_t i = 0; i < vsize; i++)
		vArr[i] = obj.vArr[i];
}

// 释放动态数组申请的空间
template <typename T>
Vector<T>::~Vector()
{
	if (NULL != vArr)
		delete vArr;
}

// 赋值函数， 将rhs拷贝到当前对象
template <typename T>
Vector<T>& Vector<T>::operator= (const Vector<T>& rhs)
{
	if (vCapacity < rhs.vSize)
		reserve(rhs.vSize, false);

	vSize = obj.vSize;
	// 初始化空间元素
	for (size_t i = 0; i < vSize; i++)
		vArr[i] = obj.vArr[i];

	return *this;
}

// 访问向量末尾元素
// 前置条件，如果向量为空， throw underflowError
template <typename T>
T& Vector<T>::back()
{
		// 如果向量为空， throw underflowError
	if (0 == vSize)
		throw underflowError("back()访问一个空向量");

	return vArr[vSize - 1];
}

template <typename T>
const T& Vector<T>::back() const
{
	// 如果向量为空， throw underflowError
	if (0 == vSize)
		throw underflowError("back()访问一个空向量");

	return vArr[vSize - 1];
}

// 重载下标访问运算符， 
// 前置条件 ;如果 i<0 或者 i> vSize-1， throw underflowError
// 后置条件： 返回向量 i 位置上的元素
template <typename T>
T& Vector<T>::operator[](int i)
{
		// 如果 i<0 或者 i> vSize-1， throw underflowError
	if (i < 0 || i > vSize - 1)
		throw indexRangeError("operator=（）参数不是有限的范围", i, vSize);

	return vArr[i];
}

template <typename T>
const T& Vector<T>::operator[](int i)const
{
		// 如果 i<0 或者 i> vSize-1， throw underflowError
	if (i < 0 || i > vSize - 1)
		throw indexRangeError("operator=（）参数不是有限的范围", i, vSize);

	return vArr[i];
}

// 前置条件： 如果当前向量已满，且容量不为0， 将向量容量加倍， 如果容量为0， 则置为1
// 后置条件， 向量的大小增加1， 且末尾元素为item
template <typename T>
void Vector<T>::push_back(const T& item)
{	
		// 如果当前向量已满，且容量不为0， 将向量容量加倍， 如果容量为0， 则置为1
	if (vSize == vCapacity)
	{
		if (vCapacity == 0)
			reserve(1, false);
		else
			reserve(2 * vCapacity, true);
	}

	vArr[vSize] = item;
	vSize++;

}

// 删除向量末尾元素， 
// 前置条件： 如果向量为空， throw underflowError
// 后置条件： 向量的 vSize - 1
template <typename T>
void Vector<T>::pop_back()
{
	if (vSize == 0)
		throw underflowError("pop_back()访问空向量");

	vSize--;
}

// 当前向量的大小
template <typename T>
int Vector<T>::size() const
{
	return vSize;
}

//	当前向量的容量
template <typename T>
int Vector<T>::capacity() const
{
	return vCapacity;
}

// 判断向量是否为空
template <typename T>
bool Vector<T>::empty() const
{
	return vSize == 0;
}

#endif // !VECTOR
