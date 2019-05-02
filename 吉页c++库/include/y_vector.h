#ifndef VECTOR
#define VECTOR

#include <exception>
Vector
using namespace std;

template <typename T>
class Vector
{
public:
		// ���캯��, ���size > 0�� ����size��С�Ŀռ䣬ʹ��T����Ĭ�Ϲ��캯����ʼ���ռ�
		// ���������� �����������ʹ�С��Ϊ size
	Vector(int size = 0);

		// ���ƹ��캯���� 
	Vector(const Vector<T>& obj);

		// �ͷŶ�̬��������Ŀռ�
	~Vector();

		// ��ֵ������ ��rhs��������ǰ����
	Vector<T>& operator= (const Vector<T>& rhs);
	
		// ��������ĩβԪ��
		// ǰ���������������Ϊ�գ� throw underflowError
	T& back();
	const T& back() const;

		// �����±����������� 
		// ǰ������ ;��� i<0 ���� i> vSize-1�� throw underflowError
		// ���������� �������� i λ���ϵ�Ԫ��
	T& operator[](int i);
	const T& operator[](int i)const;

		// ǰ�������� �����ǰ������������������Ϊ0�� �����������ӱ��� �������Ϊ0�� ����Ϊ1
		// ���������� �����Ĵ�С����1�� ��ĩβԪ��Ϊitem
	void push_back(const T& item);

		// ɾ������ĩβԪ�أ� 
		// ǰ�������� �������Ϊ�գ� throw underflowError
		// ���������� ������ vSize - 1
	void pop_back();

		// ��ǰ�����Ĵ�С
	int size() const;

		//	��ǰ����������
	int capacity() const;

		// �ж������Ƿ�Ϊ��
	bool empty() const;

private:
	int vCapacity;	// ����������
	int vSize;		//  ������ǰ�洢��Ԫ����Ŀ
	T* vArr;	// �洢����Ԫ�صĶ�̬����

		/* ���ܣ� �ı������������� Ϊ�������·���n��С�Ŀռ䲢���copy = true�� ��ֵԭ������Ԫ�ص��µĿռ�
			ǰ�������� ��������µĿռ�ʧ�� throw memoryAllocationError, ԭ��������״̬����
			���������� ������������Ϊ n��
		*/
	void reserve(int n, bool copy);
};

/* ���ܣ� �ı������������� Ϊ�������·���n��С�Ŀռ䲢���copy = true�� ��ֵԭ������Ԫ�ص��µĿռ�
ǰ�������� ��������µĿռ�ʧ�� throw memoryAllocationError, ԭ��������״̬����
���������� ������������Ϊ n��
*/
template <typename T>
void Vector<T>::reserve(int n, bool copy)
{
	T* newArr = new T[n];
	if (NULL == newArr)
		throw memoryAllocationError("reserve()�����ڴ�ռ�ʧ��");

	// ��� copy == true�� ���Ƶ�ǰԪ��
	if (true == copy)
	{
		for (int i = 0; i < vSize; i++)
		{
			newArr[i] = vArr[i];
		}
	}
		// �ͷ�ԭ���Ŀռ�
	if (NULL != vArr)
		delete[] vArr;

	vArr = newArr;
	vCapacity = n;
}

// ���캯��, ���size > 0�� ����size��С�Ŀռ䣬ʹ��T����Ĭ�Ϲ��캯����ʼ���ռ�
// ���������� �����������ʹ�С��Ϊ size
template <typename T>
Vector<T>::Vector(int size) :
vSize(0), vCapacity(0), vArr(NULL)
{
	if (size == 0) return;		

		// ����ռ�
	reserve(size, false);

	vSize = size;
		// ��ʼ���ռ�Ԫ��
	for (int i = 0; i < vSize; i++)
		vArr[i] = T();
}

// ���ƹ��캯����
template <typename T>
Vector<T>::Vector(const Vector<T>& obj) :
vSize(0), vCapacity(0), vArr(NULL)
{
	if (obj.vSize == 0) return;

	// ����ռ�
	reserve(obj.vSize, false);

	vSize = obj.vSize;
	// ��ʼ���ռ�Ԫ��
	for (size_t i = 0; i < vsize; i++)
		vArr[i] = obj.vArr[i];
}

// �ͷŶ�̬��������Ŀռ�
template <typename T>
Vector<T>::~Vector()
{
	if (NULL != vArr)
		delete vArr;
}

// ��ֵ������ ��rhs��������ǰ����
template <typename T>
Vector<T>& Vector<T>::operator= (const Vector<T>& rhs)
{
	if (vCapacity < rhs.vSize)
		reserve(rhs.vSize, false);

	vSize = obj.vSize;
	// ��ʼ���ռ�Ԫ��
	for (size_t i = 0; i < vSize; i++)
		vArr[i] = obj.vArr[i];

	return *this;
}

// ��������ĩβԪ��
// ǰ���������������Ϊ�գ� throw underflowError
template <typename T>
T& Vector<T>::back()
{
		// �������Ϊ�գ� throw underflowError
	if (0 == vSize)
		throw underflowError("back()����һ��������");

	return vArr[vSize - 1];
}

template <typename T>
const T& Vector<T>::back() const
{
	// �������Ϊ�գ� throw underflowError
	if (0 == vSize)
		throw underflowError("back()����һ��������");

	return vArr[vSize - 1];
}

// �����±����������� 
// ǰ������ ;��� i<0 ���� i> vSize-1�� throw underflowError
// ���������� �������� i λ���ϵ�Ԫ��
template <typename T>
T& Vector<T>::operator[](int i)
{
		// ��� i<0 ���� i> vSize-1�� throw underflowError
	if (i < 0 || i > vSize - 1)
		throw indexRangeError("operator=���������������޵ķ�Χ", i, vSize);

	return vArr[i];
}

template <typename T>
const T& Vector<T>::operator[](int i)const
{
		// ��� i<0 ���� i> vSize-1�� throw underflowError
	if (i < 0 || i > vSize - 1)
		throw indexRangeError("operator=���������������޵ķ�Χ", i, vSize);

	return vArr[i];
}

// ǰ�������� �����ǰ������������������Ϊ0�� �����������ӱ��� �������Ϊ0�� ����Ϊ1
// ���������� �����Ĵ�С����1�� ��ĩβԪ��Ϊitem
template <typename T>
void Vector<T>::push_back(const T& item)
{	
		// �����ǰ������������������Ϊ0�� �����������ӱ��� �������Ϊ0�� ����Ϊ1
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

// ɾ������ĩβԪ�أ� 
// ǰ�������� �������Ϊ�գ� throw underflowError
// ���������� ������ vSize - 1
template <typename T>
void Vector<T>::pop_back()
{
	if (vSize == 0)
		throw underflowError("pop_back()���ʿ�����");

	vSize--;
}

// ��ǰ�����Ĵ�С
template <typename T>
int Vector<T>::size() const
{
	return vSize;
}

//	��ǰ����������
template <typename T>
int Vector<T>::capacity() const
{
	return vCapacity;
}

// �ж������Ƿ�Ϊ��
template <typename T>
bool Vector<T>::empty() const
{
	return vSize == 0;
}

#endif // !VECTOR
