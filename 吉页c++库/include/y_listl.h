#ifndef LIST_FUNCTIONS
#define LIST_FUNCTIONS

#include <list>

using namespace std;

	// 采用插叙排序法向已需表中插入数据
	// 函数利用遍历并比较表中元素，找到第一个 >= target 元素， 将target 插入此位置
template <typename T>
void insertSort(list<T> orderedList, const T& item);

	// 删除表中重复的元素
template <typename T>
void removeDuplicates(list<T> aList);

	// 和并两个表
template <typename T>
void splice(list<T> destList, list<T>::iterator pos, const list<T>& srcList);


///////////////////////////////////////////////////////////////////////////////
//						函数实现
///////////////////////////////////////////////////////////////////////////////


// 采用插叙排序法向已需表中插入数据
// 函数利用遍历并比较表中元素，找到第一个 >= target 元素， 将target 插入此位置
template <typename T>
void insertSort(list<T> orderedList, const T& item)
{
	list<T>::iterator iter;
	for (iter = orderedList.begin(); iter != orderedList.end(); ++iter)
	{
		if (item <= *iter) break;
	}

	orderedList.insert(iter, item);
}

// 删除表中重复的元素
template <typename T>
void removeDuplicates(list<T> aList)
{
	list<T>::iterator curIter = aList.begin();
	list<T>::iterator	transIter;

	while (curIter != aList.end())
	{
		transIter = curIter;
		while (transIter != aList.end())
		{
			if (*transIter == *curIter)
				aList.remove(transIter++);
			else
				transIter++
		}
		curIter++;
	}
}

// 和并两个表
template <typename T>
void splice(list<T> destList, list<T>::iterator pos, const list<T>& srcList)
{
	list<T>::iterator curIter;

	for (curIter = srcList.begin(); curIter != srcList.end(); ++curIter)
	{
		destList.insert(pos, *curIter);
	}
}


#endif // !LIST_FUNCTIONS
