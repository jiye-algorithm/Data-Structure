#ifndef SORT_FUNCTIONS
#define  SORT_FUNCTIONS

#include <queue>
#include <algorithm>
#include <vector>

#include "y_heap.h"

using namespace std;

	// ��������, �㷨������ÿ��Ϊ�ӵ�λ����λ������λ����
template <typename T>
void radixSort(vector<T>& v, int d);

	// ѡ����������
template <typename T>
void selectionSort(T arr[], int n);

// sort a vector of type T using selection sort
template <typename T>
void selectionSort(vector<T>& v);

	// ������������
template <typename T>
void insertionSort(vector<T>& v);




///////////////////////////////////////////////////////////////					����ʵ��			///////////////////////////////////////////////////////


// sort an array of type T using selection sort
template <typename T>
void selectionSort(T arr[], int n)
{
		// ��¼����±귽�㽻��
	int max;

		// �����ҵ��������Ԫ�أ� �ŵ� i λ��
	for (int i = 0; i < n - 1; ++i)
	{
			// ����ǰ�±�Ĭ��Ϊ���ֵ���꣬ Ȼ��ӵ�ǰλ�ö���һ��λ�ÿ�ʼ�ҵ�����±�
		max = i;

		for (int j = i + 1; j < n; ++j)
		{
			if (arr[max] < arr[j])
				max = j;
		}
		
			// ��������±겻�ǵ�ǰλ��ʱ�� ���н���
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
	// ��¼����±귽�㽻��
	int max;

		// ��¼������Ԫ�صĸ���
	int n = v.size();

		// �������������Ԫ�أ� �ŵ� i λ��
	for (int i = 0; i < n - 1; ++i)
	{
			// ����ǰ�±�Ĭ��Ϊ���ֵ���꣬ Ȼ��ӵ�ǰλ�ö���һ��λ�ÿ�ʼ�ҵ�����±�
		max = i;

		for (int j = i + 1; j < n; ++j)
		{
			if (v[max] < v[j])
				max = j;
		}

			// ��������±겻�ǵ�ǰλ��ʱ�� ���н���
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
		// ��¼������Ԫ�ظ���
	int n = v.size();

		// �ӵ�ǰλ�ÿ�ʼ�� ����ǰ���Ԫ��������ģ� �ҵ���ǰλ�õ��������еĺ���λ�ã� ����
	for (int i = 1; i < n; i++)
	{
		T target = v[i];
		
			// �ҵ���ǰԪ��Ӧ�������򲿷��еĺ���λ��
		int j = i;
		while (j > 0 && target < v[j - 1])
		{
			v[j] = v[j - 1];
			j--;
		}
			
			// ��Ԫ�ز��뵽�ҵ���λ��
		v[j] = target;
	}
}

// sort the elements of a vector of type T in the range
// [first, last) using insertion sort
template <typename T>
void insertionSort(vector<T>& v, int first, int last)
{
		// �ӵ�ǰλ�ÿ�ʼ�� ����ǰ���Ԫ��������ģ� �ҵ���ǰλ�õ��������еĺ���λ�ã� ����
	for (int i = first + 1; i < last; i++)
	{
		T target = v[i];

		// �ҵ���ǰԪ��Ӧ�������򲿷��еĺ���λ��
		int j = i;
		while (j > first && target < v[j - 1])
		{
			v[j] = v[j - 1];
			j--;
		}

		// ��Ԫ�ز��뵽�ҵ���λ��
		v[j] = target;
	}
}

// sort a vector using heapsort
template <typename T, typename Compare>
void heapSort(vector<T>& v, Compare comp)
{
		// ʹ�������Ի�
	makeHeap(v, comp);

		// ��������
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
		// ��ʱ������������ʱ�����
	vector<T> tempVec;
		// ��ʼ��¼������ �������С�first��mid���͡�mid�� last�� �����Ԫ�ؽ�������
		// ���������Լ���ѡ���С��Ԫ�أ� ������ʱ������
	int indexA = first, 
		indexB = mid;

		// �����ӱ��У� �������ӱ���Ϊ��ʱ
	while (indexA < mid && indexB < last)
	{
			// ���ӱ��н�С��Ԫ�ز�����ʱ������
		if (v[indexA] < v[indexB])
			tempVec.push_back(v[indexA++]);
		else
			tempVec.push_back(v[indexB++]);
	}

		// �������ӱ��л�δ��������Ԫ�ز�������
	while (indexA < mid)
		tempVec.push_back(v[indexA++]);
	while (indexB < last)
		tempVec.push_back(v[indexB++]);

		// ������ɣ� ��ʱ������ǰ���� ����ʱ����Ԫ�ز���Դ������
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
			//���ú�������ķ�ʽ�� ���������й鲢����
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


	/*				����ʵ�ֻ�������Ĺ�						// begin													*/
template <typename T>
void distribute(vector<T>& v, queue<T> q[10], int power)
{
		// ���������� ��������������powerλ
	for (int i = 0; i < v.size(); i++)
	{
		q[v[i] / power % 10].push(v[i]);
	}
}

template <typename T>
void collect(queue<T> q[10], vector<T>& v)
{
		// ��¼�����¸����ʵ��±�
	int index = 0;
		// ��������Ķ������飬 ��Ԫ�ط�������
	for (int i = 0; i < 10; ++i)
	{
		while (!q[i].empty())
		{
			v[index++] = q[i].front();
			q[i].pop();
		}
	}
}

	// ��������, �㷨������ÿ��Ϊ�ӵ�λ����λ������λ����
template <typename T>
void radixSort(vector<T>& v, int d)
{
	int power = 1;
	queue<T> digitQueue[10];

		// ��λ����
	for (int i = 0; i < d; ++i)
	{
		distribute(v, digitQueue, power);
		collect(digitQueue, v);
		power *= 10;
	}

}

/*				����ʵ�ֻ�������Ĺ�						// end													*/


#endif // !SORT_FUNCTIONS
