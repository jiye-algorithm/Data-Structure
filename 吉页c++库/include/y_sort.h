#ifndef SORT_FUNCTIONS
#define  SORT_FUNCTIONS

#include <queue>
#include <algorithm>
#include <vector>

#include "y_heap.h"

using namespace std;

	// 基数排序, 算法将数字每个为从低位到高位进行逐位排序
template <typename T>
void radixSort(vector<T>& v, int d);

	// 选择排序数组
template <typename T>
void selectionSort(T arr[], int n);

// sort a vector of type T using selection sort
template <typename T>
void selectionSort(vector<T>& v);

	// 插入排序向量
template <typename T>
void insertionSort(vector<T>& v);




///////////////////////////////////////////////////////////////					函数实现			///////////////////////////////////////////////////////


// sort an array of type T using selection sort
template <typename T>
void selectionSort(T arr[], int n)
{
		// 记录最大下标方便交换
	int max;

		// 遍历找到数组最大元素， 放到 i 位置
	for (int i = 0; i < n - 1; ++i)
	{
			// 将当前下标默认为最大值坐标， 然后从当前位置饿后一个位置开始找到最大下标
		max = i;

		for (int j = i + 1; j < n; ++j)
		{
			if (arr[max] < arr[j])
				max = j;
		}
		
			// 如果最大的下标不是当前位置时， 进行交换
		if (max != i)
		{
			swap(arr[max], arr[i]);
		}
	}

}

// sort a vector of type T using selection sort
template <typename T>
void selectionSort(vector<T>& v)
{
	// 记录最大下标方便交换
	int max;

		// 记录向量中元素的个数
	int n = v.size();

		// 遍历找向量最大元素， 放到 i 位置
	for (int i = 0; i < n - 1; ++i)
	{
			// 将当前下标默认为最大值坐标， 然后从当前位置饿后一个位置开始找到最大下标
		max = i;

		for (int j = i + 1; j < n; ++j)
		{
			if (v[max] < v[j])
				max = j;
		}

			// 如果最大的下标不是当前位置时， 进行交换
		if (max != i)
		{
			swap(v[max], v[i]);
		}
	}

}

// sort a vector of type T using insertion sort
template <typename T>
void insertionSort(vector<T>& v)
{
		// 记录向量的元素个数
	int n = v.size();

		// 从当前位置开始， 在它前面的元素是依序的， 找到当前位置的在依序中的合适位置， 插入
	for (int i = 1; i < n; i++)
	{
		T target = v[i];
		
			// 找到当前元素应该在依序部分中的合适位置
		int j = i;
		while (j > 0 && target < v[j - 1])
		{
			v[j] = v[j - 1];
			j--;
		}
			
			// 将元素插入到找到的位置
		v[j] = target;
	}
}

// sort the elements of a vector of type T in the range
// [first, last) using insertion sort
template <typename T>
void insertionSort(vector<T>& v, int first, int last)
{
		// 从当前位置开始， 在它前面的元素是依序的， 找到当前位置的在依序中的合适位置， 插入
	for (int i = first + 1; i < last; i++)
	{
		T target = v[i];

		// 找到当前元素应该在依序部分中的合适位置
		int j = i;
		while (j > first && target < v[j - 1])
		{
			v[j] = v[j - 1];
			j--;
		}

		// 将元素插入到找到的位置
		v[j] = target;
	}
}

// sort a vector using heapsort
template <typename T, typename Compare>
void heapSort(vector<T>& v, Compare comp)
{
		// 使得向量对话
	makeHeap(v, comp);

		// 排序向量
	for (int i = v.size(); i > 1; --i)
	{
		popHeap(v, i, comp);
	}
}

// the elements in the ranges [first,mid) and [mid,last) are
// ordered. the function merges the ordered sequences into
// an ordered sequence in the range [first,last)
template <typename T>
void merge(vector<T>& v, int first, int mid, int last)
{
		// 临时向量，存数临时以序表
	vector<T> tempVec;
		// 开始记录变量， 对向量中【first，mid）和【mid， last） 区间的元素进行排序，
		// 遍历两个自己，选择较小的元素， 插入临时向量中
	int indexA = first, 
		indexB = mid;

		// 遍历子表中， 当两个子表都不为空时
	while (indexA < mid && indexB < last)
	{
			// 将子表中较小的元素插入临时向量中
		if (v[indexA] < v[indexB])
			tempVec.push_back(v[indexA++]);
		else
			tempVec.push_back(v[indexB++]);
	}

		// 将两个子表中还未遍历到的元素插入向量
	while (indexA < mid)
		tempVec.push_back(v[indexA++]);
	while (indexB < last)
		tempVec.push_back(v[indexB++]);

		// 操作完成， 临时向量当前有序， 将临时向量元素插入源向量中
	indexA = first;
	for (int i = 0; i < tempVec.size(); ++i)
		v[indexA++] = tempVec[i];
}

// sorts v in the index range [first,last) by merging
// ordered sublists
template <typename T>
void mergeSort(vector<T>& v, int first, int last)
{
	if (first + 1 < last)
	{
			//利用后跟遍历的方式， 将向量进行归并排序
		int mid = (first + last) / 2;
		mergeSort(v, first, mid);
		mergeSort(v, mid, last);
		merge(v, first, mid, last);
	}
}

// using the value at the midpoint of [first,last) as the pivot,
// locate the pivot in its final location so all elements
// to its left are <= to its value and all elements to the
// right are >= to its value. return the index of the pivot
template <typename T>
int pivotIndex(vector<T>& v, int first, int last);

// sort a vector using quicksort
template <typename T>
void quicksort(vector<T>& v, int first, int last);

// locate the kth largest element of v at index k
template <typename T>
void findK(vector<T>& v, int first, int last, int k);


	/*				函数实现基数排序的功						// begin													*/
template <typename T>
void distribute(vector<T>& v, queue<T> q[10], int power)
{
		// 遍历向量， 排序向量的排序power位
	for (int i = 0; i < v.size(); i++)
	{
		q[v[i] / power % 10].push(v[i]);
	}
}

template <typename T>
void collect(queue<T> q[10], vector<T>& v)
{
		// 记录向量下个访问的下标
	int index = 0;
		// 遍历排序的队列数组， 将元素返回向量
	for (int i = 0; i < 10; ++i)
	{
		while (!q[i].empty())
		{
			v[index++] = q[i].front();
			q[i].pop();
		}
	}
}

	// 基数排序, 算法将数字每个为从低位到高位进行逐位排序
template <typename T>
void radixSort(vector<T>& v, int d)
{
	int power = 1;
	queue<T> digitQueue[10];

		// 逐位排序
	for (int i = 0; i < d; ++i)
	{
		distribute(v, digitQueue, power);
		collect(digitQueue, v);
		power *= 10;
	}

}

/*				函数实现基数排序的功						// end													*/


#endif // !SORT_FUNCTIONS
