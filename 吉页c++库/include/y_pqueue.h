#ifndef MINI_PRIORITY_QUEUE_CLASS
#define MINI_PRIORITY_QUEUE_CLASS

#include <vector>

#include "y_heap.h"
#include "y_except.h"

template <typename T, typename Compare = greater<T> >
class miniPQ
{
public:
		// Ĭ�Ϲ��캯��
	miniPQ() 
	{}

		// ���еĴ�С
	int size() const
	{		return pqList.size(); 		}

		// �����Ƿ�Ϊ��
	bool empty() const
	{
		return pqList.empty();
	}

		// ����Ԫ�ص�����
	void push(const T& item);

		// ��������Ԫ��
	void pop();

		// ��ö���Ԫ��
	T& top();
	const T& top() const;

private:
	vector<T> pqList;
	Compare comp;
};


/************************************************************************/
/*							ʵ��                                                                     */
/************************************************************************/


// ����Ԫ�ص�����
template <typename T, typename Compare = greater<T> >
void miniPQ<T, Compare>::push(const T& item)
{
	// �������ѣ� ���ڵõ����ȼ��ߵ�Ԫ��
	pqList.push_back(item);
	push_heap(pqList, pqList.size(), comp);
}

// ��������Ԫ��
template <typename T, typename Compare = greater<T> >
void miniPQ<T, Compare>::pop()
{
		// ���в���Ϊ��
	if (pqList.empty())
		throw underflowError("pop()����һ��������");

		// �����ȼ��ߵ�Ԫ�طŵ���β
	popHeap(pqList, pqList.size, comp);
		// ����Ԫ��
	pqList.pop_back();
}

// ��ö���Ԫ��
template <typename T, typename Compare = greater<T> >
T& miniPQ<T, Compare>::top()
{
	// ���в���Ϊ��
	if (pqList.empty())
		throw underflowError("top()����һ��������");

		// ������ǰ���ֵ�����ŵ�
	return pqList[0];
}

template <typename T, typename Compare = greater<T> >
const T& miniPQ<T, Compare>::top() const
{
	// ���в���Ϊ��
	if (pqList.empty())
		throw underflowError("top()����һ��������");

	return pqList[0];
}


#endif // !MINI_PRIORITY_QUEUE_CLASS
