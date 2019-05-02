#ifndef LIST_FUNCTIONS
#define LIST_FUNCTIONS

#include <list>

using namespace std;

	// ���ò���������������в�������
	// �������ñ������Ƚϱ���Ԫ�أ��ҵ���һ�� >= target Ԫ�أ� ��target �����λ��
template <typename T>
void insertSort(list<T> orderedList, const T& item);

	// ɾ�������ظ���Ԫ��
template <typename T>
void removeDuplicates(list<T> aList);

	// �Ͳ�������
template <typename T>
void splice(list<T> destList, list<T>::iterator pos, const list<T>& srcList);


///////////////////////////////////////////////////////////////////////////////
//						����ʵ��
///////////////////////////////////////////////////////////////////////////////


// ���ò���������������в�������
// �������ñ������Ƚϱ���Ԫ�أ��ҵ���һ�� >= target Ԫ�أ� ��target �����λ��
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

// ɾ�������ظ���Ԫ��
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

// �Ͳ�������
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
