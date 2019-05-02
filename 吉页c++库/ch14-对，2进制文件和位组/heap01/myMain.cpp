/*
	2014年5月13日 18:34:13
	吉页
	功能： 使用堆的pushHeap和popHeap操作
*/

#include <iostream>
#include <vector>

#include "../../include/y_heap.h"

using namespace std;

int main()
{
	int arr[] = { 5, 9, 2, 7, 1, 3, 8 };
	vector<int>va, vb;
	int arrSize = sizeof(arr) / sizeof(int);

		// 组件一个最大堆和最小堆
	for (int i = 0; i < arrSize; ++i)
	{
		va.push_back(arr[i]);
		pushHeap(va, va.size(), greater<int>());
		vb.push_back(arr[i]);
		pushHeap(vb, vb.size(), less<int>());
	}

	cout << "Maximum heap: ";
	while (!va.empty())
	{
		popHeap(va, va.size(), greater<int>());
		cout << va.back() << "  ";
		va.pop_back();
	}
	cout << endl;

	cout << "Minum heap:";
	while (!vb.empty())
	{
		popHeap(vb, vb.size(), less<int>());
		cout << vb.back() << "  ";
		vb.pop_back();
	}

	system("pause");
	return 0;
}