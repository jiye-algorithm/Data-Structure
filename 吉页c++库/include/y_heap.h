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


/////////////////////////////////////////		函数实现		////////////////////////////////////////////////////////


// the vector elements in the range [0, last-1) are a heap.
// insert the element v[last-1] into the heap so that the
// range [0, last) is a heap. use the function object comp
// to perform comparisons
template <typename T, typename Compare>
void pushHeap(vector<T>& v, int last, Compare comp)
{
		// 记录当前的位置和父节点位置， 以及要插入元素
	T target = v[last - 1];
	int currentPos = last - 1;
	int parrentPos = (currentPos - 1) / 2;
	
	while (currentPos != 0)
	{
			// 如果当前结点不是合适位置是， 将当前节点和父节点同时上移。
		if (comp(target, v[parrentPos]))
		{	
			v[currentPos] = v[parrentPos];
			currentPos = parrentPos;
			parrentPos = (currentPos - 1) / 2;
		}
		else
			break;
	}
		// 将元素放到找到的堆中合适的位置
	v[currentPos] = target;
}

// filter the vector element v[first] down the heap with index
// range [first, last)
template <typename T, typename Compare>
void adjustHeap(vector<T>& v, int first, int last, Compare comp)
{
		// 记录当前结点和它的子节点
	int currentPos = first,
		childPos = currentPos * 2 + 1;
	T target = v[first];

		// 总根节点开始查找目标元素的合适位置， 当为最后一个结点或当前结点值 comp函数， 比较后为false时 ， 退出循环
	while (childPos <= last - 1)
	{
			// 找到子节点中较大的元素
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

		// 插入合适的位置
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

		// 调整堆【0， last - 1）元素， 使其堆化
	adjustHeap(v, 0, last - 1, comp);
}

// arrange the vector elements into a heap. use the function
// object comp to perform comparisons
template <typename T, typename Compare>
void makeHeap(vector<T>& v, Compare comp)
{
	int lastPos = v.size();
	int heapPos = (lastPos - 2) / 2;

		// 利用递归的思想， 从下向上堆化元素， 可见树与递归关系的紧密
	while (heapPos >= 0)
	{
		adjustHeap(v, heapPos, lastPos, comp);
		heapPos--;
	}
}


#endif // !HEAP_FUNCTIONS