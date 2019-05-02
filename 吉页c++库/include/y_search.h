#ifndef SEARCH_FUNCTIONS
#define SEARCH_FUNCTIONS

#include <list>
#include <vector>

using namespace std;

// ˳�����
// �������±� [first, last) ��Χ�ڣ�����Ŀ��ֵ
//����ҵ�Ŀ��ֵ���������������е��±꣬ ���򷵻�last
int seqSearch(const int arr[], int first, int last, int target);

template <typename T>
int seqSearch(const T arr[], int first, int last, const T& target);

// ���ֲ�ֵ��  �������±� [first, last) ��Χ�ڣ�����Ŀ��ֵ
//����ҵ�Ŀ��ֵ���������������е��±꣬ ���򷵻�last
int binSearch(const int arr[], int first, int last, int target);

template <typename T>
int binSearch(const T arr[], int first, int last, const T& target);

// ˳����ң�  �������±� [first, last) ��Χ�ڣ�����Ŀ��ֵ
//����ҵ�Ŀ��ֵ���������������е��±꣬ ���򷵻�last
template <typename T>
int seqSearch(const vector<T> v, int first, int last, const T& target);

// ���ֲ�ֵ��  �������±� [first, last) ��Χ�ڣ�����Ŀ��ֵ
//����ҵ�Ŀ��ֵ���������������е��±꣬ ���򷵻�last
template <typename T>
int binSearch(const vector<T> v, int first, int last, const T& target);

// ˳����ң�  �������±� [first, last) ��Χ�ڣ�����Ŀ��ֵ
//����ҵ�Ŀ��ֵ���������������е��±꣬ ���򷵻�last

template <typename FwdIt, typename T> inline
FwdIt seqSearch(FwdIt first, FwdIt last, const T& target);

// ���ܣ� ����[first, end�������ڵ�Ԫ�أ�����Ŀ��ֵ
// ���Ŀ��ֵ�ҵ��� ����ָ��Ŀ��ֵ�ĵ������� ���򷵻�last
template <typename Iterator, typename T>
Iterator find(Iterator first, Iterator last, const T& target);


/*---------------------------------------------------------
						������ʵ��
-----------------------------------------------------------*/

// ˳�����
// �������±� [first, last) ��Χ�ڣ�����Ŀ��ֵ
//����ҵ�Ŀ��ֵ���������������е��±꣬ ���򷵻�last
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
			return i;	//	����ҵ������±�

	return last;		// û���ҵ�����last
}

// ���ֲ�ֵ��  �������±� [first, last) ��Χ�ڣ�����Ŀ��ֵ
//����ҵ�Ŀ��ֵ���������������е��±꣬ ���򷵻�last
int binSearch(const int arr[], int first, int last, int target)
{
	int midIndex, midValue;

	while (first != last)
	{
		midIndex = (first + last) / 2;
		midValue = arr[midIndex];

		if (target == midValue) 
			return midIndex;	// �����ҵ��ĵ��±�
		else if (target < midValue)
			last = midIndex;	// �������ǰ�����ֲ���
		else
			first = midIndex + 1;	// ������ĺ󲿲��ֲ���
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
			return midIndex;	// �����ҵ��ĵ��±�
		else if (target < midValue)
			last = midIndex;	// �������ǰ�����ֲ���
		else
			first = midIndex + 1;	// ������ĺ󲿲��ֲ���
	}

	return last;
}

// ˳����ң�  �������±� [first, last) ��Χ�ڣ�����Ŀ��ֵ
//����ҵ�Ŀ��ֵ���������������е��±꣬ ���򷵻�last
template <typename T>
int seqSearch(const vector<T> v, int first, int last, const T& target)
{
	for (int i = first; i < last; ++i)
		if (v[i] == target)
			return i;		// ����ҵ��������±�

	return last;		// ���û���ҵ��� ����last
}

// ���ֲ�ֵ��  �������±� [first, last) ��Χ�ڣ�����Ŀ��ֵ
//����ҵ�Ŀ��ֵ���������������е��±꣬ ���򷵻�last
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
			return midIndex;	// �����ҵ��ĵ��±�
		else if (target < midValue)
			last = midIndex;	// �������ǰ�����ֲ���
		else
			first = midIndex + 1;	// ������ĺ󲿲��ֲ���
	}

	return last;
}
//
// ˳����ң�  �������±� [first, last) ��Χ�ڣ�����Ŀ��ֵ
//����ҵ�Ŀ��ֵ���������������е��±꣬ ���򷵻�last
template <typename FwdIt, typename T> inline
FwdIt seqSearch(FwdIt first, FwdIt last, const T& target)
{
	FwdIt iter = first;
	for (iter = first; iter != last; ++iter)
	if (*iter == target)
		return iter;		// ����ҵ��������±�

	return last;		// ���û���ҵ��� ����last
}

// ���ܣ� ����[first, end�������ڵ�Ԫ�أ�����Ŀ��ֵ
// ���Ŀ��ֵ�ҵ��� ����ָ��Ŀ��ֵ�ĵ������� ���򷵻�last
template <typename Iterator, typename T>
Iterator find(Iterator first, Iterator last, const T& target)
{
	Iterator iter = first;
	for (iter = first; iter != last; ++iter)
	if (*iter == target)
		return iter;		// ����ҵ��������±�

	return last;		// ���û���ҵ��� ����last
}


#endif // !SEARCH_FUNCTIONS
