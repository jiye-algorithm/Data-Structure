#ifndef HEAP_FUNCTIONS
#define HEAP_FUNCTIONS

#include <vector>
#include <functional>

using namespace std;

// the vector elements in the range [0, last-1) are a heap.
// insert the element v[last-1] into the heap so that the
// range [0, last) is a heap. use the function object comp
// to perform comparisons
template <typename T, typename Compare>
void pushHeap(vector<T>& v, int last, Compare comp);

// filter the vector element v[first] down the heap with index
// range [first, last)
template <typename T, typename Compare>
void adjustHeap(vector<T>& v, int first, int last, Compare comp);

// the vector elements in the range [0, last) are a heap.
// swap the first and last elements of the heap and then
// make the elements in the index range [0, last-1) a heap.
// use the function object comp to perform comparisons
template <typename T, typename Compare>
void popHeap(vector<T>& v, int last, Compare comp);

// arrange the vector elements into a heap. use the function
// object comp to perform comparisons
template <typename T, typename Compare>
void makeHeap(vector<T>& v, Compare comp);


/////////////////////////////////////////		����ʵ��		////////////////////////////////////////////////////////


// the vector elements in the range [0, last-1) are a heap.
// insert the element v[last-1] into the heap so that the
// range [0, last) is a heap. use the function object comp
// to perform comparisons
template <typename T, typename Compare>
void pushHeap(vector<T>& v, int last, Compare comp)
{
		// ��¼��ǰ��λ�ú͸��ڵ�λ�ã� �Լ�Ҫ����Ԫ��
	T target = v[last - 1];
	int currentPos = last - 1;
	int parrentPos = (currentPos - 1) / 2;
	
	while (currentPos != 0)
	{
			// �����ǰ��㲻�Ǻ���λ���ǣ� ����ǰ�ڵ�͸��ڵ�ͬʱ���ơ�
		if (comp(target, v[parrentPos]))
		{	
			v[currentPos] = v[parrentPos];
			currentPos = parrentPos;
			parrentPos = (currentPos - 1) / 2;
		}
		else
			break;
	}
		// ��Ԫ�طŵ��ҵ��Ķ��к��ʵ�λ��
	v[currentPos] = target;
}

// filter the vector element v[first] down the heap with index
// range [first, last)
template <typename T, typename Compare>
void adjustHeap(vector<T>& v, int first, int last, Compare comp)
{
		// ��¼��ǰ���������ӽڵ�
	int currentPos = first,
		childPos = currentPos * 2 + 1;
	T target = v[first];

		// �ܸ��ڵ㿪ʼ����Ŀ��Ԫ�صĺ���λ�ã� ��Ϊ���һ������ǰ���ֵ comp������ �ȽϺ�Ϊfalseʱ �� �˳�ѭ��
	while (childPos <= last - 1)
	{
			// �ҵ��ӽڵ��нϴ��Ԫ��
		if (childPos + 1 <= last - 1 &&
			comp(v[childPos + 1], v[childPos]))
			childPos = childPos + 1;

		if (comp(v[childPos], target))
		{
			v[currentPos] = v[childPos];
			currentPos = childPos;
			childPos = currentPos * 2 + 1;
		}
		else
			break;
	}

		// ������ʵ�λ��
	v[currentPos] = target;
}

// the vector elements in the range [0, last) are a heap.
// swap the first and last elements of the heap and then
// make the elements in the index range [0, last-1) a heap.
// use the function object comp to perform comparisons
template <typename T, typename Compare>
void popHeap(vector<T>& v, int last, Compare comp)
{
	T temp = v[0];
	v[0] = v[last - 1];
	v[last - 1] = temp;

		// �����ѡ�0�� last - 1��Ԫ�أ� ʹ��ѻ�
	adjustHeap(v, 0, last - 1, comp);
}

// arrange the vector elements into a heap. use the function
// object comp to perform comparisons
template <typename T, typename Compare>
void makeHeap(vector<T>& v, Compare comp)
{
	int lastPos = v.size();
	int heapPos = (lastPos - 2) / 2;

		// ���õݹ��˼�룬 �������϶ѻ�Ԫ�أ� �ɼ�����ݹ��ϵ�Ľ���
	while (heapPos >= 0)
	{
		adjustHeap(v, heapPos, lastPos, comp);
		heapPos--;
	}
}


#endif // !HEAP_FUNCTIONS