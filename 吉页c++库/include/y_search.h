#ifndef SEARCH_FUNCTIONS
#define SEARCH_FUNCTIONS

#include <list>
#include <vector>

using namespace std;

// 顺序查找
// 在数组下标 [first, last) 范围内，查找目标值
//如果找到目标值，返回其在数组中的下标， 否则返回last
int seqSearch(const int arr[], int first, int last, int target);

template <typename T>
int seqSearch(const T arr[], int first, int last, const T& target);

// 二分差值，  在数组下标 [first, last) 范围内，查找目标值
//如果找到目标值，返回其在数组中的下标， 否则返回last
int binSearch(const int arr[], int first, int last, int target);

template <typename T>
int binSearch(const T arr[], int first, int last, const T& target);

// 顺序查找，  在向量下标 [first, last) 范围内，查找目标值
//如果找到目标值，返回其在数组中的下标， 否则返回last
template <typename T>
int seqSearch(const vector<T> v, int first, int last, const T& target);

// 二分差值，  在向量下标 [first, last) 范围内，查找目标值
//如果找到目标值，返回其在数组中的下标， 否则返回last
template <typename T>
int binSearch(const vector<T> v, int first, int last, const T& target);

// 顺序查找，  在链表下标 [first, last) 范围内，查找目标值
//如果找到目标值，返回其在数组中的下标， 否则返回last

template <typename FwdIt, typename T> inline
FwdIt seqSearch(FwdIt first, FwdIt last, const T& target);

// 功能： 迭代[first, end）返回内的元素，查找目标值
// 如果目标值找到， 返回指向目标值的迭代器， 否则返回last
template <typename Iterator, typename T>
Iterator find(Iterator first, Iterator last, const T& target);


/*---------------------------------------------------------
						函数的实现
-----------------------------------------------------------*/

// 顺序查找
// 在数组下标 [first, last) 范围内，查找目标值
//如果找到目标值，返回其在数组中的下标， 否则返回last
int seqSearch(const int arr[], int first, int last, int target)
{
	for (int i = first; i < last; i++)
		if (arr[i] == target)
			return i;

	return last;
}

template <typename T>
int seqSearch(const T arr[], int first, int last, const T& target)
{
	for (size_t i = first; i < last; i++)
		if (arr[i] == target)
			return i;	//	如果找到返回下标

	return last;		// 没有找到返回last
}

// 二分差值，  在数组下标 [first, last) 范围内，查找目标值
//如果找到目标值，返回其在数组中的下标， 否则返回last
int binSearch(const int arr[], int first, int last, int target)
{
	int midIndex, midValue;

	while (first != last)
	{
		midIndex = (first + last) / 2;
		midValue = arr[midIndex];

		if (target == midValue) 
			return midIndex;	// 返回找到的的下标
		else if (target < midValue)
			last = midIndex;	// 在数组的前部部分查找
		else
			first = midIndex + 1;	// 在数组的后部部分查找
	}
	
	return last;
}

template <typename T>
int binSearch(const T arr[], int first, int last, const T& target)
{
	int midIndex;
	T midValue;

	while (first != last)
	{
		midIndex = (first + last) / 2;
		midValue = arr[midIndex];

		if (target == midValue)
			return midIndex;	// 返回找到的的下标
		else if (target < midValue)
			last = midIndex;	// 在数组的前部部分查找
		else
			first = midIndex + 1;	// 在数组的后部部分查找
	}

	return last;
}

// 顺序查找，  在向量下标 [first, last) 范围内，查找目标值
//如果找到目标值，返回其在数组中的下标， 否则返回last
template <typename T>
int seqSearch(const vector<T> v, int first, int last, const T& target)
{
	for (int i = first; i < last; ++i)
		if (v[i] == target)
			return i;		// 如果找到，返回下标

	return last;		// 如果没有找到， 返回last
}

// 二分差值，  在向量下标 [first, last) 范围内，查找目标值
//如果找到目标值，返回其在数组中的下标， 否则返回last
template <typename T>
int binSearch(const vector<T> v, int first, int last, const T& target)
{
	int midIndex;
	T midValue;

	while (first != last)
	{
		midIndex = (first + last) / 2;
		midValue = v[midIndex];

		if (target == midValue)
			return midIndex;	// 返回找到的的下标
		else if (target < midValue)
			last = midIndex;	// 在数组的前部部分查找
		else
			first = midIndex + 1;	// 在数组的后部部分查找
	}

	return last;
}
//
// 顺序查找，  在链表下标 [first, last) 范围内，查找目标值
//如果找到目标值，返回其在数组中的下标， 否则返回last
template <typename FwdIt, typename T> inline
FwdIt seqSearch(FwdIt first, FwdIt last, const T& target)
{
	FwdIt iter = first;
	for (iter = first; iter != last; ++iter)
	if (*iter == target)
		return iter;		// 如果找到，返回下标

	return last;		// 如果没有找到， 返回last
}

// 功能： 迭代[first, end）返回内的元素，查找目标值
// 如果目标值找到， 返回指向目标值的迭代器， 否则返回last
template <typename Iterator, typename T>
Iterator find(Iterator first, Iterator last, const T& target)
{
	Iterator iter = first;
	for (iter = first; iter != last; ++iter)
	if (*iter == target)
		return iter;		// 如果找到，返回下标

	return last;		// 如果没有找到， 返回last
}


#endif // !SEARCH_FUNCTIONS
