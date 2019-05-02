#ifndef MINI_PRIORITY_QUEUE_CLASS
#define MINI_PRIORITY_QUEUE_CLASS

#include <vector>

#include "y_heap.h"
#include "y_except.h"

template <typename T, typename Compare = greater<T> >
class miniPQ
{
public:
		// 默认构造函数
	miniPQ() 
	{}

		// 队列的大小
	int size() const
	{		return pqList.size(); 		}

		// 队列是否为空
	bool empty() const
	{
		return pqList.empty();
	}

		// 增加元素到队列
	void push(const T& item);

		// 弹出队首元素
	void pop();

		// 获得队首元素
	T& top();
	const T& top() const;

private:
	vector<T> pqList;
	Compare comp;
};


/************************************************************************/
/*							实现                                                                     */
/************************************************************************/


// 增加元素到队列
template <typename T, typename Compare = greater<T> >
void miniPQ<T, Compare>::push(const T& item)
{
	// 将向量堆， 便于得到优先级高的元素
	pqList.push_back(item);
	push_heap(pqList, pqList.size(), comp);
}

// 弹出队首元素
template <typename T, typename Compare = greater<T> >
void miniPQ<T, Compare>::pop()
{
		// 队列不能为空
	if (pqList.empty())
		throw underflowError("pop()操作一个空容器");

		// 将优先级高的元素放到队尾
	popHeap(pqList, pqList.size, comp);
		// 弹出元素
	pqList.pop_back();
}

// 获得队首元素
template <typename T, typename Compare = greater<T> >
T& miniPQ<T, Compare>::top()
{
	// 队列不能为空
	if (pqList.empty())
		throw underflowError("top()操作一个空容器");

		// 向量最前面的值是最优的
	return pqList[0];
}

template <typename T, typename Compare = greater<T> >
const T& miniPQ<T, Compare>::top() const
{
	// 队列不能为空
	if (pqList.empty())
		throw underflowError("top()操作一个空容器");

	return pqList[0];
}


#endif // !MINI_PRIORITY_QUEUE_CLASS
